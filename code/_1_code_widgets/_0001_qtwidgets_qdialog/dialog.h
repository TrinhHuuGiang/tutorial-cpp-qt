#ifndef DIALOG_H
#define DIALOG_H

/* =================================================================
 * Definitions
================================================================= */

#include <QDialog>

// threadig
#include <QThread>

// normal
#include <QDebug>
#include <QRandomGenerator>

// app
#include <QScreen>
#include <QRect>
#include <QApplication>


QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

    void on_progressBar_valueChanged(int value);

    void on_progressBar_2_valueChanged(int value);

private:
    Ui::Dialog *ui;

    int process_bar_limit = 100;
    int process_bar_value = 0;
};
#endif // DIALOG_H
