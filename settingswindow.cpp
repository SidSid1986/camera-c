#include "settingswindow.h"
#include "ui_settingswindow.h"
#include "EthernetScannerSDK.h"
#include <QFile>
#include <algorithm>
#include <string>
#include <stdint.h>
#include <algorithm>
#include "EthernetScannerSDKDefine.h"
#include <QTimer>
#pragma execution_character_set("utf-8")


//弹窗就自动刷新获取数据，显示默认值
#include <QShowEvent>

void SettingsWindow::showEvent(QShowEvent* event)
{
    QWidget::showEvent(event);
    on_pushButtonUpdate_clicked(); // 每次show时自动刷新current value
}



SettingsWindow::SettingsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);

    setWindowIcon(QIcon("wenglor.ico"));

    ui->setTriggerSource->setText( "0" );
    ui->setAcquisitionLineTime->setText( "5000" );
    ui->setExposureTime->setText( "100" );

    ui->setSyncOut->setText( "0" );
    ui->setSyncOutDelay->setText( "0" );

    //ui->setSignalEnable->setText( "1" );
    // 添加下拉项
    ui->comboBoxSignalEnable->clear();
    ui->comboBoxSignalEnable->addItem("Profile 1", 1);
    ui->comboBoxSignalEnable->addItem("Profile 2", 2);
    ui->comboBoxSignalEnable->addItem("Profile 1 + Profile 2", 3);

    ui->setSignalSelection->setText( "1" );
    ui->setSignalWidthMin->setText( "0" );
    ui->setSignalWidthMax->setText( "63" );
    ui->setSignalStrengthMin->setText( "0" );

    ui->setHeightZ->setText( "2048" );
    ui->setOffsetZ->setText( "0" );
    ui->setWidthX->setText( "2048" );
    ui->setOffsetX->setText( "0" );
    ui->setStepX->setText( "0" );

    ui->sendRawCommand->setText("SetExposureTime=50");

 ;

    connect(ui->pushButtonTriggerSource, SIGNAL(clicked(bool)), this, SLOT(setTriggerSource()));
    connect(ui->pushButtonExposureTime, SIGNAL(clicked(bool)), this, SLOT(setExposureTime()));
    connect(ui->pushButtonAcquisitionLineTime, SIGNAL(clicked(bool)), this, SLOT(setAcquisitionLineTime()));
    connect(ui->pushButtonSync, SIGNAL(clicked(bool)), this, SLOT(setSyncOut()));
    connect(ui->pushButtonSyncDelay, SIGNAL(clicked(bool)), this, SLOT(setSyncOutDelay()));

    connect(ui->pushButtonHeightZ, SIGNAL(clicked(bool)), this, SLOT(HeightZ()));
    connect(ui->pushButtonOffsetZ, SIGNAL(clicked(bool)), this, SLOT(setOffsetZ()));
    connect(ui->pushButtonWidthX, SIGNAL(clicked(bool)), this, SLOT(setWidthX()));
    connect(ui->pushButtonOffsetX, SIGNAL(clicked(bool)), this, SLOT(setOffsetX()));
    connect(ui->pushButtonStepX, SIGNAL(clicked(bool)), this, SLOT(setStepX()));

    connect(ui->pushButtonSignalEnable, SIGNAL(clicked(bool)), this, SLOT(setSignalEnable()));
    connect(ui->pushButtonSignalSelection, SIGNAL(clicked(bool)),this,SLOT(setSignalSelection()));
    connect(ui->pushButtonSignalWidthMin, SIGNAL(clicked(bool)), this, SLOT(setSignalWidthMin()));
    connect(ui->pushButtonSignalWidthMax, SIGNAL(clicked(bool)), this, SLOT(setSignalwWidthMax()));
    connect(ui->pushButtonSignalStrengthMin, SIGNAL(clicked(bool)), this, SLOT(setSignalStrengthMin()));

    connect(ui->pushButtonResetEncoder, SIGNAL(clicked(bool)), this, SLOT(resetEncoder()));
    connect(ui->pushButtonResetPicCnt, SIGNAL(clicked(bool)), this, SLOT(resetPiccnt()));
    connect(ui->pushButtonresetBaseTime, SIGNAL(clicked(bool)), this, SLOT(resetBaseTime()));
    connect(ui->pushButtonResetSettings, SIGNAL(clicked(bool)), this, SLOT(resetSettings()));

    connect(ui->pushButtonSetAcquisitionStart, SIGNAL(clicked(bool)), this, SLOT(setAcquisitionStart()));
    connect(ui->pushButtonSetAcquisitionStop, SIGNAL(clicked(bool)), this, SLOT(setAcquisitionStop()));

    connect(ui->pushButtonSendASCIICommand, SIGNAL(clicked(bool)), this, SLOT(sendASCIICommand()));

    connect(ui->pushButtonStopResetStart, SIGNAL(clicked(bool)), this, SIGNAL(signalStopResetStart()));

}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::exchangeData( void* pScannerHandle, std::string orderNumber, std::string ip)
{
    m_pScannerHandle = pScannerHandle;
    m_OrderNumber = orderNumber;
    m_IP = ip;
}

