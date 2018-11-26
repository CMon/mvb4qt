#include "qlittleendianprotocol.h"

QLittleEndianProtocol::QLittleEndianProtocol()
{

}

bool QLittleEndianProtocol::getBool(const quint8 *data, const quint8 byte, const quint8 bit) const
{
    if (data != nullptr && byte < 32 && bit < 8)
    {
        return *(data + byte) & (0x01 << bit) != 0 ? true : false;
    }
    else
    {
        return false;
    }
}

void QLittleEndianProtocol::setBool(quint8 *data, const quint8 byte, quint8 bit, const bool value) const
{
    if (data != nullptr && byte < 32 && bit < 8)
    {
        *(data + byte) |= (0x01 << bit);
    }
}

qint8 QLittleEndianProtocol::getQint8(const quint8 *data, const quint8 byte) const
{
    if (data != nullptr && byte <= 32 - sizeof(qint8))
    {
        return *(qint8 *)(data + byte);
    }
    else
    {
        return 0;
    }
}

void QLittleEndianProtocol::setQint8(quint8 *data, const quint8 byte, const qint8 value)
{
    if (data != nullptr && byte <= 32 - sizeof(qint8))
    {
        *(qint8 *)(data + byte) = value;
    }
}

qint16 QLittleEndianProtocol::getQint16(const quint8 *data, const quint8 byte) const
{
    if (data != nullptr && byte <= 32 - sizeof(qint16))
    {
        return *(qint16 *)(data + byte);
    }
    else
    {
        return 0;
    }
}

void QLittleEndianProtocol::setQint16(quint8 *data, const quint8 byte, const qint16 value)
{
    if (data != nullptr && byte <= 32 - sizeof(qint16))
    {
        *(qint16 *)(data + byte) = value;
    }
}

qint32 QLittleEndianProtocol::getQint32(const quint8 *data, const quint8 byte) const
{
    if (data != nullptr && byte <= 32 - sizeof(qint32))
    {
        return *(qint32 *)(data + byte);
    }
    else
    {
        return 0;
    }
}

void QLittleEndianProtocol::setQint32(quint8 *data, const quint8 byte, const qint32 value)
{
    if (data != nullptr && byte <= 32 - sizeof(qint32))
    {
        *(qint32 *)(data + byte) = value;
    }
}

quint8 QLittleEndianProtocol::getQuint8(const quint8 *data, const quint8 byte) const
{
    if (data != nullptr && byte <= 32 - sizeof(quint8))
    {
        return *(quint8 *)(data + byte);
    }
    else
    {
        return 0;
    }
}

void QLittleEndianProtocol::setQuint8(quint8 *data, const quint8 byte, const quint8 value)
{
    if (data != nullptr && byte <= 32 - sizeof(quint8))
    {
        *(quint8 *)(data + byte) = value;
    }
}

quint16 QLittleEndianProtocol::getQuint16(const quint8 *data, const quint8 byte) const
{
    if (data != nullptr && byte <= 32 - sizeof(quint16))
    {
        return *(quint16 *)(data + byte);
    }
    else
    {
        return 0;
    }
}

void QLittleEndianProtocol::setQuint16(quint8 *data, const quint8 byte, const quint16 value)
{
    if (data != nullptr && byte <= 32 - sizeof(quint16))
    {
        *(quint16 *)(data + byte) = value;
    }
}

quint32 QLittleEndianProtocol::getQuint32(const quint8 *data, const quint8 byte) const
{
    if (data != nullptr && byte <= 32 - sizeof(quint32))
    {
        return *(quint32 *)(data + byte);
    }
    else
    {
        return 0;
    }
}

void QLittleEndianProtocol::setQuint32(quint8 *data, const quint8 byte, const quint32 value)
{
    if (data != nullptr && byte <= 32 - sizeof(quint32))
    {
        *(quint32 *)(data + byte) = value;
    }
}
