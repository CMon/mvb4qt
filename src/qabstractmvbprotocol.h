#ifndef QABSTRACTMVBPROTOCOL_H
#define QABSTRACTMVBPROTOCOL_H
#include "qobject.h"

class QAbstractMvbProtocol
{
public:
    virtual bool getBool(const quint8 *data, const quint8 byte, const quint8 bit) const = 0;
    virtual void setBool(quint8 *data, const quint8 byte, quint8 bit, const bool value) const = 0;
    virtual qint8 getQint8(const quint8 *data, const quint8 byte) const = 0;
    virtual void setQint8(quint8 *data, const quint8 byte, const qint8 value) = 0;
    virtual qint16 getQint16(const quint8 *data, const quint8 byte) const = 0;
    virtual void setQint16(quint8 *data, const quint8 byte, const qint16 value) = 0;
    virtual qint32 getQint32(const quint8 *data, const quint8 byte) const = 0;
    virtual void setQint32(quint8 *data, const quint8 byte, const qint32 value) = 0;
    virtual quint8 getQuint8(const quint8 *data, const quint8 byte) const = 0;
    virtual void setQuint8(quint8 *data, const quint8 byte, const quint8 value) = 0;
    virtual quint16 getQuint16(const quint8 *data, const quint8 byte) const = 0;
    virtual void setQuint16(quint8 *data, const quint8 byte, const quint16 value) = 0;
    virtual quint32 getQuint32(const quint8 *data, const quint8 byte) const = 0;
    virtual void setQuint32(quint8 *data, const quint8 byte, const quint32 value) = 0;
};

#endif // QABSTRACTMVBPROTOCOL_H
