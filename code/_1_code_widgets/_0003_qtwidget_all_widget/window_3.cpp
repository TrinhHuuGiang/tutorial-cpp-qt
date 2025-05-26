#include "window_3.h"
#include "ui_window_3.h"

Window_3::Window_3(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Window_3)
{
    ui->setupUi(this);


    ui->gridLayout_2->setColumnStretch(0, 1);
    ui->gridLayout_2->setColumnStretch(1, 2);
    ui->gridLayout_2->setColumnStretch(2, 1);
    ui->gridLayout_2->setRowStretch(0,2);
    ui->gridLayout_2->setRowStretch(1,1);
    ui->gridLayout_2->setRowStretch(2,1);

    ui->frame->setFrameShape(QFrame::Box);
    ui->frame->setFrameShadow(QFrame::Raised);
    ui->frame->setLineWidth(5);//px
    ui->frame->setMidLineWidth(5);

    qDebug() << "Set up layout";

}

Window_3::~Window_3()
{
    delete ui;
}
