#ifndef QABSTRACTMVBDRIVER_H
#define QABSTRACTMVBDRIVER_H

#include "mvb4qt.h"
#include "qmvbport.h"
#include "qmvbcard.h"

class QMvbCard;
class QMvbPort;

class QAbstractMvbDriver
{
public:
    virtual bool start(const QMvbCard *card) = 0;
    virtual bool stop(const QMvbCard *card) = 0;
    virtual bool configure(const QMvbCard *card) = 0;
    virtual bool updatePort(QMvbPort *port) = 0;
    virtual QString getVersion() const = 0;
};

#endif // QABSTRACTMVBDRIVER_H
