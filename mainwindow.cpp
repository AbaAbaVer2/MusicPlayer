#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QPalette>
#include <QFile>
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QTime>
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    m_mode(ORDER_MODE),
     ui(new Ui::MainWindow),
     m_isPlaying(false),  // 初始化播放状态
     m_isShowFlag(false),
     m_isMuted(false),
     m_lastVolume(50)
{
    ui->setupUi(this);

    //设置应用标题
    setWindowTitle("网抑云音乐（悲~）");
    //设置应用图标
    setWindowIcon(QIcon(":/res/wyyyy.png"));
    // 初始化播放器和音频输出
    m_player = new QMediaPlayer(this);
    m_audioOutput = new QAudioOutput(this);

    // 设置音频输出
    m_player->setAudioOutput(m_audioOutput);
    // 设置初始音量（范围0-100）
    m_audioOutput->setVolume(50);

    //固定窗口大小
    setFixedSize(1020,720);
    //设置背景图片
    setBackground(":/res/bg2.png");
    //初始化按钮
    initButtons();

    // 从本地文件系统加载

    m_isPlaying = false;  // 设置初始播放状态

    //加载歌曲列表
    m_musicDir = "D:\\1STUDY1\\Codes\\MusicPlayer\\res";
    loadAppointMusicDir(m_musicDir);

    srand((unsigned)time(NULL));

    connect(m_player, &QMediaPlayer::errorOccurred, 
        [this](QMediaPlayer::Error error, const QString &errorString) {
            QMessageBox::warning(this, "播放错误", errorString);
        });

    // 在MainWindow构造函数中添加，ui->setupUi(this)之后
    ui->progressBar->setMinimum(0);
    ui->currentTime->setText("00:00");
    ui->totalTime->setText("00:00");

    // 在MainWindow构造函数中添加
    connect(ui->progressBar, &QSlider::valueChanged, [this](int value) {
        // 只在用户拖动时更新预览时间
        if (ui->progressBar->isSliderDown()) {
            ui->currentTime->setText(formatTime(value));
        }
    });

    // 在MainWindow构造函数中，ui->setupUi(this)之后添加
    // 可以放在这一行附近：ui->volumeSlider->setValue(50);
    ui->volumeLabel->setText("50%");

    // 初始化隐藏定时器
    m_hideTimer = new QTimer(this);
    m_hideTimer->setSingleShot(true);
    m_hideTimer->setInterval(200);  // 0.2秒后隐藏
    connect(m_hideTimer, &QTimer::timeout, this, &MainWindow::hideVolumeControl);
    
    // 默认隐藏音量控件
    ui->volumeSlider->hide();
    ui->volumeLabel->hide();
    
    // 安装事件过滤器
    ui->muteBtn->installEventFilter(this);
    ui->volumeSlider->installEventFilter(this);
    ui->volumeLabel->installEventFilter(this);
}
//设置背景图片
void MainWindow::setBackground(const QString & filename)
{
    QPixmap pix(filename);

    QSize windowSize = this->size();

    QPixmap scalePixmap = pix.scaled(windowSize,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);

    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window,QBrush(scalePixmap));
    this->setPalette(palette);
}
//一个设置按钮样式的函数
void MainWindow::setButtonStyle(QPushButton * button , const QString & filename)
{
    button->setFixedSize(50,50);
    button->setIcon(QIcon(filename));
    button->setIconSize(QSize(button->width(),button->height()));
    button->setStyleSheet("background-color:transparent");
}
//初始化按钮
void MainWindow::initButtons()
{
    setButtonStyle(ui->prevBtn,":/res/Pre.png");
    setButtonStyle(ui->playBtn,":/res/Play.png");
    setButtonStyle(ui->nextBtn,":/res/Next.png");
    setButtonStyle(ui->modelBtn,":/res/Order.png");
    setButtonStyle(ui->listBtn,":/res/List.png");

    ui->musicList->setStyleSheet("QListWidget { border: none; border-radius: 20px; background-color: rgba(255,255,255,0.7); }");
    ui->musicList->hide();//初始化隐藏列表

    connect(ui->playBtn,&QPushButton::clicked, this,&MainWindow::handlePlaySlot);
    connect(ui->modelBtn,&QPushButton::clicked,this,&MainWindow::handleModelSlot);
    connect(ui->nextBtn,&QPushButton::clicked,this,&MainWindow::handleNextSlot);
    connect(ui->prevBtn,&QPushButton::clicked,this,&MainWindow::handlePrevSlot);

    connect(ui->listBtn,&QPushButton::clicked,this,&MainWindow::handleListSlot);

    connect(m_player,&QMediaPlayer::positionChanged,this,&MainWindow::handlePositionSlot);

    connect(m_player,&QMediaPlayer::durationChanged,this,&MainWindow::handleDurationSlot);

    connect(ui->progressBar, &QSlider::sliderMoved, this, &MainWindow::setPosition);

    // 设置音量滑块范围和初始值
    ui->volumeSlider->setRange(0, 100);
    ui->volumeSlider->setValue(50);

    // 设置音量滑块样式
    ui->volumeSlider->setStyleSheet(
        "QSlider::groove:horizontal {"
        "    height: 5px;"
        "    background: #e0e0e0;"
        "    border-radius: 2px;"
        "}"
        "QSlider::handle:horizontal {"
        "    background: #ffffff;"
        "    border: 1px solid #cccccc;"
        "    width: 12px;"
        "    height: 12px;"
        "    margin: -4px 0;"
        "    border-radius: 6px;"
        "}"
        "QSlider::sub-page:horizontal {"
        "    background: #5e35b1;"
        "    border-radius: 2px;"
        "}"
    );
    
    // 设置静音按钮
    setButtonStyle(ui->muteBtn, ":/res/volume.png");
    
    // 连接音量滑块信号
    connect(ui->volumeSlider, &QSlider::valueChanged, this, &MainWindow::onVolumeChanged);
    
    // 连接静音按钮信号
    connect(ui->muteBtn, &QPushButton::clicked, this, &MainWindow::onMuteToggled);
}
//处理音乐时长
void MainWindow::handleDurationSlot(int duration)
{
    ui->progressBar->setRange(0, duration);
    
    // 添加这一行来更新总时长标签
    ui->totalTime->setText(formatTime(duration));
}
//处理音乐进度
void MainWindow::handlePositionSlot(int position)
{
    // 只有在用户没有拖动进度条时才更新进度条位置
    if (!ui->progressBar->isSliderDown()) {
        ui->progressBar->setValue(position);
    }
    
    // 无论如何都更新时间标签
    ui->currentTime->setText(formatTime(position));
}
//设置播放位置
void MainWindow::setPosition(int position)
{
    // 设置播放器的位置
    m_player->setPosition(position);
}
//进度条两侧的时间显示
QString MainWindow::formatTime(qint64 timeInMs)
{
    // 毫秒转换为秒
    qint64 seconds = timeInMs / 1000;
    int minutes = seconds / 60;
    int remainingSeconds = seconds % 60;
    
    // 返回格式化的字符串 (mm:ss)
    return QString("%1:%2")
            .arg(minutes, 2, 10, QChar('0'))
            .arg(remainingSeconds, 2, 10, QChar('0'));
}
//播放音乐的实现
void MainWindow::startPlayMusic()
{
    QString musicName = ui->musicList->currentItem()->text();
    
    QString musicAbsPath = m_musicDir + "\\" + musicName + ".mp3";
    
    m_player->setSource(QUrl::fromLocalFile(musicAbsPath));
    
    // 保持当前播放状态
    if (m_isPlaying) {
        m_player->play();
    }
    // 不需要改变m_isPlaying，因为我们保持原状态
}
//播放和暂停键的切换与实现
void MainWindow::handlePlaySlot()
{
    if (m_isPlaying) {
        m_player->pause();
    } else {
        m_player->play();
    }
    m_isPlaying = !m_isPlaying;
    setButtonStyle(ui->playBtn, m_isPlaying ? ":/res/Stop.png" : ":/res/Play.png");
}
//三种播放顺序的图标的切换
void MainWindow::handleModelSlot()
{
    if(m_mode == ORDER_MODE)
    {
        m_mode = RANDOM_MODE;
        ui->modelBtn->setIcon(QIcon(":/res/Radom.png"));
    }
    else if(m_mode == RANDOM_MODE)
    {
        m_mode = CIRCLE_MODE;
        ui->modelBtn->setIcon(QIcon(":/res/Circle.png"));
    }
    else if(m_mode == CIRCLE_MODE)
    {
        m_mode = ORDER_MODE;
        ui->modelBtn->setIcon(QIcon(":/res/Order.png"));
    }
}
//上一首歌曲的实现
void MainWindow::handlePrevSlot()
{
    int currentRow = ui->musicList->currentRow();
    int prevRow = 0;
    if(m_mode == ORDER_MODE)
    {
        prevRow = currentRow - 1;
        if(prevRow < 0)
        {
            prevRow = ui->musicList->count() - 1;
        }
    }
    else if(m_mode == RANDOM_MODE)
    {
        int cnt = 0;
        do{
            prevRow = rand() % ui->musicList->count();
            cnt++;
        }while(currentRow == prevRow && cnt <3);
    }
    else if(m_mode == CIRCLE_MODE)
    {
        prevRow = currentRow;
    }

    ui->musicList->setCurrentRow(prevRow);

    startPlayMusic();
}
//下一首歌曲的实现
void MainWindow::handleNextSlot()
{
    int currentRow = ui->musicList->currentRow();
    int nextRow = 0;
    if(m_mode == ORDER_MODE)
    {
        nextRow = (currentRow + 1) % ui->musicList->count();
    }
    else if(m_mode == RANDOM_MODE)
    {
        int cnt = 0;
        do{
            nextRow = rand() % ui->musicList->count();
            cnt++;
        }while(currentRow == nextRow && cnt <3);
    }
    else if(m_mode == CIRCLE_MODE)
    {
        nextRow = currentRow;
    }

    ui->musicList->setCurrentRow(nextRow);

    startPlayMusic();
}
//显示播放列表的动画
void MainWindow::showAnimation(QWidget *window)
{
    QPropertyAnimation animation(window,"pos");
    animation.setDuration(200);
    animation.setStartValue(QPoint(this->width(),0));
    animation.setEndValue(QPoint(this->width() - ui->musicList->width(),0));
    animation.start();
    QEventLoop loop;
    connect(&animation,&QPropertyAnimation::finished,&loop,&QEventLoop::quit);
    loop.exec();
}
//隐藏播放列表的动画
void MainWindow::hideAnimation(QWidget *window)
{
    QPropertyAnimation animation(window,"pos");
    animation.setDuration(200);
    animation.setStartValue(QPoint(this->width() - ui->musicList->width(),0));
    animation.setEndValue(QPoint(this->width(),0));
    animation.start();
    QEventLoop loop;
    connect(&animation,&QPropertyAnimation::finished,&loop,&QEventLoop::quit);
    loop.exec();
}
//处理音乐播放列表的出现和消失
void MainWindow::handleListSlot()
{
    if(m_isShowFlag == false)
    {
        ui->musicList->show();
        showAnimation(ui->musicList);
        m_isShowFlag = true;
    }
    else
    {
        hideAnimation(ui->musicList);
        ui->musicList->hide();
        m_isShowFlag = false;
    }
}
//加载音乐资源
void MainWindow::loadAppointMusicDir(const QString &filepath)
{
    QDir dir(filepath);
    if(dir.exists() == false)
    {
        QMessageBox::warning(this,"文件夹","文件夹打开失败");
        return;
    }
    QFileInfoList fileList = dir.entryInfoList(QDir::Files);

    for(auto element : fileList)
    {
        if(element.suffix() == "mp3")
        {
            ui->musicList->addItem(element.baseName());
        }
    }

    ui->musicList->setCurrentRow(0);
}
// 处理音量变化
void MainWindow::onVolumeChanged(int volume)
{
    // 设置音频输出音量（范围0.0-1.0）
    m_audioOutput->setVolume(volume / 100.0);
    
    // 如果音量大于0且处于静音状态，取消静音
    if (volume > 0 && m_isMuted) {
        m_isMuted = false;
        updateMuteButtonIcon();
    }
    // 如果音量设为0，设置为静音状态
    else if (volume == 0 && !m_isMuted) {
        m_isMuted = true;
        updateMuteButtonIcon();
    }

    ui->volumeLabel->setText(QString::number(volume) + "%");
}
// 处理静音按钮点击
void MainWindow::onMuteToggled()
{
    if (m_isMuted) {
        // 取消静音，恢复之前的音量
        m_isMuted = false;
        if (m_lastVolume > 0) {
            ui->volumeSlider->setValue(m_lastVolume);
        } else {
            ui->volumeSlider->setValue(50); // 默认值
        }
    } else {
        // 设置静音，保存当前音量
        m_isMuted = true;
        m_lastVolume = ui->volumeSlider->value();
        ui->volumeSlider->setValue(0);
    }
    updateMuteButtonIcon();
}
// 更新静音按钮图标
void MainWindow::updateMuteButtonIcon()
{
    if (m_isMuted) {
        setButtonStyle(ui->muteBtn, ":/res/mute.png");
    } else {
        setButtonStyle(ui->muteBtn, ":/res/volume.png");
    }
}

// 事件过滤器
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    // 检查是否是音量相关控件
    if (obj == ui->muteBtn || obj == ui->volumeSlider || obj == ui->volumeLabel) {
        // 如果鼠标进入
        if (event->type() == QEvent::Enter) {
            showVolumeControl();
            m_hideTimer->stop();  // 停止隐藏计时器
            return true;
        }
        // 如果鼠标离开
        else if (event->type() == QEvent::Leave) {
            // 启动隐藏计时器
            m_hideTimer->start();
            return true;
        }
    }
    
    // 默认处理
    return QMainWindow::eventFilter(obj, event);
}

// 显示音量控制
void MainWindow::showVolumeControl()
{
    ui->volumeSlider->show();
    ui->volumeLabel->show();
}

// 隐藏音量控制
void MainWindow::hideVolumeControl()
{
    // 只有当鼠标不在这些控件上时才隐藏
    if (!ui->muteBtn->underMouse() && 
        !ui->volumeSlider->underMouse() && 
        !ui->volumeLabel->underMouse()) {
        ui->volumeSlider->hide();
        ui->volumeLabel->hide();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_player;
    delete m_audioOutput;
    delete m_hideTimer;
}
