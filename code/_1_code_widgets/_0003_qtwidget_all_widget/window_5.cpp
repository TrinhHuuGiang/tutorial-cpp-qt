#include "window_5.h"
#include "ui_window_5.h"

Window_5::Window_5(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Window_5)
{
    ui->setupUi(this);
}

Window_5::~Window_5()
{
    delete ui;
}
