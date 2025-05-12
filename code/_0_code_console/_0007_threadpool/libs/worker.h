#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QDebug>

#include <QRunnable>

#include <QThread>
#include <QThreadPool>

#include <QRandomGenerator>

class Worker : public QObject, public QRunnable
{
    Q_OBJECT

private:
    unsigned int work_amount;

public:
    explicit Worker(QObject *parent = nullptr);
    virtual ~Worker();

    void run();

signals:
    void work_started();
    void work_done();

public slots:
    void work_start();
    unsigned int worked_amount();

};

#endif // WORKER_H
