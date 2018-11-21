#ifndef QSIMULATEMVBDRIVER_H
#define QSIMULATEMVBDRIVER_H


#include <QTime>
#include "mvb4qt.h"

class QSimulateMvbDriver : QAbstractMvbDriver
{
public:
    QSimulateMvbDriver();
    bool start(const QMvbCard *card);
    bool stop(const QMvbCard *card);
    bool configure(const QMvbCard *card);
    bool updatePort(QMvbPort *port);
    QString getVersion() const;

private:
    const static QString version;   // the driver version
};

#endif // QSIMULATEMVBDRIVER_H
