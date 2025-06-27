/* ==========================================================================
 * list object
 *  - label_ic_back
 *  - btn_back
 *
 *  - combox_list_avail
 *
 *  - btn_add_wishlist
 *  - label_ic_add_wishlist
 *
 *  - label_stat_select
 *
 *  - combox_list_order
 *
 *  - label_logic_if_log
 *
 *  - btn_start_cf_ic
 *  - btn_start_cf
========================================================================== */



/* ==========================================================================
 * Definition
========================================================================== */


#include "_b_config_logic_layer.h"
#include "ui__b_config_logic_layer.h"

#define ICON_SVG_BACK ":/icon/rsrc/Icon/feather/arrow-left.svg"
#define ICON_SVG_ADD_WISH ":/icon/rsrc/Icon/feather/thumbs-up.svg"
#define ICON_SVG_START_CF ":/icon/rsrc/Icon/feather/tool.svg"


_b_config_logic_layer::_b_config_logic_layer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::_b_config_logic_layer)
{
    ui->setupUi(this);
    this->setWindowTitle("Setup logic blocks to board");




    //==========================Inform Config ================


    // set frame functions list ( see example combinations F1)
    ui->frame_cf_lgb->setFrameShape(QFrame::Box);
    ui->frame_cf_lgb->setFrameShadow(QFrame::Sunken);
    ui->frame_cf_lgb->setLineWidth(1);//ptx
    ui->frame_cf_lgb->setMidLineWidth(3);



    // button and label

    // set button/ label back
    {
        QSize btn_back_size = ui->btn_back->size();
        btn_back_size.setWidth(btn_back_size.height()); // square

        ui->btn_back->setStyleSheet(BTN_STYLE_DESIGN);

        ui->label_ic_back->setPixmap(renderSvgToPixmap(ICON_SVG_BACK
                                                       ,btn_back_size));

    }



    // btn_add_wishlist
    // label_ic_add_wishlist
    {
        QSize btn_wishlist_size = ui->btn_add_wishlist->size();
        btn_wishlist_size.setWidth(btn_wishlist_size.height()); // square

        ui->btn_add_wishlist->setStyleSheet(BTN_STYLE_DESIGN);

        ui->label_ic_add_wishlist->setPixmap(renderSvgToPixmap(ICON_SVG_ADD_WISH
                                                               ,btn_wishlist_size));
    }



    // btn_start_cf_ic
    // - btn_start_cf
    {
        QSize btn_start_size = ui->btn_start_cf->size();
        btn_start_size.setWidth(btn_start_size.height()); // square

        ui->btn_start_cf->setStyleSheet(BTN_STYLE_DESIGN);

        ui->btn_start_cf_ic->setPixmap(renderSvgToPixmap(ICON_SVG_START_CF
                                                               ,btn_start_size));
    }


    // groupbox
    ui->groupBox_select->setStyleSheet(GROUPBOX_OUTLINE_DESIGN);
    ui->groupBox_added->setStyleSheet(GROUPBOX_OUTLINE_DESIGN);


    qDebug()<<this<<"- created window config logic layer";
}

_b_config_logic_layer::~_b_config_logic_layer()
{
    delete ui;

    qDebug()<<this<<"- deleted window config logic layer";
}

void _b_config_logic_layer::on_btn_back_clicked()
{
    // hide this window
    this->hide(); // no continue click, smooth when switch window

    // return menu page

    qDebug() << this << "Returning menu page";

    _1_menuconfig * menu_page = new(std::nothrow) _1_menuconfig(nullptr); // nothow -> return nullptr if fail

    if(menu_page)
    {
        menu_page->show();
        qDebug() << this << "Created menu page";
    }
    else
    {
        qDebug() << this << "Failed when allocate menu_page";
        qDebug() << this << "Force quit app!!!";
        QApplication::quit();
    }

    // safe close by add delete command to last of queue exec loop
    this->deleteLater();
}

