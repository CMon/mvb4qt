#include "qmvbregister.h"

QMvbRegister::QMvbRegister()
    : minDeviceId(0), maxDeviceId(4095)
{
    // set the default value of mvb register
    this->deviceId = 0x01;
    this->phyMode = Mvb4Qt::MvbEmdMode;
    this->bufferSize = Mvb4Qt::MaxMvbBuffer;
    this->state = Mvb4Qt::MvbCardStop;
}

QMvbRegister::~QMvbRegister()
{
    foreach (quint16 number, this->portMap.keys())
    {
        delete this->portMap[number];
        this->portMap.remove(number);
    }
}

bool QMvbRegister::addPort(const qint16 number, const qint16 size, const Mvb4Qt::MvbPortType type, const quint16 cycle, QString group)
{
    if (this->state != Mvb4Qt::MvbCardStop)
    {
        qDebug() << "please stop the mvb card name of" << this->name
                    << "before adding port operation" << _MVB4QT_LIB_INFO;

        return false;
    }
    else if (this->portMap.contains(number))
    {
        QString temp;

        temp.sprintf("0x%d", QString::number(number, 16));
        qDebug() << "the port number" << temp << "has already been added";

        return false;
    }
    else if (type != Mvb4Qt::MvbVirtualPort && (number < 0 || number > 4095)
    {

    }
    else
    {
        this->portMap.insert(number, new QMvbPort(number, size, type, cycle, group));

        return true;
    }
}

QList<qint16> QMvbRegister::getPortNumberList() const
{
    return this->portMap.keys();
}

QList<qint16> QMvbRegister::getPortNumberList(const Mvb4Qt::MvbPortType type) const
{
    QList<qint16> list;

    foreach(qint16 number, this->portMap.keys())
    {
        if (this->portMap[number]->type == type)
        {
            list << number;
        }
    }

    return list;
}

QMvbPort *QMvbRegister::getPort(const qint16 number) const
{
    if (this->portMap.contains(number))
    {
        return this->portMap[number];
    }
    else
    {
        QString temp;

        temp.sprintf("%d0x", QString::number(number, 16));
        qDebug() << "fail getting the port number" << temp << _MVB4QT_LIB_INFO;

        return nullptr;
    }
}
