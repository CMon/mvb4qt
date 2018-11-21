#include "qmvbcard.h"
#include "qmvbprotocol.h"
#include "qmvbport.h"
QMvbCard::QMvbCard(QAbstractMvbDriver *driver, QMvbProtocol *protocol)
{
    this->driver = driver;

    if (protocol != nullptr)
    {
        this->protocol = protocol;
    }
    else
    {
        this->protocol = new QMvbProtocol();
    }

    this->deviceId = 1;
    this->phyMode = Mvb4Qt::MvbEmdMode;
    this->bufferSize = Mvb4Qt::MaxMvbBuffer;
    this->state = Mvb4Qt::MvbCardConfigure;
    this->interval = 100;
    this->moveToThread(&(this->thread()));
    this->connect(&timer, SIGNAL(timeout()), this, SLOT(updateMvbSlot()));
}

QMvbCard::~QMvbCard()
{
    delete this->driver;
    delete this->protocol;

    foreach (quint16 number, this->portMap.keys())
    {
        delete this->portMap[number];
        this->portMap.remove(number);
    }
}

qint32 QMvbCard::getInterval() const
{
    return this->interval;
}

void QMvbCard::setInterval(const qint32 interval)
{
    if (interval < 100)
    {
       this->interval = 100;
    }
    else
    {
        this->interval = interval;
    }
}

bool QMvbCard::addSourcePort(const qint16 number, const quint16 cycle, const QString group)
{
    return this->addPort(number, Mvb4Qt::MvbSourcePort, cycle, group);
}

bool QMvbCard::addSinkPort(const qint16 number, const quint16 cycle, const QString group)
{ 
    return this->addPort(number, Mvb4Qt::MvbSourcePort, cycle, group);
}

bool QMvbCard::addVirtualPort(const qint16 number, const quint16 cycle, const QString group)
{   
    return this->addPort(number, Mvb4Qt::MvbVirtualPort, cycle, group);
}

