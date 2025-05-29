#include "http_test.h"
#include "ui_http_test.h"

http_test::http_test(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::http_test)
{
    ui->setupUi(this);
}

http_test::~http_test()
{
    delete ui;
}
