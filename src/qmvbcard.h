#ifndef QMVBCARD_H
#define QMVBCARD_H


#include <QObject>
#include <QMap>
#include <QTimer>
#include <QReadWriteLock>
#include <QReadLocker>
#include <QWriteLocker>
#include <QThread>
#include "mvb4qt.h"
#include "qmvbregister.h"

class QAbstractMvbDriver;
class QAbstractMvbProtocol;

/*
 * The class is the register of the mvb card that is used store almost all information like
 * device id, mvb ports and physical mode etc.
 */
class QMvbCard : public QObject
{
    Q_OBJECT

    friend class QMvbCardManager;

public:
    ~QMvbCard();

public:
    /*
     * Brief    Get the pointer of the register that could be used to configure this card.
     * Param    void
     * Return   Return the pointer of the mvb register.
     */
    QMvbRegister *getMvbRegister();

    /*
     * Brief    Get the interval time of refreshing mvb data whose unit is millisecond.
     * Param    void
     * Return   Return the interval time(millisecond).
     */
    qint32 getInterval() const;

    /*
     * Brief    Get the endian mode of this hardware, it would be delegated by protocol class.
     * Param    void
     * Return   Return enum EndianMode.
     */
    Mvb4Qt::EndianMode getEndianMode() const;

    /*
     * Brief    Get bool variable from the specific mvb port, the implementation
     *          is is delegated to the protocol that the user specified.
     * Param    "byte" is the index of byte according to the protocol.
     *          "bit" is the index of bit according to the protocol.
     * Return   Return true if the bit at that address is 1, or return false,
     *          if the address is invalid, return false.
     */
    bool getBool(const qint16 number, const quint8 byte, const quint8 bit);

    /*
     * Brief    Set bool variable in the specific mvb port to specific value, the implementation
     *          is is delegated to the protocol that the user specified.
     * Param    "byte", "bit" see also the method of getBool.
     *          "value" is the value that the signal at that address would by set.
     * Return   void
     */
    void setBool(const qint16 number, const quint8 byte, quint8 bit, const bool value);

    /*
     * Brief    Get int8 variable from the specific mvb port, the implementation
     *          is is delegated to the protocol that the user specified.
     * Param    "byte" is the index of byte according to the protocol.
     *          "bit" is the index of bit according to the protocol.
     * Return   Return the value at that address.
     */
    qint8 getQint8(const qint16 number, const quint8 byte);

    /*
     * Brief    Set int8 variable in the specific mvb port to specific value, the implementation
     *          is is delegated to the protocol that the user specified.
     * Param    "byte", "bit" see also the method of getBool.
     *          "value" is the value that the signal at that address would by set.
     * Return   void
     */
    void setQint8(const qint16 number, const quint8 byte, const qint8 value);
    qint16 getQint16(const qint16 number, const quint8 byte);
    void setQint16(const qint16 number, const quint8 byte, const qint16 value);
    qint32 getQint32(const qint16 number, const quint8 byte);
    void setQint32(const qint16 number, const quint8 byte, const qint32 value);
    quint8 getQuint8(const qint16 number, const quint8 byte);
    void setQuint8(const qint16 number, const quint8 byte, const quint8 value);
    quint16 getQuint16(const qint16 number, const quint8 byte);
    void setQuint16(const qint16 number, const quint8 byte, const quint16 value);
    quint32 getQuint32(const qint16 number, const quint8 byte);
    void setQuint32(const qint16 number, const quint8 byte, const quint32 value);
    quint8 getByte() const;
    void setByte(const bool bit);
    bool getBit() const;
    void setBit(const bool bit);

public slots:
    /*
     * Brief    Start the mvb card, it would send or receive data automatically.
     * Param    void
     * Return   void
     */
    void start();

    /*
     * Brief    Stop the mvb card, it wouldn't send or receive, but data in mvb card would be reserved.
     * Param    void
     * Return   void
     */
    void stop();

    /*
     * Brief    Configure the mvb card according to the register, this method should be called when the
     *          the card stopped.
     *
     * Param    void
     * Return   void
     */
    void configure();

    /*
     * Brief    All data in mvb port would be printed on console in each refresh time
     *          when the debug mode is enabled.
     * Param    "debugMode" set true or false.
     * Return   void
     */
    void setDebugMode(const bool debugMode);

    /*
     * Brief    Set the interval time of refreshing mvb data whose unit is millisecond.
     * Param    void
     * Return   void
     */
    void setInterval(const qint32 interval);

signals:
    void refreshed(const QString cardName);

private:
    explicit QMvbCard(QString name, QAbstractMvbDriver *driver = nullptr, QAbstractMvbProtocol *protocol = nullptr);

private:
    QMvbRegister *mvbRegister;
    QAbstractMvbDriver *driver;
    QAbstractMvbProtocol *protocol;
    QTimer *timer;
    QReadWriteLock lock;
    QThread thread;
    bool debugMode;

private slots:
    void updateCard();
};

#endif // QMVBCARD_H
