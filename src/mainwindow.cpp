#pragma execution_character_set("utf-8")
#include "mainwindow.h"
#include <sstream>
#include "xlsxdocument.h"
#include <QFileDialog>

#if defined (_MSC_VER)
#include <Windows.h>
#else
#include <unistd.h>
typedef uint32_t    DWORD;
#define Sleep(n) usleep(n*1000)
DWORD GetTickCount(void)
{
    struct timespec ts;
    unsigned theTick = 0U;
    clock_gettime( CLOCK_MONOTONIC, &ts );
    theTick  = ts.tv_nsec/ 1000000;
    theTick += ts.tv_sec * 1000;
    return theTick;
}
#endif

#define tstr(a) #a
#define xstr(a) tstr(a)
#define APP_VERSION C_MAJOR.C_MINOR.C_BUILD
#define VERSION_STRING xstr(APP_VERSION)

void getImageThread(void* lpParameter);


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

    setWindowIcon(QIcon("wenglor.ico"));

    m_pSettings = new SettingsWindow();

    connect(pushButtonConnect, SIGNAL(clicked(bool)), this, SLOT(ScannerConnect()));
    connect(pushButtonDisconnect, SIGNAL(clicked(bool)), this, SLOT(ScannerDisconnect()));
    connect(pushButtonSettings, SIGNAL(clicked(bool)),this, SLOT(showSettingsWindow()));
    connect(pushButtonResetPicCnt,SIGNAL(clicked(bool)), this, SLOT(resetPictureCounter()));
    connect(pushButtonDLLFifoReset,SIGNAL(clicked(bool)), this, SLOT(resetDllFifo()));
    connect(pushButtonSaveProfiles, SIGNAL(clicked(bool)), this, SLOT(SaveProfiles()));
    connect(pushButtonGetPropertyValue, SIGNAL(clicked(bool)), this, SLOT(GetPropertyValue()));
    connect(pushButtonSetMeasuringRate, SIGNAL(clicked(bool)), this, SLOT(SetMeasuringRate()));

    connect(this, SIGNAL(UpdatePixmap(QPixmap)), this, SLOT(RefreshPixmap(QPixmap)));

    connect(m_pSettings, SIGNAL(signalStopResetStart()), this, SLOT(StopResetStart()));

    connect(&m_Timer, SIGNAL(timeout()), this, SLOT(onTimer()));
   connect(pushButtonSaveExcel, SIGNAL(clicked(bool)), this, SLOT(SaveProfilesAsExcel()));
   connect(pushButtonScreenshot, SIGNAL(clicked()), this, SLOT(onScreenshot()));
    connect(pushButtonReboot, SIGNAL(clicked()), this, SLOT(rebootCamera()));

     connect(pushButtonSetMode, SIGNAL(clicked()), this, SLOT(setMode()));
    unsigned char ucBuffer[1024];
    char str[1024];
    EthernetScanner_GetVersion(ucBuffer, 1024);
    sprintf(str, "%s", ucBuffer);
    QMainWindow::setWindowTitle("Free测试");

    lineEditVersion->setText(str);

    lineEditGuiVersion->setText(VERSION_STRING);

    m_pImageThread = nullptr;

    m_Timer.start(1000);

    m_hScanner = nullptr;
    m_strSerialNummber = "....";
    m_strZstart = "....";
    m_strZrange = "....";
    m_strXRangeAtStart = "....";
    m_strXRangeAtEnd = "....";
    m_strWidthX = "....";
    m_strHeightZ = "....";
    m_strSerialNummber = "....";
    m_strOrderNumber = "....";
    m_strProductVersion = "....";
    m_strProducer = "....";
    m_strDescriptor = "....";
    m_strHardwareVersion = "....";
    m_strFWVersion = "....";
    m_strMAC = "....";
    m_iPicCntErr = 0;
    m_dwScanner_Frequency = 0;
    m_usPicCnt = 0;

    m_iEncoderHTL=0;
    m_iEncoderTTL=0;
    m_iCPUFiFo=0;
    m_iDLLFiFo=0;
    m_iScannerState=0;

    checkBoxActivateDisplay->setChecked(true);

    m_SaveLog = false;
    m_iNumberOfProfilesToSave = 1;

    m_bScannerConnectStatus = false;

    m_Event = neosmart::CreateEvent(true,true);


    comboBoxPropertyName->addItem("温度", "GetTemperature");
     comboBoxPropertyName->addItem("模式", "GetCameraMode");
      comboBoxPropertyName->addItem("触发源", "GetTriggerSource");
      comboBoxPropertyName->addItem("采集线时间", "GetAcquisitionLineTime");
      comboBoxPropertyName->addItem("曝光时间", "GetExposureTime");
    comboBoxPropertyName->addItem("扫描仪状态", "GetScannerState");
    comboBoxPropertyName->addItem("固件版本","GetFirmwareVersion");
    comboBoxPropertyName->addItem("序列码","GetSerialNumber");
    comboBoxPropertyName->addItem("MAC地址", "GetMAC");
    comboBoxPropertyName->addItem("Z起始值", "GetWorkingRangeZStart");
    comboBoxPropertyName->addItem("Z结束值", "GetWorkingRangeZEnd");
    comboBoxPropertyName->addItem("X起始值", "GetFieldWidthXStart");
    comboBoxPropertyName->addItem("X结束值", "GetFieldWidthXEnd");
    comboBoxPropertyName->addItem("摄像头运行", "GetCameraRunning");
    comboBoxPropertyName->addItem("IO状态", "GetIOState");
    comboBoxPropertyName->setCurrentIndex(0);

    //mode
    //comboBoxMode->addItem("请选择模式", -1);
