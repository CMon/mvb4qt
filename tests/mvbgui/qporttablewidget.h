#ifndef QPORTTABLEWIDGET_H
#define QPORTTABLEWIDGET_H

#include <QTableWidget>
#include <QList>
#include <QStringList>

class QMvbPort;

class QPortTableWidget : public QTableWidget
{
public:
    QPortTableWidget(QWidget *parent = nullptr);
    void update(QList<QMvbPort *> portList);

signals:

public slots:

private:
    QStringList header;
};

#endif // QPORTTABLEWIDGET_H
