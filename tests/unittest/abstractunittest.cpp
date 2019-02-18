#include <QDebug>
#include <QDateTime>
#include "abstractunittest.h"

AbstractUnitTest::AbstractUnitTest()
{

}

void AbstractUnitTest::run()
{
    qDebug() << "the test begins at" << QDateTime::currentDateTime().toString("hh:mm:ss.z");

    this->before();
    this->test();
    this->after();

    qDebug() << "the test ends at" << QDateTime::currentDateTime().toString("hh:mm:ss.z");
}

