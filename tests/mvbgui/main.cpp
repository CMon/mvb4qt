#include <QApplication>
#include <QTableWidget>
#include "qmvbcardmanagerviewer.h"
#include "qmvbcardmanager.h"
#include "qrandommvbdriver.h"
#include "qnormalmvbdriver.h"
#include "qlittleendianprotocol.h"
#include "qbigendianprotocol.h"
#include "qmvbcard.h"
#include "qmvbregister.h"
#include "qporttablewidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMvbCardManager *manager = QMvbCardManager::getManager();
    QMvbCard *card0 = manager->addMvbCard("card0", new QRandomMvbDriver(), new QLittleEndianProtocol());

    card0->getMvbRegister()->setDeviceId(0x01);
    card0->getMvbRegister()->setPhyMode(Mvb4Qt::MvbEmdMode);
    card0->getMvbRegister()->setBufferSize(Mvb4Qt::MaxMvbBuffer);

    card0->getMvbRegister()->addSinkPort(0x411, 8, 128, "acu");
    card0->getMvbRegister()->addSinkPort(0x412, 8, 128, "acu");
    card0->getMvbRegister()->addSinkPort(0x413, 8, 128, "acu");

    card0->getMvbRegister()->addSinkPort(0x511, 16, 256, "tcu");
    card0->getMvbRegister()->addSinkPort(0x512, 16, 256, "tcu");
    card0->getMvbRegister()->addSinkPort(0x513, 16, 256, "tcu");

    card0->getMvbRegister()->addSinkPort(0x611, 32, 512, "bcu");
    card0->getMvbRegister()->addSinkPort(0x612, 32, 512, "bcu");
    card0->getMvbRegister()->addSinkPort(0x613, 32, 512, "bcu");

    card0->getMvbRegister()->addSourcePort(0x711, 32, 128, "hmi");
    card0->getMvbRegister()->addSourcePort(0x712, 32, 256, "hmi");
    card0->getMvbRegister()->addSourcePort(0x713, 32, 512, "hmi");

    card0->configure();

    // card->setDebugMode(true);
    // card->setInterval(2048);
    // card->start();

    QMvbCard *card1 = manager->addMvbCard("card1", new QNormalMvbDriver(), new QBigEndianProtocol());

    card1->getMvbRegister()->setDeviceId(0x02);
    card1->getMvbRegister()->setPhyMode(Mvb4Qt::MvbEmsMode);
    card1->getMvbRegister()->setBufferSize(Mvb4Qt::MinMvbBuffer);

    card1->getMvbRegister()->addSinkPort(0x111, 4, 128, "siv");
    card1->getMvbRegister()->addSinkPort(0x112, 8, 1024, "siv");
    card1->getMvbRegister()->addSinkPort(0x113, 16, 128, "siv");

    card1->getMvbRegister()->addSinkPort(0x121, 32, 64, "pcu");
    card1->getMvbRegister()->addSinkPort(0x122, 16, 256, "pcu");
    card1->getMvbRegister()->addSinkPort(0x123, 8, 32, "pcu");

    card1->getMvbRegister()->addSinkPort(0x131, 2, 512, "fau");
    card1->getMvbRegister()->addSinkPort(0x132, 4, 16, "fau");
    card1->getMvbRegister()->addSinkPort(0x133, 6, 32, "fau");

    card1->getMvbRegister()->addSourcePort(0x214, 16, 128, "vcu");
    card1->getMvbRegister()->addSourcePort(0x215, 32, 256, "vcu");
    card1->getMvbRegister()->addSourcePort(0x216, 32, 512, "vcu");

    card1->configure();

     QMvbCardManagerViewer viewer;

     QObject::connect(card0, SIGNAL(refreshed(const QString)), &viewer, SLOT(statusChanged(const QString)));
     QObject::connect(card1, SIGNAL(refreshed(const QString)), &viewer, SLOT(statusChanged(const QString)));

    viewer.show();

    return a.exec();
}
