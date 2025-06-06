/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
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
    QLabel *label_8;
    QLineEdit *lineEditMeasureRate;
    QLabel *label_14;
    QLabel *label_15;
    QPushButton *pushButtonSaveExcel;
    QPushButton *pushButtonScreenshot;
    QGroupBox *groupBox_3;
    QPushButton *pushButtonGetPropertyValue;
    QLabel *label_16;
    QLineEdit *lineEditCashTime;
    QLabel *label_5;
    QTextEdit *lineEditPropertyValue;
    QComboBox *comboBoxPropertyName;
    QPushButton *pushButtonSetMeasuringRate;
    QLineEdit *lineEditHzNumber;
    QLabel *label_4;
    QPushButton *pushButtonReboot;
    QGroupBox *groupBox_4;
    QLabel *label_6;
    QLineEdit *lineEditSerial1;
    QLineEdit *lineEditSerial2;
    QLineEdit *lineEditSerial3;
    QPushButton *pushButtonSetMode;
    QComboBox *comboBoxMode;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1049, 581);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setStyleSheet(QString::fromUtf8(" /* ===== \345\205\250\345\261\200\346\240\267\345\274\217 ===== */\n"
"QMainWindow {\n"
"    background-color: #F5F8FA;\n"
"    font-family: \"Segoe UI\", \"Microsoft YaHei\";\n"
"}\n"
"\n"
"/* ===== \345\267\246\344\276\247\345\233\276\345\203\217\345\214\272\345\237\237 ===== */\n"
"QWidget#scannerImageContainer {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, \n"
"                                stop:0 #2D3748, stop:1 #4A5568);\n"
"    border-radius: 8px;\n"
"  \n"
"}\n"
"\n"
"/* ===== \345\217\263\344\276\247\346\216\247\345\210\266\351\235\242\346\235\277 ===== */\n"
"QWidget#rightPanel {\n"
"    background: white;\n"
"    border-left: 1px solid #E2E8F0;\n"
"   \n"
"}\n"
"\n"
"/* ===== \347\211\210\346\234\254\344\277\241\346\201\257\346\240\207\347\255\276 ===== */\n"
"QLabel#versionLabel {\n"
"    color: #718096;\n"
"    font-size: 11px;\n"
"    font-style: italic;\n"
"}\n"
"\n"
"/* ===== \344\274\240\346\204\237\345\231\250\344\277\241\346\201\257\345\215\241\347\211\207 ===== */\n"
"QGro"
                        "upBox#sensorInfoBox {\n"
"    border: 1px solid #E2E8F0;\n"
"    border-radius: 6px;\n"
" \n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    color: #3182CE;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* ===== \346\214\211\351\222\256\346\240\267\345\274\217 ===== */\n"
"/* \346\231\256\351\200\232\346\214\211\351\222\256 */\n"
"QPushButton {\n"
"    background-color: #3182CE;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"	 padding:5px 10px;\n"
"}\n"
"QPushButton:hover { background-color: #2B6CB0; }\n"
"QPushButton:pressed { background-color: #2C5282; }\n"
"\n"
"/* \345\215\261\351\231\251\346\223\215\344\275\234\346\214\211\351\222\256 */\n"
"QPushButton#resetButton, \n"
"QPushButton#disconnectButton {\n"
"    background-color: #E53E3E;\n"
"}\n"
"QPushButton#resetButton:hover, \n"
"QPushButton#disconnectButton:hover {\n"
"    background-color: #C53030;\n"
"}\n"
"\n"
"/* ===== \350\276\223\345\205\245\346\216\247\344\273\266 ===== */\n"
"QLineEdit  {\n"
"    bo"
                        "rder: 1px solid #CBD5E0;\n"
"    border-radius: 3px;\n"
"    \n"
"    \n"
"}\n"
" \n"
"\n"
"/* ===== \346\225\260\346\215\256\350\257\273\345\217\226\345\214\272\345\237\237 ===== */\n"
"QGroupBox#readDataBox {\n"
"    border: 1px solid #E2E8F0;\n"
"    border-radius: 6px;\n"
"   \n"
"}\n"
"QGroupBox#readDataBox::title {\n"
"    color: #4A5568;\n"
"    font-weight: bold;\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 1041, 571));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        frame->setFont(font);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 361, 521));
        groupBox->setFont(font);
        labelImage = new QLabel(groupBox);
        labelImage->setObjectName(QString::fromUtf8("labelImage"));
        labelImage->setGeometry(QRect(10, 30, 341, 421));
        labelImage->setFont(font);
        labelImage->setFrameShape(QFrame::WinPanel);
        labelImage->setFrameShadow(QFrame::Sunken);
        labelImage->setScaledContents(false);
        labelImage->setAlignment(Qt::AlignCenter);
        checkBoxActivateDisplay = new QCheckBox(groupBox);
        checkBoxActivateDisplay->setObjectName(QString::fromUtf8("checkBoxActivateDisplay"));
        checkBoxActivateDisplay->setGeometry(QRect(10, 0, 101, 31));
        checkBoxActivateDisplay->setFont(font);
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(210, 480, 71, 31));
        label_10->setFont(font);
        labelTTLEncoder = new QLabel(groupBox);
        labelTTLEncoder->setObjectName(QString::fromUtf8("labelTTLEncoder"));
        labelTTLEncoder->setGeometry(QRect(280, 480, 71, 31));
        labelTTLEncoder->setFont(font);
        labelTTLEncoder->setFrameShape(QFrame::WinPanel);
        labelTTLEncoder->setFrameShadow(QFrame::Sunken);
        labelHTLEncoder = new QLabel(groupBox);
        labelHTLEncoder->setObjectName(QString::fromUtf8("labelHTLEncoder"));
        labelHTLEncoder->setGeometry(QRect(90, 480, 71, 31));
        labelHTLEncoder->setFont(font);
        labelHTLEncoder->setFrameShape(QFrame::WinPanel);
        labelHTLEncoder->setFrameShadow(QFrame::Sunken);
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 480, 71, 31));
        label_12->setFont(font);
        label_9 = new QLabel(frame);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(380, 0, 61, 16));
        label_9->setFont(font);
        label_11 = new QLabel(frame);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(530, 0, 71, 21));
        label_11->setFont(font);
        lineEditGuiVersion = new QLineEdit(frame);
        lineEditGuiVersion->setObjectName(QString::fromUtf8("lineEditGuiVersion"));
        lineEditGuiVersion->setGeometry(QRect(530, 20, 161, 36));
        lineEditGuiVersion->setFont(font);
        lineEditGuiVersion->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        lineEditVersion = new QLineEdit(frame);
        lineEditVersion->setObjectName(QString::fromUtf8("lineEditVersion"));
        lineEditVersion->setGeometry(QRect(380, 20, 141, 36));
        lineEditVersion->setFont(font);
        lineEditVersion->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        lineEditVersion->setReadOnly(true);
        groupBox_2 = new QGroupBox(frame);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(380, 213, 631, 221));
        groupBox_2->setFont(font);
        lineEditTimeOut = new QLineEdit(groupBox_2);
        lineEditTimeOut->setObjectName(QString::fromUtf8("lineEditTimeOut"));
        lineEditTimeOut->setGeometry(QRect(230, 20, 41, 36));
        lineEditTimeOut->setFont(font);
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(150, 20, 71, 31));
        label_3->setFont(font);
        lineEditIp = new QLineEdit(groupBox_2);
        lineEditIp->setObjectName(QString::fromUtf8("lineEditIp"));
        lineEditIp->setGeometry(QRect(30, 20, 91, 36));
        lineEditIp->setFont(font);
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 31, 31));
        label->setFont(font);
        pushButtonConnect = new QPushButton(groupBox_2);
        pushButtonConnect->setObjectName(QString::fromUtf8("pushButtonConnect"));
        pushButtonConnect->setGeometry(QRect(30, 70, 104, 31));
        pushButtonConnect->setFont(font);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(280, 20, 21, 31));
        label_2->setFont(font);
        lineEditStatus = new QLineEdit(groupBox_2);
        lineEditStatus->setObjectName(QString::fromUtf8("lineEditStatus"));
        lineEditStatus->setGeometry(QRect(380, 20, 91, 36));
        lineEditStatus->setFont(font);
        lineEditStatus->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        lineEditStatus->setReadOnly(true);
        pushButtonResetPicCnt = new QPushButton(groupBox_2);
        pushButtonResetPicCnt->setObjectName(QString::fromUtf8("pushButtonResetPicCnt"));
        pushButtonResetPicCnt->setGeometry(QRect(510, 70, 111, 31));
        pushButtonResetPicCnt->setFont(font);
        lineEditFrequency = new QLineEdit(groupBox_2);
        lineEditFrequency->setObjectName(QString::fromUtf8("lineEditFrequency"));
        lineEditFrequency->setGeometry(QRect(230, 70, 271, 36));
        lineEditFrequency->setFont(font);
        lineEditFrequency->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        lineEditFrequency->setReadOnly(true);
        pushButtonDLLFifoReset = new QPushButton(groupBox_2);
        pushButtonDLLFifoReset->setObjectName(QString::fromUtf8("pushButtonDLLFifoReset"));
        pushButtonDLLFifoReset->setGeometry(QRect(510, 120, 111, 31));
        pushButtonDLLFifoReset->setFont(font);
        pushButtonDisconnect = new QPushButton(groupBox_2);
        pushButtonDisconnect->setObjectName(QString::fromUtf8("pushButtonDisconnect"));
        pushButtonDisconnect->setGeometry(QRect(30, 120, 104, 31));
        pushButtonDisconnect->setFont(font);
        pushButtonSettings = new QPushButton(groupBox_2);
        pushButtonSettings->setObjectName(QString::fromUtf8("pushButtonSettings"));
        pushButtonSettings->setGeometry(QRect(30, 170, 104, 31));
        pushButtonSettings->setFont(font);
        pushButtonSaveProfiles = new QPushButton(groupBox_2);
        pushButtonSaveProfiles->setObjectName(QString::fromUtf8("pushButtonSaveProfiles"));
        pushButtonSaveProfiles->setGeometry(QRect(292, 171, 91, 31));
        pushButtonSaveProfiles->setFont(font);
        lineEditNumberOfProfilesToSave = new QLineEdit(groupBox_2);
        lineEditNumberOfProfilesToSave->setObjectName(QString::fromUtf8("lineEditNumberOfProfilesToSave"));
        lineEditNumberOfProfilesToSave->setGeometry(QRect(230, 170, 51, 36));
        lineEditNumberOfProfilesToSave->setFont(font);
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(150, 170, 81, 31));
        label_13->setFont(font);
        lineEditFiFo = new QLineEdit(groupBox_2);
        lineEditFiFo->setObjectName(QString::fromUtf8("lineEditFiFo"));
        lineEditFiFo->setGeometry(QRect(230, 120, 271, 36));
        lineEditFiFo->setFont(font);
        lineEditFiFo->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        lineEditFiFo->setReadOnly(true);
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(320, 20, 51, 31));
        label_8->setFont(font);
        lineEditMeasureRate = new QLineEdit(groupBox_2);
        lineEditMeasureRate->setObjectName(QString::fromUtf8("lineEditMeasureRate"));
        lineEditMeasureRate->setGeometry(QRect(480, 20, 61, 36));
        lineEditMeasureRate->setFont(font);
        lineEditMeasureRate->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        lineEditMeasureRate->setReadOnly(true);
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(170, 70, 51, 31));
        label_14->setFont(font);
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(180, 120, 31, 31));
        label_15->setFont(font);
        pushButtonSaveExcel = new QPushButton(groupBox_2);
        pushButtonSaveExcel->setObjectName(QString::fromUtf8("pushButtonSaveExcel"));
        pushButtonSaveExcel->setGeometry(QRect(390, 171, 81, 31));
        pushButtonSaveExcel->setFont(font);
        pushButtonScreenshot = new QPushButton(groupBox_2);
        pushButtonScreenshot->setObjectName(QString::fromUtf8("pushButtonScreenshot"));
        pushButtonScreenshot->setGeometry(QRect(478, 171, 81, 31));
        pushButtonScreenshot->setFont(font);
        groupBox_3 = new QGroupBox(frame);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(380, 438, 631, 101));
        groupBox_3->setFont(font);
        pushButtonGetPropertyValue = new QPushButton(groupBox_3);
        pushButtonGetPropertyValue->setObjectName(QString::fromUtf8("pushButtonGetPropertyValue"));
        pushButtonGetPropertyValue->setGeometry(QRect(240, 21, 71, 31));
        pushButtonGetPropertyValue->setFont(font);
        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(20, 60, 81, 31));
        label_16->setFont(font);
        lineEditCashTime = new QLineEdit(groupBox_3);
        lineEditCashTime->setObjectName(QString::fromUtf8("lineEditCashTime"));
        lineEditCashTime->setGeometry(QRect(110, 60, 61, 36));
        lineEditCashTime->setFont(font);
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 20, 51, 31));
        label_5->setFont(font);
        lineEditPropertyValue = new QTextEdit(groupBox_3);
        lineEditPropertyValue->setObjectName(QString::fromUtf8("lineEditPropertyValue"));
        lineEditPropertyValue->setEnabled(true);
        lineEditPropertyValue->setGeometry(QRect(323, 20, 291, 71));
        comboBoxPropertyName = new QComboBox(groupBox_3);
        comboBoxPropertyName->setObjectName(QString::fromUtf8("comboBoxPropertyName"));
        comboBoxPropertyName->setGeometry(QRect(110, 20, 121, 31));
        comboBoxPropertyName->setStyleSheet(QString::fromUtf8(""));
        pushButtonSetMeasuringRate = new QPushButton(groupBox_3);
        pushButtonSetMeasuringRate->setObjectName(QString::fromUtf8("pushButtonSetMeasuringRate"));
        pushButtonSetMeasuringRate->setGeometry(QRect(175, 62, 71, 31));
        pushButtonSetMeasuringRate->setFont(font);
        lineEditHzNumber = new QLineEdit(groupBox_3);
        lineEditHzNumber->setObjectName(QString::fromUtf8("lineEditHzNumber"));
        lineEditHzNumber->setGeometry(QRect(250, 60, 41, 36));
        lineEditHzNumber->setFont(font);
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(292, 67, 21, 21));
        label_4->setFont(font);
        pushButtonReboot = new QPushButton(frame);
        pushButtonReboot->setObjectName(QString::fromUtf8("pushButtonReboot"));
        pushButtonReboot->setGeometry(QRect(970, 14, 40, 40));
        pushButtonReboot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #ff6666,   /* \351\241\266\351\203\250\344\272\256\347\272\242 */\n"
