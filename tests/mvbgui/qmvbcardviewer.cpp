#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "qmvbcardviewer.h"
#include "qmvbregisterviewer.h"
#include "qmvbportviewer.h"
#include "qmvbcard.h"

QMvbCardViewer::QMvbCardViewer(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout();

    this->registerViewer = new QMvbRegisterViewer();
    this->portViewer = new QMvbPortViewer();

    mainLayout->addWidget(registerViewer);
    mainLayout->addWidget(portViewer);
    mainLayout->addStretch();

    this->setLayout(mainLayout);
}

void QMvbCardViewer::bindCard(QMvbCard *card)
{
    this->card = card;
    this->registerViewer->bindRegister(this->card->getMvbRegister());
    this->portViewer->bindRegister(this->card->getMvbRegister());
}

void QMvbCardViewer::update()
{
    this->registerViewer->update();
    this->portViewer->update();

    QWidget::update();
}
