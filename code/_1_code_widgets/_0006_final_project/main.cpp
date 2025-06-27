/* ==========================================================================
 * Note:
 * - Window:
 *  + Welcome (_1_config_window):
 *      ~ Login HiveMQ server
 *          + connect to HiveMQ server, parse info and
 *              implement interactive interface with database
 *
 *      ~ Update Http Logic Block:
 *          + with database, implement interface choose logic
 *              block setup for esp32 board
 *
 *      ~ Wifi config
 *          * http get:  get a list wifi from esp32
 *          * http post: ^ post feedback wifi info set into esp32
 *                       ^ then get feedback ok, restart wifi esp32
 *
 *      ~ MQTT config Hivemq broker info
 *          * new cert pem
 *          * username, password, broker uri
 * - Resource:
 *  + icon get from: https://feathericons.com/
 *  + font style Roboto: https://fonts.google.com/specimen/Roboto
========================================================================== */

/* ==========================================================================
 * Definition
========================================================================== */
#include <QApplication>

// Common QLibs
#include <QFontDatabase>            // set global font
#include <QFont>
#include <QString>


// window app
#include "_1_menuconfig.h"

#include "_a_login_to_broker.h"
#include "_b_config_logic_layer.h"
#include "_c_update_mqtt_info.h"
#include "_d_update_wifi_info.h"


// define
#include "z_widget_style.h"


/* ==========================================================================
 * Main
========================================================================== */
int main(int argc, char *argv[])
{
    // main variable
    QApplication a(argc, argv);


//======================================= App config

    // set default app font
    int font_default = QFontDatabase::addApplicationFont(MAIN_APP_DEFAULT_REGULAR_FONT);
    QString family = QFontDatabase::applicationFontFamilies(font_default).at(0);
    QFont font(family, MAIN_APP_DEFAULT_FONT_SIZE);

    a.setFont(font); // set default application font
                    // Do not use this function in conjunction with Qt Style Sheets.


    // set default scroll bar size / setStyleSheet is safe if not set font style
    // scroll bar style
    a.setStyleSheet(SCROLLBAR_SIZE_DESIGN);





//======================================= Page config

    // WARNING: extremely serious error
    /*
     *  _1_menuconfig w_menu; //<< if use deleteLater() in object not dynamic
     *                      // program will crash because deleta a stack
     *                      // ONLY use method normal declare in test
     *  w_menu.show();
    */

    // show menuconfig window
    _1_menuconfig* w_menu = new _1_menuconfig(nullptr);
    w_menu->show();


    // // // login to mqtt server
    // _a_login_to_broker w_login;
    // w_login.show();



    //config board logic blocks
    // _b_config_logic_layer w_config_lg_layer;
    // w_config_lg_layer.show();


    // // update mqtt inform
    // _c_update_mqtt_info w_update_mqtt_info;
    // w_update_mqtt_info.show();


    // // update wifi inform
    // _d_update_wifi_info w_update_wifi_info;
    // w_update_wifi_info.show();


//======================================= Main loop

    // loop
    return a.exec();
}
