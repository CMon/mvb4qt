#ifndef QMVBPORT_H
#define QMVBPORT_H

#include <QObject>
#include "mvb4qt.h"

/*
 * This class is a the mvb port which contains all the information about the port,
 * such as port number, port type, refresh time, and port data.
 */
class QMvbPort : public QObject
{
public:
    /*
     * Brief    Constructor
     * Param    "number" the port number.
     *          "size" the size of the port, 2 bytes, 4 bytes or more.
     *          "type" source port or sink port.
     *          "cycle" the characteristic cycle of this port, 32ms, 64ms or more.
     *          "group" the group this port belong to.
     */
    explicit QMvbPort(const qint16 number, const quint16 size,
                        const Mvb4Qt::MvbPortType type, const quint16 cycle, QString group);

    qint16 getNumber() const;
    Mvb4Qt::MvbPortType getType() const;
    qint16 getSize() const;

    /*
     * Brief    Get the characteristic cyle of this port.
     * Param    void
     * Return   return the cycle.
     */
    quint16 getCycle() const;

    /*
     * Brief    Get the real refresh time of the port.
     * Param    void
     * Return   return the real refresh time
     */
    quint16 getRefresh() const;

    QString getGroup() const;
    void setRefresh(const quint16 refresh);

    /*
     * Brief    Get the starting address of the data storage area of the mvb port,
     *          32 bytes after the pointer are available.
     * Param    void
     * Return   The pointer of the data.
     */
    quint8 *getData() const;

    /*
     * Brief    All signal in this port would be set to 0.
     * Param    void
     * Return   void
     */
    void clear();

    /*
     * Brief    If refresh is larger than cycle, this port is timeout.
     * Param    void
     * Return   Return true if the port timeout, or return false.
     */
    bool isTimeout() const;

private:
    qint16 number; // the port number
    Mvb4Qt::MvbPortType type; // the source port or the sink port
    qint16 size;    // the port size
    quint16 cycle;   // the feature cycle
    quint16 refresh; // the real refresh time;
    quint8 data[32];    // the data of mvb port
    QString group;  // the group name of mvb port
};

#endif // QMVBPORT_H
