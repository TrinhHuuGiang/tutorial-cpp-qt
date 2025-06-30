/*==============================================================
 * Notes:
 *
 * A. Threading issues:
 *  - Creating a thread consumes amount of RAM for its stack and context.
 *  - The CPU and scheduler spend more time managing multiple threads.
 *  - An excessive number of threads can slow down the system and quickly exhaust memory.
 *  => Limiting the number of threads and managing tasks through a queue is the optimal solution.

 * B. ThreadPool and QRunnable:
 *  - ThreadPool maintains a fixed number of threads and reuses them efficiently.
 *  - QRunnable is an abstract class that defines a virtual 'run' method.
 *      Implement your desired logic inside the 'run' method and submit
 *      the QRunnable to the ThreadPool for execution.
 *  - Syntax:
 *      + QThreadPool::globalInstance()->start(pointer_to_QRunnable)
 *          + globalInstance mean an unique instace threadpool of program
 *          + start is method add 'run' method of QRunnable to queue
 *  - Warn:
 *      + QRunnable have a method: setAutoDelete(true/false);
 *          + if set true, ThreadPool will delete QRunnable object after
 *            run 'run' method.
 *          + if set false, user can handle delete by code
 * C. Signals and Slots:
 * - 'qobject_cast'  support check signal input type
 *
 *
 *
 *
 * - Qt::QueuedConnection : send a signal to slot and slot will queued in destination thread
 * - Qt::Qt::DirectConnection: slot run immediate in this emit thread -> race conditon
 ==============================================================*/


#include <QCoreApplication>

#include <QDebug>
#include <QThreadPool>

#include <QScopedPointer>

#include "libs/manager.h"
#include "libs/worker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main thread");

    // check QThreadPool
    QThreadPool* tp = QThreadPool::globalInstance();

    tp->setMaxThreadCount(2);


    qDebug() << "Max thread count:" << tp->maxThreadCount();
    qDebug() << "Active thread count:" << tp->activeThreadCount();
    qDebug() << "Expiry timeout (ms):" << tp->expiryTimeout();
    qDebug() << "Wait for done:" << tp->waitForDone(0);

    // create manager and worker
    qDebug()<< "===================================";
    QScopedPointer<Manager> manager(new Manager);

    QScopedPointer<Worker> worker1(new Worker);
    QScopedPointer<Worker> worker2(new Worker);
    QScopedPointer<Worker> worker3(new Worker);
    QScopedPointer<Worker> worker4(new Worker);
    QScopedPointer<Worker> worker5(new Worker);


    manager->setObjectName("manager");
    worker1->setObjectName("worker 1");
    worker2->setObjectName("worker 2");
    worker3->setObjectName("worker 3");
    worker4->setObjectName("worker 4");
    worker5->setObjectName("worker 5");

    qDebug() << "Set name:";
    qDebug() << "-" << manager.data();
    qDebug() << "-" << worker1.data();
    qDebug() << "-" << worker2.data();
    qDebug() << "-" << worker3.data();
    qDebug() << "-" << worker4.data();
    qDebug() << "-" << worker5.data();

    // signal
    qDebug()<< "===================================";
    // Qt::QueuedConnection : send a signal to slot and slot will queued in destination thread
    // Qt::Qt::DirectConnection: slot run immediate in this emit thread -> race conditon
    QObject::connect(manager.data(), manager->work_start_now, worker1.data(), worker1->work_start, Qt::QueuedConnection);
    QObject::connect(manager.data(), manager->work_start_now, worker2.data(), worker2->work_start, Qt::QueuedConnection);
    QObject::connect(manager.data(), manager->work_start_now, worker3.data(), worker3->work_start, Qt::QueuedConnection);
    QObject::connect(manager.data(), manager->work_start_now, worker4.data(), worker4->work_start, Qt::QueuedConnection);
    QObject::connect(manager.data(), manager->work_start_now, worker5.data(), worker5->work_start, Qt::QueuedConnection);

    QObject::connect(worker1.data(), worker1->work_done, manager.data(), manager->work_salary, Qt::QueuedConnection);
    QObject::connect(worker2.data(), worker2->work_done, manager.data(), manager->work_salary, Qt::QueuedConnection);
    QObject::connect(worker3.data(), worker3->work_done, manager.data(), manager->work_salary, Qt::QueuedConnection);
    QObject::connect(worker4.data(), worker4->work_done, manager.data(), manager->work_salary, Qt::QueuedConnection);
    QObject::connect(worker5.data(), worker5->work_done, manager.data(), manager->work_salary, Qt::QueuedConnection);

    manager->work_start();

    for(int i = 3; i>=1;i--)
    {
        qDebug() << "Delay" << i << "s" ;
        QThread::currentThread()->sleep(1);
    }

    // start exec to run queued slot
    qDebug()<< "===================================";

    return a.exec();
}
