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
        MvbCardStop,
        MvbCardConfigure
    };

    enum EndianMode
    {
        BigEndian,
        LittenEndian
    };
}

#endif // MVB4QT_H
