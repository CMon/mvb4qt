#include "qabstractmvbprotocol.h"

QAbstractMvbProtocol::QAbstractMvbProtocol()
{
    quint8 test[2];

    *(quint16 *)test = 0x01;

    if (test[0] == 1)
    {
        this->endianMode = Mvb4Qt::LittenEndian;
    }
    else if (test[1] == 1)
    {
        this->endianMode = Mvb4Qt::BigEndian;
    }
    else
    {
        this->endianMode = Mvb4Qt::LittenEndian;
    }
}

Mvb4Qt::EndianMode QAbstractMvbProtocol::getEndianMode() const
{
    return this->endianMode;
}
