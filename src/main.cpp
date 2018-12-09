#include <QCoreApplication>
#include "mvb4qt.h"
#include "mvb4qtglobal.h"

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

    QMvbCard *card = QMvbCardManager::getManager()->addMvbCard("card0", new QSimulateMvbDriver(), new QLittleEndianProtocol());

    card->getMvbRegister()->addSinkPort(0x01, 4, 128);
    card->getMvbRegister()->addSinkPort(0x02, 8, 256);
    card->getMvbRegister()->addSinkPort(0x03, 16, 512);
    card->getMvbRegister()->addSinkPort(0x04, 32, 1024);
    card->getMvbRegister()->addSourcePort(0x05, 32, 1024);
    card->getMvbRegister()->addSourcePort(0x06, 32, 1024);

    card->setInterval(2048);
    card->setDebugMode(true);
    card->start();

    return a.exec();
}
