#include "../libs/manager.h"

Manager::Manager(QObject *parent)
    : QObject{parent}
{
    qDebug() << "[Constructed]" <<this << QThread::currentThread();
}

Manager::~Manager()
{
    qDebug() << "[Destructed]" <<this << QThread::currentThread();
}

void Manager::work_start()
{
    qDebug() << "[Signal] Work start now"
             << this <<QThread::currentThread();


    emit this->work_start_now();

}

void Manager::work_salary()
{
    Worker* worker = qobject_cast<Worker*>(sender());

    if(!worker) return;

    // check work amount
    qDebug() << "[Checked]" << this << "paid amount [" << worker->worked_amount() << "] for"
             << worker;

}
