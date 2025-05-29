/* ======================================================================
 * MQTT:
 * A. Install
 * - CMake:
 *   + When install Mqtt module for QT6
 *  	find_package(Qt6 REQUIRED COMPONENTS Mqtt)
 *      target_link_libraries(mytarget PRIVATE Qt6::Mqtt)
 *   + Missing mqtt module
 *      + 1. I follow these step guilde: https://www.youtube.com/watch?v=LIOw1c8I394
 *      + Find mqtt code version and download zip: https://github.com/qt/qtmqtt/tags
 *
 *      + 2. Go to 'folder Qt installed' and find "Example", then choose right Qt-version
 *      + Extract zip here change name 'qtmqtt'
 *
 *      + 3. Now open project 'qtmqtt' by CMakeLists.txt in 'qtmqtt' by QtCreator
 *      + then Build project with target 'Desktop'
 *      + Build folder create something like: 'Desktop_Qt_6_5_3_MinGW_64_bit-Debug'
 *
 *      + 4. Now install library mqtt:
 *          + sure you are in build folder
 *          + open 'terminal'
 *          + here type to call CMake tools in 'folder Qt installed / Tools':
 *              ../../../../../Tools/CMake_64/bin/cmake.exe --install . --verbose"
 *
 *      + 5. Now check installed:
 *          + Go to 'folder Qt installed' and find a folder like "6.5.3" or version installed
 *          + Find: mingw_64/lib/cmake and find folder 'Qt6Mqtt' is success
 *
 *      + Note: Repeat step 3, build with other target (x86_64, armeabi-v7a, ...) if be required in CMakeLists.txt
 *
 * B. Project:
 * - cluster URL: 7b92f852aa7b4f20a563529b35a8bd79.s1.eu.hivemq.cloud
 * - acc: mqtt_qt, pass: A123456_abc
 * - Server: HiveMQ
 * - Server Port available: 8883, 8884
 * - Require libraries:
 *      + QMqttClient
 *      + QSslConfiguration
====================================================================== */


/* ======================================================================
 * HTTP
====================================================================== */


/* ======================================================================
 * Definitions
====================================================================== */
#include "mqtt_test.h"

#include <QApplication>

#include <QMqttClient>

/* ======================================================================
 * Main
====================================================================== */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString host_url = "7b92f852aa7b4f20a563529b35a8bd79.s1.eu.hivemq.cloud";
    QString user_name = "mqtt_qt";
    QString pass_word = "A123456_abc";
    int port_num = 8883;


    mqtt_test w(nullptr, host_url, user_name, pass_word, port_num, QMqttClient::MQTT_3_1_1);
    w.show();

    return a.exec();
}
