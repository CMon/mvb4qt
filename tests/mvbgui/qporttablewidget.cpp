#include <QHeaderView>
#include "qporttablewidget.h"
#include "qmvbport.h"

QPortTableWidget::QPortTableWidget(QWidget *parent) :
    QTableWidget(parent)
{
    this->header << "port"
           << "0" << "1" << "2" << "3" << "4" << "5" << "6" << "7"
           << "8" << "9" << "10" << "11" << "12" << "13" << "14" << "15"
           << "16" << "17" << "18" << "19" << "20" << "21" << "22" << "23"
           << "24" << "25" << "26" << "27" << "28" << "29" << "30" << "31"
           << "group" << "refresh";

    this->setColumnCount(this->header.size());

    this->clearContents();
    this->setHorizontalHeaderLabels(this->header);

    this->verticalHeader()->setVisible(false);
}

void QPortTableWidget::update(QList<QMvbPort *> portList)
{
    this->clearContents();
    this->setRowCount(portList.size());

    for (int i = 0; i < portList.size(); i ++)
    {
        QMvbPort *port = portList.at(i);

        // port number
        QTableWidgetItem *portItem = new QTableWidgetItem(QString::number(port->getNumber(), 16));
        portItem->setTextAlignment(Qt::AlignCenter);
        portItem->setBackground(Qt::gray);
        this->setItem(i, 0, portItem);

        // data
        for (int j = 0; j < 32; j ++)
        {
            this->setItem(i, j + 1, new QTableWidgetItem(QString::number(*(port->getData() + j))));
        }

        // group
        this->setItem(i, 33, new QTableWidgetItem(port->getGroup()));

        // refresh
        this->setItem(i, 34, new QTableWidgetItem(QString::number(port->getRefresh())));
    }

    this->resizeColumnsToContents();
    this->resizeRowsToContents();
}
