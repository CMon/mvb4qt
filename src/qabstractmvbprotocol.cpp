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
