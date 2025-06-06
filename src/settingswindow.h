#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>
#include <QMessageBox>
#include <QtDebug>
#include <string>
#include <cmath>


#include "tinyxml2.h"

#include "EthernetScannerSDK.h"

#include "EthernetScannerSDKDefine.h"

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = 0);
    ~SettingsWindow();
    void exchangeData(void* pScannerHandle, std::string orderNumber, std::string ip);

private:
    Ui::SettingsWindow *ui;
    void* m_pScannerHandle;
    std::string m_OrderNumber;
    std::string m_IP;

private slots:
    void setTriggerSource();
    void setExposureTime();
    void setAcquisitionLineTime();

    void resetEncoder();
    void resetPiccnt();
    void resetBaseTime();
    void resetSettings();

    void setAcquisitionStart();
    void setAcquisitionStop();


    void setSyncOut();
    void setSyncOutDelay();

    void HeightZ();
    void setOffsetZ();
    void setWidthX();
    void setOffsetX();
    void setStepX();

    void setSignalEnable();
    void setSignalSelection();
    void setSignalWidthMin();
    void setSignalwWidthMax();
    void setSignalStrengthMin();
    void sendASCIICommand();

    void on_pushButtonUpdate_clicked();

    void on_pushButtonSaveXML_clicked();
    void refreshCurrentValues();

protected:
    void showEvent(QShowEvent* event) override;

signals:
    void signalRefreshRegisters();
    void signalStopResetStart();
};

#endif // SETTINGSWINDOW_H
