#ifndef QMVBCARDMANAGER_H
#define QMVBCARDMANAGER_H


#include <QMap>
#include <QDebug>
#include "mvb4qt.h"
#include "qmvbcard.h"
#include "qabstractmvbdriver.h"
#include "qabstractmvbprotocol.h"
#include "qbigendianprotocol.h"

class QMvbCardManager
{
public:
    ~QMvbCardManager();
    QMvbCardManager *getManager();
    QMvbCard *addMvbCard(const QString name, QAbstractMvbDriver *driver);
    QMvbCard *addMvbCard(const QString name, QAbstractMvbDriver *driver, QAbstractMvbProtocol *protocol);
    bool removeMvbCard(const QString name);
    QMvbCard *getMvbCard(const QString name) const;

private:
    QMvbCardManager();

private:
    static QMvbCardManager *manager;
    QMap<QString, QMvbCard *> cardMap;
};

#endif // QMVBCARDMANAGER_H
