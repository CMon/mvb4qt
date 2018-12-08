#ifndef MVB4QT_H
#define MVB4QT_H


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
