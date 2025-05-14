#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
    , exit_flag(0)
{
    ui->setupUi(this);

    // resize fit with screen
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect availableGeometry = screen->availableGeometry();
    this->resize(availableGeometry.width(), availableGeometry.height());


    qDebug() << "[Constructed] << dialog";

}

Dialog::~Dialog()
{
    delete ui;

    qDebug() << "[Destructed] << dialog";
}

void Dialog::on_pushButton_clicked()
{
    if(exit_flag) return;

    exit_flag = true;
    this->hide();
    emit go_to_dialog_2();
    this->deleteLater();
}

