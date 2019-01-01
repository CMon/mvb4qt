#include "qpixymvbdriver.h"
#include "PixyMvbLib.h"
#include "PixyTypes.h"
#include "qmvbregister.h"
#include "qmvbport.h"

QPixyMvbDriver::QPixyMvbDriver()
{

}

bool QPixyMvbDriver::start(const QMvbRegister* mvbRegister)
{
    quint16 value = pixymvb_ChangeState(PIXYMVB_OPERATION_STATE);

    if (PIXYMVB_OK == value)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool QPixyMvbDriver::stop(const QMvbRegister* mvbRegister)
{
    quint16 value = pixymvb_ChangeState(PIXYMVB_STOP_STATE);

    if (PIXYMVB_OK == value)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool QPixyMvbDriver::configure(const QMvbRegister* mvbRegister)
{
    quint16 value = 0;

    // configure the parameters of the mvb card
    quint16 bufferSize = 0, phyMode = 0;

    if (mvbRegister->getBufferSize() == Mvb4Qt::MinMvbBuffer
            || mvbRegister->getBufferSize() == Mvb4Qt::MidMvbBuffer)
    {
        bufferSize = PIXYMVB_MIN_TMMODEL;
    }
    else if (mvbRegister->getBufferSize() == Mvb4Qt::MaxMvbBuffer)
    {
        bufferSize = PIXYMVB_MAX_TMMODEL;
    }

    if (mvbRegister->getPhyMode() == Mvb4Qt::MvbEmdMode)
    {
        phyMode = PIXYMVB_PHY_EMD;
    }
    else if (mvbRegister->getPhyMode() == Mvb4Qt::MvbEmsMode)
    {
        phyMode = PIXYMVB_PHY_ESD;
    }
    else if (mvbRegister->getPhyMode() == Mvb4Qt::MvbOfgMode)
    {
        phyMode = PIXYMVB_PHY_OFG;
    }

    value = pixymvb_CfgHWInit(PIXYMVB_MIN_TMMODEL, PIXYMVB_PHY_EMD, mvbRegister->getDeviceId(), 1);

    if (PIXYMVB_OK != value)
    {
        return false;
    }

    // configure the source and sink port
    foreach (QMvbPort *port, mvbRegister->getPortList())
    {
        if (port->getType() == Mvb4Qt::MvbSourcePort)
        {
            value = pixymvb_AddPort(port->getNumber(), PIXYMVB_SRCPORT, port->getSize() / 2, (PIXYMVB_Data *)(port->getData()));
        }
        else if (port->getType() == Mvb4Qt::MvbSinkPort)
        {
            value = pixymvb_AddPort(port->getNumber(), PIXYMVB_SNKPORT, port->getSize() / 2, (PIXYMVB_Data *)(port->getData()));
        }

        if (PIXYMVB_OK != value)
        {
            return false;
        }
    }

    return true;
}

bool QPixyMvbDriver::updatePort(const QMvbRegister* mvbRegister, QMvbPort *port)
{
    quint16 value = 0;

    foreach (QMvbPort *port, mvbRegister->getPortList())
    {
        if (port->getType() == Mvb4Qt::MvbSourcePort)
        {
            value = pixymvb_PutPort(port->getNumber(), (PIXYMVB_Data *)(port->getData()));
        }
        else if (port->getType() == Mvb4Qt::MvbSinkPort)
        {
            quint16 refresh = 0;

            value = pixymvb_GetPort(port->getNumber(), (PIXYMVB_Data *)(port->getData()), &refresh);
            port->setRefresh(refresh);  // update its refresh time
        }

        if (PIXYMVB_OK != value)
        {
            return false;
        }
    }
}

QString QPixyMvbDriver::getVersion() const
{
    quint32 major = 0, minor = 0;
    quint16 value = 0;

    value = pixymvb_GetLibVersion(&major, &minor);

    if (PIXYMVB_OK == value)
    {
        QString temp;

        return temp.sprintf("%d.%d", major, minor);
    }
    else
    {
        return QString("0");
    }
}
