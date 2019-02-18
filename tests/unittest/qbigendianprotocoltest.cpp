#include "qbigendianprotocoltest.h"

QBigEndianProtocolTest::QBigEndianProtocolTest()
{

}

void QBigEndianProtocolTest::before()
{
    this->data = new quint8[32];

}

void QBigEndianProtocolTest::after()
{
    delete this->data;
}

void QBigEndianProtocolTest::test()
{
    this->testGetBool();
    this->testSetBool();
    this->testGetQint8();
    this->testSetQint8();
    this->testGetQint16();
    this->testSetQint16();
    this->testGetQint32();
    this->testSetQint32();
    this->testGetQuint8();
    this->testSetQuint8();
    this->testGetQuint16();
    this->testSetQuint16();
    this->testGetQuint32();
    this->testSetQuint32();
}

void QBigEndianProtocolTest::testGetBool()
{
    this->data[0] = 0x01;
    this->data[1] = 0x80;
    this->assertEquals<bool>(_STR(this->protocol.getBool(this->data, 0, 0)),
                                    this->protocol.getBool(this->data, 0, 0), true);
    this->assertEquals<bool>(_STR(this->protocol.getBool(this->data, 0, 1)),
                                    this->protocol.getBool(this->data, 0, 1), false);
    this->assertEquals<bool>(_STR(this->protocol.getBool(this->data, 1, 6)),
                                    this->protocol.getBool(this->data, 1, 6), false);
    this->assertEquals<bool>(_STR(this->protocol.getBool(this->data, 1, 7)),
                                    this->protocol.getBool(this->data, 1, 7), true);
}

void QBigEndianProtocolTest::testSetBool()
{
    this->data[2] = 0;
    this->protocol.setBool(this->data, 2, 0, true);
    this->protocol.setBool(this->data, 2, 1, false);
    this->assertEquals<bool>(_STR(this->protocol.getBool(this->data, 2, 0)), this->protocol.getBool(this->data, 2, 0), true);
    this->assertEquals<bool>(_STR(this->protocol.getBool(this->data, 2, 1)), this->protocol.getBool(this->data, 2, 1), false);
}

void QBigEndianProtocolTest::testGetQint8()
{

}

void QBigEndianProtocolTest::testSetQint8()
{

}

void QBigEndianProtocolTest::testGetQint16()
{

}

void QBigEndianProtocolTest::testSetQint16()
{

}

void QBigEndianProtocolTest::testGetQint32()
{

}

void QBigEndianProtocolTest::testSetQint32()
{

}

void QBigEndianProtocolTest::testGetQuint8()
{

}

void QBigEndianProtocolTest::testSetQuint8()
{

}

void QBigEndianProtocolTest::testGetQuint16()
{

}

void QBigEndianProtocolTest::testSetQuint16()
{

}

void QBigEndianProtocolTest::testGetQuint32()
{

}

void QBigEndianProtocolTest::testSetQuint32()
{

}
