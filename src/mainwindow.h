#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma comment(lib, "Ws2_32.lib")

#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include <QTime>
#include <QFile>
#include <QtDebug>

#include <string>
#include <thread>
#include <mutex>
#include <stdint.h>
#include <cmath>

#include "EthernetScannerSDK.h"
#include "EthernetScannerSDKDefine.h"

#include "tinyxml2.h"
#include "pevents.h"
#include "cimage.h"
#include "settingswindow.h"

#define BUFFERLENGTH        1000
#define EXTRAINFOLENGTH     32
#define IMAGEWIDTHMAX       2064
#define IMAGEHEIGHTMAX      2048
#define CHECK_BIT(var,pos)  ((var) & (1<<(pos)))

class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //QT classes
    QFile           *m_pFile;
    QTextStream     *m_pDebugStream;
    QTimer          m_Timer;

    //GUI classes
    SettingsWindow  *m_pSettings;
    CImage          *m_CImage;

    void            *m_hScanner;

    bool            m_SaveLog;
    int             m_iNumberOfProfilesToSave;
    int             m_iCnt;
    int             m_iEncoderHTL;
    int             m_iEncoderTTL;
    int             m_iCPUFiFo;
    int             m_iDLLFiFo;
    int             m_iScannerState;

    std::thread*    m_pImageThread;
    std::mutex      m_picCntMutex;
    bool            m_bDrawingThreadExit;

    neosmart::neosmart_event_t m_Event;

    // Scanner output members (from dll)
    char            m_cScannerInfo[ETHERNETSCANNER_GETINFOSIZEMAX];
    double          m_dScannerBufferX[ETHERNETSCANNER_SCANXMAX * ETHERNETSCANNER_PEAKSPERCMOSSCANLINEMAX];
    double          m_dScannerBufferZ[ETHERNETSCANNER_SCANXMAX * ETHERNETSCANNER_PEAKSPERCMOSSCANLINEMAX];
    int             m_iScannerBufferI[ETHERNETSCANNER_SCANXMAX * ETHERNETSCANNER_PEAKSPERCMOSSCANLINEMAX];
    int             m_iScannerBufferPeakWidth[ETHERNETSCANNER_SCANXMAX * ETHERNETSCANNER_PEAKSPERCMOSSCANLINEMAX];
    unsigned int    m_uScannerEncoder;
    unsigned char   m_ucScannerDigitalInputs;


    //Scanner members
    unsigned short  m_usPicCnt;
    unsigned long   m_dwScanner_Frequency;
    int             m_iLengthReceivedData;
    int             m_iPicCntErr;
    std::string     m_strZstart;
    std::string     m_strZrange;
    std::string     m_strXRangeAtStart;
    std::string     m_strXRangeAtEnd;
    std::string     m_strWidthX;
    std::string     m_strHeightZ;
    std::string     m_strSerialNummber;
    std::string     m_strOrderNumber;
    std::string     m_strProductVersion;
    std::string     m_strProducer;
    std::string     m_strDescriptor;
    std::string     m_strHardwareVersion;
    std::string     m_strFWVersion;
    std::string     m_strMAC;

private:
    std::string  m_strScannerIP;
    std::string  m_strScannerTimeOut;

    bool    m_bGetScanProfileXZI;
    bool    m_bScannerConnectStatus;


    void GetInfoParser(char *chGetInfo);
    //std::vector<std::string>split( const std::string &s, char delim );

signals:
    void UpdatePixmap(QPixmap);

private slots:
    void ScannerConnect();
    void ScannerDisconnect();
    void onTimer();
    void showSettingsWindow();
    void resetPictureCounter();
    void resetDllFifo();
    void RefreshPixmap(QPixmap);
    void SaveProfiles();
    void GetPropertyValue();
    void closeEvent(QCloseEvent *event);
    void StopResetStart();
    void SaveProfilesAsExcel();
    void onScreenshot();
    void SetMeasuringRate();
    void rebootCamera();
    void setMode();
    void syncCameraModeFromDevice();

};

#endif // MAINWINDOW_H
