#ifndef QRANDOMMVBDRIVER_H
#define QRANDOMMVBDRIVER_H

#include "qabstractmvbdriver.h"

/*
 * This class is an implementation of the abstract class QAbstractMvbDriver,
 * which is an simulation of mvb driver that allows users to generate random
 * numbers for each mvb port without mvb card. It is extremely useful under
 * test conditions.
 */
class QRandomMvbDriver : public QAbstractMvbDriver
{
public:
    QRandomMvbDriver();
    virtual bool start(const QMvbRegister* mvbRegister);
    virtual bool stop(const QMvbRegister* mvbRegister);
    virtual bool configure(const QMvbRegister* mvbRegister);

    // Generate random numbers for each mvb port.
    virtual bool updatePort(const QMvbRegister* mvbRegister, QMvbPort *port);

    virtual QString getVersion() const;
};

#endif // QRANDOMMVBDRIVER_H
