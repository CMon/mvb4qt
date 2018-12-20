#ifndef QMVBCARDMANAGERVIEWER_H
#define QMVBCARDMANAGERVIEWER_H

#include <QMainWindow>

class QMenu;

class QMvbCardManagerViewer : public QMainWindow
{
    Q_OBJECT
public:
    explicit QMvbCardManagerViewer(QWidget *parent = nullptr);

signals:

public slots:

private:
    QString version;
    QMenu *cardMenu;
    QToolBar *cardToolBar;

private:
    void createAction();
    void createMenu();
    void createContextMenu();
    void createToolBar();
    void createStatusBar();
};

#endif // QMVBCARDMANAGERVIEWER_H
