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
