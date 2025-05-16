#ifndef WINDOW_4_H
#define WINDOW_4_H

#include <QMainWindow>

namespace Ui {
class Window_4;
}

class Window_4 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window_4(QWidget *parent = nullptr);
    ~Window_4();

private:
    Ui::Window_4 *ui;
};

#endif // WINDOW_4_H