void SettingsWindow::setTriggerSource()
{
    std::string cmd = "SetTriggerSource=" + ui->setTriggerSource->toPlainText().toStdString();
    EthernetScanner_WriteData(m_pScannerHandle, (char*)cmd.data(), cmd.length());
    QTimer::singleShot(200, this, SLOT(refreshCurrentValues()));
}

void SettingsWindow::setExposureTime()
{
    int iTemp = atoi(ui->setExposureTime->toPlainText().toStdString().c_str());
    std::string cmd = "SetExposureTime=" + std::to_string(iTemp) ;
    EthernetScanner_WriteData(m_pScannerHandle, (char*)cmd.data(), cmd.length());
    QTimer::singleShot(200, this, SLOT(refreshCurrentValues()));
}

void SettingsWindow::setAcquisitionLineTime()
{
    std::string cmd  = "SetAcquisitionLineTime=" + ui->setAcquisitionLineTime->toPlainText().toStdString() ;
    EthernetScanner_WriteData(m_pScannerHandle, (char*)cmd.data(),  cmd.length());
    // 延迟200毫秒后刷新
    QTimer::singleShot(200, this, SLOT(refreshCurrentValues()));
}


void SettingsWindow::setSyncOut()
{
    std::string cmd  = "SetSyncOut=" + ui->setSyncOut->toPlainText().toStdString() ;
    EthernetScanner_WriteData(m_pScannerHandle, (char*)cmd.data(),  cmd.length());
    QTimer::singleShot(200, this, SLOT(refreshCurrentValues()));
}

void SettingsWindow::setSyncOutDelay()
{
    std::string cmd  = "SetSyncOutDelay=" + ui->setSyncOutDelay->toPlainText().toStdString() ;
    EthernetScanner_WriteData(m_pScannerHandle, (char*)cmd.data(),  cmd.length());
    QTimer::singleShot(200, this, SLOT(refreshCurrentValues()));
}


void SettingsWindow::HeightZ()
{
    std::string cmd  = "SetROI1HeightZ=" + ui->setHeightZ->toPlainText().toStdString() ;
    EthernetScanner_WriteData(m_pScannerHandle, (char*)cmd.data(), cmd.length());
    QTimer::singleShot(200, this, SLOT(refreshCurrentValues()));
}

void SettingsWindow::setOffsetZ()
{
    std::string cmd  = "SetROI1OffsetZ=" + ui->setOffsetZ->toPlainText().toStdString() ;
    EthernetScanner_WriteData(m_pScannerHandle, (char*)cmd.data(), cmd.length());
    QTimer::singleShot(200, this, SLOT(refreshCurrentValues()));
}

void SettingsWindow::setWidthX()
{
    std::string cmd  = "SetROI1WidthX=" + ui->setWidthX->toPlainText().toStdString() ;
    EthernetScanner_WriteData(m_pScannerHandle, (char*)cmd.data(), cmd.length());
    QTimer::singleShot(200, this, SLOT(refreshCurrentValues()));
}

void SettingsWindow::setOffsetX()
{
    std::string cmd  = "SetROI1OffsetX=" + ui->setOffsetX->toPlainText().toStdString() ;
    EthernetScanner_WriteData(m_pScannerHandle, (char*)cmd.data(), cmd.length());
    QTimer::singleShot(200, this, SLOT(refreshCurrentValues()));
}

void SettingsWindow::setStepX()
{
    std::string cmd  = "SetROI1StepX=" + ui->setStepX->toPlainText().toStdString() ;
    EthernetScanner_WriteData(m_pScannerHandle, (char*)cmd.data(), cmd.length());
    QTimer::singleShot(200, this, SLOT(refreshCurrentValues()));
}

