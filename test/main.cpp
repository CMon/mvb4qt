#include "widget.h"
#include <QApplication>
#include <QDebug>
#include "mvb4qt.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    Mvb4Qt::MvbPortType type = Mvb4Qt::MvbSourcePort;
    qDebug() << type;

    w.show();

    return a.exec();
}
