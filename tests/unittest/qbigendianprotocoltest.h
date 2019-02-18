#ifndef QBIGENDIAPROTOCOLTEST_H
#define QBIGENDIAPROTOCOLTEST_H

#include "abstractunittest.h"
#include "qbigendianprotocol.h"

class QBigEndianProtocolTest: public AbstractUnitTest
{
public:
    QBigEndianProtocolTest();
    virtual void before();
    virtual void after();
    virtual void test();

    // the test object
    quint8 *data;
    QBigEndianProtocol protocol;

private:
    void testGetBool();
    void testSetBool();
    void testGetQint8();
    void testSetQint8();
    void testGetQint16();
    void testSetQint16();
    void testGetQint32();
    void testSetQint32();
    void testGetQuint8();
    void testSetQuint8();
    void testGetQuint16();
    void testSetQuint16();
    void testGetQuint32();
    void testSetQuint32();
};

#endif // QBIGENDIAPROTOCOLTEST_H
