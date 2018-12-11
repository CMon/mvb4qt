#include <QDebug>
#include "qoffsetbigendianprotocol.h"

QOffsetBigEndianProtocol::QOffsetBigEndianProtocol()
{

}

bool QOffsetBigEndianProtocol::getBool(const quint8 *data, const quint8 byte, const quint8 bit) const
{
    return QBigEndianProtocol::getBool(data, byte, this->getOffset(bit));
}

void QOffsetBigEndianProtocol::setBool(quint8 *data, const quint8 byte, quint8 bit, const bool value) const
{
    QBigEndianProtocol::setBool(data, byte, this->getOffset(bit), value);
}

quint8 QOffsetBigEndianProtocol::getOffset(const quint8 bit) const
{
    return 7 - bit;
}
