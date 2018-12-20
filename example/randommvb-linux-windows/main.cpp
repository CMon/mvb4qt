#include <QCoreApplication>
#include "qmvbcardmanager.h"
#include "qrandommvbdriver.h"
#include "qlittleendianprotocol.h"
#include "qmvbcard.h"
#include "qmvbregister.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMvbCardManager *manager = QMvbCardManager::getManager();
    QMvbCard *card = manager->addMvbCard("random", new QRandomMvbDriver(), new QLittleEndianProtocol());

    card->getMvbRegister()->addSinkPort(0x01, 32, 128);
    card->getMvbRegister()->addSinkPort(0x02, 16, 256);
    card->getMvbRegister()->addSinkPort(0x03, 8, 512);
    card->getMvbRegister()->addSinkPort(0x04, 4, 1024);
    card->setDebugMode(true);
    card->setInterval(2048);
    card->start();

    return a.exec();
}
