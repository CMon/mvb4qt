#ifndef QABSTRACTMVBDRIVER_H
#define QABSTRACTMVBDRIVER_H

#include <QObject>

class QMvbRegister;
class QMvbPort;

/*
 * This class is an abstract class of MVB card, which requires users to implement the class
 * according to the api function of the actual card, like pixy mvb card and siemens mvb card.
 */
class QAbstractMvbDriver : public QObject
{
public:
    /*
     * Brief    Start the mvb card.
     * Param    "mvbRegister" contains all configuration information of the mvb card,
     *                        including device id, source port and sink port etc.
     *                        See also the class of QMvbRegister.
     * Return   Return true if start the mvb card successfully, or return false.
     */
    virtual bool start(const QMvbRegister* mvbRegister) = 0;

    /*
     * Brief    Stop the mvb card.
     * Param    "mvbRegister" see also the method of start.
     * Return   Return true if stop the mvb card successfully, or return false.
     */
    virtual bool stop(const QMvbRegister* mvbRegister) = 0;

    /*
     * Brief    Configure the mvb card.
     * Param    "mvbRegister" see also the method of start.
     * Return   Return true if configure the mvb card successfully, or return false.
     */
    virtual bool configure(const QMvbRegister* mvbRegister) = 0;

    /*
     * Brief    Update the mvb port.
     * Param    "mvbRegister" see also the method of start.
     *          "port" is the mvb port to update, it contains all information of a mvb port,
     *                 like port number, port data and refresh time etc.
     *                 See also the class of QMvbPort.
     * Return   Return a list of mvb port number.
     */
    virtual bool updatePort(const QMvbRegister* mvbRegister, QMvbPort *port) = 0;

    /*
     * Brief    Get the version of the api function of the actual card, sometimes it is useful
     *          to ensure the quality of the software.
     * Param    void
     * Return   Return the version of the api function.
     */
    virtual QString getVersion() const = 0;
};

#endif // QABSTRACTMVBDRIVER_H
