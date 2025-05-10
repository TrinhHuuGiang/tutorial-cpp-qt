/*
About Signals and Slots:
- Any class inheriting from 'QObject' can declare 'signals:' and 'slots:' sections.
- These mechanisms allow dynamic connections between 'QObject' instances
  using the 'QObject::connect()' function.

Notes:
+ A slot is essentially a regular member function.
+ A slot can be triggered automatically when a connected signal is emitted.
+ When emitting a signal, use the 'emit' keyword as a prefix.
+ Though 'emit' is just a macro, it helps indicate that a signal is being sent.
+ A signal only declare but not define, it using create relationship with
    another QObject 'slots'

About 'QObject::connect()':
The full function signature is:

    QObject::connect(const QObject *sender,
                     const char *signal,
                     const QObject *receiver,
                     const char *method,
                     Qt::ConnectionType type);

+ We often use 'Qt::QueuedConnection' to ensure the slot is invoked only
  after the event loop (exec()) starts.

+ If 'Qt::QueuedConnection' is not specified, the default is 'Qt::AutoConnection':
    + AutoConnection == DirectConnection :
    which may execute the slot immediately when signal raised if sender and receiver
    are in the same thread.
    + AutoConnection == QueuedConnection :
    which may the slot when signal raised will send into eventloop of thread exist
    the QObject slot.
  This can result in the event loop not being entered if 'exec()' is never reached.
    So program will be hanging.
*/

/*
 * About QObject
 * - Note:
 *  + QObject can't copy because it make
 *    QT signals & slots system and Parent-child tree
 *    become wrong
 *  + These macro defined to block this:
 *      '
        #define Q_DISABLE_COPY(Class) \
            Class(const Class &) = delete;\
            Class &operator=(const Class &) = delete;

        #define Q_DISABLE_COPY_MOVE(Class) \
            Q_DISABLE_COPY(Class) \
            Class(Class &&) = delete; \
            Class &operator=(Class &&) = delete;
 *      '
 *
 */

/* ====================================================
 * Definitons
==================================================== */

#include "main.h"


/* ====================================================
 * Prototypes
==================================================== */

/* ====================================================
 * Main code
==================================================== */

int main(int argc, char *argv[])
{
    // init qcore
    QCoreApplication a(argc, argv);

    // variable
    Test test;

    // connect signal 'close' to slot 'a.quit'
    QObject::connect(&test, test.close, &a, a.quit, Qt::QueuedConnection);

    // do stuff -> signal close
    test.do_stuff();

    // start exec event loop
    int ret = a.exec();

    // return ok / quit done
    return ret;
}

/* ====================================================
 * Define codes
==================================================== */



