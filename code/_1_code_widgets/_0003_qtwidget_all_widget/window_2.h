#ifndef WINDOW_2_H
#define WINDOW_2_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QStandardItem>

#include <QDebug>
#include <QString>
#include <QList>
#include <QtAlgorithms>


namespace Ui {
class Window_2;
}

class Window_2 : public QMainWindow
{
    Q_OBJECT
private:
    QStandardItemModel* model_view;

public:
    explicit Window_2(QWidget *parent = nullptr);
    ~Window_2();

private:
    Ui::Window_2 *ui;
};

#endif // WINDOW_2_H
