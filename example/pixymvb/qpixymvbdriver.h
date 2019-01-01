#ifndef QPIXYMVBDRIVER_H
#define QPIXYMVBDRIVER_H

#include "qabstractmvbdriver.h"

class QPixyMvbDriver : public QAbstractMvbDriver
{
public:
    QPixyMvbDriver();
public:
    virtual bool start(const QMvbRegister* mvbRegister);
    virtual bool stop(const QMvbRegister* mvbRegister);
    virtual bool configure(const QMvbRegister* mvbRegister);
    virtual bool updatePort(const QMvbRegister* mvbRegister, QMvbPort *port);
    virtual QString getVersion() const;
};

#endif // QPIXYMVBDRIVER_H
