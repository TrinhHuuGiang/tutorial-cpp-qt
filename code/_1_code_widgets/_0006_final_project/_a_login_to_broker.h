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
