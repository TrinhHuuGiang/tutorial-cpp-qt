#include "window_2.h"
#include "ui_window_2.h"

Window_2::Window_2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Window_2)
    , model_view(new QStandardItemModel)
{
    ui->setupUi(this);

    // ============= [set widget]

    //ITEMS VIEW
    // check model view
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




    // LIST WIDGET
    // add widget by hand
    QPushButton* btn_list_1 =new QPushButton;
    btn_list_1->setText(QString("ListBtn1"));

    QListWidgetItem* item_list_1 = new QListWidgetItem();
    ui->listWidget->addItem(item_list_1);


    // set widget to item

    // 1. check old widget if exist
    QObject* tmp_ob = ui->listWidget->itemWidget(item_list_1);
    if(tmp_ob)
    {
        ui->listWidget->removeItemWidget(item_list_1);
        delete tmp_ob; // dont care widget type
                    // using polimophism, QObject is parent all QWidget
    }
    ui->listWidget->setItemWidget(item_list_1,btn_list_1);

    item_list_1->setBackground(Qt::green);
    btn_list_1->setStyleSheet("color: red; margin: 2px;");

    // QListWidgetItem* item = ui->listWidget->takeItem(row); // row have item want take to delete
    // delete item;


    // TABLE WIDGET
    QPushButton* btn_table_1 = new QPushButton;
    btn_table_1->setText(QString("TableBtn1"));

    // QObject* tmp_ob = ui->tableWidget->item(row, col);

    // set table size
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setRowCount(6);

    // set table label
    ui->tableWidget->setHorizontalHeaderLabels({"Col1","Col2","Col3"});
    ui->tableWidget->setVerticalHeaderLabels({"Row1","Row2","Row3"});
    // set item
    QTableWidgetItem* table_item_1 = new QTableWidgetItem;
    ui->tableWidget->setItem(4,5,table_item_1); // back ground
    ui->tableWidget->setCellWidget(4,5,btn_table_1);// Logic

    table_item_1->setBackground(Qt::yellow);




    // TREE WIDGET
    // set tree label
    ui->treeWidget->setHeaderLabels({"Main Relate", "C2", "C3"});

    // set item
    ui->treeWidget->setColumnCount(4);

    // add item and widget
    for(int i = 1; i<=5;i++)
    {
        // item
        QTreeWidgetItem* tree_parent = new QTreeWidgetItem;
        // widget
        QPushButton* btn_tree_parent = new QPushButton;
        QPushButton* btn_tree_parent_2 = new QPushButton;
        btn_tree_parent->setText(QString("Tree Parent ") + QString::number(i));
        btn_tree_parent_2->setText(QString("Tree Parent ") + QString::number(i) + QString("Col 2"));

        ui->treeWidget->addTopLevelItem(tree_parent);
        ui->treeWidget->setItemWidget(tree_parent,0,btn_tree_parent);
        ui->treeWidget->setItemWidget(tree_parent,1,btn_tree_parent_2);

        // add child
        for(int j = 1; j<=5; j++)
        {
            // item
            QTreeWidgetItem* tree_child = new QTreeWidgetItem;
            // widget
            QPushButton* btn_tree_child = new QPushButton;
            QPushButton* btn_tree_child_3 = new QPushButton;
            btn_tree_child->setText(QString("Child ") + QString::number(j));
            btn_tree_child_3->setText(QString("Child ") + QString::number(j) + QString("Col3") );

            tree_parent->addChild(tree_child);

            ui->treeWidget->setItemWidget(tree_child, 0, btn_tree_child);
            ui->treeWidget->setItemWidget(tree_child, 3, btn_tree_child_3);

        }
    }



}

Window_2::~Window_2()
{
    delete ui;
}
