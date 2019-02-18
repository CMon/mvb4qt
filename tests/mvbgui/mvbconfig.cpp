#include "mvbconfig.h"
#include "qmvbcardmanager.h"
#include "qrandommvbdriver.h"
#include "qnormalmvbdriver.h"
#include "qlittleendianprotocol.h"
#include "qbigendianprotocol.h"
#include "qmvbcard.h"
#include "qmvbregister.h"
#include "qporttablewidget.h"

MvbConfig::MvbConfig()
{

}

// please write all config code in this method.
void MvbConfig::run()
{
    QMvbCardManager *manager = QMvbCardManager::getManager();

    // add the mvb card0
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


    // add the mvb card1
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


    // add the mvb card2
    QMvbCard *card2 = manager->addMvbCard("card2", new QNormalMvbDriver(), new QBigEndianProtocol());

    card2->getMvbRegister()->setDeviceId(0x03);
    card2->getMvbRegister()->setPhyMode(Mvb4Qt::MvbEmsMode);
    card2->getMvbRegister()->setBufferSize(Mvb4Qt::MinMvbBuffer);

    card2->getMvbRegister()->addSinkPort(0x811, 4, 128, "siv");
    card2->getMvbRegister()->addSinkPort(0x812, 8, 1024, "siv");
    card2->getMvbRegister()->addSinkPort(0x813, 16, 128, "siv");
    card2->getMvbRegister()->addSinkPort(0x121, 32, 64, "pcu");
    card2->getMvbRegister()->addSinkPort(0x122, 16, 256, "pcu");
    card2->getMvbRegister()->addSinkPort(0x123, 8, 32, "pcu");
    card2->getMvbRegister()->addSinkPort(0x131, 2, 512, "fau");
    card2->getMvbRegister()->addSinkPort(0x132, 4, 16, "fau");
    card2->getMvbRegister()->addSinkPort(0x133, 6, 32, "fau");
    card2->getMvbRegister()->addSourcePort(0x914, 16, 128, "vcu");
    card2->getMvbRegister()->addSourcePort(0x915, 32, 256, "vcu");
    card2->getMvbRegister()->addSourcePort(0x916, 32, 512, "vcu");
    card2->getMvbRegister()->addVirtualPort(0xF914, 32, 256, "vedcu");
    card2->getMvbRegister()->addVirtualPort(0xF915, 32, 256, "vedcu");
    card2->getMvbRegister()->addVirtualPort(0xF916, 32, 256, "vedcu");

    card1->configure();
}
