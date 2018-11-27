#include "qsimulatemvbdriver.h"

QSimulateMvbDriver::QSimulateMvbDriver()
{
}

QSimulateMvbDriver::~QSimulateMvbDriver()
{

}

const QString QSimulateMvbDriver::version = "1.0.0";

bool QSimulateMvbDriver::start(const QMvbCard *card)
{
    return true;
}

bool QSimulateMvbDriver::stop(const QMvbCard *card)
{
    return true;
}

bool QSimulateMvbDriver::configure(QMvbConfigure *configure)
{
    configure->setDeviceId(0x31);
    configure->setPhyMode(Mvb4Qt::MvbEmdMode);
    configure->setState(Mvb4Qt::MvbCardConfigure);
    configure->setBufferSize(Mvb4Qt::MaxMvbBuffer);
    return true;
}

bool QSimulateMvbDriver::updatePort(QMvbPort *port)
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
            qsrand(QTime(0,0,0).secsTo(QTime::currentTime()) + i + port->getNumber());
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
    return version;
}
