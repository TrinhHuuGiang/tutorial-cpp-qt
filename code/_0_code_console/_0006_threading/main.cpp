/* =================================================
 * Notes:
 * A. Thread
 *  - get current thread infor - QThread::currentThread()
 *  - set current thread name - QThread::currentThread()->setObjectName("name")
 *
 *  - QObject change to another thread:
 *      + QObject not allow copy this so alloc 'new' then using pointer
 *      + Syntax: object_ptr->moveToThread(QThread* thread);
 *  - QThread support sleep by
 *      + QThread::currentThread()->msleep(millisecond)
 *      + QThread::currentThread()->sleep(second)
 *      + QThread::currentThread()->usleep(microsecond)
 *
 *  - worker2->moveToThread(&work_thread); in example below only
 *      ask Qt system signal / slot will execute slot funtion
 *      in other thread.
 *      + that mean we still using method at current thread
 *
 * B. Threadpool
 * C. Concurrent
================================================= */

/* =================================================
 * Definitions
================================================= */
#include <QCoreApplication>

#include "libs/worker.h"

#include <QDebug>
#include <QThread>

/* =================================================
 * Main code
================================================= */
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");

    // Object
    Worker* worker1 = new Worker;
    Worker* worker2 = new Worker;

    worker1->setObjectName("worker 1");
    worker2->setObjectName("worker 2");

    qDebug() << "Set name: " << worker1;
    qDebug() << "Set name: " << worker2;

    // init new thread
    qDebug("=========================");

    QThread work_thread;
    work_thread.setObjectName("Work Thread");

    worker2->moveToThread(&work_thread);
    qDebug() << worker2->objectName() << "move to" << &work_thread;

    // connect
    QObject::connect(&work_thread, QThread::started, worker2, Worker::working_in);
    QObject::connect(worker2, Worker::work_done, &work_thread, QThread::quit);

    // start
    qDebug("=========================");
    work_thread.start();

    worker1->working_in();
    worker2->working_in();


    // wait done
    qDebug("=========================");
    qDebug() << "wait quit" << &work_thread;
    work_thread.wait();

    delete(worker1);
    delete(worker2);

    return 0;
    return a.exec();
}