"        stop:0.5 #ff0000, /* \344\270\255\351\227\264\347\272\242 */\n"
"        stop:1 #b20000    /* \345\272\225\351\203\250\346\232\227\347\272\242 */\n"
"    );\n"
"    color: white;\n"
"    font-weight: bold;\n"
" border-radius: 18px;\n"
"      min-width: 36px;\n"
"    min-height: 36px;\n"
"    max-width: 36px;\n"
"    max-height: 36px;\n"
"   \n"
"    border: 2px solid #bb2222; /* \346\267\261\350\211\262\351\253\230\344\272\256\350\276\271\346\241\206 */\n"
"    padding: 0 0px;\n"
"\n"
"    /* \347\253\213\344\275\223\345\244\226\351\230\264\345\275\261\357\274\214\346\233\264\345\212\240\346\230\216\346\230\276\347\232\204\346\265\256\350\265\267\346\204\237 */\n"
"    box-shadow:\n"
"        0 6px 20px 2px rgba(0,0,0,0.32),  /* \345\274\272\347\203\210\345\244\226\351\230\264\345\275\261 */\n"
"        0 2px 0 #fff inset, "
                        "               /* \351\241\266\351\203\250\345\206\205\351\253\230\345\205\211 */\n"
"        0 -2px 10px 0 rgba(0,0,0,0.15) inset; /* \345\272\225\351\203\250\345\206\205\346\232\227 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\357\274\232\351\242\234\350\211\262\346\233\264\344\272\256\357\274\214\351\230\264\345\275\261\346\233\264\345\244\247 */\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #ff8888,\n"
"        stop:0.5 #ff2222,\n"
"        stop:1 #d00000\n"
"    );\n"
"    box-shadow:\n"
"        0 10px 28px 4px rgba(0,0,0,0.38),\n"
"        0 3px 0 #fff inset,\n"
"        0 -2.5px 12px 0 rgba(0,0,0,0.20) inset;\n"
"    border: 2px solid #d83333;\n"
"}\n"
"\n"
"/* \346\214\211\344\270\213\357\274\232\351\242\234\350\211\262\345\217\230\346\267\261\357\274\214\345\206\205\345\244\226\351\230\264\345\275\261\346\224\266\346\225\233\357\274\214\345\276\256\345\207\271\351\231\267\346\204\237 */\n"
"QPushButton:pressed {\n"
"    back"
                        "ground-color: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #cc0000,\n"
