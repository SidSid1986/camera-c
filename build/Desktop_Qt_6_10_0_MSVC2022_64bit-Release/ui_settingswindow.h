/********************************************************************************
** Form generated from reading UI file 'settingswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWINDOW_H
#define UI_SETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsWindow
{
public:
    QPushButton *pushButtonResetEncoder;
    QPushButton *pushButtonResetPicCnt;
    QPushButton *pushButtonresetBaseTime;
    QLineEdit *getExposureTime;
    QTextEdit *setExposureTime;
    QLineEdit *getAcquisitionLineTime;
    QTextEdit *setAcquisitionLineTime;
    QTextEdit *setSyncOutDelay;
    QTextEdit *setHeightZ;
    QTextEdit *setSyncOut;
    QLineEdit *getSyncOutDelay;
    QLineEdit *getHeightZ;
    QLineEdit *getSyncOut;
    QLineEdit *getSignalWidthMin;
    QTextEdit *setSignalStrengthMin;
    QTextEdit *setWidthX;
    QTextEdit *setOffsetX;
    QTextEdit *setStepX;
    QLineEdit *getOffsetZ;
    QLineEdit *getOffsetX;
    QLineEdit *getSignalWidthMax;
    QLineEdit *getWidthX;
    QTextEdit *setOffsetZ;
    QLineEdit *getStepX;
    QTextEdit *setSignalWidthMin;
    QTextEdit *setSignalWidthMax;
    QLineEdit *getSignalStrengthMin;
    QPushButton *pushButtonSendASCIICommand;
    QTextEdit *sendRawCommand;
    QLabel *label_19;
    QLabel *label_20;
    QPushButton *pushButtonUpdate;
    QTextEdit *setSignalSelection;
    QLabel *label_23;
    QLabel *label_24;
    QTextEdit *setTriggerSource;
    QLabel *label_6;
    QLabel *label_3;
    QPushButton *pushButtonResetSettings;
    QLineEdit *lineEditMaxMeasureRate;
    QLabel *label_17;
    QLabel *label_18;
    QLineEdit *getTriggersource;
    QLineEdit *getSignalEnable;
    QLineEdit *getSignalSelection;
    QPushButton *pushButtonSetAcquisitionStart;
    QPushButton *pushButtonSetAcquisitionStop;
    QPushButton *pushButtonStopResetStart;
    QPushButton *pushButtonSaveXML;
    QPushButton *pushButtonAcquisitionLineTime;
    QPushButton *pushButtonTriggerSource;
    QPushButton *pushButtonExposureTime;
    QPushButton *pushButtonSync;
    QPushButton *pushButtonSyncDelay;
    QPushButton *pushButtonSignalEnable;
    QPushButton *pushButtonSignalSelection;
    QPushButton *pushButtonSignalWidthMin;
    QPushButton *pushButtonSignalWidthMax;
    QPushButton *pushButtonSignalStrengthMin;
    QPushButton *pushButtonHeightZ;
    QPushButton *pushButtonStepX;
    QPushButton *pushButtonOffsetX;
    QPushButton *pushButtonWidthX;
    QPushButton *pushButtonOffsetZ;
    QComboBox *comboBoxSignalEnable;

    void setupUi(QWidget *SettingsWindow)
    {
        if (SettingsWindow->objectName().isEmpty())
            SettingsWindow->setObjectName(QString::fromUtf8("SettingsWindow"));
        SettingsWindow->resize(822, 545);
        SettingsWindow->setStyleSheet(QString::fromUtf8("/* \344\270\273\347\252\227\345\217\243\350\203\214\346\231\257 */\n"
"QMainWindow {\n"
"    background-color: #F5F7FA;\n"
"    font-family: \"Segoe UI\", Arial, sans-serif;\n"
"}\n"
"\n"
"/* \345\267\246\344\276\247\346\240\217\350\203\214\346\231\257 */\n"
"QTreeView, QTableWidget {\n"
"    background-color: #E6ECF2;\n"
"    border-right: 1px solid #CBD5E0;\n"
"}\n"
"\n"
"/* \346\226\207\345\255\227\346\240\267\345\274\217 */\n"
"QLabel,QComboBox {\n"
"    color: #2D3748;\n"
"    font-size: 12px;\n"
"}\n"
"\n"
"\n"
"\n"
"/* \345\267\246\344\276\247\346\240\217\350\203\214\346\231\257 */\n"
"QTreeView, QTableWidget {\n"
"    background-color: #E6ECF2;\n"
"    border-right: 1px solid #CBD5E0;\n"
"}\n"
"\n"
"/* \346\226\207\345\255\227\346\240\267\345\274\217 */\n"
"QLabel, QComboBox {\n"
"    color: #2D3748;\n"
"    font-size: 12px;\n"
"}\n"
"\n"
"QLineEdit {\n"
"    color: #727272;\n"
"    font-size: 12px;\n"
"    border: 1px solid #CBD5E0;\n"
"    border-radius: 3px;\n"
"    padding: 4px;\n"
"  	background:#"
                        "F0F0F0;\n"
"   \n"
"}\n"
"\n"
"/* \351\273\230\350\256\244\346\214\211\351\222\256 */\n"
"QPushButton {\n"
"    background-color: #3182CE;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
" \n"
"	padding:5px 10px;\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\346\225\210\346\236\234 */\n"
"QPushButton:hover {\n"
"    background-color: #2C5282;\n"
"}\n"
"\n"
"/* \346\214\211\344\270\213\346\225\210\346\236\234 */\n"
"QPushButton:pressed {\n"
"    background-color: #1A365D;\n"
"}\n"
"\n"
"/* \350\255\246\345\221\212\347\261\273\346\214\211\351\222\256\357\274\210\345\246\202Reset\357\274\211 */\n"
"QPushButton#resetButton {\n"
"    background-color: #E53E3E;\n"
"}\n"
"QPushButton#resetButton:hover {\n"
"    background-color: #C53030;\n"
"}\n"
"/* \350\276\223\345\205\245\346\241\206/\344\270\213\346\213\211\346\241\206 */\n"
" QComboBox {\n"
"    border: 1px solid #CBD5E0;\n"
"    border-radius: 3px;\n"
"    padding: 4px;\n"
"    background: white;\n"
"}\n"
"\n"
"/* \345\275\223\345\211\215"
                        "\345\200\274\351\253\230\344\272\256 */\n"
