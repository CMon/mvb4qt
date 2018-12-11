#include <QDebug>
#include <QTime>
#include "qsimulatemvbdriver.h"
#include "mvb4qt.h"

QSimulateMvbDriver::QSimulateMvbDriver()
{
}

bool QSimulateMvbDriver::start(const QMvbRegister* mvbRegister)
{
    return true;
}

bool QSimulateMvbDriver::stop(const QMvbRegister* mvbRegister)
{
    return true;
}

bool QSimulateMvbDriver::configure(const QMvbRegister* mvbRegister)
{
    return true;
}

bool QSimulateMvbDriver::updatePort(const QMvbRegister* mvbRegister, QMvbPort *port)
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

QString QSimulateMvbDriver::getVersion() const
{
    return "1.0.0";
}
