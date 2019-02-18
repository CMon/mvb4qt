#ifndef UNITTEST_H
#define UNITTEST_H

#include <QObject>
#include <QDebug>

#define _STR(NAME) #NAME

class AbstractUnitTest: public QObject
{
public:
    AbstractUnitTest();
    virtual void before() = 0;
    virtual void after() = 0;
    virtual void test() = 0;
    void run();

    template <typename T>
    void assertEquals(QString name, T a, T b)
    {
        if (a == b)
        {
            qDebug() << name << "passes...";
        }
        else
        {
            qDebug() << name << "fails..." << a << "<>" << b;
        }
    }
};

#endif // UNITTEST_H
