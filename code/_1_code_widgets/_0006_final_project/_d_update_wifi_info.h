#ifndef _D_UPDATE_WIFI_INFO_H
#define _D_UPDATE_WIFI_INFO_H

#include <QWidget>
#include <QIcon>


#include "z_widget_style.h"

#include "_1_menuconfig.h"

namespace Ui {
class _d_update_wifi_info;
}

class _d_update_wifi_info : public QWidget
{
    Q_OBJECT

public:
    explicit _d_update_wifi_info(QWidget *parent = nullptr);
    ~_d_update_wifi_info();

private slots:
    void on_btn_back_clicked();

private:
    Ui::_d_update_wifi_info *ui;
};

#endif // _D_UPDATE_WIFI_INFO_H
