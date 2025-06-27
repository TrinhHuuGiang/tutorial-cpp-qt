#ifndef _B_CONFIG_LOGIC_LAYER_H
#define _B_CONFIG_LOGIC_LAYER_H

#include <QWidget>


#include "z_widget_style.h"

#include "_1_menuconfig.h"

namespace Ui {
class _b_config_logic_layer;
}

class _b_config_logic_layer : public QWidget
{
    Q_OBJECT

public:
    explicit _b_config_logic_layer(QWidget *parent = nullptr);
    ~_b_config_logic_layer();

private slots:
    void on_btn_back_clicked();

private:
    Ui::_b_config_logic_layer *ui;
};

#endif // _B_CONFIG_LOGIC_LAYER_H
