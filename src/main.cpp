#include <QCoreApplication>
#include "mvb4qt.h"
#include "qmvbcard.h"
#include "qsimulatemvbdriver.h"
#include "qlittleendianprotocol.h"
#include "qthread.h"
int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

    QMvbCard *card =new QMvbCard("card0", new QSimulateMvbDriver(),new QMvbConfigure(), new QLittleEndianProtocol());

    card->configure();//configure 能否在addport后面？
    card->addSinkPort(0x01, 4, 128);
    card->addSinkPort(0x02, 8, 256);
    card->addSinkPort(0x03, 16, 512);
    card->addSinkPort(0x04, 32, 1024);
    card->addSourcePort(0x05, 32, 1024);
    card->addSourcePort(0x06, 32, 1024);
    // qDebug()<<QThread::currentThreadId();

    card->setInterval(2048);
    card->start();

    return a.exec();
}
