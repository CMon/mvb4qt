#ifndef QMVBREGISTERVIEWER_H
#define QMVBREGISTERVIEWER_H

#include <QWidget>

class QLabel;
class QMvbRegister;

class QMvbRegisterViewer : public QWidget
{
    Q_OBJECT
public:
    explicit QMvbRegisterViewer(QWidget *parent = nullptr);
    void showEvent(QShowEvent *event);
    void bindRegister(QMvbRegister *mvbRegister);

signals:

public slots:

private:
    QMvbRegister *mvbRegister;
    QLabel *lblNameTitle;
    QLabel *lblName;
    QLabel *lblDeviceIdTitle;
    QLabel *lblDeviceId;
    QLabel *lblBufferSizeTitle;
    QLabel *lblBufferSize;
    QLabel *lblPhyModeTitle;
    QLabel *lblPhyMode;
    QLabel *lblTotalPortTilte;
    QLabel *lblTotalPort;
    QLabel *lblSourcePortTitle;
    QLabel *lblSourcePort;
    QLabel *lblSinkPortTitle;
    QLabel *lblSinkPort;
    QLabel *lblVirtualPortTitle;
    QLabel *lblVirtualPort;
};

#endif // QMVBREGISTERVIEWER_H
