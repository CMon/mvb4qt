#ifndef QMVBREGISTER_H
#define QMVBREGISTER_H


#include <QObject>
#include <QMap>
#include <QList>
#include "mvb4qt.h"
#include "qmvbport.h"

class QMvbRegister : QObject
{
public:
    QMvbRegister();
    ~QMvbRegister();

public:
    QList<qint16> getPortNumberList() const;
    QList<qint16> getPortNumberList(const Mvb4Qt::MvbPortType type) const;
    QMvbPort *getPort(const qint16 number) const;
    bool addPort(const qint16 number, const qint16 size, const Mvb4Qt::MvbPortType, const quint16 cycle, QString group);

private:
    quint16 deviceId;   // the id of mvb device
    Mvb4Qt::MvbPhyMode phyMode;    // the mode of mvb device
    Mvb4Qt::MvbBufferSize bufferSize;  // the buffer size of mvb device
    Mvb4Qt::MvbCardState state;    // the state of mvb card
    qint16 minDeviceId, maxDeviceId;    // the device limitation
    qint16 minPortNumber, maxPortNumber;    // the port number limitation
    QMap<qint16, QMvbPort *> portMap; // a map used to store all ports
};

#endif // QMVBREGISTER_H
