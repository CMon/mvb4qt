#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include <QIcon>
#include <QLabel>
#include <QGroupBox>
#include "qmvbcardmanagerviewer.h"
#include "ui_qmvbcardmanagerviewer.h"
#include "qmvbcardmanager.h"
#include "qmvbcardviewer.h"

QMvbCardManagerViewer::QMvbCardManagerViewer(QWidget *parent) :
    QWidget(parent)
{
    this->timer = new QTimer();     // the timer is used to refresh the widget.
    this->manager = QMvbCardManager::getManager();  // init the mvb manager.

    // the layouts in this widget.
    QHBoxLayout *topLayout = new QHBoxLayout();
    QHBoxLayout *bottomLayout = new QHBoxLayout();
    QVBoxLayout *mainLayout = new QVBoxLayout();

    // the components in the top layout.
    this->cbCard = new QComboBox();
    this->btnStart = new QPushButton("&Start");
    this->btnStop = new QPushButton("&Stop");
    QGroupBox *groupBox = new QGroupBox("Select Card");
    topLayout->addWidget(this->cbCard);
    topLayout->addWidget(this->btnStart);
    topLayout->addWidget(this->btnStop);
    topLayout->addStretch();
    groupBox->setLayout(topLayout);

    // init the viewers of the mvb card.
    foreach (QMvbCard *card, this->manager->getAllCard())
    {
        QMvbCardViewer *cardViewer = new QMvbCardViewer();
        cardViewer->bindCard(card);     // bind the mvb card.
        cardViewer->hide();
        this->cardViewerMap.insert(card->getMvbRegister()->getName(), cardViewer);
        this->cbCard->addItem(card->getMvbRegister()->getName());
        bottomLayout->addWidget(cardViewer);
    }

    // init the main layout.
    mainLayout->addWidget(groupBox);
    mainLayout->addLayout(bottomLayout);
    this->setLayout(mainLayout);

    // set the title and the logo of the widget.
    this->setWindowTitle("Mvb4Qt-Gui");
    this->setWindowIcon(QIcon(":/images/logo.png"));

    // signals and slots.
    this->connect(this->btnStart, SIGNAL(clicked()), this, SLOT(on_btnStart_clicked()), Qt::AutoConnection);
    this->connect(this->btnStop, SIGNAL(clicked()), this, SLOT(on_btnStop_clicked()), Qt::AutoConnection);
    this->connect(this->cbCard, SIGNAL(currentTextChanged(const QString &)), this, SLOT(on_cbCard_currentTextChanged(const QString &)), Qt::AutoConnection);
    this->connect(this->timer, SIGNAL(timeout()), this, SLOT(updateViewer()), Qt::AutoConnection);

}

QMvbCardManagerViewer::~QMvbCardManagerViewer()
{
    delete ui;
}

void QMvbCardManagerViewer::on_btnStart_clicked()
{
    QString cardName = this->cbCard->currentText();
    this->manager->getMvbCard(cardName)->start();

    qDebug() << "start the card named" << cardName;
}

void QMvbCardManagerViewer::on_btnStop_clicked()
{
    QString cardName = this->cbCard->currentText();
    this->manager->getMvbCard(cardName)->stop();

    qDebug() << "stop the card named" << cardName;
}

void QMvbCardManagerViewer::on_cbCard_currentTextChanged(const QString &text)
{
    // show the specific viewer according to the combobox
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

    this->timer->start(100);
}

// update the mvb card according to the timer.
void QMvbCardManagerViewer::updateViewer()
{
    foreach (QString cardName, this->manager->getAllCardName())
    {
        if (cardName == this->cbCard->currentText())
        {
            this->cardViewerMap[cardName]->update();
        }
    }

    this->update();
}
