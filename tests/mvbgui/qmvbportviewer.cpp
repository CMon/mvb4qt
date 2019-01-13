#include "qmvbregister.h"
#include "qmvbportviewer.h"
#include "qporttablewidget.h"

QMvbPortViewer::QMvbPortViewer(QWidget *parent) :
    QTabWidget(parent)
{
    this->sourcePortTable = new QPortTableWidget();
    this->sinkPortTable = new QPortTableWidget();
    this->virtualPortTable = new QPortTableWidget();

    this->addTab(this->sourcePortTable, "Source Ports");
    this->addTab(this->sinkPortTable, "Sink Ports");
    this->addTab(this->virtualPortTable, "Virtual Ports");
}

void QMvbPortViewer::bindRegister(QMvbRegister *mvbRegister)
{
    this->mvbRegister = mvbRegister;
}

void QMvbPortViewer::update()
{
    this->sourcePortTable->update(this->mvbRegister->getSourcePortList());
    this->sinkPortTable->update(this->mvbRegister->getSinkPortList());
    this->virtualPortTable->update(this->mvbRegister->getVirtualPortList());

    QTabWidget::update();
}
