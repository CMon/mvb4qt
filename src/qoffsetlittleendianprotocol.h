#ifndef QOFFSETLITTLEENDIANPROTOCOL_H
#define QOFFSETLITTLEENDIANPROTOCOL_H


#include "qlittleendianprotocol.h"

class QOffsetLittleEndianProtocol : QLittleEndianProtocol
{
public:
    QOffsetLittleEndianProtocol();
    bool getBool(const quint8 *data, const quint8 byte, const quint8 bit) const;
    void setBool(quint8 *data, const quint8 byte, quint8 bit, const bool value) const;

private:
    quint8 getOffset(const quint8 bit) const;
};

#endif // QOFFSETLITTLEENDIANPROTOCOL_H
