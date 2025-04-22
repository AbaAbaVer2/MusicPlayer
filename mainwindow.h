#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

enum PLAYMODE
{
    ORDER_MODE,
    RANDOM_MODE,
    CIRCLE_MODE
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void handlePlaySlot();
    void handleModelSlot();
    void handleNextSlot();
    void handlePrevSlot();
    void handleListSlot();
    void handlePositionSlot(int position);
    void handleDurationSlot(int duration);
    void setPosition(int position);
    void onVolumeChanged(int volume);
    void onMuteToggled();

private:
    void setButtonStyle(QPushButton *button, const QString &filename);
    void initButtons();
    void setBackground(const QString &filename);
    void loadAppointMusicDir(const QString &filepath);
    void startPlayMusic();
    QString m_musicDir;
    void showAnimation(QWidget *window);
    void hideAnimation(QWidget *window);
    void updateMuteButtonIcon();
    void showVolumeControl();
    void hideVolumeControl();
private:
    Ui::MainWindow *ui;
    QMediaPlayer *m_player;
    QAudioOutput *m_audioOutput;
    bool m_isPlaying;
    PLAYMODE m_mode;
    bool m_isShowFlag;//列表是否存在的状态
    QString formatTime(qint64 timeInMs);
    bool m_isMuted;
    int m_lastVolume;
    bool eventFilter(QObject *obj, QEvent *event) override;
    QTimer *m_hideTimer;
};
#endif // MAINWINDOW_H
