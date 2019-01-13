#ifndef QMVBCARDVIEWER_H
#define QMVBCARDVIEWER_H

#include <QWidget>

class QMvbRegisterViewer;
class QMvbPortViewer;
class QMvbCard;

class QMvbCardViewer : public QWidget
{
    Q_OBJECT

public:
    explicit QMvbCardViewer(QWidget *parent = nullptr);
    void bindCard(QMvbCard *card);
    void update();

signals:

public slots:

private:
    QMvbCard *card;
    QMvbPortViewer *portViewer;
    QMvbRegisterViewer *registerViewer;
};

#endif // QMVBCARDVIEWER_H