void SettingsWindow::setSignalEnable()
{
//    std::string cmd  = "SetSignalEnable="+ ui->setSignalEnable->toPlainText().toStdString();
//    EthernetScanner_WriteData(m_pScannerHandle, (char*)cmd.data(), cmd.length());
//    QTimer::singleShot(200, this, SLOT(refreshCurrentValues()));
       int value = ui->comboBoxSignalEnable->currentData().toInt();
       std::string cmd = "SetSignalEnable=" + std::to_string(value);
       EthernetScanner_WriteData(m_pScannerHandle, (char*)cmd.data(), cmd.length());
       QTimer::singleShot(200, this, SLOT(refreshCurrentValues()));
}

void SettingsWindow::setSignalSelection()
{
    std::string cmd  = "SetSignalSelection=" + ui->setSignalSelection->toPlainText().toStdString();;
    EthernetScanner_WriteData(m_pScannerHandle, (char*)cmd.data(), cmd.length());
}

void SettingsWindow::setSignalWidthMin()
{
    std::string cmd  = "SetSignalWidthMax=" + ui->setSignalWidthMin->toPlainText().toStdString() ;
    EthernetScanner_WriteData(m_pScannerHandle, (char*)cmd.data(), cmd.length());
    QTimer::singleShot(200, this, SLOT(refreshCurrentValues()));
}

void SettingsWindow::setSignalwWidthMax()
{
    std::string cmd  = "SetSignalWidthMax=" + ui->setSignalWidthMax->toPlainText().toStdString() ;
    EthernetScanner_WriteData(m_pScannerHandle, (char*)cmd.data(), cmd.length());
    QTimer::singleShot(200, this, SLOT(refreshCurrentValues()));
}

void SettingsWindow::setSignalStrengthMin()
{
    std::string cmd  = "SetSignalStrengthMin=" + ui->setSignalStrengthMin->toPlainText().toStdString();
    EthernetScanner_WriteData(m_pScannerHandle, (char*)cmd.data(), cmd.length());
    QTimer::singleShot(200, this, SLOT(refreshCurrentValues()));
}

void SettingsWindow::sendASCIICommand()
{
    std::string cmd  = ui->sendRawCommand->toPlainText().toStdString();
    int pos = cmd.find("\n");
    if( pos != std::string::npos)
        cmd.replace(pos,1, "\r" );
    EthernetScanner_WriteData(m_pScannerHandle, (char*)cmd.data(), cmd.length());
    QTimer::singleShot(200, this, SLOT(refreshCurrentValues()));
}


void SettingsWindow::resetEncoder()
{
    std::string cmd = "SetResetEncoder";
    EthernetScanner_WriteData(m_pScannerHandle, (char*)cmd.data(), cmd.length());
    QTimer::singleShot(200, this, SLOT(refreshCurrentValues()));
}

void SettingsWindow::resetPiccnt()
{
    std::string cmd = "SetResetPictureCounter";
    EthernetScanner_WriteData(m_pScannerHandle, (char*)cmd.data(), cmd.length());
    QTimer::singleShot(200, this, SLOT(refreshCurrentValues()));
    }

void SettingsWindow::resetBaseTime()
{
    std::string cmd = "SetResetBaseTimeCounter";
    EthernetScanner_WriteData(m_pScannerHandle, (char*)cmd.data(), cmd.length());
    QTimer::singleShot(200, this, SLOT(refreshCurrentValues()));
}

void SettingsWindow::resetSettings()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "确认重置", "确定要恢复默认设置吗？所有自定义配置将被清除。",
                                QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        std::string cmd = "SetResetSettings";
        EthernetScanner_WriteData(m_pScannerHandle, (char*)cmd.data(), cmd.length());
        QTimer::singleShot(200, this, SLOT(refreshCurrentValues()));
    }

}

void SettingsWindow::setAcquisitionStart()
{
    std::string cmd = "SetAcquisitionStart";
    EthernetScanner_WriteData(m_pScannerHandle, (char*)cmd.data(), cmd.length());
    QTimer::singleShot(200, this, SLOT(refreshCurrentValues()));
}


void SettingsWindow::setAcquisitionStop()
{
    std::string cmd = "SetAcquisitionStop";
    EthernetScanner_WriteData(m_pScannerHandle, (char*)cmd.data(), cmd.length());
    QTimer::singleShot(200, this, SLOT(refreshCurrentValues()));
}


