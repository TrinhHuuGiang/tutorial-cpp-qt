#ifndef WINDOW_3_H
#define WINDOW_3_H

#include <QMainWindow>

#include <QFrame>

namespace Ui {
class Window_3;
}

class Window_3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window_3(QWidget *parent = nullptr);
    ~Window_3();

    QString svgToBase64Png(const QString &svgPath);

private:
    Ui::Window_3 *ui;
};

#endif // WINDOW_3_H
