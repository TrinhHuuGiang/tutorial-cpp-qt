#ifndef MQTT_TEST_H
#define MQTT_TEST_H

#include <QMainWindow>

#include <QObject>
#include <QString>
#include <QDebug>
#include <QList>
#include <QDateTime>

#include <QByteArray>


#include <QMqttClient>
#include <QMqttTopicName>
#include <QSslConfiguration>
#include <QMqttTopicFilter>

#define PUB_Q_HELLO "qt6_hello" // qt side
#define SUB_H_HELLO "hmq_hello" // server side


QT_BEGIN_NAMESPACE
namespace Ui {
class mqtt_test;
}
QT_END_NAMESPACE

class mqtt_test : public QMainWindow
{
    Q_OBJECT
private:
    QString host_name;
    QString user_name;
    QString pass_word;
    int port_num;
    QMqttClient* mqtt_client;

public:
    mqtt_test(QWidget *parent = nullptr,
              const QString& host_name = "",
              const QString& user_name = "",
              const QString& pass_word = "",
              const int& port_num = 8883,
              enum QMqttClient::ProtocolVersion pro_ver = QMqttClient::MQTT_3_1_1);
    ~mqtt_test();

private:
    void log_to_text_edit(const QString &log);

signals:


private slots:
    void on_mqtt_connected();
    void on_mqtt_disconnected();
    void on_mqtt_messageReceived(const QByteArray &message, const QMqttTopicName &topic);
    void on_mqtt_messageSent(qint32 id);

    void on_clean_Button_clicked();

    void on_reconn_Button_clicked();

    void on_send_Button_clicked();

private:
    Ui::mqtt_test *ui;
};
#endif // MQTT_TEST_H
