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


#ifndef _C_UPDATE_MQTT_INFO_H
#define _C_UPDATE_MQTT_INFO_H

#include <QWidget>


#include <QWidget>
#include <QFrame>
#include <QSize>

#include "z_widget_style.h"

#include "_1_menuconfig.h"

namespace Ui {
class _c_update_mqtt_info;
}

class _c_update_mqtt_info : public QWidget
{
    Q_OBJECT

public:
    explicit _c_update_mqtt_info(QWidget *parent = nullptr);
    ~_c_update_mqtt_info();

private slots:
    void on_btn_back_clicked();

private:
    Ui::_c_update_mqtt_info *ui;
};

#endif // _C_UPDATE_MQTT_INFO_H
