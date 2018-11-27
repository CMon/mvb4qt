#include "qlittleendianprotocol.h"

QLittleEndianProtocol::QLittleEndianProtocol()
{

}

bool QLittleEndianProtocol::getBool(const quint8 *data, const quint8 byte, const quint8 bit) const
{
    if (data == nullptr)
    {
        qDebug() << "the data is invalid" << _MVB4QT_LIB_INFO;

        return false;
    }
    else if (byte > 32 - sizeof (bool))
    {
        qDebug() << "the byte address" << byte << "is out of range" << _MVB4QT_LIB_INFO;

        return false;
    }
    else if (bit >= 8)
    {
        qDebug() << "the bit address" << bit << "is out of range" << _MVB4QT_LIB_INFO;

        return false;
    }
    else
    {
        return *(data + byte) & (0x01 << bit) != 0 ? true : false;
    }
}

void QLittleEndianProtocol::setBool(quint8 *data, const quint8 byte, quint8 bit, const bool value) const
{
    if (data == nullptr)
    {
        qDebug() << "the data is invalid" << _MVB4QT_LIB_INFO;
    }
    else if (byte >= 32)
    {
        qDebug() << "the byte address" << byte << "is out of range" << _MVB4QT_LIB_INFO;
    }
    else if (bit >= 8)
    {
        qDebug() << "the bit address" << bit << "is out of range" << _MVB4QT_LIB_INFO;
    }
    else
    {
        *(data + byte) |= (0x01 << bit);
    }
}

qint8 QLittleEndianProtocol::getQint8(const quint8 *data, const quint8 byte) const
{
    return getValue<quint8>(data, byte);
}

void QLittleEndianProtocol::setQint8(quint8 *data, const quint8 byte, const qint8 value)
{
    setValue<qint8>(data, byte, value);
}

qint16 QLittleEndianProtocol::getQint16(const quint8 *data, const quint8 byte) const
{
    return getValue<qint16>(data, byte);
}

void QLittleEndianProtocol::setQint16(quint8 *data, const quint8 byte, const qint16 value)
{
    setValue<qint16>(data, byte, value);
}

qint32 QLittleEndianProtocol::getQint32(const quint8 *data, const quint8 byte) const
{
    return getValue<qint32>(data, byte);
}

void QLittleEndianProtocol::setQint32(quint8 *data, const quint8 byte, const qint32 value)
{
    setValue<qint32>(data, byte, value);
}

quint8 QLittleEndianProtocol::getQuint8(const quint8 *data, const quint8 byte) const
{
    return getValue<quint8>(data, byte);
}

void QLittleEndianProtocol::setQuint8(quint8 *data, const quint8 byte, const quint8 value)
{
    setValue<quint8>(data, byte, value);
}

quint16 QLittleEndianProtocol::getQuint16(const quint8 *data, const quint8 byte) const
{
    return getValue<quint16>(data, byte);
}

void QLittleEndianProtocol::setQuint16(quint8 *data, const quint8 byte, const quint16 value)
{
    setValue<quint16>(data, byte, value);
}

quint32 QLittleEndianProtocol::getQuint32(const quint8 *data, const quint8 byte) const
{
    return getValue<quint32>(data, byte);
}

void QLittleEndianProtocol::setQuint32(quint8 *data, const quint8 byte, const quint32 value)
{
    setValue<quint32>(data, byte, value);
}

template <typename T>
T QLittleEndianProtocol::getValue(const quint8 *data, const quint8 byte) const
{
    if (data == nullptr)
    {
        qDebug() << "the data is invalid" << _MVB4QT_LIB_INFO;

        return 0;
    }
    else if (byte > 32 - sizeof (T))
    {
        qDebug() << "the byte address" << byte << "is out of range" << _MVB4QT_LIB_INFO;

        return 0;
    }
    else if (this->endianMode == Mvb4Qt::LittenEndian)
    {
        return *(qint8 *)(data + byte);
    }
    else if (this->endianMode == Mvb4Qt::BigEndian)
    {
        quint8 a[sizeof (T)] = {0};

        for (int i = 0; i < sizeof (T); i ++)
        {
            a[i] = data[byte + sizeof (T) - i];
        }

        return *(T *)a;
    }
}

template <typename T>
void QLittleEndianProtocol::setValue(const quint8 *data, const quint8 byte, const T value) const
{
    if (data == nullptr)
    {
        qDebug() << "the data is invalid" << _MVB4QT_LIB_INFO;
    }
    else if (byte > 32 - sizeof (T))
    {
        qDebug() << "the byte address" << byte << "is out of range" << _MVB4QT_LIB_INFO;
    }
    else if (this->endianMode == Mvb4Qt::LittenEndian)
    {
        *(T *)(data + byte) = value;
    }
    else if (this->endianMode == Mvb4Qt::BigEndian)
    {
        quint8 a[sizeof (T)] = {0};

        // convert the variable into little endian
        for (int i = 0; i < sizeof (T) / 2; i ++)
        {
            quint8 temp = *((quint8 *)&value + i);

            *((quint8 *)&value + i) = *((quint8 *)&value + sizeof (T) - 1 - i);
            *((quint8 *)&value + sizeof (T) - 1 - i) = temp;
        }
    }
}
