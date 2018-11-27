#ifndef QOFFSETBIGENDIANPROTOCOL_H
#define QOFFSETBIGENDIANPROTOCOL_H


#include "qbigendianprotocol.h"

class QOffsetBigEndianProtocol : QBigEndianProtocol
{
public:
    QOffsetBigEndianProtocol();
    bool getBool(const quint8 *data, const quint8 byte, const quint8 bit) const;
    void setBool(quint8 *data, const quint8 byte, quint8 bit, const bool value) const;

private:
    quint8 getOffset(const quint8 bit) const;
};

#endif // QOFFSETBIGENDIANPROTOCOL_H
