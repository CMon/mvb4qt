#include <QDebug>
#include "qmvbcardmanager.h"
#include "qabstractmvbprotocol.h"
#include "qabstractmvbdriver.h"
#include "qbigendianprotocol.h"

QMvbCardManager::QMvbCardManager()
{

}

QMvbCardManager::~QMvbCardManager()
{
    foreach (QString name, this->cardMap.keys())
    {
        delete this->cardMap[name];
        this->cardMap.remove(name);
    }
}

QMvbCardManager *QMvbCardManager::manager = nullptr;

QMvbCardManager *QMvbCardManager::getManager()
{
    if (manager == nullptr)
    {
        manager = new QMvbCardManager();

        return manager;
    }
    else
    {
        return manager;
    }
}

QMvbCard *QMvbCardManager::addMvbCard(const QString name, QAbstractMvbDriver *driver, QAbstractMvbProtocol *protocol)
{
    if (this->cardMap.contains(name))
    {
        qDebug() << "the card name of"  << name << "already exists" << _MVB4QT_LIB_INFO;

        return nullptr;
    }
    else if (protocol == nullptr)
    {
        // If there is no protocol specified, big endian protocol would be applied.
        this->cardMap.insert(name, new QMvbCard(name, driver, new QBigEndianProtocol()));

        return this->cardMap[name];
    }
    else
    {
        this->cardMap.insert(name, new QMvbCard(name, driver, protocol));

        return this->cardMap[name];
    }
}

bool QMvbCardManager::removeMvbCard(const QString name)
{
    if (this->cardMap.contains(name))
    {
        delete this->cardMap[name];
        this->cardMap.remove(name);

        return true;
    }
    else
    {
        qDebug() << "the card name of"  << name << "already exists" << _MVB4QT_LIB_INFO;

        return false;
    }
}

QMvbCard *QMvbCardManager::getMvbCard(const QString name) const
{
    if (this->cardMap.contains(name))
    {
        return this->cardMap[name];
    }
    else
    {
        qDebug() << "the card name of"  << name << "already exists" << _MVB4QT_LIB_INFO;

        return nullptr;
    }
}

QList<QMvbCard *> QMvbCardManager::getAllCard() const
{
    return this->cardMap.values();
}

QList<QString> QMvbCardManager::getAllCardName() const
{
    return this->cardMap.keys();
}

qint16 QMvbCardManager::getCardSum() const
{
    return this->cardMap.size();
}
