#include <QApplication>
#include "qmvbcardmanagerviewer.h"
#include "createcarddialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // QMvbCardManagerViewer managerViewer;
    // managerViewer.show();
    CreateCardDialog dialog;
    dialog.show();

    // auto connection
    QMetaObject::connectSlotsByName(&dialog);

    return a.exec();
}
