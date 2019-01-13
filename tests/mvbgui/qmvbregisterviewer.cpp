#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QGroupBox>
#include "qmvbregisterviewer.h"
#include "qmvbregister.h"

QMvbRegisterViewer::QMvbRegisterViewer(QWidget *parent)
    : QWidget(parent)
{
    this->lblNameTitle = new QLabel("Card Name:");
    this->lblDeviceIdTitle = new QLabel("Device Id:");
    this->lblBufferSizeTitle = new QLabel("Buffer Size:");
    this->lblPhyModeTitle = new QLabel("Physical Layer:");
    this->lblTotalPortTilte = new QLabel("Total Ports:");
    this->lblSourcePortTitle = new QLabel("Source Ports:");
    this->lblSinkPortTitle = new QLabel("Sink Ports:");
    this->lblVirtualPortTitle = new QLabel("Virtual Ports:");

    QFont font;
    font.setBold(true);

    this->lblNameTitle->setFont(font);
    this->lblDeviceIdTitle->setFont(font);
    this->lblBufferSizeTitle->setFont(font);
    this->lblPhyModeTitle->setFont(font);
    this->lblTotalPortTilte->setFont(font);
    this->lblSourcePortTitle->setFont(font);
    this->lblSinkPortTitle->setFont(font);
    this->lblVirtualPortTitle->setFont(font);

    QGridLayout *gridLayout = new QGridLayout();

    gridLayout->addWidget(this->lblNameTitle, 0, 0);
    gridLayout->addWidget(this->lblDeviceIdTitle, 0, 2);
    gridLayout->addWidget(this->lblBufferSizeTitle, 0, 4);
    gridLayout->addWidget(this->lblPhyModeTitle, 0, 6);

    gridLayout->addWidget(this->lblTotalPortTilte, 1, 0);
    gridLayout->addWidget(this->lblSourcePortTitle, 1, 2);
    gridLayout->addWidget(this->lblSinkPortTitle, 1, 4);
    gridLayout->addWidget(this->lblVirtualPortTitle, 1, 6);

    this->lblName = new QLabel();
    this->lblNameTitle->setBuddy(this->lblName);
    this->lblDeviceId = new QLabel();
    this->lblBufferSize = new QLabel();
    this->lblPhyMode = new QLabel();
    this->lblTotalPort = new QLabel();
    this->lblSourcePort = new QLabel();
    this->lblSinkPort = new QLabel();
    this->lblVirtualPort = new QLabel();

    gridLayout->addWidget(this->lblName, 0, 1);
    gridLayout->addWidget(this->lblDeviceId, 0, 3);
    gridLayout->addWidget(this->lblBufferSize, 0, 5);
    gridLayout->addWidget(this->lblPhyMode, 0, 7);

    gridLayout->addWidget(this->lblTotalPort, 1, 1);
    gridLayout->addWidget(this->lblSourcePort, 1, 3);
    gridLayout->addWidget(this->lblSinkPort, 1, 5);
    gridLayout->addWidget(this->lblVirtualPort, 1, 7);

    gridLayout->setSpacing(20);

    QGroupBox *groupBox = new QGroupBox("Basic Information");
    groupBox->setLayout(gridLayout);

    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->addWidget(groupBox);
    mainLayout->addStretch();

    this->setLayout(mainLayout);
}

void QMvbRegisterViewer::showEvent(QShowEvent *event)
{
    this->lblName->setText(this->mvbRegister->getName());
    this->lblDeviceId->setText(QString::number(this->mvbRegister->getDeviceId()));

    // buffer size
    switch (this->mvbRegister->getBufferSize())
    {
        case Mvb4Qt::MaxMvbBuffer:
           this->lblBufferSize->setText("Max Size");
           break;
        case Mvb4Qt::MidMvbBuffer:
           this->lblBufferSize->setText("Middle Size");
           break;
        case Mvb4Qt::MinMvbBuffer:
           this->lblBufferSize->setText("Min Size");
           break;
        default:
            this->lblBufferSize->setText("Unknown");
    }

    // physical layer
    switch (this->mvbRegister->getPhyMode())
    {
        case Mvb4Qt::MvbEmdMode:
            this->lblPhyMode->setText("EMD");
            break;
        case Mvb4Qt::MvbEmsMode:
            this->lblPhyMode->setText("EMS");
            break;
        case Mvb4Qt::MvbOfgMode:
            this->lblPhyMode->setText("OFG");
            break;
        default:
            this->lblPhyMode->setText("Unknown");
    }

    this->lblTotalPort->setText(QString::number(this->mvbRegister->getPortSum()));
    this->lblSourcePort->setText(QString::number(this->mvbRegister->getSourcePortSum()));
    this->lblSinkPort->setText(QString::number(this->mvbRegister->getSinkPortSum()));
    this->lblVirtualPort->setText(QString::number(this->mvbRegister->getVirtualPortSum()));
}

void QMvbRegisterViewer::bindRegister(QMvbRegister *mvbRegister)
{
    this->mvbRegister = mvbRegister;
}