"        stop:1 #880000\n"
"    );\n"
"    box-shadow:\n"
"        0 2px 7px 2px rgba(0,0,0,0.18),\n"
"        0 0.5px 0 #fff inset,\n"
"        0 -3px 16px 0 rgba(0,0,0,0.25) inset;\n"
"    border: 2px solid #990a0a;\n"
"}"));
        groupBox_4 = new QGroupBox(frame);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(380, 60, 631, 151));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(4, 12, 421, 25));
        label_6->setMinimumSize(QSize(0, 25));
        label_6->setFont(font);
        lineEditSerial1 = new QLineEdit(groupBox_4);
        lineEditSerial1->setObjectName(QString::fromUtf8("lineEditSerial1"));
        lineEditSerial1->setGeometry(QRect(5, 38, 621, 31));
        lineEditSerial1->setMinimumSize(QSize(0, 0));
        lineEditSerial1->setFont(font);
        lineEditSerial1->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        lineEditSerial1->setReadOnly(true);
        lineEditSerial2 = new QLineEdit(groupBox_4);
        lineEditSerial2->setObjectName(QString::fromUtf8("lineEditSerial2"));
        lineEditSerial2->setGeometry(QRect(5, 74, 621, 31));
        lineEditSerial2->setMinimumSize(QSize(0, 0));
        lineEditSerial2->setFont(font);
        lineEditSerial2->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        lineEditSerial3 = new QLineEdit(groupBox_4);
        lineEditSerial3->setObjectName(QString::fromUtf8("lineEditSerial3"));
        lineEditSerial3->setGeometry(QRect(5, 110, 621, 31));
        lineEditSerial3->setMinimumSize(QSize(0, 0));
        lineEditSerial3->setFont(font);
        lineEditSerial3->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        pushButtonSetMode = new QPushButton(frame);
        pushButtonSetMode->setObjectName(QString::fromUtf8("pushButtonSetMode"));
        pushButtonSetMode->setGeometry(QRect(701, 22, 104, 31));
        pushButtonSetMode->setFont(font);
        comboBoxMode = new QComboBox(frame);
        comboBoxMode->setObjectName(QString::fromUtf8("comboBoxMode"));
        comboBoxMode->setGeometry(QRect(809, 22, 141, 31));
        comboBoxMode->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1049, 23));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "EthernetScanner DLL Test", nullptr));
        groupBox->setTitle(QString());
        labelImage->setText(QApplication::translate("MainWindow", "Scanner Image", nullptr));
        checkBoxActivateDisplay->setText(QApplication::translate("MainWindow", "View Disable", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "TTL Encoder", nullptr));
        labelTTLEncoder->setText(QApplication::translate("MainWindow", "...", nullptr));
        labelHTLEncoder->setText(QApplication::translate("MainWindow", "...", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "HTL Encoder", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Dll-Version:", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "GUI-Version:", nullptr));
        lineEditVersion->setText(QApplication::translate("MainWindow", "...", nullptr));
        groupBox_2->setTitle(QString());
        lineEditTimeOut->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Rec. timeout:", nullptr));
        lineEditIp->setText(QApplication::translate("MainWindow", "192.168.3.240", nullptr));
        label->setText(QApplication::translate("MainWindow", "IP:", nullptr));
        pushButtonConnect->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "ms", nullptr));
        lineEditStatus->setText(QApplication::translate("MainWindow", "\345\267\262\346\226\255\345\274\200", nullptr));
        pushButtonResetPicCnt->setText(QApplication::translate("MainWindow", "\351\207\215\347\275\256\347\273\237\350\256\241", nullptr));
        lineEditFrequency->setText(QApplication::translate("MainWindow", "...", nullptr));
        pushButtonDLLFifoReset->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\347\274\223\345\255\230", nullptr));
        pushButtonDisconnect->setText(QApplication::translate("MainWindow", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
        pushButtonSettings->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        pushButtonSaveProfiles->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230txt", nullptr));
        lineEditNumberOfProfilesToSave->setText(QApplication::translate("MainWindow", "1", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\347\232\204\346\226\207\344\273\266\346\225\260", nullptr));
        lineEditFiFo->setText(QApplication::translate("MainWindow", "...", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245\347\212\266\346\200\201", nullptr));
        lineEditMeasureRate->setText(QApplication::translate("MainWindow", "...", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "\346\265\213\351\207\217\351\242\221\347\216\207", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "CPU", nullptr));
        pushButtonSaveExcel->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230excel", nullptr));
        pushButtonScreenshot->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\210\252\345\233\276", nullptr));
        groupBox_3->setTitle(QString());
        pushButtonGetPropertyValue->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226\346\225\260\346\215\256", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "\347\274\223\345\255\230\346\227\266\351\227\264 (ms)", nullptr));
        lineEditCashTime->setText(QApplication::translate("MainWindow", "100", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\345\261\236\346\200\247\345\220\215\347\247\260", nullptr));
        pushButtonSetMeasuringRate->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\351\242\221\347\216\207", nullptr));
        lineEditHzNumber->setText(QApplication::translate("MainWindow", "100", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Hz", nullptr));
        pushButtonReboot->setText(QApplication::translate("MainWindow", "\351\207\215\345\220\257", nullptr));
        groupBox_4->setTitle(QString());
        label_6->setText(QApplication::translate("MainWindow", "\344\274\240\346\204\237\345\231\250\344\277\241\346\201\257", nullptr));
        lineEditSerial1->setText(QApplication::translate("MainWindow", "...", nullptr));
        lineEditSerial2->setText(QApplication::translate("MainWindow", "...", nullptr));
        lineEditSerial3->setText(QApplication::translate("MainWindow", "...", nullptr));
        pushButtonSetMode->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\346\250\241\345\274\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
