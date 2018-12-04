#include "qmvbcard.h"
#include "qlittleendianprotocol.h"
#include "qmvbport.h"

QMvbCard::QMvbCard(QAbstractMvbDriver *driver, QMvbConfigure *configure, QAbstractMvbProtocol *protocol)
{
    this->driver = driver;
    this->protocol = protocol;
    this->MvbConfigure = configure;

    this->interval = 100;
    this->moveToThread(&(this->thread));
    this->connect(&timer, SIGNAL(timeout()), this, SLOT(updateMvbSlot()), Qt::DirectConnection);

}

QMvbCard::~QMvbCard()
{
    if (this->driver != nullptr)
    {
        delete this->driver;
    }

    if (this->protocol != nullptr)
    {
        delete this->protocol;
    }

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

bool QMvbCard::addSourcePort(const qint16 number, const qint16 size, const quint16 cycle, const QString group)
{
    return this->addPort(number, size, Mvb4Qt::MvbSourcePort, cycle, group);
}

bool QMvbCard::addSinkPort(const qint16 number, const qint16 size, const quint16 cycle, const QString group)
{ 
    return this->addPort(number, size, Mvb4Qt::MvbSinkPort, cycle, group);
}

bool QMvbCard::addVirtualPort(const qint16 number, const qint16 size, const quint16 cycle, const QString group)
{   
    return this->addPort(number, size, Mvb4Qt::MvbVirtualPort, cycle, group);
}

bool QMvbCard::removePort(const qint16 number)
{
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

bool QMvbCard::addPort(const qint16 number, const qint16 size, const Mvb4Qt::MvbPortType type, const quint16 cycle, QString group)
{
    if (this->MvbConfigure->getState() == Mvb4Qt::MvbCardStart)
    {
        return false;
    }
    else if (this->portMap.contains(number))
    {
        return false;
    }
    else
    {
        this->portMap.insert(number, new QMvbPort(number, size, type, cycle, group));

        return true;
    }
}
bool QMvbCard::getBool(const qint16 number, const quint8 byte, const quint8 bit)
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

void QMvbCard::setBool(const qint16 number, const quint8 byte, quint8 bit, const bool value)
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

qint8 QMvbCard::getQint8(const qint16 number, const quint8 byte)
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

qint16 QMvbCard::getQint16(const qint16 number, const quint8 byte)
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

qint32 QMvbCard::getQint32(const qint16 number, const quint8 byte)
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

quint8 QMvbCard::getQuint8(const qint16 number, const quint8 byte)
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

quint16 QMvbCard::getQuint16(const qint16 number, const quint8 byte)
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

quint32 QMvbCard::getQuint32(const qint16 number, const quint8 byte)
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
    this->thread.start();

    this->MvbConfigure->setState(Mvb4Qt::MvbCardStart);
    //start cycle for thread function(update)
    this->timer.start(this->interval);
}

void QMvbCard::stop()
{
    this->timer.stop();
    this->MvbConfigure->setState(Mvb4Qt::MvbCardStop);
    this->driver->stop(this);
}

void QMvbCard::configure()
{
    this->driver->configure(this->MvbConfigure);
}

void QMvbCard::updateMvbSlot()
{
    foreach(QMvbPort *port, this->portMap.values())
    {
        if (port->getType() == Mvb4Qt::MvbSourcePort)
        {
            QReadLocker loker(&(this->lock));

            this->driver->updatePort(port);
        }
        else if (port->getType() == Mvb4Qt::MvbSinkPort)
        {
            QWriteLocker loker(&(this->lock));

            this->driver->updatePort(port);
        }
    }

    // debug mode, may add a flag to active this function later
    foreach(QMvbPort *port, this->portMap.values())
    {
        QString info;

        info.append(QString::number(port->getNumber(), 16));
        info.append(":");

        for (int i = 0; i < port->getSize(); i ++)
        {
            // info.append(QString::number(*(port->getData() + i), 16));
            info.append(QString::number(this->getQuint8(port->getNumber(), i), 16));
        }

        qDebug() << info << QThread::currentThreadId();
    }
}

const QString &QMvbCard::getName() const
{
    return this->name;
}

void QMvbCard::setName(const QString name)
{
    return this->name = name;
}
