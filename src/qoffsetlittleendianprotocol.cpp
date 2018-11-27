#include "qoffsetlittleendianprotocol.h"

QOffsetLittleEndianProtocol::QOffsetLittleEndianProtocol()
{

}

bool QOffsetLittleEndianProtocol::getBool(const quint8 *data, const quint8 byte, const quint8 bit) const
{
    return QLittleEndianProtocol::getBool(data, byte, this->getOffset(bit));
}

void QOffsetLittleEndianProtocol::setBool(quint8 *data, const quint8 byte, quint8 bit, const bool value) const
{
    QLittleEndianProtocol::setBool(data, byte, this->getOffset(bit), value);
}

quint8 QOffsetLittleEndianProtocol::getOffset(const quint8 bit) const
{
    return 7 - bit;
}
