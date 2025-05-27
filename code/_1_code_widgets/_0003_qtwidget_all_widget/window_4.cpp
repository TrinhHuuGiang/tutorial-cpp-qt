#include "window_4.h"
#include "ui_window_4.h"

Window_4::Window_4(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Window_4)
{
    ui->setupUi(this);

    // add value for combo box
    QStringList list_cb = {"Apple", "Mew Mew", "Pineapple", "Pen"};
    ui->comboBox->addItems(list_cb);


    // set text for line edit, text edit, plain text edit
    ui->lineEdit->setText("<b>Hello \n ooo</b>");

    ui->textEdit->setText("<b>Hello \n ooo</b>");

    ui->plainTextEdit->setPlainText("<b>Hello \n ooo</b>");

}

Window_4::~Window_4()
{
    delete ui;
}

void Window_4::on_comboBox_currentIndexChanged(int index)
{
    ui->label_5->setText(QString("Idx ") + QString::number(index) + ":" + ui->comboBox->currentText());
}


void Window_4::on_fontComboBox_currentFontChanged(const QFont &f)
{
    ui->label_6->setText(QString("Font ")+":" + f.family());

    ui->comboBox->setFont(f);
}


void Window_4::on_spinBox_valueChanged(int arg1)
{
    ui->label_14->setText(QString::number(arg1));
}


void Window_4::on_doubleSpinBox_valueChanged(double arg1)
{
    ui->label_15->setText(QString::number(arg1));
}


void Window_4::on_timeEdit_userTimeChanged(const QTime &time)
{
    ui->label_16->setText(time.toString("hh:mm:ss"));
}

