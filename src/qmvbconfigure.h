#ifndef QMVBCONFIGURE_H
#define QMVBCONFIGURE_H
#include <QObject>
#include "mvb4qt.h"

class QMvbConfigure
{
public:
    QMvbConfigure();

    //based on XXMVB API

    //quint8 tMModel;
    //quint8 SNKTIMESUPVINTV;
    quint8 phyMode;
    quint16 deviceID;


};

#endif // QMVBCONFIGURE_H
