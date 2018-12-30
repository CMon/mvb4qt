#include "qnormalmvbdriver.h"

QNormalMvbDriver::QNormalMvbDriver()
{

}

bool QNormalMvbDriver::start(const QMvbRegister* mvbRegister)
{
    return true;
}

bool QNormalMvbDriver::stop(const QMvbRegister* mvbRegister)
{
    return true;
}

bool QNormalMvbDriver::configure(const QMvbRegister* mvbRegister)
{
    return true;
}

bool QNormalMvbDriver::updatePort(const QMvbRegister* mvbRegister, QMvbPort *port)
{
    return true;
}

QString QNormalMvbDriver::getVersion() const
{
    return "1.0.0";
}
