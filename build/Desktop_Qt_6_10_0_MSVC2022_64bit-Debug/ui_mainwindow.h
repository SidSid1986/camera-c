/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *frame;
    QGroupBox *groupBox;
    QLabel *labelImage;
    QCheckBox *checkBoxActivateDisplay;
    QLabel *label_10;
    QLabel *labelTTLEncoder;
    QLabel *labelHTLEncoder;
    QLabel *label_12;
    QLabel *label_9;
    QLabel *label_11;
    QLineEdit *lineEditGuiVersion;
    QLineEdit *lineEditVersion;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEditSerial2;
    QLineEdit *lineEditSerial1;
    QLineEdit *lineEditSerial3;
    QLabel *label_6;
    QGroupBox *groupBox_2;
    QLineEdit *lineEditTimeOut;
    QLabel *label_3;
    QLineEdit *lineEditIp;
    QLabel *label;
    QPushButton *pushButtonConnect;
    QLabel *label_2;
    QLineEdit *lineEditStatus;
    QPushButton *pushButtonResetPicCnt;
    QLineEdit *lineEditFrequency;
    QPushButton *pushButtonDLLFifoReset;
    QPushButton *pushButtonDisconnect;
    QPushButton *pushButtonSettings;
    QPushButton *pushButtonSaveProfiles;
    QLineEdit *lineEditNumberOfProfilesToSave;
    QLabel *label_13;
    QLineEdit *lineEditFiFo;
    QLineEdit *lineEditMeasureRate;
    QLabel *label_8;
    QGroupBox *groupBox_3;
    QPushButton *pushButtonGetPropertyValue;
    QLineEdit *lineEditPropertyName;
    QLabel *label_16;
    QLineEdit *lineEditCashTime;
    QLabel *label_5;
    QTextEdit *lineEditPropertyValue;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(928, 565);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        frame = new QFrame(centralWidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 931, 521));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        frame->setFont(font);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        groupBox = new QGroupBox(frame);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 0, 361, 521));
        groupBox->setFont(font);
        labelImage = new QLabel(groupBox);
        labelImage->setObjectName("labelImage");
        labelImage->setGeometry(QRect(10, 40, 341, 421));
        labelImage->setFont(font);
        labelImage->setFrameShape(QFrame::WinPanel);
        labelImage->setFrameShadow(QFrame::Sunken);
        labelImage->setScaledContents(false);
        labelImage->setAlignment(Qt::AlignCenter);
        checkBoxActivateDisplay = new QCheckBox(groupBox);
        checkBoxActivateDisplay->setObjectName("checkBoxActivateDisplay");
        checkBoxActivateDisplay->setGeometry(QRect(10, 10, 81, 31));
        checkBoxActivateDisplay->setFont(font);
        label_10 = new QLabel(groupBox);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(210, 480, 71, 31));
        label_10->setFont(font);
        labelTTLEncoder = new QLabel(groupBox);
        labelTTLEncoder->setObjectName("labelTTLEncoder");
        labelTTLEncoder->setGeometry(QRect(280, 480, 71, 31));
        labelTTLEncoder->setFont(font);
        labelTTLEncoder->setFrameShape(QFrame::WinPanel);
        labelTTLEncoder->setFrameShadow(QFrame::Sunken);
        labelHTLEncoder = new QLabel(groupBox);
        labelHTLEncoder->setObjectName("labelHTLEncoder");
        labelHTLEncoder->setGeometry(QRect(90, 480, 71, 31));
        labelHTLEncoder->setFont(font);
        labelHTLEncoder->setFrameShape(QFrame::WinPanel);
        labelHTLEncoder->setFrameShadow(QFrame::Sunken);
        label_12 = new QLabel(groupBox);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 480, 71, 31));
        label_12->setFont(font);
        label_9 = new QLabel(frame);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(380, 0, 61, 16));
        label_9->setFont(font);
        label_11 = new QLabel(frame);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(690, 0, 61, 21));
        label_11->setFont(font);
        lineEditGuiVersion = new QLineEdit(frame);
        lineEditGuiVersion->setObjectName("lineEditGuiVersion");
        lineEditGuiVersion->setGeometry(QRect(690, 20, 221, 25));
        lineEditGuiVersion->setFont(font);
        lineEditGuiVersion->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        lineEditVersion = new QLineEdit(frame);
        lineEditVersion->setObjectName("lineEditVersion");
        lineEditVersion->setGeometry(QRect(380, 20, 291, 25));
        lineEditVersion->setFont(font);
        lineEditVersion->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        lineEditVersion->setReadOnly(true);
        gridLayoutWidget = new QWidget(frame);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(380, 60, 531, 120));
        gridLayoutWidget->setFont(font);
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEditSerial2 = new QLineEdit(gridLayoutWidget);
        lineEditSerial2->setObjectName("lineEditSerial2");
        lineEditSerial2->setMinimumSize(QSize(0, 25));
        lineEditSerial2->setFont(font);
        lineEditSerial2->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));

        gridLayout->addWidget(lineEditSerial2, 5, 0, 1, 1);

        lineEditSerial1 = new QLineEdit(gridLayoutWidget);
        lineEditSerial1->setObjectName("lineEditSerial1");
        lineEditSerial1->setMinimumSize(QSize(0, 25));
        lineEditSerial1->setFont(font);
        lineEditSerial1->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        lineEditSerial1->setReadOnly(true);

        gridLayout->addWidget(lineEditSerial1, 4, 0, 1, 1);

        lineEditSerial3 = new QLineEdit(gridLayoutWidget);
        lineEditSerial3->setObjectName("lineEditSerial3");
        lineEditSerial3->setMinimumSize(QSize(0, 25));
        lineEditSerial3->setFont(font);
        lineEditSerial3->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));

        gridLayout->addWidget(lineEditSerial3, 6, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName("label_6");
        label_6->setMinimumSize(QSize(0, 25));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        groupBox_2 = new QGroupBox(frame);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(380, 190, 531, 221));
        groupBox_2->setFont(font);
        lineEditTimeOut = new QLineEdit(groupBox_2);
        lineEditTimeOut->setObjectName("lineEditTimeOut");
        lineEditTimeOut->setGeometry(QRect(200, 20, 41, 31));
        lineEditTimeOut->setFont(font);
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(130, 20, 61, 31));
        label_3->setFont(font);
        lineEditIp = new QLineEdit(groupBox_2);
        lineEditIp->setObjectName("lineEditIp");
        lineEditIp->setGeometry(QRect(30, 20, 91, 31));
        lineEditIp->setFont(font);
        label = new QLabel(groupBox_2);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 31, 31));
        label->setFont(font);
        pushButtonConnect = new QPushButton(groupBox_2);
        pushButtonConnect->setObjectName("pushButtonConnect");
        pushButtonConnect->setGeometry(QRect(30, 70, 101, 31));
        pushButtonConnect->setFont(font);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(250, 20, 21, 31));
        label_2->setFont(font);
        lineEditStatus = new QLineEdit(groupBox_2);
        lineEditStatus->setObjectName("lineEditStatus");
        lineEditStatus->setGeometry(QRect(280, 20, 81, 31));
        lineEditStatus->setFont(font);
        lineEditStatus->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        lineEditStatus->setReadOnly(true);
        pushButtonResetPicCnt = new QPushButton(groupBox_2);
        pushButtonResetPicCnt->setObjectName("pushButtonResetPicCnt");
        pushButtonResetPicCnt->setGeometry(QRect(430, 70, 91, 31));
        pushButtonResetPicCnt->setFont(font);
        lineEditFrequency = new QLineEdit(groupBox_2);
        lineEditFrequency->setObjectName("lineEditFrequency");
        lineEditFrequency->setGeometry(QRect(140, 70, 271, 31));
        lineEditFrequency->setFont(font);
        lineEditFrequency->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        lineEditFrequency->setReadOnly(true);
        pushButtonDLLFifoReset = new QPushButton(groupBox_2);
        pushButtonDLLFifoReset->setObjectName("pushButtonDLLFifoReset");
        pushButtonDLLFifoReset->setGeometry(QRect(430, 120, 91, 31));
        pushButtonDLLFifoReset->setFont(font);
        pushButtonDisconnect = new QPushButton(groupBox_2);
        pushButtonDisconnect->setObjectName("pushButtonDisconnect");
        pushButtonDisconnect->setGeometry(QRect(30, 120, 101, 31));
        pushButtonDisconnect->setFont(font);
        pushButtonSettings = new QPushButton(groupBox_2);
        pushButtonSettings->setObjectName("pushButtonSettings");
        pushButtonSettings->setGeometry(QRect(30, 170, 101, 31));
        pushButtonSettings->setFont(font);
        pushButtonSaveProfiles = new QPushButton(groupBox_2);
        pushButtonSaveProfiles->setObjectName("pushButtonSaveProfiles");
        pushButtonSaveProfiles->setGeometry(QRect(400, 170, 121, 31));
        pushButtonSaveProfiles->setFont(font);
        lineEditNumberOfProfilesToSave = new QLineEdit(groupBox_2);
        lineEditNumberOfProfilesToSave->setObjectName("lineEditNumberOfProfilesToSave");
        lineEditNumberOfProfilesToSave->setGeometry(QRect(340, 170, 51, 31));
        lineEditNumberOfProfilesToSave->setFont(font);
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(180, 170, 151, 31));
        label_13->setFont(font);
        lineEditFiFo = new QLineEdit(groupBox_2);
        lineEditFiFo->setObjectName("lineEditFiFo");
        lineEditFiFo->setGeometry(QRect(140, 120, 271, 31));
        lineEditFiFo->setFont(font);
        lineEditFiFo->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        lineEditFiFo->setReadOnly(true);
        lineEditMeasureRate = new QLineEdit(groupBox_2);
        lineEditMeasureRate->setObjectName("lineEditMeasureRate");
        lineEditMeasureRate->setGeometry(QRect(470, 20, 51, 31));
        lineEditMeasureRate->setFont(font);
        lineEditMeasureRate->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        lineEditMeasureRate->setReadOnly(true);
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(370, 20, 91, 31));
        label_8->setFont(font);
        groupBox_3 = new QGroupBox(frame);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(380, 420, 531, 101));
        groupBox_3->setFont(font);
        pushButtonGetPropertyValue = new QPushButton(groupBox_3);
        pushButtonGetPropertyValue->setObjectName("pushButtonGetPropertyValue");
        pushButtonGetPropertyValue->setGeometry(QRect(240, 20, 75, 31));
        pushButtonGetPropertyValue->setFont(font);
        lineEditPropertyName = new QLineEdit(groupBox_3);
        lineEditPropertyName->setObjectName("lineEditPropertyName");
        lineEditPropertyName->setGeometry(QRect(110, 20, 121, 31));
        lineEditPropertyName->setFont(font);
        lineEditPropertyName->setReadOnly(false);
        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(10, 60, 91, 31));
        label_16->setFont(font);
        lineEditCashTime = new QLineEdit(groupBox_3);
        lineEditCashTime->setObjectName("lineEditCashTime");
        lineEditCashTime->setGeometry(QRect(110, 60, 61, 31));
        lineEditCashTime->setFont(font);
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 20, 91, 31));
        label_5->setFont(font);
        lineEditPropertyValue = new QTextEdit(groupBox_3);
        lineEditPropertyValue->setObjectName("lineEditPropertyValue");
        lineEditPropertyValue->setEnabled(true);
        lineEditPropertyValue->setGeometry(QRect(323, 20, 201, 71));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 928, 21));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "EthernetScanner DLL Test", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Profile (not scaled)", nullptr));
        labelImage->setText(QCoreApplication::translate("MainWindow", "Scanner Image", nullptr));
        checkBoxActivateDisplay->setText(QCoreApplication::translate("MainWindow", "View Disable", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "TTL Encoder", nullptr));
        labelTTLEncoder->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        labelHTLEncoder->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "HTL Encoder", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Dll-Version:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "GUI-Version:", nullptr));
        lineEditVersion->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        lineEditSerial2->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        lineEditSerial1->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        lineEditSerial3->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Sensor Info", nullptr));
        groupBox_2->setTitle(QString());
        lineEditTimeOut->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Rec. timeout:", nullptr));
        lineEditIp->setText(QCoreApplication::translate("MainWindow", "192.168.100.1", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "IP:", nullptr));
        pushButtonConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "ms", nullptr));
        lineEditStatus->setText(QCoreApplication::translate("MainWindow", "Disconnected", nullptr));
        pushButtonResetPicCnt->setText(QCoreApplication::translate("MainWindow", "Reset Statistic", nullptr));
        lineEditFrequency->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        pushButtonDLLFifoReset->setText(QCoreApplication::translate("MainWindow", "DLL FiFo Reset", nullptr));
        pushButtonDisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        pushButtonSettings->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        pushButtonSaveProfiles->setText(QCoreApplication::translate("MainWindow", "Save Profile(s)", nullptr));
        lineEditNumberOfProfilesToSave->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Number of profiles to save:", nullptr));
        lineEditFiFo->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        lineEditMeasureRate->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Measurement rate", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Read data", nullptr));
        pushButtonGetPropertyValue->setText(QCoreApplication::translate("MainWindow", "Get value", nullptr));
        lineEditPropertyName->setText(QCoreApplication::translate("MainWindow", "GetTemperature", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Cash time (ms)", nullptr));
        lineEditCashTime->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Property name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
