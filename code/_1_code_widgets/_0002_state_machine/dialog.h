#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>

// app
#include <QScreen>
#include <QRect>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT
private:
    int exit_flag;
public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

signals:
    void go_to_dialog_2();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
