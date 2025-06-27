
/* ==========================================================================
 * list object
 *  - label_ic_back
 *  - btn_back
 *
 *  - combox_wnet
 *  - btn_refresh_wnet
 *
 *  - ledit_pass_wnet
 *  - label_check_wnet
 *
 *
 *  - label_status_log
 *
 *  - label_ic_up_wnet
 *  - btn_update_wnet
 *
 *
 *  - ledit_ssid_wap
 *  - ledit_pass_wap
 *
 *  - lbel_check_wap
 *  - label_ic_up_wap
 *
========================================================================== */



/* ==========================================================================
 * Definition
========================================================================== */

#include "_d_update_wifi_info.h"
#include "ui__d_update_wifi_info.h"


#define ICON_WIFI_NET_INFO ":/icon/rsrc/Icon/feather/server.svg"
#define ICON_AP_MODE_INFO  ":/icon/rsrc/Icon/feather/radio.svg"

#define ICON_SVG_BACK ":/icon/rsrc/Icon/feather/arrow-left.svg"

_d_update_wifi_info::_d_update_wifi_info(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::_d_update_wifi_info)
{
    ui->setupUi(this);
    this->setWindowTitle("Update wifi information");



    //==========================Style ================

    // set frame functions list ( see example combinations F1)
    ui->wifi_frame->setFrameShape(QFrame::Box);
    ui->wifi_frame->setFrameShadow(QFrame::Sunken);
    ui->wifi_frame->setLineWidth(1);//ptx
    ui->wifi_frame->setMidLineWidth(3);

    // set button/label wwifi net
    ui->btn_refresh_wnet->setStyleSheet(BTN_STYLE_DESIGN);

    ui->btn_update_wnet->setStyleSheet(BTN_STYLE_DESIGN);


    // set button/label wwifi ap
    ui->btn_update_wap->setStyleSheet(BTN_STYLE_DESIGN);


    // set button back
    QSize btn_back_size = ui->btn_back->size();
    btn_back_size.setWidth(btn_back_size.height()); // square

    ui->btn_back->setStyleSheet(BTN_STYLE_DESIGN);

    ui->label_ic_back->setPixmap(renderSvgToPixmap(ICON_SVG_BACK
                                                     ,btn_back_size));


    // tab widget
    ui->Tabwidget_wifi->setTabText(0,"");// clear for icon
    ui->Tabwidget_wifi->setTabText(1,"");// clear for icon

    {
        QIcon qicon_wnet(ICON_WIFI_NET_INFO);
        QIcon qicon_wap(ICON_AP_MODE_INFO);

        ui->Tabwidget_wifi->setTabIcon(0, qicon_wnet);
        ui->Tabwidget_wifi->setTabIcon(1, qicon_wap);

    }



    qDebug()<<this<<"- created window wifi inform";


}

_d_update_wifi_info::~_d_update_wifi_info()
{

    delete ui;

    qDebug()<<this<<"- deleted window wifi inform";
}

void _d_update_wifi_info::on_btn_back_clicked()
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

