#ifndef QSIMULATEMVBDRIVER_H
#define QSIMULATEMVBDRIVER_H


#include <QTime>
#include "mvb4qt.h"

class QSimulateMvbDriver : QAbstractMvbDriver
{
public:
    QSimulateMvbDriver();
    virtual bool start(const QMvbCard *card);
    virtual bool stop(const QMvbCard *card);
    virtual bool configure(const QMvbCard *card);
    virtual bool updatePort(QMvbPort *port);
    virtual QString getVersion() const;

private:
    const static QString version;   // the driver version
};

#endif // QSIMULATEMVBDRIVER_H