//工具函数
QString signalEnableToText(const std::string& value) {
    if (value == "1") return "Profile 1";
    if (value == "2") return "Profile 2";
    if (value == "3") return "Profile 1 + Profile 2";
    return QString::fromStdString(value); // fallback
}

//刷新获取current
void SettingsWindow::refreshCurrentValues()
{
    char ucScannerData[ETHERNETSCANNER_GETINFOSIZEMAX];
    int iRes = EthernetScanner_GetInfo(m_pScannerHandle, ucScannerData, ETHERNETSCANNER_GETINFOSIZEMAX, (char*)"xml");

    if (iRes > 0)
    {
        std::string xml = std::string(ucScannerData);
        tinyxml2::XMLDocument doc;
        doc.Parse(xml.data());
        if (doc.ErrorID() == 0)
        {
            std::string modelNumber = doc.FirstChildElement("device")->FirstChildElement("general")->FirstChildElement("ordernumber")->GetText();

            std::string triggersource = doc.FirstChildElement("device")->FirstChildElement("settings")->FirstChildElement("triggersource")->FirstChildElement("current")->GetText();
            std::string exposuretime = doc.FirstChildElement("device")->FirstChildElement("settings")->FirstChildElement("exposuretime")->FirstChildElement("current")->GetText();
            std::string acquisitionlinetime = doc.FirstChildElement("device")->FirstChildElement("settings")->FirstChildElement("acquisitionlinetime")->FirstChildElement("current")->GetText();

            std::string widthx = doc.FirstChildElement("device")->FirstChildElement("settings")->FirstChildElement("roi")->FirstChildElement("x1")->FirstChildElement("width")->FirstChildElement("current")->GetText();
            std::string offsetx = doc.FirstChildElement("device")->FirstChildElement("settings")->FirstChildElement("roi")->FirstChildElement("x1")->FirstChildElement("offset")->FirstChildElement("current")->GetText();
            std::string stepx = doc.FirstChildElement("device")->FirstChildElement("settings")->FirstChildElement("roi")->FirstChildElement("x1")->FirstChildElement("step")->FirstChildElement("current")->GetText();
            std::string heightz = doc.FirstChildElement("device")->FirstChildElement("settings")->FirstChildElement("roi")->FirstChildElement("z1")->FirstChildElement("height")->FirstChildElement("current")->GetText();
            std::string offsetz = doc.FirstChildElement("device")->FirstChildElement("settings")->FirstChildElement("roi")->FirstChildElement("z1")->FirstChildElement("offset")->FirstChildElement("current")->GetText();

            std::string syncout = doc.FirstChildElement("device")->FirstChildElement("settings")->FirstChildElement("syncout")->FirstChildElement("current")->GetText();
            std::string syncoutdelay = doc.FirstChildElement("device")->FirstChildElement("settings")->FirstChildElement("syncoutdelay")->FirstChildElement("current")->GetText();

            std::string signalenable = doc.FirstChildElement("device")->FirstChildElement("settings")->FirstChildElement("protocol")->FirstChildElement("profile")->FirstChildElement("signal")->FirstChildElement("enable")->FirstChildElement("current")->GetText();
            std::string signalselection = doc.FirstChildElement("device")->FirstChildElement("settings")->FirstChildElement("signalselection")->FirstChildElement("current")->GetText();
            std::string signalwidthmin = doc.FirstChildElement("device")->FirstChildElement("settings")->FirstChildElement("signalwidthmin")->FirstChildElement("current")->GetText();
            std::string signalwidthmax = doc.FirstChildElement("device")->FirstChildElement("settings")->FirstChildElement("signalwidthmax")->FirstChildElement("current")->GetText();
            std::string signalstrengthmin = doc.FirstChildElement("device")->FirstChildElement("settings")->FirstChildElement("signalstrengthmin")->FirstChildElement("current")->GetText();

            ui->getTriggersource->setText(triggersource.data());
            ui->getExposureTime->setText(exposuretime.data());
            ui->getAcquisitionLineTime->setText(acquisitionlinetime.data());

            ui->getHeightZ->setText(heightz.data());
            ui->getOffsetZ->setText(offsetz.data());

            ui->getWidthX->setText(widthx.data());
            ui->getOffsetX->setText(offsetx.data());
            ui->getStepX->setText(stepx.data());

            ui->getSyncOut->setText(syncout.data());
            ui->getSyncOutDelay->setText(syncoutdelay.data());

            //ui->getSignalEnable->setText(signalenable.data());
            //工具函数处理
            ui->getSignalEnable->setText(signalEnableToText(signalenable));
            // 同步Set value的下拉框
            int idx = ui->comboBoxSignalEnable->findData(QString::fromStdString(signalenable));
            if (idx >= 0) {
                ui->comboBoxSignalEnable->setCurrentIndex(idx);
            }


            ui->getSignalSelection->setText(signalselection.data());
            ui->getSignalWidthMin->setText(signalwidthmin.data());
            ui->getSignalWidthMax->setText(signalwidthmax.data());
            ui->getSignalStrengthMin->setText(signalstrengthmin.data());

            double heightZ = atoi(heightz.data());
            double widthX = atoi(widthx.data());

            double exposureTime = atoi(exposuretime.data());
            int exposuretimeinHz = 1000000 / exposureTime;

            int iMaxMeasureRate;
            if (modelNumber.substr(0, 4) == "MLWL")
            {
                iMaxMeasureRate = floor((149359.5 * pow(heightZ, -0.8678007147)) - 20);
                ui->lineEditMaxMeasureRate->setText(QString::number(std::min(iMaxMeasureRate, exposuretimeinHz)));
            }
            else if (modelNumber.substr(0, 4) == "MLSL")
            {
                iMaxMeasureRate = floor((1000000 / ((0.003458273 * widthX + 0.073443424) * heightZ + 56)) * 0.95);
                ui->lineEditMaxMeasureRate->setText(QString::number(std::min(iMaxMeasureRate, exposuretimeinHz)));
            }
        }
        else
        {
            QMessageBox::warning(this, "Warning", "Error in parsing XML!!!");
        }
    }
    else
    {
        QMessageBox::critical(this, "Error", "No Valid XML-Packet!!!");
    }
}
void SettingsWindow::on_pushButtonUpdate_clicked()
{
    refreshCurrentValues();
}

