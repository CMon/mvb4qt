#ifndef QBIGENDIANPROTOCOL_H
#define QBIGENDIANPROTOCOL_H

#include "qabstractmvbprotocol.h"

/*
 * An implementation of the abstract class QAbstractMvbProtocol, it is a big endian protocol
 * that is common in mvb, all signal would by parsed by big endian. This class could adapt to different types of the hardware platform,
 * such as intel and arm, it means that users doesn't need to consider the endian of the hareware.
 */
class QBigEndianProtocol : public QAbstractMvbProtocol
{
public:
    QBigEndianProtocol();
    bool getBool(const quint8 *data, const quint8 byte, const quint8 bit) const;
    void setBool(quint8 *data, const quint8 byte, quint8 bit, const bool value) const;
    qint8 getQint8(const quint8 *data, const quint8 byte) const;
    void setQint8(quint8 *data, const quint8 byte, const qint8 value);
    qint16 getQint16(const quint8 *data, const quint8 byte) const;
    void setQint16(quint8 *data, const quint8 byte, const qint16 value);
    qint32 getQint32(const quint8 *data, const quint8 byte) const;
    void setQint32(quint8 *data, const quint8 byte, const qint32 value);
    quint8 getQuint8(const quint8 *data, const quint8 byte) const;
    void setQuint8(quint8 *data, const quint8 byte, const quint8 value);
    quint16 getQuint16(const quint8 *data, const quint8 byte) const;
    void setQuint16(quint8 *data, const quint8 byte, const quint16 value);
    quint32 getQuint32(const quint8 *data, const quint8 byte) const;
    void setQuint32(quint8 *data, const quint8 byte, const quint32 value);

private:
    template <typename T>
    T getValue(const quint8 *data, const quint8 byte) const;
    template <typename T>
    void setValue(quint8 *data, const quint8 byte, const T value);
};

#endif // QBIGENDIANPROTOCOL_H
