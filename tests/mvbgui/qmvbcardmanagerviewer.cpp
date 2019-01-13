#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include <QIcon>
#include <QLabel>
#include "qmvbcardmanagerviewer.h"
#include "ui_qmvbcardmanagerviewer.h"
#include "qmvbcardmanager.h"
#include "qmvbcardviewer.h"

QMvbCardManagerViewer::QMvbCardManagerViewer(QWidget *parent) :
    QWidget(parent)
{
    this->manager = QMvbCardManager::getManager();


    QHBoxLayout *topLayout = new QHBoxLayout();
    QHBoxLayout *bottomLayout = new QHBoxLayout();
    QVBoxLayout *mainLayout = new QVBoxLayout();

    QLabel *lblCardTitle = new QLabel("Select a Card:");
    this->cbCard = new QComboBox();
    lblCardTitle->setBuddy(this->cbCard);
    this->btnStart = new QPushButton("&Start");
    this->btnStop = new QPushButton("&Stop");

    topLayout->addWidget(lblCardTitle);
    topLayout->addWidget(this->cbCard);
    topLayout->addWidget(this->btnStart);
    topLayout->addWidget(this->btnStop);
    topLayout->addStretch();

    // Init the card viewer.
    foreach (QMvbCard *card, this->manager->getAllCard())
    {
        QMvbCardViewer *cardViewer = new QMvbCardViewer();
        cardViewer->bindCard(card);
        cardViewer->hide();
        this->cardViewerMap.insert(card->getMvbRegister()->getName(), cardViewer);
        this->cbCard->addItem(card->getMvbRegister()->getName());
        bottomLayout->addWidget(cardViewer);
    }

    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(bottomLayout);
    this->setLayout(mainLayout);

    this->setWindowTitle("Mvb4Qt-Gui");
    this->setWindowIcon(QIcon(":/images/logo.png"));

    this->connect(this->btnStart, SIGNAL(clicked()), this, SLOT(on_btnStart_clicked()), Qt::AutoConnection);
    this->connect(this->btnStop, SIGNAL(clicked()), this, SLOT(on_btnStop_clicked()), Qt::AutoConnection);
    this->connect(this->cbCard, SIGNAL(currentTextChanged(const QString &)), this, SLOT(on_cbCard_currentTextChanged(const QString &)), Qt::AutoConnection);
}

QMvbCardManagerViewer::~QMvbCardManagerViewer()
{
    delete ui;
}

void QMvbCardManagerViewer::on_btnStart_clicked()
{
    QString cardName = this->cbCard->currentText();

    QMvbCardManager::getManager()->getMvbCard(cardName)->start();

    qDebug() << "start the card named" << cardName;
}

void QMvbCardManagerViewer::on_btnStop_clicked()
{
    QString cardName = this->cbCard->currentText();

    QMvbCardManager::getManager()->getMvbCard(cardName)->stop();

    qDebug() << "stop the card named" << cardName;
}

void QMvbCardManagerViewer::on_cbCard_currentTextChanged(const QString &text)
{
    foreach (QString cardName, this->manager->getAllCardName())
    {
        if (cardName == text)
        {
            this->cardViewerMap[cardName]->show();
        }
        else
        {
            this->cardViewerMap[cardName]->hide();
        }
    }
}

void QMvbCardManagerViewer::showEvent(QShowEvent *event)
{
    foreach (QString cardName, this->manager->getAllCardName())
    {
        if (cardName == this->cbCard->currentText())
        {
            this->cardViewerMap[cardName]->show();
        }
        else
        {
            this->cardViewerMap[cardName]->hide();
        }
    }
}

void QMvbCardManagerViewer::statusChanged(const QString name)
{
    this->cardViewerMap[name]->update();
}
