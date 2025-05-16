/* =================================================
 * Note:
 * A. GUI thread safe problem
 *  - Qt only use main thread for GUI
 *  - See section 'GUI Thread and Worker Thread' in: https://doc.qt.io/qt-5/thread-basics.html
 * B. Signal / slot and delete object problem
 *  - 1. Using flag (may not use a thread save) and a flag help
 *      call other action "emit" wrong time (after deleteLater()) and Widget
 *      + the flag should atomic or mutex if other thread do something :p but Qt using only main thread for GUI
 *      + ignore step 2 and 3 if flag set (that mean don't care code if flags set)
 *  - 2. Then disconnect all signal not safe for delete Widget
 *      + Or simple call 'hide' because only run on main thread
 *          after hide user can spam any signal.
 *
 *  - Now we need analzing:
 *      + Some signal/slot maybe rest in main loop -> check flag
 *      + These signal/slot need real object to refer (because function QObject::connect(4 param))
 *          -> deleteLater() with queue a delete command after all now signal slot
 *      + Some future signal/slot may call by user emit
 *          -> No way, after step 2 disconnect all signal
 *
 *  - 3. Using deleteLater() and should check not call multiple
 *
 * C. Using "state chart" to build "state chine"
 *  - Add scxml to project: https://doc.qt.io/qt-6.5/qscxmlc.html
 *      + add 'Scxml' to [find_package]
 *      + add Qt${QT_VERSION_MAJOR}::Scxml to [target_link_libraries]
 *      + add commamd:
 *          qt6_add_statecharts(_0002_state_machine
                ssm_dialog.scxml
            )
 *  - If missing module Compile scxml we add by: goto "MaintainTool.exe"
 *      in download and add module "Qt State machine"
 *
 *  - Necessary methods when using a state machine:
 *      + include library .h with the same name .scxml
 *      + method: connectToState() using link a state with object signal
 *      + method: init() to implement scxml element
 *      + method: start() will find and run initial state
 *
 *  - Note about QMetaObject:
 *      + any connect return a QMetaObject
 *      + using QObject::disconnect(that_metaobject) to delete connect
================================================= */
#include <QApplication>
#include <QThread>
#include <QDebug>

#include "handle_ssm.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // init construct for Qt system (argc,argv), init queue for exec, config sigal-slot system...

    handle_ssm ssm;

    // connect
    QObject::connect(&ssm, SIGNAL(error_catch()), &a, SLOT(quit()), Qt::QueuedConnection);

    // start
    if(ssm.start_ssm_dialog())
    {
        qDebug()<< "[ERROR] state machine start failed";
    }

    return a.exec();
}
