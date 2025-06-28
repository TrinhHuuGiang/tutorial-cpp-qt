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


#ifndef _1_MENUCONFIG_H
#define _1_MENUCONFIG_H

/* ==========================================================================
 * Definitions
========================================================================== */
// QT libs
#include <QDebug>


#include <QWidget>
#include <QFrame>
#include <QSize>

#include <QTimer>

// other call page
#include "_a_login_to_broker.h"
#include "_b_config_logic_layer.h"
#include "_c_update_mqtt_info.h"
#include "_d_update_wifi_info.h"


// user define
#include "z_widget_style.h"


//c/cpp
// #include <stdint.h>

// #include <new>

namespace Ui {
class _1_menuconfig;
}


/* ==========================================================================
 * Class
========================================================================== */
class _1_menuconfig : public QWidget
{
    Q_OBJECT

public:
    explicit _1_menuconfig(QWidget *parent = nullptr);
    ~_1_menuconfig();

private slots:
    void on_btn_broker_login_clicked(); // goto login to broker

    void on_btn_board_cf_clicked();     // goto board config logic block



    void on_btn_mqtt_ud_clicked();

    void on_btn_wifi_ud_clicked();

private:
    Ui::_1_menuconfig *ui;
};


#endif // _1_MENUCONFIG_H
