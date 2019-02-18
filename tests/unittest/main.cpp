#include <QCoreApplication>
#include <QList>
#include "abstractunittest.h"
#include "qbigendianprotocoltest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<AbstractUnitTest *> list;
    list << new QBigEndianProtocolTest();

    for (AbstractUnitTest *unitTest: list)
    {
        unitTest->run();
    }

    return a.exec();
}
