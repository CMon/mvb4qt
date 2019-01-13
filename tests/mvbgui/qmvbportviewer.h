#ifndef QMVBPORTVIEWER_H
#define QMVBPORTVIEWER_H

#include <QTabWidget>

class QTableWidget;
class QPortTableWidget;
class QMvbRegister;

class QMvbPortViewer : public QTabWidget
{
    Q_OBJECT

public:
    QMvbPortViewer(QWidget *parent = nullptr);
    void bindRegister(QMvbRegister *mvbRegister);
    void updateWidget();
    void update();

private:
    QMvbRegister *mvbRegister;
    QPortTableWidget *sourcePortTable;
    QPortTableWidget *sinkPortTable;
    QPortTableWidget *virtualPortTable;
};

#endif // QMVBPORTVIEWER_H
