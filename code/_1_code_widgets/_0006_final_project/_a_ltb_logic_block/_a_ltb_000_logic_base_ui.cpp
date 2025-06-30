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

#include "_a_ltb_000_logic_base_ui.h"



// Deploy child widgets onto this widget
// connect  with mqtt client signal 'QMqttClient::messageReceived'
// subcribe topic (default with QOS1)
_a_ltb_000_logic_base_UI::_a_ltb_000_logic_base_UI(
    QMqttClient* mqtt_client ,                        //must have
    const QString& LB_Code, const  QString& LB_index, //must have
    QWidget *parent)                                  // << default null ptr
    : QWidget{parent},
    m_mqtt_client(mqtt_client),
    LB_code(LB_Code),
    LB_idx(LB_index)
{
    /* =============================== Deploy child widget
     * - Create any child widget here
     * - SCROLL DOWN TO SUBCRIBE RECEIVE TOPIC AT phase connect 'QMqttClient::messageReceived'
     * - WITH PUBLISH, use defaul button or any signal widget
     *          + then call to it slot and handle send by
     *              method: logic_block_send_topic_to_broker(QString& topic, QString& message);
     *
     *          + Format for each topic to ensure these is unique topic to each logic block UI
     *              [logic block code] + [/ index number] + [/ send control code]
     *              + scroll down below to see how to deploy topic
     */





    /*
    * ================================ + connect to  'QMqttClient::messageReceived'
    */
    // example: connect(m_mqtt_client, &QMqttClient::messageReceived, this, &this_class::on_mqtt_messageReceived);
    // note that never connect here :( this class is a template




    /*
    * ================================ + connect to  'QMqttClient::messageReceived'
    */
    // config ssl (Secure Sockets Layer)/tls (Transport Layer Security)
    QSslConfiguration sslConf = QSslConfiguration::defaultConfiguration();

    // connect to host
    m_mqtt_client->connectToHostEncrypted(sslConf);



    /* DEPLOY LIST OF TOPIC SUBCRIBE FOR THESE CHILDREN WIDGET HERE
    * KEEP IT IN 'rsrc_code/mqtt_topic/_xxx_xx_mqtt_topic.h' to easy manage
    *
    * Format for each topic to ensure these is unique topic to each logic block UI
    *    [logic block code] + [/ index number] + [/ send control code]
    *
    * example:       T_000/0/LBA (if u have good define i mean each topic length ~ 10 -> 20 character)
    * meaning:
    *    + T_000: This is a test logic block [T_000] define unique in database 'primary key'
    *              + database name: 'dev_board_designed.db'
    *              + table: 'logic_code_block'
    *              + redefine map in:
    *    + 0: logic block can be repeat because dev board can deplay the same logic block if
    *                  it has enough port
    *    + LBA: This is This is the unified communication code between this UI control logic
    *                  block and the embedded processing logic block on the board.
    *           Define in 'rsrc_code/mqtt_topic/_xxx_xx_mqtt_topic.h' to easy manage
    */

    // logic_block_subcribe_topic_to_broker(
    //                 QString([logic block code] +"/"+ [index number] + "/" + [send control code]));



    // ========================================== OK
    qDebug()<<this <<"Created ltb lb base UI";
}







// ============================================== Destructor
_a_ltb_000_logic_base_UI::~_a_ltb_000_logic_base_UI()
{


    // ========================================== OK
    qDebug()<<this <<"Deleted ltb lb base UI";
}







// ============================================== PUB SUB FUNCTION
// SUBCRIBE to GET FEEDBACK TOPIC , DEFAULT MAX QOS is QOS1
void _a_ltb_000_logic_base_UI::logic_block_subcribe_topic_to_broker(QString& topic)
{
    // try subcribe to topic
    QMqttTopicFilter get_feedback_topic(topic);

    m_mqtt_client->subscribe(get_feedback_topic, MQTT_GENERAL_HANDSHAKE_SUBCRIBE_DEFAULT_MAX_QOS);

}




// PUBLISH a message to TOPIC
void _a_ltb_000_logic_base_UI::logic_block_send_topic_to_broker(QString& topic, QString& message)
{
    QMqttTopicName topic_name(topic);
    m_mqtt_client->publish(topic_name, message.toUtf8(),
                         MQTT_GENERAL_HANDSHAKE_PUBLIC_DEFAULT_QOS,
                         MQTT_GENERAL_HANDSHAKE_PUBLIC_DEFAULT_RETAIN); // standard by mqtt 3.1.1
}
