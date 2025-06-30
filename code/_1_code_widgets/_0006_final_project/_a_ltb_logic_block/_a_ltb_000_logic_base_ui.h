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


#ifndef _A_LTB_000_LOGIC_BASE_UI_H
#define _A_LTB_000_LOGIC_BASE_UI_H
/* ==================================================
 * ABOUT: BASE CLASS FOR IMPLEMENTING A LOGIC BLOCK
 *
 * PURPOSE:
 * - Each logic block UI must inherit this class.
 * - Each block must be constructed with:
 *      + A pointer to the shared QMqttClient instance.
 * - This widget can be directly added into a QTabWidget
 *   (e.g., from the "Login to broker" page).
 * - Automatically subscribes to its designed topic from:
 *      + "rsrc/mqtt_topic/" (see topic constants defined there).
 *
 * SIGNAL CONNECTION:
 * - Listens to: QMqttClient::messageReceived
 * - Each derived class must filter and handle its own topic.
 *
 * DISADVANTAGE:
 * - In dynamic systems with many logic blocks (e.g., n blocks),
 *   each incoming message is sent to all slots, even though
 *   only 1 block may need it => (n-1) redundant calls.
 *   -> Slight performance waste in large systems.
 *
 * ADVANTAGE:
 * - Simple, clean design for small to medium systems.
 * - No extra router or hub required.
 *
 * FUTURE IMPROVEMENT:
 * - Implement a message hub/router:
 *     + Subscribes once globally
 *     + Internally routes messages to registered destinations
 *     + Reduces unnecessary slot activations
 * - Downside: adds architectural complexity.
 *
 * ================================================== */


#include <QWidget>
#include <QDebug>
#include <QString>

// MQTTservice
#include <QMqttClient>
#include <QMqttTopicName>
#include <QSslConfiguration>
#include <QMqttTopicFilter>

// mqtt
#include "../rsrc_code/mqtt_topic/__general_handshake_topic.h"


/* =================================================
 * Class
====================================================== */
class _a_ltb_000_logic_base_UI : public QWidget
{
    Q_OBJECT
public:
    // Deploy child widgets onto this widget
    // connect  with mqtt client signal 'QMqttClient::messageReceived'
    // subcribe topic (default with QOS1)
    explicit _a_ltb_000_logic_base_UI(QMqttClient* mqtt_client,
                                      const QString& LB_Code, const  QString& LB_index,
                                      QWidget *parent = nullptr);



    /* static  cant use with virtual -> can't over writte
     * -> we need create a static constuctor function in derived class
     *     to get class pointer to base map table
     *
     *      if i define a get constructor here, derived class alway
     *      call back this parent function -> wrong logic
     *
     * template:
     *
     *      static QWidget*  create_polymorphism(QMqttClient* mqtt_client, const QString& LB_Code, const  QString& LB_index)
     *      {
     *          return new Drived_class(QMqttClient* mqtt_client, const QString& LB_Code, const  QString& LB_index);
     *      };
     */



    // destruct
    virtual ~_a_ltb_000_logic_base_UI();


private:
    // subcribe designed topic to get feedback from dev board
    void logic_block_subcribe_topic_to_broker(QString& topic);


    // send topic to broker to control devboard
    void logic_block_send_topic_to_broker(QString& topic, QString& message);


    /*
     * handle when new feedback  message
     * - check message -> compare by switch case -> handle, otherwise ignore
     */
    virtual void on_mqtt_messageReceived(const QByteArray &message, const QMqttTopicName &topic) = 0; //<< pure virtual, forced to redefine handle

signals:

private:
    QMqttClient* m_mqtt_client; // member mqtt client
    QString LB_code;
    QString LB_idx;


};

#endif // _A_LTB_000_LOGIC_BASE_UI_H
