#ifndef WORKER_H
#define WORKER_H

#include <QObject>

#include <QThread>
#include <QDebug>


class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);
    virtual ~Worker();
    void working_in();
signals:
    void work_done();
};

#endif // WORKER_H