//    comboBoxMode->addItem("Profile 轮廓", 0);
//    comboBoxMode->addItem("Camera images 图像 ", 1);
    //comboBoxMode->setCurrentIndex(0);


}

MainWindow::~MainWindow()
{

}

void MainWindow::closeEvent(QCloseEvent *event)
{
    m_pSettings->hide();
    ScannerDisconnect();
    delete m_pSettings;
}

void MainWindow::showSettingsWindow()
{
    if(m_bScannerConnectStatus)
    {
        m_pSettings->activateWindow();
        m_pSettings->show();
        m_pSettings->raise();
        m_pSettings->setFocus();
    }
    else
    {
        QMessageBox::critical(this, "Error", "Sensor should be connected" );
    }
}

void MainWindow::ScannerConnect(void)
{
    if (m_hScanner == nullptr)
    {
        m_strScannerIP = lineEditIp->text().toUtf8().constData();

        // this is receive timeout, the DLL will close the connection if no data is received.
        // use 0 to keep the connection alive in case of no data transmition
        m_strScannerTimeOut = lineEditTimeOut->text().toUtf8().constData();

        //start the connection to the Scanneratoi(m_strScanner1TimeOut)
        m_hScanner = EthernetScanner_Connect((char*)m_strScannerIP.c_str(), (char*) "32001", atoi(m_strScannerTimeOut.c_str()));

        //if no valid value: ERROR
        if (m_hScanner == nullptr)
        {
            QMessageBox::critical(this, "Error", "Error: EthernetScanner_Connect: nullptr-Pointer" );
            m_hScanner = nullptr;
            return;
        }

        //Wait for valid connection to scanner
        DWORD time = GetTickCount();
        int ConnectionStatus = 0;
        m_iPicCntErr = 0;
        while(ConnectionStatus != ETHERNETSCANNER_TCPSCANNERCONNECTED)
        {
            //current state of the connection
            EthernetScanner_GetConnectStatus(m_hScanner, &ConnectionStatus);
            //Detect the timeout
            if( (GetTickCount()-time) > 1000 )
            {
                m_hScanner = EthernetScanner_Disconnect(m_hScanner);
                QMessageBox::critical(this, "Error", "Error: EthernetScanner_Connect: Error in connection" );
                m_hScanner = nullptr;
                return;
            }
        }


        int iRes = -1;

        iRes = EthernetScanner_GetInfo(m_hScanner, m_cScannerInfo, ETHERNETSCANNER_GETINFOSIZEMAX, (char*)"xml");
        if(iRes > 0)
        {
            GetInfoParser(m_cScannerInfo);
            m_CImage = new CImage( labelImage->width(),(int) labelImage->height());
            m_CImage->fill(Qt::GlobalColor::black);
            m_CImage->setImageParameters(m_strZstart,m_strZrange,m_strXRangeAtStart,m_strXRangeAtEnd,m_strWidthX,m_strHeightZ);
            labelImage->setPixmap(*m_CImage);

            std::string serial1 = m_strOrderNumber + " " + m_strSerialNummber + " " + m_strDescriptor + " " + m_strProducer;
            std::string serial2 = "Product version: " + m_strProductVersion + "  HW: " + m_strHardwareVersion + "  FW: " + m_strFWVersion;
            std::string serial3 = "Working range Z start: " + m_strZstart + "  Working range: " + m_strZrange + "  Field width X start: " + m_strXRangeAtStart + "  Field width X end: " + m_strXRangeAtEnd;;
            lineEditSerial1->setText(serial1.data());
            lineEditSerial2->setText(serial2.data());
            lineEditSerial3->setText(serial3.data());

            m_pSettings->exchangeData(m_hScanner, m_strOrderNumber, m_strScannerIP);

            m_bDrawingThreadExit = false;
            m_pImageThread = new std::thread(getImageThread,this);

            // 重新添加下拉项
             comboBoxMode->clear();
             comboBoxMode->addItem("Profile 轮廓", 0);
             comboBoxMode->addItem("Camera images 图像", 1);
            //查询mode
            syncCameraModeFromDevice();
        }
        else
        {
            //XML Error
        }

    }
}

