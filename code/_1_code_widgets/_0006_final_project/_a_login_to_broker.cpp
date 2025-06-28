/*
    Copyright (C) 2025  Giang Trinh

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

/* ==========================================================================
 * list object
 *  - label_ic_back
 *  - btn_back
 *
 *  - ledit_url_broker
 *  - ledit_port_broker
 *  - ledit_username
 *  - ledit_password
 *
 *  - ledit_log_status
 *
 *  - label_ic_reconn
 *  - btn_reconn
 *
 *  - tabwid_logic_controller
 *
========================================================================== */



/* ==========================================================================
 * Definition
========================================================================== */
#include "_a_login_to_broker.h"
#include "ui__a_login_to_broker.h"


#define ICON_SVG_BACK ":/icon/rsrc/Icon/feather/arrow-left.svg"
#define ICON_SVG_RECONN ":/icon/rsrc/Icon/feather/download-cloud.svg"




/* ==========================================================================
 * Class
========================================================================== */
_a_login_to_broker::_a_login_to_broker(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::_a_login_to_broker)
{
    ui->setupUi(this);
    this->setWindowTitle("Login to broker");


    //==========================Style ================

    // set frame functions list ( see example combinations F1)
    ui->frame_login_broker->setFrameShape(QFrame::Box);
    ui->frame_login_broker->setFrameShadow(QFrame::Sunken);
    ui->frame_login_broker->setLineWidth(1);//ptx
    ui->frame_login_broker->setMidLineWidth(3);



    // button and label

    // set button/ label back
    QSize btn_back_size = ui->btn_back->size();
    btn_back_size.setWidth(btn_back_size.height()); // square

    ui->btn_back->setStyleSheet(BTN_STYLE_DESIGN);

    ui->label_ic_back->setPixmap(renderSvgToPixmap(ICON_SVG_BACK
                                                   ,btn_back_size));



    // label_ic_reconn
    // btn_reconn
    QSize btn_reconn_size = ui->btn_reconn->size();
    btn_reconn_size.setWidth(btn_reconn_size.height()); // square

    ui->btn_reconn->setStyleSheet(BTN_STYLE_DESIGN);

    ui->label_ic_reconn->setPixmap(renderSvgToPixmap(ICON_SVG_RECONN
                                                   ,btn_reconn_size));




    //==========================Inform Config ================

    qDebug()<<this<<"- created window login";

}

_a_login_to_broker::~_a_login_to_broker()
{
    delete ui;

    qDebug()<<this<<"- deleted window login";
}

void _a_login_to_broker::on_btn_back_clicked()
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

