#include "cimage.h"

CImage::CImage(int width, int height):QPixmap(width,height)
{
    m_pPaint = new QPainter(this);
}

CImage::~CImage()
{
    delete m_pPaint;
}

void CImage::setImageParameters(   std::string  Zstart,
                                   std::string  Zrange,
                                   std::string  XRangeAtStart,
                                   std::string  XRangeAtEnd,
                                   std::string  WidthX,
                                   std::string  HeightZ)
{
    m_dZstart = atoi(Zstart.data());
    m_dZrange = atoi(Zrange.data());
    m_dXRangeAtStart = atoi(XRangeAtStart.data());
    m_dXRangeAtEnd = atoi(XRangeAtEnd.data());
    m_dWidthX = atoi(WidthX.data());
    m_dWidthZ = atoi(HeightZ.data());

}


void CImage::drawImage(double *doEthernetScannerScannerBufferX,
                       double *doEthernetScannerScannerBufferZ,
                       int *iEthernetScannerScannerBufferI,
                       int iEthernetScannerScannerBufferValues)
{
    fill(Qt::GlobalColor::black);

    int x = 0;
    int z = 0;
    int i = 0;


    //Z-Wert-Darstellung
    m_pPaint->setPen(Qt::GlobalColor::white);
    if (doEthernetScannerScannerBufferZ)
    {
        double scaleX = (double)width()/m_dXRangeAtEnd;
        double scaleY = (double)height()/m_dZrange;
        for (i = 0; i < iEthernetScannerScannerBufferValues; i++)
        {
            x = width()-(int)(scaleX*((double)doEthernetScannerScannerBufferX[i] + m_dXRangeAtEnd / 2));
            if ((int)(doEthernetScannerScannerBufferZ[i] - m_dZstart) > 0)
            {
                z = height()-(int)(scaleY*((double)doEthernetScannerScannerBufferZ[i] - m_dZstart));
                m_pPaint->drawPoint(x,z);
            }
        }
    }

    m_pPaint->setPen(Qt::GlobalColor::yellow);
    if (iEthernetScannerScannerBufferI)
    {
        double scaleX = (double)width()/m_dXRangeAtEnd;
        for (i = 0; i < iEthernetScannerScannerBufferValues; i++)
        {
            {
                x = width()-(int)(scaleX*((double)doEthernetScannerScannerBufferX[i] + m_dXRangeAtEnd / 2));
                z = height()*(1-(double)iEthernetScannerScannerBufferI[i]/1023);
                m_pPaint->drawPoint(x,z);
            }
        }
    }
}

