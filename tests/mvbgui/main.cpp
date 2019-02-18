#include <QApplication>
#include <QTableWidget>
#include "qmvbcardmanagerviewer.h"
#include "mvbconfig.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // configure the mvb card.
    MvbConfig config;
    config.run();

    // init the viewer of the mvb manager.
    QMvbCardManagerViewer viewer;
    viewer.show();

    return a.exec();
}
