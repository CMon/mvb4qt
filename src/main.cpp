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

    card->getMvbRegister()->setDeviceId(0x01);
    card->getMvbRegister()->setPhyMode(Mvb4Qt::MvbEmdMode);
    card->getMvbRegister()->setBufferSize(Mvb4Qt::MaxMvbBuffer);

    card->getMvbRegister()->addSinkPort(0x01, 8, 128, "acu");
    card->getMvbRegister()->addSinkPort(0x02, 16, 256, "tcu");
    card->getMvbRegister()->addSinkPort(0x03, 32, 512, "bcu");

    card->getMvbRegister()->addSourcePort(0x11, 32, 128, "hmi");
    card->getMvbRegister()->addSourcePort(0x012, 32, 256, "hmi");
    card->getMvbRegister()->addSourcePort(0x013, 32, 512, "hmi");

    card->setQuint8(0x11, 0, 0xFF);
    card->setQuint8(0x12, 14, 0xFE);
    card->setQuint8(0x13, 31, 0xEE);

    card->configure();

    card->setDebugMode(true);
    card->setInterval(2048);
    card->start();

    double vehicleSpeed = card->getQuint16(0x01, 0) * 0.1;
    bool doorOpen = card->getBool(0x02, 2, 1);
    bool doorClose = card->getBool(0x03, 4, 7);
    quint32 mileage = card->getQuint32(0x03, 28);

    return a.exec();
}
