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

#ifndef _A_LOGIN_TO_BROKER_H
#define _A_LOGIN_TO_BROKER_H

#include <QWidget>



#include "z_widget_style.h"

#include "_1_menuconfig.h"


namespace Ui {
class _a_login_to_broker;
}

class _a_login_to_broker : public QWidget
{
    Q_OBJECT

public:
    explicit _a_login_to_broker(QWidget *parent = nullptr);
    ~_a_login_to_broker();

private slots:
    void on_btn_back_clicked();

private:
    Ui::_a_login_to_broker *ui;
};

#endif // _A_LOGIN_TO_BROKER_H
