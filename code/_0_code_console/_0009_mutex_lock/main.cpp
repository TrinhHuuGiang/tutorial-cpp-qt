/* ================================================================
 * Note: Resoure management
 *
 * A. Mutex
 * B. Mutex Lock
 *
================================================================ */

#include <QCoreApplication>
#include <QDebug>

#include <QThread>
#include <QThreadPool>
#include <QtConcurrent>

#include <QMutex>
#include <QMutexLocker>

#include <stdint.h>
#include <list>

/* ================================================================
 * Variable
================================================================ */
static int s_max_thread = 10;
static uint32_t s_value_normal = 0;
static uint32_t s_value_mutex  = 0;

/* ================================================================
 * Prototypes
================================================================ */
static int value_increase_normal(uint32_t* value, uint32_t increase);
static int value_increase_mutex(uint32_t* value, uint32_t increase, QMutex* increase_mutex);
/* ================================================================
 * Main
================================================================ */
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // set main name
    QThread::currentThread()->setObjectName("Main thread");
    qDebug() << "Start ..." << QThread::currentThread();
    qDebug() << "===============================";

    // set up threadpool
    QThreadPool::globalInstance()->setMaxThreadCount(s_max_thread);
    qDebug() << "Set max thread pool: " << QThreadPool::globalInstance()->maxThreadCount();

    // run increase value normal
    qDebug() << "===============================";
    uint32_t count_down = 1000;
    uint32_t increase = 1;

    QMutex i_mutex;
    std::list<QFuture<int>> lst_future_normal;
    std::list<QFuture<int>> lst_future_mutex;

    qDebug() << "Expect: " << count_down*increase;

    for(uint32_t i = 1; i<= count_down;i++)
    {
        qDebug() << "Push 'future' to list ["<<i<< "]";
        lst_future_normal.push_back(QtConcurrent::run(value_increase_normal, &s_value_normal, increase));
        lst_future_mutex.push_back(QtConcurrent::run(value_increase_mutex, &s_value_mutex, increase, &i_mutex));
    }

    // Check increase
    // Wait for all futures to finish (normal version)
    uint32_t count = 1;
    for (auto& future : lst_future_normal) {
        future.result(); // Block until result is ready (even if we ignore the value)
        qDebug() << "check normal:" <<"[" << count++ <<"]";
    }

    count = 1;
    // Wait for all futures to finish (mutex version)
    for (auto& future : lst_future_mutex) {
        future.result(); // Block until result is ready
        qDebug() << "check mutex:" <<"[" << count++ <<"]";
    }



    // Final values
    qDebug() << "===============================";
    qDebug() << "Expect: " << count_down*increase;
    qDebug() << "Final value without mutex:" << s_value_normal;
    qDebug() << "Final value with mutex   :" << s_value_mutex;


    qDebug() << "===============================";
    qDebug() << "Stop" << QThread::currentThread();
    return a.exec();
}

/* ================================================================
 * Codes
================================================================ */
static int value_increase_normal(uint32_t* value, uint32_t increase)
{
    uint32_t old_value = *value;

    QThread::currentThread()->msleep(1);

    *value = old_value + increase; // no thread save, value will be accepted by many thread

    return 0;
}

static int value_increase_mutex(uint32_t* value, uint32_t increase, QMutex* increase_mutex)
{
    increase_mutex->lock();

    uint32_t old_value = *value;

    QThread::currentThread()->msleep(1);

    *value = old_value + increase;

    increase_mutex->unlock();

    return 0;
}
