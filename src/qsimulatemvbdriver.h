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
    ~QSimulateMvbDriver();
    bool start(const QMvbCard *card);
    bool stop(const QMvbCard *card);
    bool configure(QMvbConfigure *card);
    bool updatePort(QMvbPort *port);
    QString getVersion() const;

private:
    const static QString version;   // the driver version
};

#endif // QSIMULATEMVBDRIVER_H