void MainWindow::ScannerDisconnect(void)
{
    neosmart::SetEvent(m_Event);

    m_bDrawingThreadExit = true;

    if(m_pImageThread)
        m_pImageThread->join();
    m_pImageThread = nullptr;

    if (m_hScanner)
    {
        EthernetScanner_Disconnect(m_hScanner);
        m_hScanner = nullptr;
    }
    m_pSettings->exchangeData(nullptr,"", "");

    //clear comboBox
    comboBoxMode->clear();


    lineEditStatus->setText("已断开");
    lineEditSerial1->setText("...");
    lineEditSerial2->setText("...");
    lineEditSerial3->setText("...");
    lineEditFrequency->setText("...");
    lineEditFiFo->setText("...");
    lineEditMeasureRate->setText("...");
    lineEditMeasureRate->setStyleSheet("QLineEdit {background-color: rgb(240, 240, 240);}");
    labelHTLEncoder->setText("...");
    labelTTLEncoder->setText("...");
    // 新增：断开时清空画面
    labelImage->clear();
    labelImage->setText("Scanner Image");
    labelImage->setAlignment(Qt::AlignCenter);
    m_bScannerConnectStatus = false;

}


void getImageThread(void* lpParameter)
{
    MainWindow *pMainWindow = (MainWindow *)lpParameter;

    QTime time;
    time.start();

    int  iNumberOfSavedProfiles = 0;

    char SaveLogBuf[1024];

    char chRetBuf[100];
    int  iRetVal;

    if (pMainWindow != nullptr)
    {
        //chech the valid value of the Scanner-Handle: nullptr is not valid, otherwise is OK
        while (pMainWindow->m_hScanner)
        {

            neosmart::WaitForEvent(pMainWindow->m_Event,-1);

            if(pMainWindow->m_bDrawingThreadExit)
            {
                break;
            }
            int iPicCnt = 0;

            //EthernetScanner_GetXZIExtended: the Data are linearized
            int dataLength = EthernetScanner_GetXZIExtended( pMainWindow->m_hScanner,
                                                             pMainWindow->m_dScannerBufferX,
                                                             pMainWindow->m_dScannerBufferZ,
                                                             pMainWindow->m_iScannerBufferI,
                                                             pMainWindow->m_iScannerBufferPeakWidth,
                                                             ETHERNETSCANNER_SCANXMAX * ETHERNETSCANNER_PEAKSPERCMOSSCANLINEMAX,
                                                             &pMainWindow->m_uScannerEncoder,
                                                             &pMainWindow->m_ucScannerDigitalInputs,
                                                             1000,
                                                             nullptr,
                                                             0,
                                                             &iPicCnt);

            if(dataLength == ETHERNETSCANNER_ERROR || dataLength == 0)
            {
                if(pMainWindow->m_bDrawingThreadExit)
                {
                    break;
                }
                continue;
            }

            pMainWindow->m_iLengthReceivedData = dataLength;
            pMainWindow->m_picCntMutex.lock();
            pMainWindow->m_dwScanner_Frequency++;
            pMainWindow->m_picCntMutex.unlock();

            //Save the data in PCL format
            if(pMainWindow->m_SaveLog)
            {

                iNumberOfSavedProfiles++;
                for(int i = 0; i < pMainWindow->m_iLengthReceivedData; i++ )
                {
                    sprintf(SaveLogBuf, "%-12.4f\t%04d\t%-12.4f\t%d\n",
                        pMainWindow->m_dScannerBufferX[i],
                        pMainWindow->m_uScannerEncoder,
                        pMainWindow->m_dScannerBufferZ[i],
                        pMainWindow->m_iScannerBufferI[i]);
                    *(pMainWindow->m_pDebugStream)<<SaveLogBuf;
                }
                if (iNumberOfSavedProfiles >= pMainWindow->m_iNumberOfProfilesToSave)
                {
                    pMainWindow->m_SaveLog = false;
                    pMainWindow->m_pDebugStream->flush();
                    pMainWindow->m_pFile->close();
                    delete pMainWindow->m_pDebugStream;
                    delete pMainWindow->m_pFile;
                    iNumberOfSavedProfiles = 0;
                }
            }

            //check the Picutre counter if we have a missing scan
            //Picute counter can be read from the function EthernetScanner_GetXZIExtended
            //or using the function EthernetScanner_ReadData in scan mode
            //see the weCat3D Interface protocol
            if (iPicCnt - pMainWindow->m_usPicCnt != 1)
            {
                if( (pMainWindow->m_usPicCnt != 0) && (pMainWindow->m_usPicCnt != 0xFFFF) )
                {
                    if(pMainWindow->m_iPicCntErr > 0)
                    {
                    }
                    pMainWindow->m_iPicCntErr++;
                }
            }
            pMainWindow->m_usPicCnt = iPicCnt;

            //read the Encoder values using the function EthernetScanner_ReadData
            iRetVal = EthernetScanner_ReadData(pMainWindow->m_hScanner, (char*) "EncoderHTL", chRetBuf, 100, -1);
            if(iRetVal == ETHERNETSCANNER_READDATAOK)
            {
                pMainWindow->m_iEncoderHTL = atoll(chRetBuf);
            }

            iRetVal = EthernetScanner_ReadData(pMainWindow->m_hScanner, (char*) "EncoderTTL", chRetBuf, 100, -1);
            if(iRetVal == ETHERNETSCANNER_READDATAOK)
            {
                pMainWindow->m_iEncoderTTL = atoll(chRetBuf);
            }

            //CPUFIFO shows the internal FiFO state in the scanner, if the CPUFiFo is increasing, it  means
            //that the scanner is generating data more than what it can transfer.
            //please note that the maximum data transfer in the scanner is 30 MByte/s
            //If you want to increase the output rate of the scanner, beside decreasinf the ROI size, remember to switch off
            // non necessary data content like peak end position and peak width
            iRetVal = EthernetScanner_ReadData(pMainWindow->m_hScanner, (char*) "CPUFiFo", chRetBuf, 100, -1);
            if(iRetVal == ETHERNETSCANNER_READDATAOK)
            {
                pMainWindow->m_iCPUFiFo = atoi(chRetBuf);
            }

            //ScannerState is used in this example to check if the scanner is over triggered
            iRetVal = EthernetScanner_ReadData(pMainWindow->m_hScanner, (char*) "ScannerState", chRetBuf, 100, -1);
            if(iRetVal == ETHERNETSCANNER_READDATAOK)
            {
                pMainWindow->m_iScannerState = atoi(chRetBuf);
            }

            pMainWindow->m_iDLLFiFo = EthernetScanner_GetDllFiFoState(pMainWindow->m_hScanner);

            if ( time.elapsed() > 100)
            {
                if(pMainWindow->checkBoxActivateDisplay->isChecked())
                {
                    pMainWindow->m_CImage->drawImage(pMainWindow->m_dScannerBufferX,
                                                     pMainWindow->m_dScannerBufferZ,
                                                     pMainWindow->m_iScannerBufferI,
                                                     pMainWindow->m_iLengthReceivedData);

                    emit pMainWindow->UpdatePixmap(*pMainWindow->m_CImage);
                }
                time.start();
            }
        }
    }
    return;
}


