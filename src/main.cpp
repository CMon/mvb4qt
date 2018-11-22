#include <QCoreApplication>
#include "mvb4qt.h"
#include "qmvbcard.h"
#include "qsimulatemvbdriver.h"
#include "qmvbprotocol.h"
#include "qthread.h"
int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

    QMvbCard *card =new QMvbCard(new QSimulateMvbDriver(), new QMvbProtocol());

    card->addSinkPort(0x01, 128);
    card->addSinkPort(0x02, 256);
    card->addSinkPort(0x03, 512);
    card->addSinkPort(0x04, 1024);
    qDebug()<<QThread::currentThreadId();

    card->setInterval(111);
    card->configure();
    card->start();

    return a.exec();
}
