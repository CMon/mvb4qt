#include <QMenuBar>
#include "qmvbcardmanagerviewer.h"

QMvbCardManagerViewer::QMvbCardManagerViewer(QWidget *parent)
                            : QMainWindow(parent)
{
    this->version = "1.0.0";

    this->setWindowTitle(QObject::tr("%1 V%2").arg("QMvbCardManagerViewer")
                            .arg(this->version));

    this->setWindowIcon(QIcon(":/images/icon.png"));

    // initial
    this->createAction();
    this->createMenu();
    this->createStatusBar();
}

void QMvbCardManagerViewer::createAction()
{
    this->cardMenu = this->menuBar()->addMenu(tr("&Card"));
}

void QMvbCardManagerViewer::createMenu()
{

}

void QMvbCardManagerViewer::createToolBar()
{

}

void QMvbCardManagerViewer::createStatusBar()
{
    this->cardToolBar = this->addToolBar(tr("&Card"));
}
