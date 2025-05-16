#include "window_2.h"
#include "ui_window_2.h"

Window_2::Window_2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Window_2)
    , model_view(new QStandardItemModel)
{
    ui->setupUi(this);

    // ============= [set widget]

    // chech model
    if(!model_view)
    {
        qDebug() << "[ERROR]" << model_view << "[is NULL]";
    }

    // model_view->setHorizontalHeaderLabels({"Tên", "Thông tin", "Ghi chú", "More"});
    model_view->setHorizontalHeaderLabels({"Tên", "Thông tin"});

    for(int i = 0; i < 10; i++)
    {
        QStandardItem *parenti = new QStandardItem(QString("Mục ")+QString::number(i));  // Cột 0
        QStandardItem *infoi   = new QStandardItem(QString("Thông tin ")+QString::number(i));
        QStandardItem *notei   = new QStandardItem(QString("Ghi chú ")+QString::number(i));

        QList<QStandardItem*> row;



        for(int j=0;j<5;j++)
        {
            QList<QStandardItem*> child_row;

            QStandardItem *child_j       =new QStandardItem(QString("Child ")+ QString::number(j));
            QStandardItem *child_infor_j =new QStandardItem(QString("Info ")+ QString::number(j));
            QStandardItem *child_note_j  =new QStandardItem(QString("Note ")+ QString::number(j));
            QStandardItem *child_more_j  =new QStandardItem(QString("More ")+ QString::number(j));

            child_row<<child_j<<child_infor_j<<child_note_j<< child_more_j;

            parenti->appendRow(child_row);
        }

        row << parenti<<infoi<<notei;

        model_view->appendRow(row);

        // qDeleteAll(row); not using , :) if make model_view empty

    }

    // add model to view
    ui->listView->setModel(model_view);
    ui->tableView->setModel(model_view);
    ui->treeView->setModel(model_view);

}

Window_2::~Window_2()
{
    delete ui;
}
