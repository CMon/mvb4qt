#include "qmvbconfigure.h"

QMvbConfigure::QMvbConfigure()
{

}
quint16 QMvbConfigure::getDeviceId() const
{
    return this->deviceId;
}

Mvb4Qt::MvbPhyMode QMvbConfigure::getPhyMode() const
{
    return this->phyMode;
}

Mvb4Qt::MvbBufferSize QMvbConfigure::getBufferSize() const
{
    return this->bufferSize;
}

Mvb4Qt::MvbCardState QMvbConfigure::getState() const
{
    return this->state;
}

void QMvbConfigure::setDeviceId(quint16 deviceId)
{
    this->deviceId = deviceId;
}

void QMvbConfigure::setPhyMode(const Mvb4Qt::MvbPhyMode phyMode)
{
    this->phyMode = phyMode;
}

void QMvbConfigure::setBufferSize(const Mvb4Qt::MvbBufferSize bufferSize)
{
    this->bufferSize = bufferSize;
}

void QMvbConfigure::setState(const Mvb4Qt::MvbCardState state)
{
    this->state = state;
}