bool QMvbCard::removePort(const qint16 number)
{
    if (this->state == Mvb4Qt::MvbCardStart)
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

bool QMvbCard::addPort(const qint16 number, const enum MvbPortType type, const quint16 cycle, QString group)
{
    if (this->state == Mvb4Qt::MvbCardStart)
    {
        return false;
    }
    else if (this->portMap.contains(number))
    {
        return false;
    }
    else
    {
        this->portMap.insert(number, new QMvbPort(number, type, cycle, group));

        return true;
    }
}

quint16 QMvbCard::getDeviceId() const
{
    return this->deviceId;
}

enum MvbPhyMode QMvbCard::getPhyMode() const
{
    return this->phyMode;
}

enum MvbBufferSize QMvbCard::getBufferSize() const
{
    return this->bufferSize;
}

enum MvbCardState QMvbCard::getState() const
{
    return this->state;
}

void QMvbCard::setDeviceId(quint16 deviceId)
{
    this->deviceId = deviceId;
}

void QMvbCard::setPhyMode(const enum MvbPhyMode phyMode)
{
    this->phyMode = phyMode;
}

void QMvbCard::getBufferSize(const enum MvbBufferSize bufferSize)
{
    this->bufferSize = bufferSize;
}

void QMvbCard::getState(const enum MvbCardState state)
{
    this->state = state;
}
bool QMvbCard::getBool(const qint16 number, const quint8 byte, const quint8 bit) const
{
    if (this->portMap.contains(number))
    {
        QReadLocker locker(&(this->lock));

        return this->protocol->getBool(this->portMap[number]->getData(), byte, bit);
    }
    else
    {
        qDebug()<<"No port"<<number<<"in the map";
        return false;
    }
}

void QMvbCard::setBool(const qint16 number, const quint8 byte, quint8 bit, const bool value) const
{
    if (this->portMap.contains(number))
    {
        QWriteLocker locker(&(this->lock));

        this->protocol->setBool(this->portMap[number]->getData(), byte, bit, value);
    }
    else
    {
        qDebug()<<"No port"<<number<<"in the map";
    }
}

qint8 QMvbCard::getQint8(const qint16 number, const quint8 byte) const
{
    if (this->portMap.contains(number))
    {
        QReadLocker locker(&(this->lock));

        return this->protocol->getQint8(this->portMap[number]->getData(), byte);
    }
    else
    {
        qDebug()<<"No port"<<number<<"in the map";
        return false;
    }
}

void QMvbCard::setQint8(const qint16 number, const quint8 byte, const qint8 value)
{
    if (this->portMap.contains(number))
    {
        QWriteLocker locker(&(this->lock));

        this->protocol->setQint8(this->portMap[number]->getData(), byte, value);
    }
    else
    {
        qDebug()<<"No port"<<number<<"in the map";
    }
}

qint16 QMvbCard::getQint16(const qint16 number, const quint8 byte) const
{
    if (this->portMap.contains(number))
    {
        QReadLocker locker(&(this->lock));

        return this->protocol->getQint16(this->portMap[number]->getData(), byte);
    }
    else
    {
        qDebug()<<"No port"<<number<<"in the map";
        return false;
    }
}

void QMvbCard::setQint16(const qint16 number, const quint8 byte, const qint16 value)
{
    if (this->portMap.contains(number))
    {
        QWriteLocker locker(&(this->lock));

        this->protocol->setQint16(this->portMap[number]->getData(), byte, value);
    }
    else
    {
        qDebug()<<"No port"<<number<<"in the map";
    }
}

qint32 QMvbCard::getQint32(const qint16 number, const quint8 byte) const
{
    if (this->portMap.contains(number))
    {
        QReadLocker locker(&(this->lock));

        return this->protocol->getQint32(this->portMap[number]->getData(), byte);
    }
    else
    {
        qDebug()<<"No port"<<number<<"in the map";
        return false;
    }
}

void QMvbCard::setQint32(const qint16 number, const quint8 byte, const qint32 value)
{
    if (this->portMap.contains(number))
    {
        QWriteLocker locker(&(this->lock));

        this->protocol->setQint32(this->portMap[number]->getData(), byte, value);
    }
    else
    {
        qDebug()<<"No port"<<number<<"in the map";
    }
}

quint8 QMvbCard::getQuint8(const qint16 number, const quint8 byte) const
{
    if (this->portMap.contains(number))
    {
        QReadLocker locker(&(this->lock));

        return this->protocol->getQuint8(this->portMap[number]->getData(), byte);
    }
    else
    {
        qDebug()<<"No port"<<number<<"in the map";
        return false;
    }
}

void QMvbCard::setQuint8(const qint16 number, const quint8 byte, const quint8 value)
{
    if (this->portMap.contains(number))
    {
        QWriteLocker locker(&(this->lock));

        this->protocol->setQuint8(this->portMap[number]->getData(), byte, value);
    }
    else
    {
        qDebug()<<"No port"<<number<<"in the map";
    }
}

quint16 QMvbCard::getQuint16(const qint16 number, const quint8 byte) const
{
    if (this->portMap.contains(number))
    {
        QReadLocker locker(&(this->lock));

        return this->protocol->getQuint16(this->portMap[number]->getData(), byte);
    }
    else
    {
        qDebug()<<"No port"<<number<<"in the map";
        return false;
    }
}

void QMvbCard::setQuint16(const qint16 number, const quint8 byte, const quint16 value)
{
    if (this->portMap.contains(number))
    {
        QWriteLocker locker(&(this->lock));

        this->protocol->setQuint16(this->portMap[number]->getData(), byte, value);
    }
    else
    {
        qDebug()<<"No port"<<number<<"in the map";
    }
}

quint32 QMvbCard::getQuint32(const qint16 number, const quint8 byte) const
{
    if (this->portMap.contains(number))
    {
        QReadLocker locker(&(this->lock));

        return this->protocol->getQuint32(this->portMap[number]->getData(), byte);
    }
    else
    {
        qDebug()<<"No port"<<number<<"in the map";
        return false;
    }
}

void QMvbCard::setQuint32(const qint16 number, const quint8 byte, const quint32 value)
{
    if (this->portMap.contains(number))
    {
        QWriteLocker locker(&(this->lock));

        this->protocol->setQuint32(this->portMap[number]->getData(), byte, value);
    }
    else
    {
        qDebug()<<"No port"<<number<<"in the map";
    }
}

void QMvbCard::start()
{
    this->state = Mvb4Qt::MvbCardStart;
    this->timer.start(this->interval);
    this->driver->start(this);
}

void QMvbCard::stop()
{
    this->state = Mvb4Qt::MvbCardStop;
    this->timer.stop();
    this->driver->stop(this);
}

void QMvbCard::configure()
{
    this->state = Mvb4Qt::MvbCardConfigure;
}

void QMvbCard::updateMvbSlot()
{
    foreach(QMvbPort *port, this->portMap.values())
    {
        if (port->type == Mvb4Qt::MvbSourcePort)
        {
            QReadLocker loker(&(this->lock));

            this->driver->updatePort(port);
        }
        else if (port->type == Mvb4Qt::MvbSinkPort)
        {
            QWriteLocker loker(&(this->lock));

            this->driver->updatePort(port);
        }
    }
}
