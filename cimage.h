#ifndef CIMAGE_H
#define CIMAGE_H

#include <QPixmap>
#include <QPainter>

#include "EthernetScannerSDKDefine.h"

class CImage:public QPixmap
{
public:
    CImage(int width, int height);
    ~CImage();


    QPainter  *m_pPaint;
    double  m_dZstart;
    double  m_dZrange;
    double  m_dXRangeAtStart;
    double  m_dXRangeAtEnd;
    double  m_dWidthX;
    double  m_dWidthZ;

    void setImageParameters(std::string Zstart,
                            std::string Zrange,
                            std::string XRangeAtStart,
                            std::string XRangeAtEnd,
                            std::string WidthX,
                            std::string HeightZ);
    void drawImage(double *doEthernetScannerScannerBufferX,
                   double *doEthernetScannerScannerBufferZ,
                   int *iEthernetScannerScannerBufferI,
                   int iEthernetScannerScannerBufferValues);

};

#endif // CIMAGE_H
