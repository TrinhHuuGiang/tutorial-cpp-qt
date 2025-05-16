#include "window_3.h"
#include "ui_window_3.h"

Window_3::Window_3(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Window_3)
{
    ui->setupUi(this);
}

Window_3::~Window_3()
{
    delete ui;
}