void MainWindow::StopResetStart()
{
    //this code is an example on what is the best behaviour to reset the Picture counter or any other counter in the scanner.
    //normally when the client sends SetResetPicutreCounter command, there could be already scans in the DLL
    //FiFo or in the TCP stack in the operating system that are transmited before the scanner received the
    //command. Thus it is importent when reseting a counter to do the follwing:
    // 1. Stop Acquistion
    // 2. make sure the scanner does not send any new scans and the DLL FiFo is empty
    // 3. send the appropriate counter reset command
    // 4. Start acquisition
    // after that, the scans will be transmitted with new counter value

    //Reset event
    neosmart::ResetEvent(m_Event);

    //send stop
    EthernetScanner_WriteData(m_hScanner, (char*) "SetAcquisitionStop\r", strlen("SetAcquisitionStop\r"));

    //clear DLL FiFo buffer
    while(true)
    {
        int iRet = EthernetScanner_GetXZIExtended( m_hScanner,
                                                   m_dScannerBufferX,
                                                   m_dScannerBufferZ,
                                                   m_iScannerBufferI,
                                                   m_iScannerBufferPeakWidth,
                                                   ETHERNETSCANNER_SCANXMAX * ETHERNETSCANNER_PEAKSPERCMOSSCANLINEMAX,
                                                   nullptr,
                                                   nullptr,
                                                   1000,
                                                   nullptr,
                                                   0,
                                                   nullptr);
        if(iRet == -1)
            break;

    }
    //send reset
    EthernetScanner_WriteData(m_hScanner, (char*) "SetResetPictureCounterr\rSetResetBaseTimeCounter\r", strlen("SetResetPictureCounterr\rSetResetBaseTimeCounter\r"));

    //set event
    neosmart::SetEvent(m_Event);

    //send start
    EthernetScanner_WriteData(m_hScanner, (char*) "SetAcquisitionStart\r", strlen("SetAcquisitionStart\r"));
}


