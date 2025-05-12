/* =====================================================
 * Note:
 * A. QThread and QThreadpool problem
 *  - Any method (slots) running in QThread or QThreadPool needs a signal
 *      to notify when the method is done.
 *
 * B. QtConcurrent and QFuture / QFutureWatcher
 *  - QtConcurrent is wrapper / high level of QThreadpool
 *
 *  - QtConcurrent supports returning a class QFuture pointer to the runtime state
 *      of the method running in a thread. So we know how and when to
 *      create an event to react to that situation.
 *
 *  - QtConcurrent simple call method 'run' and input funtion you want to threading
 *
 *  - QFuture keep return value of a function called by QtConcurrent.
 *      + method: 'result' is a blocking function wait until function finish and return
 *
 * C. Fix missing QtConcurrent:
 *  - add key 'Concurrent' into 'find_packet()'
 *  - add key 'Qt${QT_VERSION_MAJOR}::Concurrent' into 'target_link_libraries()'
 *
 * D. QtConcurrent mismatch parameter
 *  - Function parameter must able be copy: do not use reference type '&'
 *  - Instead use pointer for safe.
===================================================== */

/* =====================================================
 * Definition
===================================================== */
#include <QCoreApplication>
#include <QDebug>

#include <QRandomGenerator>

#include <QThread>
#include <QFuture>
#include <QtConcurrent>


int test_random(int limit_low, int limit_high)
{
    int rand_var = QRandomGenerator::global()->bounded(limit_low, limit_high);

    qDebug()<<"Random value: ["<< rand_var << "]" << QThread::currentThread();

    return rand_var;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread* main_thr = QThread::currentThread();

    main_thr->setObjectName("Main thread");

    qDebug() <<"Start"<< main_thr;

    QFuture<int> f1 =  QtConcurrent::run(test_random, -100, 100);

    qDebug() <<"Return random value: " << f1.result(); // << this is blocking function

    qDebug() <<"End"<< main_thr;

    return a.exec();
}
