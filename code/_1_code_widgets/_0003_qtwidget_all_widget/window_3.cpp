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

    // set frame widget
    ui->frame->setFrameShape(QFrame::Box);
    ui->frame->setFrameShadow(QFrame::Raised);
    ui->frame->setLineWidth(5);//px
    ui->frame->setMidLineWidth(5);

    // add icon for label
    ui->label->setText("<img src=':/img_png/resources/img_png/airplane_wt.png' width='20' height='20'> Group Box");
    ui->label_2->setText("<img src=':/img_png/resources/img_png/airplane_bl.png' width='20' height='20'> Scroll Aria");

    ui->label_3->setText("svg img <img src=':/img_svg/resources/img_svg/people.svg' width='20' height='20'> Tool Box");           // << no support svg
    ui->label_4->setText("svg img <img src=':/img_svg/resources/img_svg/people_ellipsis.svg' width='20' height='20'> Tab Widget");// << no support svg
    ui->label_6->setText("svg img <img src=':/img_svg/resources/img_svg/people_question.svg' width='20' height='20'> MDI area");// << no support svg
    ui->label_7->setText("svg img <img src=':/img_svg/resources/img_svg/people_tick.svg' width='20' height='20'> Stacked Widget");// << no support svg


    ui->label_5->setText("Hello _ Dock Widget");
    ui->label_8->setText("Hello _ Frame");
    ui->label_9->setText("Hello _ Widget");

    qDebug() << "Set up layout";

}

Window_3::~Window_3()
{
    delete ui;
}

