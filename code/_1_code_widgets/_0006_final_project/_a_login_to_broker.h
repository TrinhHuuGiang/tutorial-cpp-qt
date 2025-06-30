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

/* =======================================================
 * Definitions
======================================================= */
// QT libs
#include <QWidget>
#include <QString>
#include <QVariant>
#include <QObject>
#include <QTimer>

#include <QIntValidator>

// MQTTservice
#include <QMqttClient>
#include <QMqttTopicName>
#include <QSslConfiguration>
#include <QMqttTopicFilter>

// user define
#include "z_widget_style.h"
#include "z_global_db_connect.h"

#include "_1_menuconfig.h"
#include "rsrc_code/mqtt_topic/__general_handshake_topic.h"

#include "_a_ltb_logic_block/_a_ltb_001_logic_base_map.h"

// c
#include <stdint.h>






/* =======================================================
 * UI class
======================================================= */
namespace Ui {
class _a_login_to_broker;
}

class _a_login_to_broker : public QWidget
{
    Q_OBJECT

public:

    // init ui
    // query default mqtt inform to lineedit
    explicit _a_login_to_broker(QWidget *parent = nullptr);

    // destruct
    ~_a_login_to_broker();

private slots:
    // response signal back to menu
    void on_btn_back_clicked();

    // submit all line edit have broker information to broker
    void on_btn_reconn_clicked();




private:
    // ui
    Ui::_a_login_to_broker *ui;

    // mqtt
    QMqttClient* mqtt_client;



private slots:
    void on_mqtt_connected();
    void on_mqtt_disconnected();
    void on_mqtt_messageReceived(const QByteArray &message, const QMqttTopicName &topic);
    void on_mqtt_messageSent(qint32 id);

private:
    void clear_UI_tabWidget();

};

#endif // _A_LOGIN_TO_BROKER_H
