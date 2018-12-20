#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include "createcarddialog.h"

CreateCardDialog::CreateCardDialog()
{
    // the title and the icon
    this->setWindowTitle("Create A New Card");
    this->setWindowIcon(QIcon(":/logo.ico"));

    // the card name
    QHBoxLayout *hlyName = new QHBoxLayout();
    this->lblName = new QLabel("MVB Card Name");
    this->ldName = new QLineEdit();
    this->lblName->setBuddy(this->ldName);
    hlyName->addWidget(this->lblName);
    hlyName->addWidget(this->ldName);

    // the card driver
    QHBoxLayout *hlyDriver = new QHBoxLayout();
    this->lblDriver = new QLabel("MVB Driver");
    this->cbDriver = new QComboBox();
    this->lblDriver->setBuddy(this->cbDriver);
    hlyDriver->addWidget(this->lblDriver);
    hlyDriver->addWidget(this->cbDriver);

    // the card protocol
    QHBoxLayout *hlyProtocol = new QHBoxLayout();
    this->lblProtocol = new QLabel("MVB Protocol");
    this->cbProtocol = new QComboBox();
    this->lblProtocol->setBuddy(this->cbProtocol);
    hlyProtocol->addWidget(this->lblProtocol);
    hlyProtocol->addWidget(this->cbProtocol);

    // the operation buttons
    QHBoxLayout *hlyOperation = new QHBoxLayout();
    this->btnAdd = new QPushButton("&Add");
    this->btnAdd->setObjectName("btnAdd");
    this->btnCancel = new QPushButton("&Cancel");
    this->btnCancel->setObjectName("btnCancel");
    hlyOperation->addWidget(this->btnAdd);
    hlyOperation->addWidget(this->btnCancel);

    // the main layout
    QVBoxLayout *vlyMain = new QVBoxLayout();
    vlyMain->addLayout(hlyName);
    vlyMain->addLayout(hlyDriver);
    vlyMain->addLayout(hlyProtocol);
    vlyMain->addLayout(hlyOperation);
    this->setLayout(vlyMain);

    // fill the dirvers
    this->cbDriver->addItem("QSimulateDriver");

    // fill the protocols
    this->cbProtocol->addItem(("QLittleEndianProtocol"));
    this->cbProtocol->addItem(("QBigEndianProtocol"));
    this->cbProtocol->addItem(("QOffsetLittleEndianProtocol"));
    this->cbProtocol->addItem(("QOffsetBigEndianProtocol"));
}

void CreateCardDialog::on_btnAdd_clicked(bool checked)
{
    qDebug() << "a new mvb card has been added.";
}

void CreateCardDialog::on_btnCancel_clicked(bool checked)
{
    qDebug() << "no mvb card added.";
}

bool CreateCardDialog::addDriver(const QString &driver)
{

}

bool CreateCardDialog::addProtocol(const QString &protocol)
{

}

void CreateCardDialog::showEvent(QShowEvent *event)
{

}
