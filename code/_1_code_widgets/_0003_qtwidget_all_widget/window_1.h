#ifndef WINDOW_1_H
#define WINDOW_1_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Window_1;
}
QT_END_NAMESPACE

class Window_1 : public QMainWindow
{
    Q_OBJECT

public:
    Window_1(QWidget *parent = nullptr);
    ~Window_1();

private slots:
    void on_radioButton_2_clicked();

    void on_radioButton_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_5_clicked();

private:
    Ui::Window_1 *ui;
};
#endif // WINDOW_1_H
