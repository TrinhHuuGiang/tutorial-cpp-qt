#ifndef WINDOW_4_H
#define WINDOW_4_H

#include <QMainWindow>

#include <QStringList>


namespace Ui {
class Window_4;
}

class Window_4 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window_4(QWidget *parent = nullptr);
    ~Window_4();

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_fontComboBox_currentFontChanged(const QFont &f);

    void on_spinBox_valueChanged(int arg1);

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_timeEdit_userTimeChanged(const QTime &time);

private:
    Ui::Window_4 *ui;
};

#endif // WINDOW_4_H