//void SettingsWindow::on_pushButtonUpdate_clicked()
//{
//    char   ucScannerData[ETHERNETSCANNER_GETINFOSIZEMAX];
//    int iRes;
//    iRes = EthernetScanner_GetInfo(m_pScannerHandle, ucScannerData, ETHERNETSCANNER_GETINFOSIZEMAX, (char*)"xml");

//    if (iRes > 0)
//    {
//        std::string xml = std::string(ucScannerData);
//        tinyxml2::XMLDocument doc;
//        doc.Parse( xml.data() );
//        if( doc.ErrorID() == 0 )
//        {
//            std::string  modelNumber = doc.FirstChildElement("device")->FirstChildElement("general")->FirstChildElement("ordernumber")->GetText();

//            std::string  triggersource = doc.FirstChildElement( "device" )->FirstChildElement( "settings" )->FirstChildElement("triggersource")->FirstChildElement("current")->GetText();
//            std::string  exposuretime = doc.FirstChildElement( "device" )->FirstChildElement( "settings" )->FirstChildElement("exposuretime")->FirstChildElement("current")->GetText();
//            std::string  acquisitionlinetime = doc.FirstChildElement( "device" )->FirstChildElement( "settings" )->FirstChildElement("acquisitionlinetime")->FirstChildElement("current")->GetText();

//            std::string  widthx = doc.FirstChildElement( "device" )->FirstChildElement( "settings" )->FirstChildElement("roi")->FirstChildElement("x1")->FirstChildElement("width")->FirstChildElement("current")->GetText();
//            std::string  offsetx = doc.FirstChildElement( "device" )->FirstChildElement( "settings" )->FirstChildElement("roi")->FirstChildElement("x1")->FirstChildElement("offset")->FirstChildElement("current")->GetText();
//            std::string  stepx = doc.FirstChildElement( "device" )->FirstChildElement( "settings" )->FirstChildElement("roi")->FirstChildElement("x1")->FirstChildElement("step")->FirstChildElement("current")->GetText();
//            std::string  heightz = doc.FirstChildElement( "device" )->FirstChildElement( "settings" )->FirstChildElement("roi")->FirstChildElement("z1")->FirstChildElement("height")->FirstChildElement("current")->GetText();
//            std::string  offsetz = doc.FirstChildElement( "device" )->FirstChildElement( "settings" )->FirstChildElement("roi")->FirstChildElement("z1")->FirstChildElement("offset")->FirstChildElement("current")->GetText();

