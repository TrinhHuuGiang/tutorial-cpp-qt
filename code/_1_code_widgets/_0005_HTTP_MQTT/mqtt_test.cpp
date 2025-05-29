#include "mqtt_test.h"
#include "./ui_mqtt_test.h"

mqtt_test::mqtt_test(QWidget *parent,
                     const QString& host_name,
                     const QString& user_name,
                     const QString& pass_word,
                     const int& port_num,
                     enum QMqttClient::ProtocolVersion pro_ver)
    : QMainWindow(parent)
    , ui(new Ui::mqtt_test)
{
    //set up
    ui->setupUi(this);

    // set up ui
    ui->reconn_Button->hide();
    ui->send_Button->hide();
    ui->lineEdit->hide();


    // mqtt data
    this->user_name = user_name;
    this->pass_word = pass_word;
    this->port_num  = port_num;
    this->host_name = host_name;


    // start
    // for(int i = 0;i<100;i++)
    this->log_to_text_edit(QString("init mqtt test"));


    // init client
    mqtt_client = new QMqttClient(this);

    // edit HiveMQ cluster
    mqtt_client->setHostname(host_name);
    mqtt_client->setUsername(user_name);
    mqtt_client->setPassword(pass_word);

    mqtt_client->setPort(port_num);

    // TLS
    mqtt_client->setProtocolVersion(pro_ver);

    // set connect signal mqtt with special case
    // https://doc.qt.io/qt-6.5/qmqttclient.html#details

    connect(mqtt_client, &QMqttClient::connected, this, &mqtt_test::on_mqtt_connected);
    connect(mqtt_client, &QMqttClient::disconnected, this, &mqtt_test::on_mqtt_disconnected);

    connect(mqtt_client, &QMqttClient::messageReceived, this, &mqtt_test::on_mqtt_messageReceived);
    connect(mqtt_client, &QMqttClient::messageSent, this, &mqtt_test::on_mqtt_messageSent);

    // ui show
    ui->reconn_Button->show();

    // done
    this->log_to_text_edit(QString("init done"));
}

mqtt_test::~mqtt_test()
{
    delete ui;
}

void mqtt_test::log_to_text_edit(const QString &log)
{
    ui->textEdit->moveCursor(QTextCursor::End);
    QString timestamp = QDateTime::currentDateTime().toString("hh:mm:ss");

    ui->textEdit->append(QString("==========")+timestamp+"==========");

    ui->textEdit->append(log);
}

void mqtt_test::on_mqtt_connected()
{
    this->log_to_text_edit(QString("Connected!!!"));

    // hide connect button
    ui->reconn_Button->hide();

    // set ui send data
    ui->lineEdit->show();
    ui->send_Button->show();

    // try subcribe
    this->log_to_text_edit(QString("Try subcribe: %1").arg(SUB_H_HELLO));

    QMqttTopicFilter sub_topic(SUB_H_HELLO);
    this->mqtt_client->subscribe(sub_topic);
    // subcribe return QMqttSubcription to follow connect (comming soon)
}

void mqtt_test::on_mqtt_disconnected()
{
    this->log_to_text_edit(QString("Disconnected !!!"));

    // hide connect button
    ui->reconn_Button->show();

    // set ui send data
    ui->lineEdit->hide();
    ui->send_Button->hide();


}

void mqtt_test::on_mqtt_messageReceived(const QByteArray &message, const QMqttTopicName &topic)
{
    QString log = QString("Received message from topic [%1]: %2")
    .arg(topic.name())
        .arg(QString::fromUtf8(message));

    this->log_to_text_edit(log);
}

void mqtt_test::on_mqtt_messageSent(qint32 id)
{
    // this example i use default qos sending so never get ACK from server

    this->log_to_text_edit(QString("[Sent id] ") +QString::number(id));
}



void mqtt_test::on_clean_Button_clicked()
{
    ui->textEdit->setText("");
}


void mqtt_test::on_reconn_Button_clicked()
{
    // hide button
    ui->reconn_Button->hide();

    // config ssl (Secure Sockets Layer)/tls (Transport Layer Security)
    QSslConfiguration sslConf = QSslConfiguration::defaultConfiguration();

    // connect to host
    this->mqtt_client->connectToHostEncrypted(sslConf);
}


void mqtt_test::on_send_Button_clicked()
{
    QString input_text = ui->lineEdit->text();
    QString send_text;

    // send something to mqtt
    if(input_text == "")
    {
        send_text = "empty";
    }
    else
    {
        send_text = input_text;
    }

    // sending
    this->log_to_text_edit(QString("[Sending] %1").arg(send_text));

    // send
    //qint32 QMqttClient::publish(const QMqttTopicName &topic,
    //      const QByteArray &message = QByteArray(), quint8 qos = 0,
    //      bool retain = false)
    QMqttTopicName topic(QString(PUB_Q_HELLO));
    this->mqtt_client->publish(topic, send_text.toUtf8());

}

