#ifndef QMVBCARDMANAGERVIEW_H
#define QMVBCARDMANAGERVIEW_H

#include <QWidget>

class QListView;
class QFrame;

class QMvbCardManagerView : public QWidget
{
    Q_OBJECT
public:
    explicit QMvbCardManagerView(QWidget *parent = nullptr);

signals:

public slots:

private:
    QListView *listView;
    QFrame *frame;
};

#endif // QMVBCARDMANAGERVIEW_H