"/*QLineEdit[current=\"true\"] {\n"
"    background-color: #EBF8FF;\n"
"}*/\n"
"QTableWidget {\n"
"    border-radius: 6px;\n"
"    background: white;\n"
"    padding: 8px;\n"
"    margin: 5px;\n"
"}\n"
"QGroupBox {\n"
"    border: 1px solid #E2E8F0;\n"
"    border-radius: 6px;\n"
"    margin-top: 10px;\n"
"    padding-top: 15px;\n"
"}\n"
"QTextEdit#commandWindow {\n"
"    background-color: #EDF2F7;\n"
"    border: 1px solid #3182CE;\n"
"    font-family: monospace;\n"
"}"));
        pushButtonResetEncoder = new QPushButton(SettingsWindow);
        pushButtonResetEncoder->setObjectName(QString::fromUtf8("pushButtonResetEncoder"));
        pushButtonResetEncoder->setGeometry(QRect(410, 420, 104, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        pushButtonResetEncoder->setFont(font);
        pushButtonResetPicCnt = new QPushButton(SettingsWindow);
        pushButtonResetPicCnt->setObjectName(QString::fromUtf8("pushButtonResetPicCnt"));
        pushButtonResetPicCnt->setGeometry(QRect(528, 420, 104, 31));
        pushButtonResetPicCnt->setFont(font);
        pushButtonresetBaseTime = new QPushButton(SettingsWindow);
        pushButtonresetBaseTime->setObjectName(QString::fromUtf8("pushButtonresetBaseTime"));
        pushButtonresetBaseTime->setGeometry(QRect(647, 420, 104, 31));
        pushButtonresetBaseTime->setFont(font);
        pushButtonresetBaseTime->setStyleSheet(QString::fromUtf8("padding:0;"));
        getExposureTime = new QLineEdit(SettingsWindow);
        getExposureTime->setObjectName(QString::fromUtf8("getExposureTime"));
        getExposureTime->setEnabled(false);
        getExposureTime->setGeometry(QRect(228, 87, 110, 31));
        getExposureTime->setFont(font);
        setExposureTime = new QTextEdit(SettingsWindow);
        setExposureTime->setObjectName(QString::fromUtf8("setExposureTime"));
        setExposureTime->setGeometry(QRect(149, 87, 70, 31));
        setExposureTime->setFont(font);
        getAcquisitionLineTime = new QLineEdit(SettingsWindow);
        getAcquisitionLineTime->setObjectName(QString::fromUtf8("getAcquisitionLineTime"));
        getAcquisitionLineTime->setEnabled(false);
        getAcquisitionLineTime->setGeometry(QRect(228, 129, 110, 31));
        getAcquisitionLineTime->setFont(font);
        setAcquisitionLineTime = new QTextEdit(SettingsWindow);
        setAcquisitionLineTime->setObjectName(QString::fromUtf8("setAcquisitionLineTime"));
        setAcquisitionLineTime->setGeometry(QRect(149, 129, 70, 31));
        setAcquisitionLineTime->setFont(font);
        setSyncOutDelay = new QTextEdit(SettingsWindow);
        setSyncOutDelay->setObjectName(QString::fromUtf8("setSyncOutDelay"));
        setSyncOutDelay->setGeometry(QRect(150, 214, 70, 31));
        setSyncOutDelay->setFont(font);
        setHeightZ = new QTextEdit(SettingsWindow);
        setHeightZ->setObjectName(QString::fromUtf8("setHeightZ"));
        setHeightZ->setGeometry(QRect(557, 40, 70, 31));
        setHeightZ->setFont(font);
        setSyncOut = new QTextEdit(SettingsWindow);
        setSyncOut->setObjectName(QString::fromUtf8("setSyncOut"));
        setSyncOut->setGeometry(QRect(150, 171, 70, 31));
        setSyncOut->setFont(font);
        getSyncOutDelay = new QLineEdit(SettingsWindow);
        getSyncOutDelay->setObjectName(QString::fromUtf8("getSyncOutDelay"));
        getSyncOutDelay->setEnabled(false);
        getSyncOutDelay->setGeometry(QRect(229, 214, 110, 31));
        getSyncOutDelay->setFont(font);
        getHeightZ = new QLineEdit(SettingsWindow);
        getHeightZ->setObjectName(QString::fromUtf8("getHeightZ"));
        getHeightZ->setEnabled(false);
        getHeightZ->setGeometry(QRect(637, 40, 110, 31));
        getHeightZ->setFont(font);
        getSyncOut = new QLineEdit(SettingsWindow);
        getSyncOut->setObjectName(QString::fromUtf8("getSyncOut"));
        getSyncOut->setEnabled(false);
        getSyncOut->setGeometry(QRect(229, 171, 110, 31));
        getSyncOut->setFont(font);
        getSignalWidthMin = new QLineEdit(SettingsWindow);
        getSignalWidthMin->setObjectName(QString::fromUtf8("getSignalWidthMin"));
        getSignalWidthMin->setEnabled(false);
        getSignalWidthMin->setGeometry(QRect(229, 344, 110, 31));
        getSignalWidthMin->setFont(font);
        setSignalStrengthMin = new QTextEdit(SettingsWindow);
        setSignalStrengthMin->setObjectName(QString::fromUtf8("setSignalStrengthMin"));
        setSignalStrengthMin->setGeometry(QRect(149, 427, 70, 31));
        setSignalStrengthMin->setFont(font);
        setWidthX = new QTextEdit(SettingsWindow);
        setWidthX->setObjectName(QString::fromUtf8("setWidthX"));
        setWidthX->setGeometry(QRect(557, 123, 70, 31));
        setWidthX->setFont(font);
        setOffsetX = new QTextEdit(SettingsWindow);
        setOffsetX->setObjectName(QString::fromUtf8("setOffsetX"));
        setOffsetX->setGeometry(QRect(557, 164, 70, 31));
        setOffsetX->setFont(font);
        setStepX = new QTextEdit(SettingsWindow);
        setStepX->setObjectName(QString::fromUtf8("setStepX"));
        setStepX->setGeometry(QRect(557, 205, 70, 31));
        setStepX->setFont(font);
        getOffsetZ = new QLineEdit(SettingsWindow);
        getOffsetZ->setObjectName(QString::fromUtf8("getOffsetZ"));
        getOffsetZ->setEnabled(false);
        getOffsetZ->setGeometry(QRect(637, 81, 110, 31));
        getOffsetZ->setFont(font);
        getOffsetX = new QLineEdit(SettingsWindow);
        getOffsetX->setObjectName(QString::fromUtf8("getOffsetX"));
        getOffsetX->setEnabled(false);
        getOffsetX->setGeometry(QRect(637, 164, 110, 31));
        getOffsetX->setFont(font);
        getSignalWidthMax = new QLineEdit(SettingsWindow);
        getSignalWidthMax->setObjectName(QString::fromUtf8("getSignalWidthMax"));
        getSignalWidthMax->setEnabled(false);
        getSignalWidthMax->setGeometry(QRect(229, 384, 110, 31));
        getSignalWidthMax->setFont(font);
        getWidthX = new QLineEdit(SettingsWindow);
        getWidthX->setObjectName(QString::fromUtf8("getWidthX"));
        getWidthX->setEnabled(false);
        getWidthX->setGeometry(QRect(637, 123, 110, 31));
        getWidthX->setFont(font);
        setOffsetZ = new QTextEdit(SettingsWindow);
        setOffsetZ->setObjectName(QString::fromUtf8("setOffsetZ"));
        setOffsetZ->setGeometry(QRect(557, 81, 70, 31));
        setOffsetZ->setFont(font);
        getStepX = new QLineEdit(SettingsWindow);
        getStepX->setObjectName(QString::fromUtf8("getStepX"));
        getStepX->setEnabled(false);
        getStepX->setGeometry(QRect(637, 205, 110, 31));
        getStepX->setFont(font);
        setSignalWidthMin = new QTextEdit(SettingsWindow);
        setSignalWidthMin->setObjectName(QString::fromUtf8("setSignalWidthMin"));
        setSignalWidthMin->setGeometry(QRect(149, 343, 70, 31));
        setSignalWidthMin->setFont(font);
        setSignalWidthMax = new QTextEdit(SettingsWindow);
        setSignalWidthMax->setObjectName(QString::fromUtf8("setSignalWidthMax"));
        setSignalWidthMax->setGeometry(QRect(149, 384, 70, 31));
        setSignalWidthMax->setFont(font);
        getSignalStrengthMin = new QLineEdit(SettingsWindow);
        getSignalStrengthMin->setObjectName(QString::fromUtf8("getSignalStrengthMin"));
        getSignalStrengthMin->setEnabled(false);
        getSignalStrengthMin->setGeometry(QRect(229, 427, 110, 31));
        getSignalStrengthMin->setFont(font);
        pushButtonSendASCIICommand = new QPushButton(SettingsWindow);
        pushButtonSendASCIICommand->setObjectName(QString::fromUtf8("pushButtonSendASCIICommand"));
        pushButtonSendASCIICommand->setGeometry(QRect(717, 322, 51, 51));
        pushButtonSendASCIICommand->setFont(font);
        sendRawCommand = new QTextEdit(SettingsWindow);
        sendRawCommand->setObjectName(QString::fromUtf8("sendRawCommand"));
        sendRawCommand->setGeometry(QRect(410, 322, 291, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(8);
        sendRawCommand->setFont(font1);
        label_19 = new QLabel(SettingsWindow);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(157, 10, 61, 31));
        label_19->setFont(font);
        label_20 = new QLabel(SettingsWindow);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(245, 10, 91, 31));
        label_20->setFont(font);
        pushButtonUpdate = new QPushButton(SettingsWindow);
        pushButtonUpdate->setObjectName(QString::fromUtf8("pushButtonUpdate"));
        pushButtonUpdate->setGeometry(QRect(530, 457, 104, 41));
        pushButtonUpdate->setFont(font);
        setSignalSelection = new QTextEdit(SettingsWindow);
        setSignalSelection->setObjectName(QString::fromUtf8("setSignalSelection"));
        setSignalSelection->setGeometry(QRect(149, 299, 71, 31));
        setSignalSelection->setFont(font);
        label_23 = new QLabel(SettingsWindow);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(654, 10, 91, 31));
        label_23->setFont(font);
        label_24 = new QLabel(SettingsWindow);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(568, 10, 61, 31));
        label_24->setFont(font);
        setTriggerSource = new QTextEdit(SettingsWindow);
        setTriggerSource->setObjectName(QString::fromUtf8("setTriggerSource"));
        setTriggerSource->setGeometry(QRect(149, 45, 70, 31));
        setTriggerSource->setFont(font);
        label_6 = new QLabel(SettingsWindow);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 40, 131, 31));
        label_6->setFont(font);
        label_3 = new QLabel(SettingsWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(410, 289, 331, 31));
        label_3->setFont(font);
        pushButtonResetSettings = new QPushButton(SettingsWindow);
        pushButtonResetSettings->setObjectName(QString::fromUtf8("pushButtonResetSettings"));
        pushButtonResetSettings->setGeometry(QRect(410, 460, 104, 31));
        pushButtonResetSettings->setFont(font);
        lineEditMaxMeasureRate = new QLineEdit(SettingsWindow);
        lineEditMaxMeasureRate->setObjectName(QString::fromUtf8("lineEditMaxMeasureRate"));
        lineEditMaxMeasureRate->setEnabled(false);
        lineEditMaxMeasureRate->setGeometry(QRect(550, 247, 51, 31));
        lineEditMaxMeasureRate->setFont(font);
        label_17 = new QLabel(SettingsWindow);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(390, 247, 151, 31));
        label_17->setFont(font);
        label_17->setStyleSheet(QString::fromUtf8(""));
        label_18 = new QLabel(SettingsWindow);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(610, 243, 191, 51));
        label_18->setFont(font);
        label_18->setWordWrap(true);
        getTriggersource = new QLineEdit(SettingsWindow);
        getTriggersource->setObjectName(QString::fromUtf8("getTriggersource"));
        getTriggersource->setEnabled(false);
        getTriggersource->setGeometry(QRect(228, 45, 110, 31));
        getTriggersource->setFont(font);
        getSignalEnable = new QLineEdit(SettingsWindow);
        getSignalEnable->setObjectName(QString::fromUtf8("getSignalEnable"));
        getSignalEnable->setEnabled(false);
        getSignalEnable->setGeometry(QRect(230, 257, 110, 31));
        getSignalEnable->setFont(font);
        getSignalSelection = new QLineEdit(SettingsWindow);
        getSignalSelection->setObjectName(QString::fromUtf8("getSignalSelection"));
        getSignalSelection->setEnabled(false);
        getSignalSelection->setGeometry(QRect(229, 299, 110, 31));
        getSignalSelection->setFont(font);
        pushButtonSetAcquisitionStart = new QPushButton(SettingsWindow);
        pushButtonSetAcquisitionStart->setObjectName(QString::fromUtf8("pushButtonSetAcquisitionStart"));
        pushButtonSetAcquisitionStart->setGeometry(QRect(600, 376, 151, 41));
        pushButtonSetAcquisitionStop = new QPushButton(SettingsWindow);
        pushButtonSetAcquisitionStop->setObjectName(QString::fromUtf8("pushButtonSetAcquisitionStop"));
        pushButtonSetAcquisitionStop->setGeometry(QRect(410, 376, 151, 41));
        pushButtonStopResetStart = new QPushButton(SettingsWindow);
        pushButtonStopResetStart->setObjectName(QString::fromUtf8("pushButtonStopResetStart"));
        pushButtonStopResetStart->setGeometry(QRect(410, 502, 341, 31));
        pushButtonStopResetStart->setStyleSheet(QString::fromUtf8("padding:0;"));
        pushButtonSaveXML = new QPushButton(SettingsWindow);
        pushButtonSaveXML->setObjectName(QString::fromUtf8("pushButtonSaveXML"));
        pushButtonSaveXML->setGeometry(QRect(647, 460, 104, 31));
        pushButtonSaveXML->setFont(font);
        pushButtonAcquisitionLineTime = new QPushButton(SettingsWindow);
        pushButtonAcquisitionLineTime->setObjectName(QString::fromUtf8("pushButtonAcquisitionLineTime"));
        pushButtonAcquisitionLineTime->setGeometry(QRect(4, 124, 141, 41));
        pushButtonAcquisitionLineTime->setStyleSheet(QString::fromUtf8("padding:0; "));
        pushButtonTriggerSource = new QPushButton(SettingsWindow);
        pushButtonTriggerSource->setObjectName(QString::fromUtf8("pushButtonTriggerSource"));
        pushButtonTriggerSource->setGeometry(QRect(3, 40, 141, 41));
        pushButtonTriggerSource->setStyleSheet(QString::fromUtf8("/* \345\234\250 QLabel \346\210\226 QPushButton \344\270\255\346\215\242\350\241\214 */\n"
"QLabel, QPushButton {\n"
"    /* \345\274\272\345\210\266\346\226\207\346\234\254\346\215\242\350\241\214\357\274\210\\A \350\241\250\347\244\272\346\215\242\350\241\214\347\254\246\357\274\211 */\n"
"    qproperty-wordWrap: true;  /* \345\205\201\350\256\270\350\207\252\345\212\250\346\215\242\350\241\214\357\274\210\345\217\257\351\200\211\357\274\211 */\n"
"}\n"
"\n"
"QLabel {\n"
"    qproperty-alignment: 'AlignCenter';  /* \346\226\207\346\234\254\345\261\205\344\270\255 */\n"
"    white-space: pre;                   /* \344\277\235\347\225\231\346\215\242\350\241\214\347\254\246\357\274\210\345\205\263\351\224\256\357\274\201\357\274\211 */\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"}"));
        pushButtonExposureTime = new QPushButton(SettingsWindow);
        pushButtonExposureTime->setObjectName(QString::fromUtf8("pushButtonExposureTime"));
        pushButtonExposureTime->setGeometry(QRect(3, 82, 141, 41));
        pushButtonExposureTime->setStyleSheet(QString::fromUtf8("/* \345\234\250 QLabel \346\210\226 QPushButton \344\270\255\346\215\242\350\241\214 */\n"
"QLabel, QPushButton {\n"
"    /* \345\274\272\345\210\266\346\226\207\346\234\254\346\215\242\350\241\214\357\274\210\\A \350\241\250\347\244\272\346\215\242\350\241\214\347\254\246\357\274\211 */\n"
"    qproperty-wordWrap: true;  /* \345\205\201\350\256\270\350\207\252\345\212\250\346\215\242\350\241\214\357\274\210\345\217\257\351\200\211\357\274\211 */\n"
"}\n"
"\n"
"QLabel {\n"
"    qproperty-alignment: 'AlignCenter';  /* \346\226\207\346\234\254\345\261\205\344\270\255 */\n"
"    white-space: pre;                   /* \344\277\235\347\225\231\346\215\242\350\241\214\347\254\246\357\274\210\345\205\263\351\224\256\357\274\201\357\274\211 */\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"}"));
        pushButtonSync = new QPushButton(SettingsWindow);
        pushButtonSync->setObjectName(QString::fromUtf8("pushButtonSync"));
        pushButtonSync->setGeometry(QRect(4, 166, 141, 41));
        pushButtonSync->setStyleSheet(QString::fromUtf8("/* \345\234\250 QLabel \346\210\226 QPushButton \344\270\255\346\215\242\350\241\214 */\n"
"QLabel, QPushButton {\n"
"    /* \345\274\272\345\210\266\346\226\207\346\234\254\346\215\242\350\241\214\357\274\210\\A \350\241\250\347\244\272\346\215\242\350\241\214\347\254\246\357\274\211 */\n"
"    qproperty-wordWrap: true;  /* \345\205\201\350\256\270\350\207\252\345\212\250\346\215\242\350\241\214\357\274\210\345\217\257\351\200\211\357\274\211 */\n"
"}\n"
"\n"
"QLabel {\n"
"    qproperty-alignment: 'AlignCenter';  /* \346\226\207\346\234\254\345\261\205\344\270\255 */\n"
"    white-space: pre;                   /* \344\277\235\347\225\231\346\215\242\350\241\214\347\254\246\357\274\210\345\205\263\351\224\256\357\274\201\357\274\211 */\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"}"));
        pushButtonSyncDelay = new QPushButton(SettingsWindow);
        pushButtonSyncDelay->setObjectName(QString::fromUtf8("pushButtonSyncDelay"));
        pushButtonSyncDelay->setGeometry(QRect(5, 209, 141, 41));
        pushButtonSyncDelay->setStyleSheet(QString::fromUtf8("/* \345\234\250 QLabel \346\210\226 QPushButton \344\270\255\346\215\242\350\241\214 */\n"
"QLabel, QPushButton {\n"
"    /* \345\274\272\345\210\266\346\226\207\346\234\254\346\215\242\350\241\214\357\274\210\\A \350\241\250\347\244\272\346\215\242\350\241\214\347\254\246\357\274\211 */\n"
"    qproperty-wordWrap: true;  /* \345\205\201\350\256\270\350\207\252\345\212\250\346\215\242\350\241\214\357\274\210\345\217\257\351\200\211\357\274\211 */\n"
"}\n"
"\n"
"QLabel {\n"
"    qproperty-alignment: 'AlignCenter';  /* \346\226\207\346\234\254\345\261\205\344\270\255 */\n"
"    white-space: pre;                   /* \344\277\235\347\225\231\346\215\242\350\241\214\347\254\246\357\274\210\345\205\263\351\224\256\357\274\201\357\274\211 */\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"}"));
        pushButtonSignalEnable = new QPushButton(SettingsWindow);
        pushButtonSignalEnable->setObjectName(QString::fromUtf8("pushButtonSignalEnable"));
        pushButtonSignalEnable->setGeometry(QRect(5, 252, 141, 41));
        pushButtonSignalEnable->setStyleSheet(QString::fromUtf8("/* \345\234\250 QLabel \346\210\226 QPushButton \344\270\255\346\215\242\350\241\214 */\n"
"QLabel, QPushButton {\n"
"    /* \345\274\272\345\210\266\346\226\207\346\234\254\346\215\242\350\241\214\357\274\210\\A \350\241\250\347\244\272\346\215\242\350\241\214\347\254\246\357\274\211 */\n"
"    qproperty-wordWrap: true;  /* \345\205\201\350\256\270\350\207\252\345\212\250\346\215\242\350\241\214\357\274\210\345\217\257\351\200\211\357\274\211 */\n"
"}\n"
"\n"
"QLabel {\n"
"    qproperty-alignment: 'AlignCenter';  /* \346\226\207\346\234\254\345\261\205\344\270\255 */\n"
"    white-space: pre;                   /* \344\277\235\347\225\231\346\215\242\350\241\214\347\254\246\357\274\210\345\205\263\351\224\256\357\274\201\357\274\211 */\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"}"));
        pushButtonSignalSelection = new QPushButton(SettingsWindow);
        pushButtonSignalSelection->setObjectName(QString::fromUtf8("pushButtonSignalSelection"));
        pushButtonSignalSelection->setGeometry(QRect(4, 294, 141, 41));
        pushButtonSignalSelection->setStyleSheet(QString::fromUtf8("/* \345\234\250 QLabel \346\210\226 QPushButton \344\270\255\346\215\242\350\241\214 */\n"
"QLabel, QPushButton {\n"
"    /* \345\274\272\345\210\266\346\226\207\346\234\254\346\215\242\350\241\214\357\274\210\\A \350\241\250\347\244\272\346\215\242\350\241\214\347\254\246\357\274\211 */\n"
"    qproperty-wordWrap: true;  /* \345\205\201\350\256\270\350\207\252\345\212\250\346\215\242\350\241\214\357\274\210\345\217\257\351\200\211\357\274\211 */\n"
"}\n"
"\n"
"QLabel {\n"
"    qproperty-alignment: 'AlignCenter';  /* \346\226\207\346\234\254\345\261\205\344\270\255 */\n"
"    white-space: pre;                   /* \344\277\235\347\225\231\346\215\242\350\241\214\347\254\246\357\274\210\345\205\263\351\224\256\357\274\201\357\274\211 */\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"}"));
        pushButtonSignalWidthMin = new QPushButton(SettingsWindow);
        pushButtonSignalWidthMin->setObjectName(QString::fromUtf8("pushButtonSignalWidthMin"));
        pushButtonSignalWidthMin->setGeometry(QRect(4, 337, 141, 41));
        pushButtonSignalWidthMin->setStyleSheet(QString::fromUtf8("padding:0;"));
        pushButtonSignalWidthMax = new QPushButton(SettingsWindow);
        pushButtonSignalWidthMax->setObjectName(QString::fromUtf8("pushButtonSignalWidthMax"));
        pushButtonSignalWidthMax->setGeometry(QRect(4, 379, 141, 41));
        pushButtonSignalWidthMax->setStyleSheet(QString::fromUtf8("padding:0;"));
        pushButtonSignalStrengthMin = new QPushButton(SettingsWindow);
        pushButtonSignalStrengthMin->setObjectName(QString::fromUtf8("pushButtonSignalStrengthMin"));
        pushButtonSignalStrengthMin->setGeometry(QRect(4, 422, 141, 41));
        pushButtonSignalStrengthMin->setStyleSheet(QString::fromUtf8("/* \345\234\250 QLabel \346\210\226 QPushButton \344\270\255\346\215\242\350\241\214 */\n"
"QLabel, QPushButton {\n"
"    /* \345\274\272\345\210\266\346\226\207\346\234\254\346\215\242\350\241\214\357\274\210\\A \350\241\250\347\244\272\346\215\242\350\241\214\347\254\246\357\274\211 */\n"
"    qproperty-wordWrap: true;  /* \345\205\201\350\256\270\350\207\252\345\212\250\346\215\242\350\241\214\357\274\210\345\217\257\351\200\211\357\274\211 */\n"
"}\n"
"\n"
"QLabel {\n"
"    qproperty-alignment: 'AlignCenter';  /* \346\226\207\346\234\254\345\261\205\344\270\255 */\n"
"    white-space: pre;                   /* \344\277\235\347\225\231\346\215\242\350\241\214\347\254\246\357\274\210\345\205\263\351\224\256\357\274\201\357\274\211 */\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"}"));
        pushButtonHeightZ = new QPushButton(SettingsWindow);
        pushButtonHeightZ->setObjectName(QString::fromUtf8("pushButtonHeightZ"));
        pushButtonHeightZ->setGeometry(QRect(410, 34, 141, 41));
        pushButtonHeightZ->setStyleSheet(QString::fromUtf8("/* \345\234\250 QLabel \346\210\226 QPushButton \344\270\255\346\215\242\350\241\214 */\n"
"QLabel, QPushButton {\n"
"    /* \345\274\272\345\210\266\346\226\207\346\234\254\346\215\242\350\241\214\357\274\210\\A \350\241\250\347\244\272\346\215\242\350\241\214\347\254\246\357\274\211 */\n"
"    qproperty-wordWrap: true;  /* \345\205\201\350\256\270\350\207\252\345\212\250\346\215\242\350\241\214\357\274\210\345\217\257\351\200\211\357\274\211 */\n"
"}\n"
"\n"
"QLabel {\n"
"    qproperty-alignment: 'AlignCenter';  /* \346\226\207\346\234\254\345\261\205\344\270\255 */\n"
"    white-space: pre;                   /* \344\277\235\347\225\231\346\215\242\350\241\214\347\254\246\357\274\210\345\205\263\351\224\256\357\274\201\357\274\211 */\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"}"));
        pushButtonStepX = new QPushButton(SettingsWindow);
        pushButtonStepX->setObjectName(QString::fromUtf8("pushButtonStepX"));
        pushButtonStepX->setGeometry(QRect(410, 202, 141, 41));
        pushButtonStepX->setStyleSheet(QString::fromUtf8("/* \345\234\250 QLabel \346\210\226 QPushButton \344\270\255\346\215\242\350\241\214 */\n"
"QLabel, QPushButton {\n"
"    /* \345\274\272\345\210\266\346\226\207\346\234\254\346\215\242\350\241\214\357\274\210\\A \350\241\250\347\244\272\346\215\242\350\241\214\347\254\246\357\274\211 */\n"
"    qproperty-wordWrap: true;  /* \345\205\201\350\256\270\350\207\252\345\212\250\346\215\242\350\241\214\357\274\210\345\217\257\351\200\211\357\274\211 */\n"
"}\n"
"\n"
"QLabel {\n"
"    qproperty-alignment: 'AlignCenter';  /* \346\226\207\346\234\254\345\261\205\344\270\255 */\n"
"    white-space: pre;                   /* \344\277\235\347\225\231\346\215\242\350\241\214\347\254\246\357\274\210\345\205\263\351\224\256\357\274\201\357\274\211 */\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"}"));
        pushButtonOffsetX = new QPushButton(SettingsWindow);
        pushButtonOffsetX->setObjectName(QString::fromUtf8("pushButtonOffsetX"));
        pushButtonOffsetX->setGeometry(QRect(410, 160, 141, 41));
        pushButtonOffsetX->setStyleSheet(QString::fromUtf8("/* \345\234\250 QLabel \346\210\226 QPushButton \344\270\255\346\215\242\350\241\214 */\n"
"QLabel, QPushButton {\n"
"    /* \345\274\272\345\210\266\346\226\207\346\234\254\346\215\242\350\241\214\357\274\210\\A \350\241\250\347\244\272\346\215\242\350\241\214\347\254\246\357\274\211 */\n"
"    qproperty-wordWrap: true;  /* \345\205\201\350\256\270\350\207\252\345\212\250\346\215\242\350\241\214\357\274\210\345\217\257\351\200\211\357\274\211 */\n"
"}\n"
"\n"
"QLabel {\n"
"    qproperty-alignment: 'AlignCenter';  /* \346\226\207\346\234\254\345\261\205\344\270\255 */\n"
"    white-space: pre;                   /* \344\277\235\347\225\231\346\215\242\350\241\214\347\254\246\357\274\210\345\205\263\351\224\256\357\274\201\357\274\211 */\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"}"));
        pushButtonWidthX = new QPushButton(SettingsWindow);
        pushButtonWidthX->setObjectName(QString::fromUtf8("pushButtonWidthX"));
        pushButtonWidthX->setGeometry(QRect(410, 118, 141, 41));
        pushButtonWidthX->setStyleSheet(QString::fromUtf8("/* \345\234\250 QLabel \346\210\226 QPushButton \344\270\255\346\215\242\350\241\214 */\n"
"QLabel, QPushButton {\n"
"    /* \345\274\272\345\210\266\346\226\207\346\234\254\346\215\242\350\241\214\357\274\210\\A \350\241\250\347\244\272\346\215\242\350\241\214\347\254\246\357\274\211 */\n"
"    qproperty-wordWrap: true;  /* \345\205\201\350\256\270\350\207\252\345\212\250\346\215\242\350\241\214\357\274\210\345\217\257\351\200\211\357\274\211 */\n"
"}\n"
"\n"
"QLabel {\n"
"    qproperty-alignment: 'AlignCenter';  /* \346\226\207\346\234\254\345\261\205\344\270\255 */\n"
"    white-space: pre;                   /* \344\277\235\347\225\231\346\215\242\350\241\214\347\254\246\357\274\210\345\205\263\351\224\256\357\274\201\357\274\211 */\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"}"));
        pushButtonOffsetZ = new QPushButton(SettingsWindow);
        pushButtonOffsetZ->setObjectName(QString::fromUtf8("pushButtonOffsetZ"));
        pushButtonOffsetZ->setGeometry(QRect(410, 76, 141, 41));
        pushButtonOffsetZ->setStyleSheet(QString::fromUtf8("/* \345\234\250 QLabel \346\210\226 QPushButton \344\270\255\346\215\242\350\241\214 */\n"
"QLabel, QPushButton {\n"
"    /* \345\274\272\345\210\266\346\226\207\346\234\254\346\215\242\350\241\214\357\274\210\\A \350\241\250\347\244\272\346\215\242\350\241\214\347\254\246\357\274\211 */\n"
"    qproperty-wordWrap: true;  /* \345\205\201\350\256\270\350\207\252\345\212\250\346\215\242\350\241\214\357\274\210\345\217\257\351\200\211\357\274\211 */\n"
"}\n"
"\n"
"QLabel {\n"
"    qproperty-alignment: 'AlignCenter';  /* \346\226\207\346\234\254\345\261\205\344\270\255 */\n"
"    white-space: pre;                   /* \344\277\235\347\225\231\346\215\242\350\241\214\347\254\246\357\274\210\345\205\263\351\224\256\357\274\201\357\274\211 */\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"}"));
        comboBoxSignalEnable = new QComboBox(SettingsWindow);
        comboBoxSignalEnable->setObjectName(QString::fromUtf8("comboBoxSignalEnable"));
        comboBoxSignalEnable->setGeometry(QRect(150, 260, 69, 31));
        QWidget::setTabOrder(setTriggerSource, setExposureTime);
        QWidget::setTabOrder(setExposureTime, setAcquisitionLineTime);
        QWidget::setTabOrder(setAcquisitionLineTime, setSyncOut);
        QWidget::setTabOrder(setSyncOut, setSyncOutDelay);
        QWidget::setTabOrder(setSyncOutDelay, setSignalSelection);
        QWidget::setTabOrder(setSignalSelection, setSignalWidthMin);
        QWidget::setTabOrder(setSignalWidthMin, setSignalWidthMax);
        QWidget::setTabOrder(setSignalWidthMax, setSignalStrengthMin);
        QWidget::setTabOrder(setSignalStrengthMin, setHeightZ);
        QWidget::setTabOrder(setHeightZ, setOffsetZ);
        QWidget::setTabOrder(setOffsetZ, setWidthX);
        QWidget::setTabOrder(setWidthX, setOffsetX);
        QWidget::setTabOrder(setOffsetX, setStepX);
        QWidget::setTabOrder(setStepX, sendRawCommand);
        QWidget::setTabOrder(sendRawCommand, pushButtonSetAcquisitionStop);
        QWidget::setTabOrder(pushButtonSetAcquisitionStop, pushButtonSetAcquisitionStart);
        QWidget::setTabOrder(pushButtonSetAcquisitionStart, pushButtonResetEncoder);
        QWidget::setTabOrder(pushButtonResetEncoder, pushButtonResetPicCnt);
        QWidget::setTabOrder(pushButtonResetPicCnt, pushButtonresetBaseTime);
        QWidget::setTabOrder(pushButtonresetBaseTime, pushButtonResetSettings);
        QWidget::setTabOrder(pushButtonResetSettings, pushButtonUpdate);
        QWidget::setTabOrder(pushButtonUpdate, pushButtonStopResetStart);
        QWidget::setTabOrder(pushButtonStopResetStart, getTriggersource);
        QWidget::setTabOrder(getTriggersource, getExposureTime);
        QWidget::setTabOrder(getExposureTime, getAcquisitionLineTime);
        QWidget::setTabOrder(getAcquisitionLineTime, getSyncOut);
        QWidget::setTabOrder(getSyncOut, getSyncOutDelay);
        QWidget::setTabOrder(getSyncOutDelay, getSignalEnable);
        QWidget::setTabOrder(getSignalEnable, getSignalSelection);
        QWidget::setTabOrder(getSignalSelection, getSignalWidthMin);
        QWidget::setTabOrder(getSignalWidthMin, getSignalWidthMax);
        QWidget::setTabOrder(getSignalWidthMax, getSignalStrengthMin);
        QWidget::setTabOrder(getSignalStrengthMin, getHeightZ);
        QWidget::setTabOrder(getHeightZ, getOffsetZ);
        QWidget::setTabOrder(getOffsetZ, getWidthX);
        QWidget::setTabOrder(getWidthX, getOffsetX);
        QWidget::setTabOrder(getOffsetX, getStepX);
        QWidget::setTabOrder(getStepX, lineEditMaxMeasureRate);
        QWidget::setTabOrder(lineEditMaxMeasureRate, pushButtonSendASCIICommand);

        retranslateUi(SettingsWindow);

        QMetaObject::connectSlotsByName(SettingsWindow);
    } // setupUi

    void retranslateUi(QWidget *SettingsWindow)
    {
        SettingsWindow->setWindowTitle(QApplication::translate("SettingsWindow", "Settings", nullptr));
        pushButtonResetEncoder->setText(QApplication::translate("SettingsWindow", "Reset Encoder", nullptr));
        pushButtonResetPicCnt->setText(QApplication::translate("SettingsWindow", "Reset PicCnt", nullptr));
        pushButtonresetBaseTime->setText(QApplication::translate("SettingsWindow", "Reset Basetime", nullptr));
        pushButtonSendASCIICommand->setText(QApplication::translate("SettingsWindow", "\350\256\276\347\275\256", nullptr));
        label_19->setText(QApplication::translate("SettingsWindow", "Set value", nullptr));
        label_20->setText(QApplication::translate("SettingsWindow", "Current value", nullptr));
        pushButtonUpdate->setText(QApplication::translate("SettingsWindow", " Update Values\n"
"\345\210\267\346\226\260\345\275\223\345\211\215\345\200\274", nullptr));
        label_23->setText(QApplication::translate("SettingsWindow", "Current value", nullptr));
        label_24->setText(QApplication::translate("SettingsWindow", "Set value", nullptr));
        label_6->setText(QString());
        label_3->setText(QApplication::translate("SettingsWindow", "Command Window: to put a new line, please press ENTER\n"
"\347\233\264\346\216\245\350\276\223\345\205\245\345\217\221\351\200\201ASCII\345\221\275\344\273\244", nullptr));
        pushButtonResetSettings->setText(QApplication::translate("SettingsWindow", "Reset Settings", nullptr));
        label_17->setText(QApplication::translate("SettingsWindow", "Max measurement rate [Hz]\n"
"            \346\234\200\345\244\247\346\265\213\351\207\217\351\242\221\347\216\207", nullptr));
        label_18->setText(QApplication::translate("SettingsWindow", "depends on the current ROI and the exposure time\n"
"\345\217\226\345\206\263\344\272\216\345\275\223\345\211\215 ROI \345\222\214\346\233\235\345\205\211\346\227\266\351\227\264", nullptr));
        pushButtonSetAcquisitionStart->setText(QApplication::translate("SettingsWindow", "SetAcquisitionStart\n"
"\350\256\276\347\275\256\351\207\207\351\233\206\345\274\200\345\247\213", nullptr));
        pushButtonSetAcquisitionStop->setText(QApplication::translate("SettingsWindow", "SetAcquisitionStop\n"
"\351\207\207\351\233\206\345\201\234\346\255\242", nullptr));
        pushButtonStopResetStart->setText(QApplication::translate("SettingsWindow", "Stop Acquistion - Reset Counters - Start Acquisition\n"
"\345\201\234\346\255\242\351\207\207\351\233\206 - \351\207\215\347\275\256\350\256\241\346\225\260\345\231\250 - \345\274\200\345\247\213\351\207\207\351\233\206", nullptr));
        pushButtonSaveXML->setText(QApplication::translate("SettingsWindow", "Save XML", nullptr));
        pushButtonAcquisitionLineTime->setText(QApplication::translate("SettingsWindow", "SetAcquisitionLineTime\n"
"\350\256\276\347\275\256\351\207\207\351\233\206\347\272\277\346\227\266\351\227\264[\302\265s]", nullptr));
        pushButtonTriggerSource->setText(QApplication::translate("SettingsWindow", "SetTriggerSource\n"
"\350\256\276\347\275\256\350\247\246\345\217\221\346\272\220", nullptr));
        pushButtonExposureTime->setText(QApplication::translate("SettingsWindow", "SetExposureTime [\302\265s]\n"
"\350\256\276\347\275\256\346\233\235\345\205\211\346\227\266\351\227\264", nullptr));
        pushButtonSync->setText(QApplication::translate("SettingsWindow", "SetSyncOut [\302\265s]\n"
"\350\256\276\347\275\256\345\220\214\346\255\245\350\276\223\345\207\272", nullptr));
        pushButtonSyncDelay->setText(QApplication::translate("SettingsWindow", "SetSyncOutDelay [\302\265s]\n"
"\350\256\276\347\275\256\345\220\214\346\255\245\350\276\223\345\207\272\345\273\266\350\277\237", nullptr));
        pushButtonSignalEnable->setText(QApplication::translate("SettingsWindow", "SetSignalEnable\n"
"\350\256\276\347\275\256\344\277\241\345\217\267\345\220\257\347\224\250", nullptr));
        pushButtonSignalSelection->setText(QApplication::translate("SettingsWindow", "SetSignalSelection\n"
"\350\256\276\347\275\256\344\277\241\345\217\267\351\200\211\346\213\251", nullptr));
        pushButtonSignalWidthMin->setText(QApplication::translate("SettingsWindow", "SetSignalWidthMin[px]\n"
"\350\256\276\347\275\256\344\277\241\345\217\267\345\256\275\345\272\246\346\234\200\345\260\217\345\200\274", nullptr));
        pushButtonSignalWidthMax->setText(QApplication::translate("SettingsWindow", "SetSignalWidthMax[px]\n"
"\350\256\276\347\275\256\344\277\241\345\217\267\345\256\275\345\272\246\346\234\200\345\244\247\345\200\274", nullptr));
        pushButtonSignalStrengthMin->setText(QApplication::translate("SettingsWindow", "SetSignalStrengthMin\n"
"\350\256\276\347\275\256\346\234\200\345\260\217\344\277\241\345\217\267\345\274\272\345\272\246", nullptr));
        pushButtonHeightZ->setText(QApplication::translate("SettingsWindow", "SetROI1HeightZ", nullptr));
        pushButtonStepX->setText(QApplication::translate("SettingsWindow", "SetROI1StepX", nullptr));
        pushButtonOffsetX->setText(QApplication::translate("SettingsWindow", "SetROI1OffsetX", nullptr));
        pushButtonWidthX->setText(QApplication::translate("SettingsWindow", "SetROI1WidthX", nullptr));
        pushButtonOffsetZ->setText(QApplication::translate("SettingsWindow", "SetROI1OffsetZ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsWindow: public Ui_SettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H
