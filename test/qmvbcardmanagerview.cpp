#include <QListView>
#include <QFrame>
#include <QHBoxLayout>
#include "qmvbcardmanagerview.h"
#include "qmvbcardview.h"

QMvbCardManagerView::QMvbCardManagerView(QWidget *parent) : QWidget(parent)
{
    this->listView = new QListView();
    this->frame = new QFrame();

    QHBoxLayout *mainLayout = new QHBoxLayout();

    mainLayout->addWidget(this->listView);
    mainLayout->addWidget(this->frame);

    // this->set
    this->setLayout(mainLayout);
}
