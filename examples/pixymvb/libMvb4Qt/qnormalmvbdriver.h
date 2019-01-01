#ifndef QNORMALMVBDRIVER_H
#define QNORMALMVBDRIVER_H

#include "qabstractmvbdriver.h"

/*
 * This class is an implementation of the abstract class QAbstractMvbDriver.
 * All methods invoked by the user will return true, but the port data will not be change,
 * this class can be applied in testing.
 */
class QNormalMvbDriver : public QAbstractMvbDriver
{
public:
    QNormalMvbDriver();
    virtual bool start(const QMvbRegister* mvbRegister);
    virtual bool stop(const QMvbRegister* mvbRegister);
    virtual bool configure(const QMvbRegister* mvbRegister);
    virtual bool updatePort(const QMvbRegister* mvbRegister, QMvbPort *port);
    virtual QString getVersion() const;
};

#endif // QNORMALMVBDRIVER_H
