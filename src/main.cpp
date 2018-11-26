#include <QCoreApplication>
#include "mvb4qt.h"
#include "qmvbcard.h"
#include "qsimulatemvbdriver.h"
#include "qlittleendianprotocol.h"
#include "qthread.h"
int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

    QMvbCard *card =new QMvbCard(new QSimulateMvbDriver(), new QLittleEndianProtocol());

    card->addSinkPort(0x01, 4, 128);
    card->addSinkPort(0x02, 8, 256);
    card->addSinkPort(0x03, 16, 512);
    card->addSinkPort(0x04, 32, 1024);
    // qDebug()<<QThread::currentThreadId();

    card->setInterval(2048);
    card->configure();
    card->start();

    return a.exec();
}