//            std::string  syncout = doc.FirstChildElement( "device" )->FirstChildElement( "settings" )->FirstChildElement("syncout")->FirstChildElement("current")->GetText();
//            std::string  syncoutdelay = doc.FirstChildElement( "device" )->FirstChildElement( "settings" )->FirstChildElement("syncoutdelay")->FirstChildElement("current")->GetText();

//            std::string  signalenable = doc.FirstChildElement( "device" )->FirstChildElement( "settings" )->FirstChildElement("protocol")->FirstChildElement("profile")->FirstChildElement("signal")->FirstChildElement("enable")->FirstChildElement("current")->GetText();
//            std::string  signalselection = doc.FirstChildElement( "device" )->FirstChildElement( "settings" )->FirstChildElement("signalselection")->FirstChildElement("current")->GetText();
//            std::string  signalwidthmin = doc.FirstChildElement( "device" )->FirstChildElement( "settings" )->FirstChildElement("signalwidthmin")->FirstChildElement("current")->GetText();
//            std::string  signalwidthmax = doc.FirstChildElement( "device" )->FirstChildElement( "settings" )->FirstChildElement("signalwidthmax")->FirstChildElement("current")->GetText();
//            std::string  signalstrengthmin = doc.FirstChildElement( "device" )->FirstChildElement( "settings" )->FirstChildElement("signalstrengthmin")->FirstChildElement("current")->GetText();

//            ui->getTriggersource->setText(triggersource.data());
//            ui->getExposureTime->setText(exposuretime.data());
//            ui->getAcquisitionLineTime->setText(acquisitionlinetime.data());

//            ui->getHeightZ->setText(heightz.data());
//            ui->getOffsetZ->setText(offsetz.data());

//            ui->getWidthX->setText(widthx.data());
//            ui->getOffsetX->setText(offsetx.data());
//            ui->getStepX->setText(stepx.data());

//            ui->getSyncOut->setText(syncout.data());
//            ui->getSyncOutDelay->setText(syncoutdelay.data());

//            ui->getSignalEnable->setText(signalenable.data());
//            ui->getSignalSelection->setText(signalselection.data());
//            ui->getSignalWidthMin->setText(signalwidthmin.data());
//            ui->getSignalWidthMax->setText(signalwidthmax.data());
//            ui->getSignalStrengthMin->setText(signalstrengthmin.data());

//            double heightZ =  atoi(heightz.data());
//            double widthX = atoi(widthx.data());

//            double exposureTime = atoi(exposuretime.data());
//            int exposuretimeinHz = 1000000/exposureTime;

//            int iMaxMeasureRate;
//            if (modelNumber.substr(0, 4) == "MLWL")
//            {
//                iMaxMeasureRate = floor((149359.5*pow(heightZ,-0.8678007147))-20);
//                ui->lineEditMaxMeasureRate->setText(QString::number( std::min(iMaxMeasureRate,exposuretimeinHz) ));
//            }
//            else if (modelNumber.substr(0, 4) == "MLSL")
//            {
//                iMaxMeasureRate = floor((1000000/((0.003458273*widthX + 0.073443424) * heightZ + 56))*0.95);
//                ui->lineEditMaxMeasureRate->setText(QString::number( std::min(iMaxMeasureRate,exposuretimeinHz) ));
//            }
//        }
//        else
//        {
//            QMessageBox::warning(this, "Warning", "Error in parsing XML!!!" );
//        }
//    }
//    else
//    {
//        QMessageBox::critical(this, "Error", "No Valid XML-Packet!!!" );
//    }
//}

void SettingsWindow::on_pushButtonSaveXML_clicked()
{
    std::string fileName = m_OrderNumber + "_" + m_IP + ".xml";
    QFile File(fileName.data());
    if(File.exists())
        File.remove();

    QTextStream XMLStream(&File);
    if(!File.open(QIODevice::ReadWrite))
    {
        QMessageBox::critical(this, "Error", "Error: Cannnot open the XML file" );
        return;
    }

    char   ucScannerData[ETHERNETSCANNER_GETINFOSIZEMAX];
    int iRes;
    iRes = EthernetScanner_GetInfo(m_pScannerHandle, ucScannerData, ETHERNETSCANNER_GETINFOSIZEMAX, (char*)"xml");

    if (iRes > 0)
    XMLStream << ucScannerData;
    XMLStream.flush();

    File.close();
}
