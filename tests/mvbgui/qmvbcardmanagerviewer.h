#ifndef QMVBCARDMANAGERVIEWER_H
#define QMVBCARDMANAGERVIEWER_H

#include <QWidget>
#include <QMap>

class QComboBox;
class QPushButton;
class QMvbCardViewer;

namespace Ui {
class QMvbCardManagerViewer;
}

class QMvbCardManager;

class QMvbCardManagerViewer : public QWidget
{
    Q_OBJECT

public:
    explicit QMvbCardManagerViewer(QWidget *parent = 0);
    ~QMvbCardManagerViewer();

public slots:
    void on_btnStart_clicked();
    void on_btnStop_clicked();
    void on_cbCard_currentTextChanged(const QString &text);
    void showEvent(QShowEvent *event);
    void statusChanged(const QString name);
signals:

private:
    Ui::QMvbCardManagerViewer *ui;
    QMap<QString, QMvbCardViewer *> cardViewerMap;
    QMvbCardManager *manager;
    QComboBox *cbCard;
    QPushButton *btnStart;
    QPushButton *btnStop;
};

#endif // QMVBCARDMANAGERVIEWER_H
