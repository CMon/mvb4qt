#ifndef QMVBMANAGER_H
#define QMVBMANAGER_H


#include <QThread>
#include <QTimer>
#include "mvb4qt.h"

class QMvbManager : QObject
{
    Q_OBJECT

public:
    QMvbManager();
    QMvbCard *createCard(QMvbDriver *driver, QMvbProtocol *protocol);
    bool mountCard(const QString &name, const QMvbCard *card);
    QMvbCard *unmountCard(const QString &name);
    bool delCard(const QString &name);
    bool start(const QString &name, const quint16 cycle = 100);
    bool stop(const QString &name);
    bool getBool(const QString &name, const quint16 number, const quint8 byte, const quint8 bit) const;
    void setBool(const QString &name, const quint16 number, const quint8 byte, quint8 bit, const bool value) const;
    qint8 getQint8(const QString &name, const quint16 number, const quint8 byte) const;
    void setQint8(const QString &name, const quint16 number, const quint8 byte, const qint8 value);
    qint16 getQint16(const QString &name, const quint16 number, const quint8 byte) const;
    void setQint16(const QString &name, const quint16 number, const quint8 byte, const qint16 value);
    qint32 getQint32(const QString &name, const quint16 number, const quint8 byte) const;
    void setQint32(const QString &name, const quint16 number, const quint8 byte, const qint32 value);
    quint8 getQuint8(const QString &name, const quint16 number, const quint8 byte) const;
    void setQuint8(const QString &name, const quint16 number, const quint8 byte, const quint8 value);
    quint16 getQuint16(const QString &name, const quint16 number, const quint8 byte) const;
    void setQuint16(const QString &name, const quint16 number, const quint8 byte, const quint16 value);
    quint32 getQuint32(const QString &name, const quint16 number, const quint8 byte) const;
    void setQuint32(const QString &name, const quint16 number, const quint8 byte, const quint32 value);

private:
    QMap<QString, QMvbCard *> cardMap;
    QThread thread;

private:
    signals:
    slots:
    void update();

};

#endif // QMVBMANAGER_H
