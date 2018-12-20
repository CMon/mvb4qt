#include <QDebug>
#include <QTime>
#include "qrandommvbdriver.h"
#include "qmvbport.h"

QRandomMvbDriver::QRandomMvbDriver()
{
}

bool QRandomMvbDriver::start(const QMvbRegister* mvbRegister)
{
    return true;
}

bool QRandomMvbDriver::stop(const QMvbRegister* mvbRegister)
{
    return true;
}

bool QRandomMvbDriver::configure(const QMvbRegister* mvbRegister)
{
    return true;
}

bool QRandomMvbDriver::updatePort(const QMvbRegister* mvbRegister, QMvbPort *port)
{
    if (port == nullptr)
    {
        return false;
    }
    else if (port->getType() == Mvb4Qt::MvbSourcePort)
    {

        return true;
    }
    else
    {
        quint8 *data = port->getData();

        // update the data of source port
        for (int i = 0; i < port->getSize(); i ++)
        {
            qsrand(QTime(0,0,0).secsTo(QTime::currentTime()) + i * 100 + port->getNumber());
            *(data + i) = qrand() % 256;
        }

        // update the refresh time
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()) + port->getNumber());
        port->setRefresh(qrand() % port->getCycle());

        return true;
    }
}

QString QRandomMvbDriver::getVersion() const
{
    return "1.0.0";
}
