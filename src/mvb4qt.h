#ifndef MVB4QT_H
#define MVB4QT_H


#include "qabstractmvbdriver.h"
#include "qmvbport.h"
#include "qmvbprotocol.h"
#include "qsimulatemvbdriver.h"
#include "qmvbcard.h"

namespace Mvb4Qt
{
    enum MvbPortType
    {
        MvbSinkPort,
        MvbSourcePort,
        MvbVirtualPort
    };

    enum MvbPhyMode
    {
        MvbOfgMode,
        MvbEmdMode,
        MvbEmsMode
    };

    enum MvbBufferSize
    {
        MinMvbBuffer,
        MidMvbBuffer,
        MaxMvbBuffer
    };

    enum MvbCardState
    {
        MvbCardStart,
        MvbCardStop,
        MvbCardConfigure
    };
}

#endif // MVB4QT_H
