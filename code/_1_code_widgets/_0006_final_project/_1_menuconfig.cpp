/* ==========================================================================
 * list object
 * - btn_broker_login
 * - btn_board_cf
 * - btn_mqtt_ud
 * - btn_wifi_ud
========================================================================== */



/* ==========================================================================
 * Definition
========================================================================== */
#include "_1_menuconfig.h"
#include "ui__1_menuconfig.h"

#define ICON_SVG_LOGIN ":/icon/rsrc/Icon/feather/log-in.svg"
#define ICON_SVG_BOARD_LAYER ":/icon/rsrc/Icon/feather/layers.svg"
#define ICON_SVG_MQTT_LINK    ":/icon/rsrc/Icon/feather/link.svg"
#define ICON_SVG_WIFI_CONNECT ":/icon/rsrc/Icon/feather/wifi.svg"





/* ==========================================================================
 * Class
========================================================================== */
_1_menuconfig::_1_menuconfig(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::_1_menuconfig)
{
    ui->setupUi(this);
    this->setWindowTitle("House Manager");

//==========================Style ================

    // set frame functions list ( see example combinations F1)
    ui->fl_frame->setFrameShape(QFrame::Box);
    ui->fl_frame->setFrameShadow(QFrame::Sunken);
    ui->fl_frame->setLineWidth(1);//ptx
    ui->fl_frame->setMidLineWidth(3);




    // set button/label

    QSize fl_icon_df_size = ui->btn_broker_login->size();
    fl_icon_df_size.setWidth(fl_icon_df_size.height()); // square



    ui->btn_broker_login->setStyleSheet(BTN_STYLE_DESIGN);
            // R"(...)" == Raw String Literal
            // -> enter to new line instead of "\n"
    ui->fl_broker_login->setPixmap(renderSvgToPixmap(ICON_SVG_LOGIN
                                                     ,fl_icon_df_size));


    ui->btn_board_cf->setStyleSheet(BTN_STYLE_DESIGN);
    ui->fl_board_cf->setPixmap(renderSvgToPixmap(ICON_SVG_BOARD_LAYER
                                                     ,fl_icon_df_size));



    ui->btn_mqtt_ud->setStyleSheet(BTN_STYLE_DESIGN);
    ui->fl_mqtt_ud->setPixmap(renderSvgToPixmap(ICON_SVG_MQTT_LINK
                                                     ,fl_icon_df_size));



    ui->btn_wifi_ud->setStyleSheet(BTN_STYLE_DESIGN);
    ui->fl_wifi_ud->setPixmap(renderSvgToPixmap(ICON_SVG_WIFI_CONNECT
                                                     ,fl_icon_df_size));


//==========================Inform Config ================

    qDebug()<<this<<"- created window menuconfig";
}

_1_menuconfig::~_1_menuconfig()
{
    delete ui;

    qDebug()<<this<<"- deleted window menuconfig";
}



void _1_menuconfig::on_btn_broker_login_clicked()
{

    // hide this window
    this->hide(); // no continue click, smooth when switch window

    // create broker login page

    qDebug() << this << "Creating login to broker page";

    _a_login_to_broker* login_broker = new(std::nothrow) _a_login_to_broker(nullptr); // nothow -> return nullptr if fail

    if(login_broker)
    {
        login_broker->show();
        qDebug() << this << "Created login to broker page";
    }
    else
    {
        qDebug() << this << "Failed when allocate new login to broker page";
        qDebug() << this << "Force quit app!!!";
        QApplication::quit();
    }

    // safe close by add delete command to last of queue exec loop
    this->deleteLater();
}


void _1_menuconfig::on_btn_board_cf_clicked()
{

    // hide this window
    this->hide(); // no continue click, smooth when switch window

    // create config logic block page

    qDebug() << this << "Creating config logic block page";

    _b_config_logic_layer * logic_block_page = new(std::nothrow) _b_config_logic_layer(nullptr); // nothow -> return nullptr if fail

    if(logic_block_page)
    {
        logic_block_page->show();
        qDebug() << this << "Created config logic block page";
    }
    else
    {
        qDebug() << this << "Failed when allocate new config logic block page";
        qDebug() << this << "Force quit app!!!";
        QApplication::quit();
    }

    // safe close by add delete command to last of queue exec loop
    this->deleteLater();
}


void _1_menuconfig::on_btn_mqtt_ud_clicked()
{

    // hide this window
    this->hide(); // no continue click, smooth when switch window

    // update mqtt page

    qDebug() << this << "Creating update mqtt page";

    _c_update_mqtt_info * update_mqtt_info_page = new(std::nothrow) _c_update_mqtt_info(nullptr); // nothow -> return nullptr if fail

    if(update_mqtt_info_page)
    {
        update_mqtt_info_page->show();
        qDebug() << this << "Created update mqtt page";
    }
    else
    {
        qDebug() << this << "Failed when allocate new update mqtt page";
        qDebug() << this << "Force quit app!!!";
        QApplication::quit();
    }

    // safe close by add delete command to last of queue exec loop
    this->deleteLater();
}


void _1_menuconfig::on_btn_wifi_ud_clicked()
{

    // hide this window
    this->hide(); // no continue click, smooth when switch window

    // update wifi page

    qDebug() << this << "Creating update wifi page";

    _d_update_wifi_info * update_wifi_info_page = new(std::nothrow) _d_update_wifi_info(nullptr); // nothow -> return nullptr if fail

    if(update_wifi_info_page)
    {
        update_wifi_info_page->show();
        qDebug() << this << "Created update wifi page";
    }
    else
    {
        qDebug() << this << "Failed when allocate new update wifi page";
        qDebug() << this << "Force quit app!!!";
        QApplication::quit();
    }

    // safe close by add delete command to last of queue exec loop
    this->deleteLater();
}

