#ifndef QMVBREGISTER_H
#define QMVBREGISTER_H

#include <QObject>
#include <QMap>
#include <QList>
#include "mvbglobal.h"

class QMvbPort;

/*
 * The class is the register of the mvb card that is used store almost all information like
 * device id, mvb ports and physical mode etc.
 */
class QMvbRegister : public QObject
{
    friend class QMvbCard;

public:
    QMvbRegister();
    ~QMvbRegister();

public:
    /*
     * Brief    Get all mvb port number in the mvb card.
     * Param    void
     * Return   Return a list of mvb port number.
     */
    QList<qint16> getPortNumberList() const;

    /*
     * Brief    Get all mvb port number of the specified type in the mvb card.
     * Param    "type" is the type of the mvb port number.
     * Return   Return a list of mvb port number of the specified type.
     */
    QList<qint16> getPortNumberList(const Mvb4Qt::MvbPortType type) const;

    /*
     * Brief    Get all mvb ports.
     * Param    void
     * Return   Return a list of mvb ports.
     */
    QList<QMvbPort *> getPortList() const;

    /*
     * Brief    Get the mvb port by the port number, if the port number doesn't exist, return null.
     * Param    "number" is the number of the port you want to get.
     * Return   Return the pointer of the mvb port.
     */
    QMvbPort *getPort(const qint16 number) const;

    /*
     * Brief    Add a source mvb port to the register.
     * Param    "number" is the number of the mvb port.
     *          "size" is the mvb port size, 2 4 8 16 or 32 could be applied.
     *          "cycle" is the feature cycle of the mvb port, if no value specified, default value 32ms would be used.
     *          "group" is the group that the mvb port belong to, it is useful when too many ports added,
     *                  and also if no value specified, default "" value all woule by used.
     * Return   Return true if the mvb port was added successfully, or return false.
     */
    bool addSourcePort(const qint16 number, const qint16 size, const quint16 cycle, const QString group = "");

    // See also the method of addSourcePort
    bool addSinkPort(const qint16 number, const qint16 size, const quint16 cycle, const QString group = "");

    // See also the method of addSourcePort
    bool addVirtualPort(const qint16 number, const qint16 size, const quint16 cycle, const QString group = "");

    /*
     * Brief    To test if the port of the number exists.
     * Param    "number" is the type of the mvb port number.
     * Return   Return true if the mvb port exists, or return false.
     */
    bool containPort(const qint16 number) const;

    /*
     * Brief    Remove the port of the number specified.
     * Param    "number" is the type of the mvb port number.
     * Return   Return true if remove successfully, or return false.
     */
    bool removePort(const qint16 number);

    qint16 getMinDeviceId() const;
    void setMinDeviceId(const qint16 minDeviceId);

    qint16 getMaxDeviceId() const;
    void setMaxDeviceId(const qint16 maxDeviceId);

    qint16 getMinPortNumber() const;
    void setMinPortNumeber(const qint16 minPortNumber);

    qint16 getMaxPortNumber() const;
    void setMaxPortNumber(const qint16 maxPortNumber);

    Mvb4Qt::MvbCardState getState() const;
    void setState(const Mvb4Qt::MvbCardState state);

    Mvb4Qt::MvbBufferSize getBufferSize() const;
    void setBufferSize(const Mvb4Qt::MvbBufferSize bufferSize);

    qint16 getDeviceId() const;
    void setdeviceId();

    Mvb4Qt::MvbPhyMode getPhyMode() const;
    void setPhyMode(const Mvb4Qt::MvbPhyMode phyMode);

    const QString &getName() const;
    void setName(const QString name);

private:
    /*
     * Brief    Add a mvb port to the register.
     * Param    "number" is the type of the mvb port number,
     *          "size" is the mvb port size, 2 4 8 16 or 32 could be applied.
     *          "type" is the mvb port type, sink source or virtual couble be applied.
     *          "cycle" is the feature cycle of the mvb port, if no value specified, default value 32ms would be used.
     *          "group" is the group that the mvb port belong to, it is useful when too many ports added,
     *                  and also if no value specified, default value all woule by used.
     * Return   Return true if the mvb port was added successfully, or return false.
     */
    bool addPort(const qint16 number, const qint16 size, const Mvb4Qt::MvbPortType type, const quint16 cycle = 32, QString group = "all");

    bool addAttribute(QString key, QString value);
    const QString &getAttribute(QString key) const;
    const QMap<QString, QString> &getAllAttribute() const;

private:
    QString name;
    qint16 deviceId;   // the id of mvb device
    Mvb4Qt::MvbPhyMode phyMode;    // the mode of mvb device
    Mvb4Qt::MvbBufferSize bufferSize;  // the buffer size of mvb device
    Mvb4Qt::MvbCardState state;    // the state of mvb card
    qint16 minDeviceId, maxDeviceId;    // the device limitation
    qint16 minPortNumber, maxPortNumber;    // the port number limitation
    QMap<qint16, QMvbPort *> portMap; // a map used to store all ports
    QMap<QString, QString> attributeMap;    // to store some attribute
};

#endif // QMVBREGISTER_H