void MainWindow::RefreshPixmap(QPixmap image)
{
    labelImage->setPixmap(image);
    labelImage->show();
}

void MainWindow::GetInfoParser(char *chGetInfo)
{
    std::string xml = std::string(chGetInfo);
    tinyxml2::XMLDocument doc;
    doc.Parse( xml.data() );
    if( doc.ErrorID() == 0 )
    {
        m_strOrderNumber = doc.FirstChildElement( "device" )->FirstChildElement( "general" )->FirstChildElement("ordernumber")->GetText();
        m_strProductVersion = doc.FirstChildElement( "device" )->FirstChildElement( "general" )->FirstChildElement("productversion")->GetText();
        m_strProducer = doc.FirstChildElement( "device" )->FirstChildElement( "general" )->FirstChildElement("producer")->GetText();
        m_strDescriptor = doc.FirstChildElement( "device" )->FirstChildElement( "general" )->FirstChildElement("description")->GetText();
        m_strHardwareVersion = doc.FirstChildElement( "device" )->FirstChildElement( "general" )->FirstChildElement("hardwareversion")->FirstChildElement("general")->GetText();
        m_strFWVersion = doc.FirstChildElement( "device" )->FirstChildElement( "general" )->FirstChildElement("firmwareversion")->FirstChildElement("general")->GetText();
        m_strSerialNummber = doc.FirstChildElement( "device" )->FirstChildElement( "general" )->FirstChildElement("serialnumber")->GetText();
        m_strMAC = doc.FirstChildElement( "device" )->FirstChildElement( "general" )->FirstChildElement("mac")->GetText();
        m_strZstart = doc.FirstChildElement( "device" )->FirstChildElement( "general" )->FirstChildElement("workingrange_z_start")->GetText();
        m_strZrange = doc.FirstChildElement( "device" )->FirstChildElement( "general" )->FirstChildElement("measuringrange_z")->GetText();
        m_strXRangeAtStart = doc.FirstChildElement( "device" )->FirstChildElement( "general" )->FirstChildElement("fieldwidth_x_start")->GetText();
        m_strXRangeAtEnd = doc.FirstChildElement( "device" )->FirstChildElement( "general" )->FirstChildElement("fieldwidth_x_end")->GetText();
        m_strWidthX = doc.FirstChildElement( "device" )->FirstChildElement( "general" )->FirstChildElement("pixel_x_max")->GetText();
        m_strHeightZ = doc.FirstChildElement( "device" )->FirstChildElement( "general" )->FirstChildElement("pixel_z_max")->GetText();
    }
    else
    {
        //parse error!!!
    }
}


