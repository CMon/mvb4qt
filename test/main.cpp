#include <QApplication>
#include "qmvbcardmanagerview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMvbCardManagerView managerView;

    managerView.show();

    return a.exec();
}
