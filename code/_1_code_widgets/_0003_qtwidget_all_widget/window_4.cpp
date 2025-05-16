#include "window_4.h"
#include "ui_window_4.h"

Window_4::Window_4(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Window_4)
{
    ui->setupUi(this);
}

Window_4::~Window_4()
{
    delete ui;
}
