#include "qmvbregister.h"

QMvbRegister::QMvbRegister()
{
    // Set the default value of mvb register.
    this->deviceId = 0x01;
    this->phyMode = Mvb4Qt::MvbEmdMode;
    this->bufferSize = Mvb4Qt::MaxMvbBuffer;
    this->state = Mvb4Qt::MvbCardStop;

    // Set the max and the min value of port number and device id.
    this->minDeviceId = 1;
    this->maxDeviceId = 4095;
    this->minPortNumber = 1;
    this->maxPortNumber = 4095;
}

QMvbRegister::~QMvbRegister()
{
    foreach (quint16 number, this->portMap.keys())
    {
        delete this->portMap[number];
        this->portMap.remove(number);
    }
}

bool QMvbRegister::addPort(const qint16 number, const qint16 size, const Mvb4Qt::MvbPortType type, const quint16 cycle, QString group)
{
    if (this->state != Mvb4Qt::MvbCardStop)
    {
        qDebug() << "please stop the mvb card name of" << this->name
                    << "before adding port operation" << _MVB4QT_LIB_INFO;

        return false;
    }
    else if (this->portMap.contains(number))
    {
        QString temp;

        temp.sprintf("0x%d", QString::number(number, 16));
        qDebug() << "the port number" << temp << "has already been added";

        return false;
    }
    else if (type != Mvb4Qt::MvbVirtualPort && number < this->maxPortNumber && number > this->minPortNumber)
    {
        this->portMap.insert(number, new QMvbPort(number, size, type, cycle, group));

        return true;
    }
    else if (type == Mvb4Qt::MvbVirtualPort)
    {
        this->portMap.insert(number, new QMvbPort(number, size, type, cycle, group));

        return true;
    }
    else
    {
        return false;
    }
}

QList<qint16> QMvbRegister::getPortNumberList() const
{
    return this->portMap.keys();
}

QList<qint16> QMvbRegister::getPortNumberList(const Mvb4Qt::MvbPortType type) const
{
    QList<qint16> list;

    foreach(qint16 number, this->portMap.keys())
    {
        if (this->portMap[number]->getType() == type)
        {
            list << number;
        }
    }

    return list;
}

QList<QMvbPort *> QMvbRegister::getPortList() const
{
    return this->portMap.values();
}

QMvbPort *QMvbRegister::getPort(const qint16 number) const
{
    if (this->portMap.contains(number))
    {
        return this->portMap[number];
    }
    else
    {
        QString temp;

        temp.sprintf("%d0x", QString::number(number, 16));
        qDebug() << "fail getting the port number" << temp << _MVB4QT_LIB_INFO;

        return nullptr;
    }
}

bool QMvbRegister::removePort(const qint16 number)
{
    if (this->state == Mvb4Qt::MvbCardStart)
    {
        qDebug() <<
    }
    else
    {

    }

    if (this->MvbConfigure->getState() == Mvb4Qt::MvbCardStart)
    {
        return false;
    }
    else if (this->portMap.contains(number))
    {
        delete this->portMap[number];
        this->portMap.remove(number);

        return true;
    }
    else
    {
        return false;
    }
}

bool QMvbRegister::addSourcePort(const qint16 number, const qint16 size, const quint16 cycle, const QString group)
{
    return this->addPort(number, size, Mvb4Qt::MvbSourcePort, cycle, group);
}

bool QMvbRegister::addSinkPort(const qint16 number, const qint16 size, const quint16 cycle, const QString group)
{
    return this->addPort(number, size, Mvb4Qt::MvbSinkPort, cycle, group);
}

bool QMvbRegister::addVirtualPort(const qint16 number, const qint16 size, const quint16 cycle, const QString group)
{
    return this->addPort(number, size, Mvb4Qt::MvbVirtualPort, cycle, group);
}

Mvb4Qt::MvbCardState QMvbRegister::getState() const
{
    return this->state;
}

bool QMvbRegister::containPort(const qint16 number) const
{
    return this->portMap.contains(number);
}

void QMvbRegister::setState(const Mvb4Qt::MvbCardState state)
{
    this->state = state;
}

Mvb4Qt::MvbBufferSize QMvbRegister::getBufferSize() const
{
    return this->bufferSize;
}

void QMvbRegister::setBufferSize(const Mvb4Qt::MvbBufferSize bufferSize)
{
    this->bufferSize = bufferSize;
}

qint16 QMvbRegister::getDeviceId() const
{
    return this->deviceId;
}

void QMvbRegister::setdeviceId()
{
    this->deviceId = deviceId;
}

Mvb4Qt::MvbPhyMode QMvbRegister::getPhyMode() const
{
    return this->phyMode;
}

void QMvbRegister::setPhyMode(const Mvb4Qt::MvbPhyMode phyMode)
{
    this->phyMode = phyMode;
}

const QString &QMvbRegister::getName() const
{
    return this->name;
}

void QMvbRegister::setName(const QString name)
{
    this->name = name;
}
