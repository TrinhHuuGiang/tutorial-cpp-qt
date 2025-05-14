#include "dialog_2.h"
#include "ui_dialog_2.h"

Dialog_2::Dialog_2(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_2)
    , exit_flag(0)
{
    ui->setupUi(this);

    // resize fit with screen
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect availableGeometry = screen->availableGeometry();
    this->resize(availableGeometry.width(), availableGeometry.height());

    qDebug() << "[Constructed] << dialog_2";
}

Dialog_2::~Dialog_2()
{
    delete ui;

    qDebug() << "[Destructed] << dialog_2";
}

void Dialog_2::on_pushButton_clicked()
{
    if(exit_flag) return;

    exit_flag = true;
    this->hide();
    emit go_to_dialog();
    this->deleteLater();
}