void MainWindow::onTimer(void)
{

    int ConnectionStatus = 0;
    m_picCntMutex.lock();
    m_iCnt += m_dwScanner_Frequency;
    if (m_hScanner)
    {
        EthernetScanner_GetConnectStatus(m_hScanner, &ConnectionStatus);
        if(ConnectionStatus == ETHERNETSCANNER_TCPSCANNERCONNECTED)
        {
            m_bScannerConnectStatus = true;
            lineEditStatus->setText("连接");
        }
        else if(ConnectionStatus == ETHERNETSCANNER_TCPSCANNERDISCONNECTED)
        {
            m_bScannerConnectStatus = false;
            lineEditStatus->setText("已断开");
        }

        std::stringstream ss;
        ss << (float)m_dwScanner_Frequency << " Hz" << "  PicCntErr: " << m_iPicCntErr << "  Cnt: " << m_iCnt;
        lineEditFrequency->setText(ss.str().c_str());
        m_dwScanner_Frequency = 0;
        m_picCntMutex.unlock();

        QString qstrFiFo = "CPU FiFo: " + QString::number(m_iCPUFiFo) + "   DLL FiFo: " + QString::number(m_iDLLFiFo);
        lineEditFiFo->setText(qstrFiFo);

        labelHTLEncoder->setText(QString::number(m_iEncoderHTL));

        labelTTLEncoder->setText(QString::number(m_iEncoderTTL));

        bool bScannerTriggerState = CHECK_BIT(m_iScannerState,5);

         if(bScannerTriggerState)
        {
            lineEditMeasureRate->setText("Too fast");
            lineEditMeasureRate->setStyleSheet("QLineEdit {background: red;}");

        }
        else
        {
            lineEditMeasureRate->setText("Ok");
            lineEditMeasureRate->setStyleSheet("QLineEdit {background: green;}");
        }

    }
    else{
        lineEditStatus->setText("已断开");
        m_picCntMutex.unlock();
    }
}

void MainWindow::resetPictureCounter()
{
    m_iPicCntErr = 0;
    m_iCnt = 0;
}

void MainWindow::resetDllFifo()
{
    EthernetScanner_ResetDllFiFo(m_hScanner);
}

//void MainWindow::SaveProfiles()
//{
//    qDebug() << "SaveProfiles called!";
//    m_iNumberOfProfilesToSave = atoi(lineEditNumberOfProfilesToSave->text().toUtf8().constData());
//    m_pFile = new QFile("ScanData.txt");
//    if(m_pFile->exists())
//        m_pFile->remove();
//    m_pDebugStream = new QTextStream(m_pFile);
//    if(!m_pFile->open(QIODevice::ReadWrite))
//    {
//        QMessageBox::critical(this, "Error", "Error: Cannnot open the debug file" );
//        return;
//    }
//    m_SaveLog = true;
//    qDebug() << "Current path:" << QDir::currentPath();
//}

    void MainWindow::SaveProfiles()
    {
        if (m_hScanner == nullptr) {
              QMessageBox::warning(this, tr("disconnected"), tr("please connected first"));
              return;
        }

        // 1. 弹出保存文件对话框
        QString filename = QFileDialog::getSaveFileName(this, tr("保存为TXT"), "", tr("文本文件 (*.txt)"));
        if (filename.isEmpty())
            return;

        if (!filename.endsWith(".txt", Qt::CaseInsensitive))
            filename += ".txt";

        // 2. 打开文件
        m_pFile = new QFile(filename);
        if(m_pFile->exists())
            m_pFile->remove();
        if(!m_pFile->open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox::critical(this, "Error", "Error: Cannot open the debug file" );
            delete m_pFile;
            m_pFile = nullptr;
            return;
        }

        // 3. 写表头
        m_pDebugStream = new QTextStream(m_pFile);
        *m_pDebugStream << "X\tY\tZ\tI\n";

        // 4. 设置保存开关
        m_SaveLog = true;

        // 如果你之前有m_iNumberOfProfilesToSave等设置，也保留
        m_iNumberOfProfilesToSave = atoi(lineEditNumberOfProfilesToSave->text().toUtf8().constData());
        qDebug() << "Number of profiles to save:" << m_iNumberOfProfilesToSave;
    }

