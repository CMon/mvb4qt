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

class QMvbCard : QObject
{
    Q_OBJECT

public:
    QMvbCard(QAbstractMvbDriver *driver, QAbstractMvbProtocol *protocol = nullptr);
    // ~QMvbCard();
public:
    bool addSourcePort(const qint16 number, const quint16 cycle, const QString group = "");
    bool addSinkPort(const qint16 number, const quint16 cycle, const QString group = "");
    bool addVirtualPort(const qint16 number, const quint16 cycle, const QString group = "");
    bool removePort(const qint16 number);
    quint16 getDeviceId() const;
    Mvb4Qt::MvbPhyMode getPhyMode() const;
    Mvb4Qt::MvbBufferSize getBufferSize() const;
    Mvb4Qt::MvbCardState getState() const;
    void setDeviceId(const quint16 deviceId);
    void setPhyMode(const Mvb4Qt::MvbPhyMode phyMode);
    void getBufferSize(const Mvb4Qt::MvbBufferSize bufferSize);
    void getState(const Mvb4Qt::MvbCardState state);
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
    void start();
    void stop();
    void configure();

private:
    qint32 interval;
    QMap<qint16, QMvbPort *> portMap; // a map used to store all ports
    quint16 deviceId;   // the id of mvb device
    Mvb4Qt::MvbPhyMode phyMode;    // the mode of mvb device
    Mvb4Qt::MvbBufferSize bufferSize;  // the buffer size of mvb device
    Mvb4Qt::MvbCardState state;    // the state of mvb card
    QAbstractMvbDriver *driver;
    QAbstractMvbProtocol *protocol;
    QTimer timer;
    QReadWriteLock lock;

    QThread thread;
    QMutex m_Mutex;
private:
    bool addPort(const qint16 number, const Mvb4Qt::MvbPortType, const quint16 cycle, QString group);

private slots:
    void updateMvbSlot();
};

#endif // QMVBCARD_H
