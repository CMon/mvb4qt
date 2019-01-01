#ifndef MVB4QT_H
#define MVB4QT_H

/*
 * This file defines a namespace and some necessary macros as a global reference
 * to this library class. Users must reference it before library programming.
 */

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
        MvbCardStop
    };

    enum EndianMode
    {
        BigEndian,
        LittenEndian
    };
}

#define _MVB4QT_LIB_INFO __FILE__ << __LINE__

#endif // MVB4QT_H