//void MainWindow::GetPropertyValue()
//{
//    char chRetBuf[ETHERNETSCANNER_GETINFOSIZEMAX];
//    int iCahsTimeout = lineEditCashTime->text().toInt();
//    std::string cmd = lineEditPropertyName->text().toStdString();
//    int iRetVal = EthernetScanner_ReadData(m_hScanner,(char*) cmd.data(),chRetBuf, ETHERNETSCANNER_GETINFOSIZEMAX, iCahsTimeout);
//    if(iRetVal == ETHERNETSCANNER_READDATAOK)
//        lineEditPropertyValue->setText(chRetBuf);
//    else
//        lineEditPropertyValue->setText(QString::number(iRetVal));
//}
void MainWindow::GetPropertyValue()
{
    char chRetBuf[ETHERNETSCANNER_GETINFOSIZEMAX];
    int iCahsTimeout = lineEditCashTime->text().toInt();
    QString cmd = comboBoxPropertyName->currentData().toString();   // 获取当前选中的命令
    int iRetVal = EthernetScanner_ReadData(m_hScanner, cmd.toUtf8().data(), chRetBuf, ETHERNETSCANNER_GETINFOSIZEMAX, iCahsTimeout);
    if(iRetVal == ETHERNETSCANNER_READDATAOK)
        lineEditPropertyValue->setText(chRetBuf);
    else
        lineEditPropertyValue->setText(QString::number(iRetVal));
    qDebug() << "get value cmd:" << cmd << cmd.toUtf8();
}
void MainWindow::SaveProfilesAsExcel()
{
    if (m_hScanner == nullptr) {
          QMessageBox::warning(this, tr("disconnected"), tr("please connected first"));
          return;
    }
    QXlsx::Document xlsx;
    xlsx.write("A1", "X");
    xlsx.write("B1", "Y");
    xlsx.write("C1", "Z");
    xlsx.write("D1", "I");

    for (int i = 0; i < m_iLengthReceivedData; i++)
    {
        xlsx.write(i + 2, 1, m_dScannerBufferX[i]);
        xlsx.write(i + 2, 2, m_uScannerEncoder);
        xlsx.write(i + 2, 3, m_dScannerBufferZ[i]);
        xlsx.write(i + 2, 4, m_iScannerBufferI[i]);
    }

    QString filename = QFileDialog::getSaveFileName(this, tr("保存为Excel"), "", tr("Excel 文件 (*.xlsx)"));
    if (!filename.isEmpty())
    {
        if (!filename.endsWith(".xlsx", Qt::CaseInsensitive))
            filename += ".xlsx";
        if (xlsx.saveAs(filename))
            QMessageBox::information(this, tr("success"), tr("Excel Success"));
        else
            QMessageBox::critical(this, tr("filed"), tr("filed"));
    }
}
void MainWindow::onScreenshot()
{
    // 1. 拿到pixmap指针判断有效性
    const QPixmap* pPixmap = labelImage->pixmap();
    if (!pPixmap || pPixmap->isNull()) {
        QMessageBox::warning(this, tr("failed"), tr("no image"));
        return;
    }
    // 2. 复制一份，不要用指针
    QPixmap pixmap = *pPixmap;

    // 3. 选择保存路径
    QString defaultPath = QDir::currentPath() + "/screenshot.png";
    QString path = QFileDialog::getSaveFileName(this, tr("保存截图"), defaultPath, tr("PNG 图片 (*.png);;所有文件 (*)"));
    if (path.isEmpty())
        return;

    if (!path.endsWith(".png", Qt::CaseInsensitive))
        path += ".png";

    // 4. 保存
    bool ok = pixmap.save(path, "PNG");
    if (ok) {
        QMessageBox::information(this, tr("成功"), tr("截图已保存到:\n%1").arg(path));
    } else {
        QMessageBox::warning(this, tr("失败"), tr("无法保存截图（可能路径非法或无权限）"));
    }
}
void MainWindow::SetMeasuringRate()
{
    QString hzStr = lineEditHzNumber->text().trimmed();
    if (hzStr.isEmpty()) {
        QMessageBox::warning(this, tr("输入错误"), tr("请输入频率(Hz)"));
        return;
    }
    bool ok = false;
    int hz = hzStr.toInt(&ok);
    if (!ok || hz <= 0) {
        QMessageBox::warning(this, tr("输入错误"), tr("请输入有效的正数频率"));
        return;
    }

    // 采集线时间 = 1,000,000 / 频率
    int lineTime = 1000000 / hz;
    // 正确格式：SetAcquisitionLineTime=xxx\r
    QString cmd = QString("SetAcquisitionLineTime=%1\r").arg(lineTime);
    QByteArray ba = cmd.toUtf8();
    qDebug() << "发送命令：" << cmd << " 实际发送字节数:" << ba.size();

    int res = EthernetScanner_WriteData(m_hScanner, ba.data(), ba.size());

    if (res > 0) {
        QMessageBox::information(this, tr("成功"), tr("已设置采集线时间: %1 us\n对应频率: %2 Hz").arg(lineTime).arg(hz));
    } else {
        QMessageBox::critical(this, tr("失败"), tr("设置采集线时间失败，请检查连接"));
    }
}

