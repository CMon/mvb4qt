#ifndef QMVBPORT_H
#define QMVBPORT_H

#include "mvb4qt.h"

using Mvb4Qt;

class QMvbPort: QObject
{
public:
    QMvbPort(const qint16 number, const enum MvbPortType type, const quint16 cycle, QString group);
    ~QMvbPort();
    qint16 getNumber() const;
    enum MvbPortType getType() const;
    qint16 getSize() const;
    quint16 getCycle() const;
    quint16 getRefresh() const;
    void setRefresh(const quint16 refresh);
    quint8 *getData() const;
    void setData(const quint8 data);
    void clear();

private:
    qint16 number; // the port number
    enum MvbPortType type; // the source port or the sink port
    qint16 size;    // the port size
    quint16 cycle;   // the feature cycle
    quint16 refresh; // the refresh time;
    quint8 data[32];    // the data of mvb port
    QString group;  // the group name of mvb port
};

#endif // QMVBPORT_H
