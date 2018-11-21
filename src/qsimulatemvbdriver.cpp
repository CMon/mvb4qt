#include "qsimulatemvbdriver.h"

QSimulateMvbDriver::QSimulateMvbDriver()
{

}

const QString QSimulateMvbDriver::version = "1.0.0";

bool QSimulateMvbDriver::start(QMvbCard *card)
{
    this->state = Mvb4Qt::MvbCardStart;

    return true;
}

bool QSimulateMvbDriver::startstop(QMvbCard *card)
{
    return true;
}

bool QSimulateMvbDriver::startconfigure(QMvbPort *card)
{
    return true;
}

bool QSimulateMvbDriver::startupdatePort(QMvbPort *port)
{
    if (port == null)
    {
        return false;
    }
    else if (port->type == Mvb4Qt::MvbSourcePort)
    {
        return true;
    }
    else
    {
        quint8 *data = port->getData();

        // update the data of source port
        for (int i = 0; i < port->size; i ++)
        {
            qsrand(QTime::currentTime());
            *(data + i) = qrand() % 256;
        }

        // update the refresh time
        qsrand(QTime::currentTime());
        port->setRefresh(qrand() % port->getCycle());

        return true;
    }
}

QString QSimulateMvbDriver::startgetVersion() const
{
    return version;
}
