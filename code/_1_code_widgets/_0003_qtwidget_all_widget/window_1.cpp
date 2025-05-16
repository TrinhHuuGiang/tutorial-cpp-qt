#include "window_1.h"
#include "./ui_window_1.h"

Window_1::Window_1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Window_1)
{
    ui->setupUi(this);

    // config widget

    // button box
    ui->buttonBox->addButton("Accept", QDialogButtonBox::AcceptRole);
    ui->buttonBox->addButton("Reject", QDialogButtonBox::RejectRole);
    ui->buttonBox->addButton("Destruct", QDialogButtonBox::DestructiveRole);
    ui->buttonBox->addButton("Action", QDialogButtonBox::ActionRole);
    ui->buttonBox->addButton("Help", QDialogButtonBox::HelpRole);
    ui->buttonBox->addButton("Yes", QDialogButtonBox::YesRole);
    ui->buttonBox->addButton("No", QDialogButtonBox::NoRole);
    ui->buttonBox->addButton("Apply", QDialogButtonBox::ApplyRole);
    ui->buttonBox->addButton("Reset", QDialogButtonBox::ResetRole);

}

Window_1::~Window_1()
{
    delete ui;
}


void Window_1::on_radioButton_clicked()
{
    this->ui->label_pushed_btn->setText("Radio 1 clicked");
}


void Window_1::on_radioButton_2_clicked()
{
    this->ui->label_pushed_btn->setText("Radio 2 clicked");
}


void Window_1::on_radioButton_3_clicked()
{
    this->ui->label_pushed_btn->setText("Radio 3 clicked");
}


void Window_1::on_radioButton_4_clicked()
{
    this->ui->label_pushed_btn->setText("Radio 4 clicked");
}


void Window_1::on_radioButton_5_clicked()
{
    this->ui->label_pushed_btn->setText(
        "1. Radio 5 clicked\n"
        "- :v\n"
        "- :0");
}


