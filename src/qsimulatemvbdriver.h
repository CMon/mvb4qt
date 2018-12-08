#ifndef QSIMULATEMVBDRIVER_H
#define QSIMULATEMVBDRIVER_H


#include <QTime>
#include "mvb4qt.h"
#include "qmvbcard.h"
#include "qabstractmvbdriver.h"

class QSimulateMvbDriver : public QAbstractMvbDriver
{
public:
    QSimulateMvbDriver();
    virtual bool start(const QMvbRegister* mvbRegister);
    virtual bool stop(const QMvbRegister* mvbRegister);
    virtual bool configure(const QMvbRegister* mvbRegister);
    virtual bool updatePort(const QMvbRegister* mvbRegister, QMvbPort *port);
    virtual QString getVersion() const;
};

#endif // QSIMULATEMVBDRIVER_H
