#ifndef QMVBCARD_H
#define QMVBCARD_H


#include <QMap>
#include <QTimer>
#include <QReadWriteLock>
#include <QReadLocker>
#include <QWriteLocker>
#include "mvb4qt.h"
#include "QDebug"
#include "QThread"
#include "QMutex"
#include "qabstractmvbdriver.h"
#include "qabstractmvbprotocol.h"
#include "qmvbcardmanager.h"
#include "qmvbregister.h"


/*
 * The class is the register of the mvb card that is used store almost all information like
 * device id, mvb ports and physical mode etc.
 */
class QMvbCard : QObject
{
    Q_OBJECT

    friend class QMvbCardManager;

public:
    ~QMvbCard();

public:

    bool removePort(const qint16 number);
    QMvbRegister *getMvbRegister();

    qint32 getInterval() const;
    void setInterval(const qint32 interval);
    bool getBool(const qint16 number, const quint8 byte, const quint8 bit);
    void setBool(const qint16 number, const quint8 byte, quint8 bit, const bool value);
    qint8 getQint8(const qint16 number, const quint8 byte);
    void setQint8(const qint16 number, const quint8 byte, const qint8 value);
    qint16 getQint16(const qint16 number, const quint8 byte);
    void setQint16(const qint16 number, const quint8 byte, const qint16 value);
    qint32 getQint32(const qint16 number, const quint8 byte);
    void setQint32(const qint16 number, const quint8 byte, const qint32 value);
    quint8 getQuint8(const qint16 number, const quint8 byte);
    void setQuint8(const qint16 number, const quint8 byte, const quint8 value);
    quint16 getQuint16(const qint16 number, const quint8 byte);
    void setQuint16(const qint16 number, const quint8 byte, const quint16 value);
    quint32 getQuint32(const qint16 number, const quint8 byte);
    void setQuint32(const qint16 number, const quint8 byte, const quint32 value);

public slots:
    void start();
    void stop();
    void configure();

private:
    QMvbCard(QString name, QAbstractMvbDriver *driver, QAbstractMvbProtocol *protocol = nullptr);

private:
    QMvbRegister *mvbRegister;
    QAbstractMvbDriver *driver;
    QAbstractMvbProtocol *protocol;
    QTimer *timer;
    QReadWriteLock lock;
    QThread thread;

private slots:
    void updateCard();
};

#endif // QMVBCARD_H
