#ifndef QMVBCONFIGURE_H
#define QMVBCONFIGURE_H
#include <QObject>
#include "mvb4qt.h"

class QMvbConfigure
{
public:
    QMvbConfigure();
    quint16 getDeviceId() const;
    Mvb4Qt::MvbPhyMode getPhyMode() const;
    Mvb4Qt::MvbBufferSize getBufferSize() const;
    Mvb4Qt::MvbCardState getState() const;
    void setDeviceId(const quint16 deviceId);
    void setPhyMode(const Mvb4Qt::MvbPhyMode phyMode);
    void setBufferSize(const Mvb4Qt::MvbBufferSize bufferSize);
    void setState(const Mvb4Qt::MvbCardState state);
private:
    //based on PIXY MVB API
    quint16 deviceId;   // the id of mvb device
    Mvb4Qt::MvbPhyMode phyMode;    // the mode of mvb device
    Mvb4Qt::MvbBufferSize bufferSize;  // the buffer size of mvb device
    Mvb4Qt::MvbCardState state;    // the state of mvb card
};

#endif // QMVBCONFIGURE_H
