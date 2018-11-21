#include <QCoreApplication>
#include "mvb4qt.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMvbCard *card =new QMvbCard(new QSimulateMvbDriver(), new QMvbProtocol());

    card->addSinkPort(0x01, 128);
    card->addSinkPort(0x02, 256);
    card->addSinkPort(0x03, 512);
    card->addSinkPort(0x04, 1024);

    card->setInterval(1024);
    card->configure();
    card->start();

    return a.exec();
}
