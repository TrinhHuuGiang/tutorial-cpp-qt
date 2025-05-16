#ifndef WINDOW_5_H
#define WINDOW_5_H

#include <QMainWindow>

namespace Ui {
class Window_5;
}

class Window_5 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window_5(QWidget *parent = nullptr);
    ~Window_5();

private:
    Ui::Window_5 *ui;
};

#endif // WINDOW_5_H
