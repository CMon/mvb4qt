#ifndef CREATECARDDIALOG_H
#define CREATECARDDIALOG_H

#include <QDialog>
#include <QString>

class QLabel;
class QLineEdit;
class QComboBox;
class QPushButton;

class CreateCardDialog : public QDialog
{
    Q_OBJECT

public:
    CreateCardDialog();

signals:
    void addCard(const QString name, const QString driver, const QString protocol);
public slots:
    bool addDriver(const QString &driver);
    bool addProtocol(const QString &protocol);

private:
    void showEvent(QShowEvent *event);

private:
    QLabel *lblName;
    QLineEdit *ldName;
    QLabel *lblDriver;
    QComboBox *cbDriver;
    QLabel *lblProtocol;
    QComboBox *cbProtocol;
    QPushButton *btnAdd;
    QPushButton *btnCancel;

signals:

private slots:
    void on_btnAdd_clicked(bool checked);
    void on_btnCancel_clicked(bool checked);
};

#endif // CREATECARDDIALOG_H
