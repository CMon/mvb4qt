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
//using Mvb4Qt;

class QMvbPort;
class QAbstractMvbDriver;
class QMvbProtocol;

class QMvbCard : QObject
{
    Q_OBJECT

public:
    QMvbCard(QAbstractMvbDriver *driver, QMvbProtocol *protocol = nullptr);
    ~QMvbCard();
public:
    bool addSourcePort(const qint16 number, const quint16 cycle, const QString group = "");
    bool addSinkPort(const qint16 number, const quint16 cycle, const QString group = "");
    bool addVirtualPort(const qint16 number, const quint16 cycle, const QString group = "");
    bool removePort(const qint16 number);
    quint16 getDeviceId() const;
    enum MvbPhyMode getPhyMode() const;
    enum MvbBufferSize getBufferSize() const;
    enum MvbCardState getState() const;
    void setDeviceId(const quint16 deviceId);
    void setPhyMode(const enum MvbPhyMode phyMode);
    void getBufferSize(const enum MvbBufferSize bufferSize);
    void getState(const enum MvbCardState state);
    qint32 getInterval() const;
    void setInterval(const qint32 interval);
    bool getBool(const qint16 number, const quint8 byte, const quint8 bit) const;
    void setBool(const qint16 number, const quint8 byte, quint8 bit, const bool value) const;
    qint8 getQint8(const qint16 number, const quint8 byte) const;
    void setQint8(const qint16 number, const quint8 byte, const qint8 value);
    qint16 getQint16(const qint16 number, const quint8 byte) const;
    void setQint16(const qint16 number, const quint8 byte, const qint16 value);
    qint32 getQint32(const qint16 number, const quint8 byte) const;
    void setQint32(const qint16 number, const quint8 byte, const qint32 value);
    quint8 getQuint8(const qint16 number, const quint8 byte) const;
    void setQuint8(const qint16 number, const quint8 byte, const quint8 value);
    quint16 getQuint16(const qint16 number, const quint8 byte) const;
    void setQuint16(const qint16 number, const quint8 byte, const quint16 value);
    quint32 getQuint32(const qint16 number, const quint8 byte) const;
    void setQuint32(const qint16 number, const quint8 byte, const quint32 value);
    void start();
    void stop();
    void configure();

private:
    qint32 interval;
    QMap<qint16, QMvbPort *> portMap; // a map used to store all ports
    quint16 deviceId;   // the id of mvb device
    enum MvbPhyMode phyMode;    // the mode of mvb device
    enum MvbBufferSize bufferSize;  // the buffer size of mvb device
    enum MvbCardState state;    // the state of mvb card
    QAbstractMvbDriver *driver;
    QMvbProtocol *protocol;
    QTimer timer;
    QReadWriteLock lock;

    QThread m_thread;
    QMutex m_Mutex;
private:
    bool addPort(const qint16 number, const enum MvbPortType, const quint16 cycle, QString group);

private slots:
    void updateMvbSlot();
};

#endif // QMVBCARD_H
