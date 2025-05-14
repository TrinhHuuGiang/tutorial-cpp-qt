#ifndef DIALOG_2_H
#define DIALOG_2_H

#include <QDialog>
#include <QDebug>

// app
#include <QScreen>
#include <QRect>

namespace Ui {
class Dialog_2;
}

class Dialog_2 : public QDialog
{
    Q_OBJECT
private:
    int exit_flag;
public:
    explicit Dialog_2(QWidget *parent = nullptr);
    ~Dialog_2();

signals:
    void go_to_dialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_2 *ui;
};

#endif // DIALOG_2_H
