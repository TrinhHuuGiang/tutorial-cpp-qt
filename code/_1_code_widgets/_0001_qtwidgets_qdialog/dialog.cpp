/* =================================================================
 * Definitions
================================================================= */
#include "dialog.h"
#include "./ui_dialog.h"



/* =================================================================
 * Codes
================================================================= */
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // resize fit with screen
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect availableGeometry = screen->availableGeometry();
    this->resize(availableGeometry.width(), availableGeometry.height());

    // init
    ui->progressBar->setMaximum(this->process_bar_limit);
    ui->progressBar_2->setMaximum(this->process_bar_limit);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    qDebug() << "clicked\n[Current thread]" << QThread::currentThread();

    int i = QRandomGenerator::global()->bounded(this->process_bar_limit);

    this->ui->progressBar->setValue(i);
    this->ui->progressBar_2->setValue(process_bar_limit - i);
}


void Dialog::on_progressBar_valueChanged(int value)
{
    qDebug() << "changed"<< this->ui->progressBar  <<"[Current thread]" << QThread::currentThread();
}


void Dialog::on_progressBar_2_valueChanged(int value)
{
    qDebug() << "changed"<< this->ui->progressBar_2 <<" [Current thread]" << QThread::currentThread();
}


