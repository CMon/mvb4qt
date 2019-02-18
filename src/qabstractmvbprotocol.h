#ifndef QABSTRACTMVBPROTOCOL_H
#define QABSTRACTMVBPROTOCOL_H

#include <QObject>
#include <QtGlobal>
#include "mvb4qt.h"

/*
 * This is an abstract class of the mvb protocol, users should implement it according to their
 * own real protocol in order to obtain bool data integer data etc.
 */
class QAbstractMvbProtocol : public QObject
{
public:
    QAbstractMvbProtocol();

    /*
     * Brief    Get endian mode of the platform, it is useful when parse signals.
     * Param    void
     * Return   Enum EndianMode
     */
    Mvb4Qt::EndianMode getEndianMode() const;

    /*
     * Brief    Get bool variable from the specific mvb port.
     * Param    "data" is the starting address of the data storage area of the mvb port,
     *                 32 bytes after the pointer are available, of course user should
     *                 consider of the size of the mvb port.
     *          "byte" is the index of byte, different protocols of application means different
     *                 things, such as the byte index 0 means byte0, but in other protocols it
     *                 means byte31.
     *          "bit" is similar to byte, that is the index of bit.
     * Return   Return true if the bit at that address is 1, or return false,
     *          if the address is invalid, return false.
     */
    virtual bool getBool(const quint8 *data, const quint8 byte, const quint8 bit) const = 0;

    /*
     * Brief    Set bool variable in the specific mvb port to specific value.
     * Param    "data", "byte", "bit" see also the method of getBool.
     *          "value" is the value that the signal at that address would by set.
     * Return   void
     */
    virtual void setBool(quint8 *data, const quint8 byte, quint8 bit, const bool value) const = 0;

    /*
     * Brief    Get int8 variable from the specific mvb port.
     * Param    "data", "byte", "bit" see also the method of getBool.
     * Return   Return the value at that address.
     */
    virtual qint8 getQint8(const quint8 *data, const quint8 byte) const = 0;

    /*
     * Brief    Set int8 variable in the specific mvb port to specific value.
     * Param    "data", "byte", "bit" see also the method of getBool.
     *          "value" is the value that the signal at that address would by set.
     * Return   void
     */
    virtual void setQint8(quint8 *data, const quint8 byte, const qint8 value) = 0;

    virtual qint16 getQint16(const quint8 *data, const quint8 byte) const = 0;
    virtual void setQint16(quint8 *data, const quint8 byte, const qint16 value) = 0;
    virtual qint32 getQint32(const quint8 *data, const quint8 byte) const = 0;
    virtual void setQint32(quint8 *data, const quint8 byte, const qint32 value) = 0;
    virtual quint8 getQuint8(const quint8 *data, const quint8 byte) const = 0;
    virtual void setQuint8(quint8 *data, const quint8 byte, const quint8 value) = 0;
    virtual quint16 getQuint16(const quint8 *data, const quint8 byte) const = 0;
    virtual void setQuint16(quint8 *data, const quint8 byte, const quint16 value) = 0;
    virtual quint32 getQuint32(const quint8 *data, const quint8 byte) const = 0;
    virtual void setQuint32(quint8 *data, const quint8 byte, const quint32 value) = 0;

    virtual quint16 getWord(const quint8 *data, const quint8 wordAddress) const;
    virtual void setWord(const quint8 *data, const quint8 wordAddress, quint16 value);
    virtual quint8 getByte(const quint8 *data, const quint8 byteAddress) const;
    virtual void setByte(const quint8 *data, const quint8 byteAddress, quint8 value);
    virtual bool getBit(const quint8 *data, const quint8 byteAddress, const quint8 bitAddress) const;
    virtual void setBit(const quint8 *data, const quint8 byteAddress, const quint8 bitAddress, const bool value);

protected:
    Mvb4Qt::EndianMode endianMode;
};

#endif // QABSTRACTMVBPROTOCOL_H
