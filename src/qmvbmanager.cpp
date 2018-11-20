#include "qmvbmanager.h"

QMvbManager::QMvbManager()
{

}

QMvbCard *QMvbManager::createCard(QMvbDriver *driver, QMvbProtocol *protocol)
{
    QMvbCard *card = new QMvbCard();

    card->setDriver(driver);

    if (protocol == null)
    {
        card->setProtocol(new QMvbCard());
    }
    else
    {
        card->setProtocol(protocol);
    }

    return card;
}

bool QMvbManager::mountCard(const QString &name, const QMvbCard *card)
{
    if (card == null)
    {
        return false;
    }
    else if (this->cardMap.contains(name))
    {
        return false;
    }
    else
    {
        this->cardMap.insert(name, card);
        card->moveToThread(&thread);

        return true;
    }
}

QMvbCard *QMvbManager::unmountCard(const QString &name)
{
    if (this->cardMap.contains(name))
    {
        QMvbCard *card = this->cardMap[name];

        this->cardMap.remove(name);
        card->moveToThread(this);

        return card;
    }
    else
    {
        return null;
    }
}

bool QMvbManager::delCard(const QString &name)
{
    if (this->cardMap.contains(name))
    {
        QMvbCard *card = this->cardMap[name];

        this->cardMap.remove(name);
        delete card;

        return true;
    }
    else
    {
        return false;
    }
}

bool QMvbManager::start(const QString &name, quint16 cycle = 100)
{
    if (cycle < 100)
    {
        cycle = 100;
    }

    QTimer *timer = new QTimer();

    this->timerMap.insert(name, timer);
    this->conn

    if (this->cardMap.contains(name))
    {
        QMvbCard *card = this->cardMap[name];

        this->cardMap.remove(name);
        delete card;

        return true;
    }
    else
    {
        return false;
    }
}

bool QMvbManager::stop(const QString &name)
{

}

bool QMvbManager::getBool(const QString &name, const quint16 number, const quint8 byte, const quint8 bit) const
{
    if (this->cardMap.contains(name))
    {
        QMvbCard *card = this->cardMap[name];
        quint8 *data =

        card->lock.lockForRead();
        card->protocol->getBool(card->)
    }
}

void QMvbManager::setBool(const QString &name, const quint8 byte, quint8 bit, const bool value) const
{

}

qint8 QMvbManager::getQint8(const QString &name, const quint8 byte) const
{

}

void QMvbManager::setQint8(const QString &name, const quint8 byte, const qint8 value)
{

}

qint16 QMvbManager::getQint16(const QString &name, const quint8 byte) const
{

}

void QMvbManager::setQint16(const QString &name, const quint8 byte, const qint16 value)
{

}

qint32 QMvbManager::getQint32(const QString &name, const quint8 byte) const
{

}

void QMvbManager::setQint32(const QString &name, const quint8 byte, const qint32 value)
{

}

quint8 QMvbManager::getQuint8(const QString &name, const quint8 byte) const
{

}

void QMvbManager::setQuint8(const QString &name, const quint8 byte, const quint8 value)
{

}

quint16 QMvbManager::getQuint16(const QString &name, const quint8 byte) const
{

}

void QMvbManager::setQuint16(const QString &name, const quint8 byte, const quint16 value)
{

}

quint32 QMvbManager::getQuint32(const QString &name, const quint8 byte) const
{

}

void QMvbManager::setQuint32(const QString &name, const quint8 byte, const quint32 value)
{

}
