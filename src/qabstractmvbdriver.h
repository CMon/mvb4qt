#ifndef QABSTRACTMVBDRIVER_H
#define QABSTRACTMVBDRIVER_H

#include "mvb4qt.h"
#include "qmvbport.h"
#include "qmvbcard.h"
#include "qmvbconfigure.h"
#include "qmvbregister.h"

class QMvbCard;
class QMvbPort;
class QMvbConfigure;

class QAbstractMvbDriver
{
public:
    virtual bool start(const QMvbRegister* mvbRegister) = 0;
    virtual bool stop(const QMvbRegister* mvbRegister) = 0;
    virtual bool configure(const QMvbRegister* mvbRegister) = 0;
    virtual bool updatePort(const QMvbRegister* mvbRegister, QMvbPort *port) = 0;
    virtual QString getVersion() const = 0;
};

#endif // QABSTRACTMVBDRIVER_H