void MainWindow::rebootCamera()
{
    if (!m_hScanner) {
        QMessageBox::warning(this, tr("未连接"), tr("请先连接设备"));
        return;
    }

    // 1. 增加确认弹窗（带"Yes/No"按钮）
    QMessageBox::StandardButton confirm;
    confirm = QMessageBox::question(
        this,
        tr("确认重启"),
        tr("确定要重启设备吗？"),
        QMessageBox::Yes | QMessageBox::No
    );

    if (confirm == QMessageBox::No) {
        return; // 用户点击取消
    }

    // 2. 执行重启命令
    QString cmd = "SetReboot\r";
    QByteArray ba = cmd.toUtf8();
    int res = EthernetScanner_WriteData(m_hScanner, ba.data(), ba.size());

    // 3. 优化弹窗按钮样式（通过QSS）
    QString styleSheet =
        "QMessageBox QPushButton {"
        "   min-width:  80px;"  // 按钮最小宽度
        "   min-height: 25px;"  // 按钮最小高度
        "   padding:    5px;"   // 内边距
        "}";

    if (res > 0) {
        QMessageBox msgBox;
        msgBox.setStyleSheet(styleSheet); // 应用样式
        msgBox.information(this, tr("命令已发送"), tr("设备正在重启..."));
    } else {
        QMessageBox msgBox;
        msgBox.setStyleSheet(styleSheet); // 应用样式
        msgBox.critical(this, tr("失败"), tr("重启命令发送失败，请检查连接"));
    }
}


//设置模式
void MainWindow::setMode()
{
    // 假设 comboBoxMode 和 m_hScanner 是 SettingsWindow 的成员
    if (!m_hScanner) {
        QMessageBox::warning(this, tr("未连接"), tr("请先连接设备"));
        return;
    }

    int modeValue = comboBoxMode->currentData().toInt(); // 取 0 或 1
    QString cmd = QString("SetCameraMode=%1\r").arg(modeValue);
    QByteArray ba = cmd.toUtf8();

    int res = EthernetScanner_WriteData(m_hScanner, ba.data(), ba.size());

    if (res > 0) {
        QMessageBox::information(this, tr("成功"), tr("已设置相机模式为: %1").arg(modeValue == 0 ? "Profile 轮廓" : "Camera images 图像"));
    } else {
        QMessageBox::critical(this, tr("失败"), tr("设置相机模式失败，请检查连接"));
    }
}


// 在合适位置（如ScannerConnect成功后、或窗口初始化后）添加：

void MainWindow::syncCameraModeFromDevice()
{
    if (!m_hScanner) return;

    char chRetBuf[128] = {0};
    // "GetCameraMode" 可以直接用
    int iRetVal = EthernetScanner_ReadData(m_hScanner, (char*)"GetCameraMode", chRetBuf, sizeof(chRetBuf), 1000);
    if (iRetVal == ETHERNETSCANNER_READDATAOK) {
        int mode = atoi(chRetBuf); // 0=Profile, 1=Camera images
        // 查找对应data并设置
        int index = comboBoxMode->findData(mode);
        if (index >= 0)
            comboBoxMode->setCurrentIndex(index);
    }
}



//void MainWindow::SetInternalTriggerMode()
//{
//    if (m_hScanner == nullptr) {
//        QMessageBox::warning(this, tr("未连接"), tr("请先连接设备"));
//        return;
//    }

//    // Internal Trigger Mode, x=0
//    QString cmd = QString("SetTriggerSource 0\r");
//    QByteArray ba = cmd.toUtf8();
//    qDebug() << "发送命令：" << cmd << " 实际发送字节数:" << ba.size();

//    int res = EthernetScanner_WriteData(m_hScanner, ba.data(), ba.size());

//    if (res > 0) {
//        QMessageBox::information(this, tr("成功"), tr("已设置为Internal Trigger Mode"));
//    } else {
//        QMessageBox::critical(this, tr("失败"), tr("设置Internal Trigger Mode失败，请检查连接"));
//    }
//}

//测试曝光
//void MainWindow::SetMeasuringRate()
//{
//    if (m_hScanner == nullptr) {
//        QMessageBox::warning(this, tr("未连接"), tr("请先连接设备"));
//        return;
//    }

//    // 曝光时间, 设为88
//    QString cmd = QString("SetExposureTime 88\r");
//    QByteArray ba = cmd.toUtf8();
//    qDebug() << "发送命令：" << cmd << " 实际发送字节数:" << ba.size();

//    int res = EthernetScanner_WriteData(m_hScanner, ba.data(), ba.size());

//    if (res > 0) {
//        QMessageBox::information(this, tr("成功"), tr("已设置曝光时间为88"));
//    } else {
//        QMessageBox::critical(this, tr("失败"), tr("设置曝光时间失败，请检查连接"));
//    }
//}
