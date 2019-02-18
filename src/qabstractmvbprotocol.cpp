#include <QDebug>
#include "qabstractmvbprotocol.h"
#include "qmvbregister.h"
#include "qmvbport.h"

QAbstractMvbProtocol::QAbstractMvbProtocol()
{
    quint8 a[2] = {0};

    *(quint16 *)a = 0x01;

    if (a[0] == 1)
    {
        this->endianMode = Mvb4Qt::LittenEndian;
    }
    else if (a[1] == 1)
    {
        this->endianMode = Mvb4Qt::BigEndian;
    }
    else
    {
        // the default value
        this->endianMode = Mvb4Qt::LittenEndian;
    }
}

Mvb4Qt::EndianMode QAbstractMvbProtocol::getEndianMode() const
{
    return this->endianMode;
}

quint16 QAbstractMvbProtocol::getWord(const quint8 *data, const quint8 wordAddress) const
{
    if (data == nullptr)
    {
        qDebug() << "the data is invalid" << _MVB4QT_LIB_INFO;

        return 0;
    }
    else if (wordAddress * 2 > 32 - sizeof (quint16))
    {
        qDebug() << "the byte address" << (wordAddress * 2) << "is out of range" << _MVB4QT_LIB_INFO;

        return 0;
    }
    else if (this->endianMode == Mvb4Qt::LittenEndian)
    {
        quint8 a[2] = {0};

        for (int i = 0; i < sizeof (quint16); i ++)
        {
            a[i] = data[byte + sizeof (T) - i];
        }

        return *(T *)a;
    }
    else if (this->endianMode == Mvb4Qt::BigEndian)
    {
        return *(qint8 *)(data + byte);
    }
}

void QAbstractMvbProtocol::setWord(const quint8 *data, const quint8 word, quint16 value)
{

}

quint8 QAbstractMvbProtocol::getByte(const quint8 *data, const quint8 byte) const
{

}

void QAbstractMvbProtocol::setByte(const bool bit)
{

}

bool QAbstractMvbProtocol::getBit(const quint8 *data, const quint8 byte, const quint8 bit) const
{

}

void QAbstractMvbProtocol::setBit(const bool bit)
{

}
