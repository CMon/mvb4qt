#ifndef QOFFSETLITTLEENDIANPROTOCOL_H
#define QOFFSETLITTLEENDIANPROTOCOL_H


#include "qlittleendianprotocol.h"

/*
 * An implementation of the abstract class QAbstractMvbProtocol, it is an offset little endian protocol,
 * all signal would by parsed by little endian. This class could adapt to different types of the hardware
 * platform, such as intel and arm, it means that users doesn't need to consider the endian of the hareware.
 * The only difference from QLittleEndianProtocol is that the index 0 of bit mean bit7 and the index 7 of
 * bit means bit0.
 */
class QOffsetLittleEndianProtocol : public QLittleEndianProtocol
{
public:
    QOffsetLittleEndianProtocol();
    bool getBool(const quint8 *data, const quint8 byte, const quint8 bit) const;
    void setBool(quint8 *data, const quint8 byte, quint8 bit, const bool value) const;

private:
    quint8 getOffset(const quint8 bit) const;
};

#endif // QOFFSETLITTLEENDIANPROTOCOL_H
