#ifndef QLITTLEENDIANPROTOCOL_H
#define QLITTLEENDIANPROTOCOL_H


#include "qabstractmvbprotocol.h"

class QLittleEndianProtocol: public QAbstractMvbProtocol
{
public:
    QLittleEndianProtocol();
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
    void setValue(const quint8 *data, const quint8 byte, const T value) const;
};

#endif // QBIGENDIANPROTOCOL_H
