/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *listBtn;
    QPushButton *prevBtn;
    QPushButton *playBtn;
    QPushButton *nextBtn;
    QPushButton *modelBtn;
    QListWidget *musicList;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *currentTime;
    QSlider *progressBar;
    QLabel *totalTime;
    QSlider *volumeSlider;
    QPushButton *muteBtn;
    QWidget *widget_2;
    QLabel *volumeLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1020, 720);
        MainWindow->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    border: none;\n"
"    height: 6px;\n"
"    border-radius: 3px;\n"
"    background-color: #f0f0f0;  /* \346\233\264\346\265\205\347\232\204\347\201\260\350\211\262\350\203\214\346\231\257 */\n"
"}\n"
"    \n"
"QSlider::handle:horizontal {\n"
"    background-color: #ffffff;  /* \347\231\275\350\211\262\350\277\233\345\272\246\347\220\203 */\n"
"    border: 1px solid #dddddd;  /* \346\233\264\346\265\205\347\232\204\350\276\271\346\241\206 */\n"
"    width: 14px;\n"
"    height: 14px;\n"
"    margin: -4px 0;\n"
"    border-radius: 7px;\n"
"}\n"
"    \n"
"QSlider::sub-page:horizontal {\n"
"    background-color: #7986cb;  /* \346\233\264\346\265\205\347\232\204\347\264\253\350\223\235\350\211\262\345\267\262\346\222\255\346\224\276\351\203\250\345\210\206 */\n"
"    border: none;\n"
"    height: 6px;\n"
"    border-radius: 3px;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(140, 600, 441, 61));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        listBtn = new QPushButton(widget);
        listBtn->setObjectName("listBtn");

        horizontalLayout->addWidget(listBtn);

        prevBtn = new QPushButton(widget);
        prevBtn->setObjectName("prevBtn");

        horizontalLayout->addWidget(prevBtn);

        playBtn = new QPushButton(widget);
        playBtn->setObjectName("playBtn");

        horizontalLayout->addWidget(playBtn);

        nextBtn = new QPushButton(widget);
        nextBtn->setObjectName("nextBtn");

        horizontalLayout->addWidget(nextBtn);

        modelBtn = new QPushButton(widget);
        modelBtn->setObjectName("modelBtn");

        horizontalLayout->addWidget(modelBtn);

        musicList = new QListWidget(centralwidget);
        musicList->setObjectName("musicList");
        musicList->setGeometry(QRect(750, 10, 256, 521));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(160, 570, 411, 24));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        currentTime = new QLabel(layoutWidget);
        currentTime->setObjectName("currentTime");

        horizontalLayout_2->addWidget(currentTime);

        progressBar = new QSlider(layoutWidget);
        progressBar->setObjectName("progressBar");
        progressBar->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    border: none;\n"
"    height: 10px;\n"
"    border-radius: 5px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #1c1c1c, stop:1 #2f2f2f);\n"
"}\n"
"    \n"
"QSlider::handle:horizontal {\n"
"    background: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 #ffffff, stop:1 #7986cb);\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    margin: -3px 0;\n"
"    border-radius: 8px;\n"
"}\n"
"    \n"
"QSlider::sub-page:horizontal {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #5e35b1, stop:1 #7986cb);\n"
"    border: none;\n"
"    height: 10px;\n"
"    border-radius: 5px;\n"
"}"));
        progressBar->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(progressBar);

        totalTime = new QLabel(layoutWidget);
        totalTime->setObjectName("totalTime");

        horizontalLayout_2->addWidget(totalTime);

        volumeSlider = new QSlider(centralwidget);
        volumeSlider->setObjectName("volumeSlider");
        volumeSlider->setGeometry(QRect(640, 430, 16, 160));
        volumeSlider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"            height: 5px;\n"
"            background: #e0e0e0;\n"
"            border-radius: 2px;\n"
"        }\n"
"        QSlider::handle:horizontal {\n"
"            background: #ffffff;\n"
"            border: 1px solid #cccccc;\n"
"            width: 12px;\n"
"            height: 12px;\n"
"            margin: -4px 0;\n"
"            border-radius: 6px;\n"
"        }\n"
"        QSlider::sub-page:horizontal {\n"
"            background: #5e35b1;\n"
"            border-radius: 2px;\n"
"        }"));
        volumeSlider->setOrientation(Qt::Vertical);
        muteBtn = new QPushButton(centralwidget);
        muteBtn->setObjectName("muteBtn");
        muteBtn->setGeometry(QRect(620, 610, 56, 18));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(530, 319, 71, 191));
        volumeLabel = new QLabel(centralwidget);
        volumeLabel->setObjectName("volumeLabel");
        volumeLabel->setGeometry(QRect(630, 590, 40, 12));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1020, 18));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        listBtn->setText(QString());
        prevBtn->setText(QString());
        playBtn->setText(QString());
        nextBtn->setText(QString());
        modelBtn->setText(QString());
        currentTime->setText(QCoreApplication::translate("MainWindow", "00\357\274\23200", nullptr));
        totalTime->setText(QCoreApplication::translate("MainWindow", "03\357\274\23221", nullptr));
        muteBtn->setText(QString());
        volumeLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
