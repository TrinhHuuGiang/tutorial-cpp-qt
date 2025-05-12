#include "../libs/worker.h"

Worker::Worker(QObject *parent)
    : QObject{parent}
{
    qDebug() <<"[Constructed]" <<this << QThread::currentThread();
}

Worker::~Worker()
{
    qDebug() <<"[Destructed]" <<this << QThread::currentThread();
}

void Worker::working_in()
{
    for(int i = 0; i< 10; i++)
    {
        qDebug() << this->objectName() << "working in" << QThread::currentThread();
        QThread::msleep(300);
    }

    emit this->work_done();
}

