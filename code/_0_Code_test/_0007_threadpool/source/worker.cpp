#include "../libs/worker.h"

Worker::Worker(QObject *parent)
    : QObject{parent}
{
    qDebug() << "[Constructed]" <<this << QThread::currentThread();

    this->setAutoDelete(false);

    qDebug() << "[Setup] turn off auto delete" << this << QThread::currentThread();
}

Worker::~Worker()
{
    qDebug() << "[Destructed]" <<this << QThread::currentThread();
}

void Worker::run()
{
    emit this->work_started();

    qDebug() << this << "working in" << QThread::currentThread();

    QThread::currentThread()->sleep(2);

    this->work_amount = QRandomGenerator::global()->generate();

    qDebug() << this << "work amount [" << this->work_amount << "]";

    emit this->work_done();
}


void Worker::work_start()
{
    QThreadPool::globalInstance()->start(this);
}

unsigned int Worker::worked_amount()
{
    return this->work_amount;
}
