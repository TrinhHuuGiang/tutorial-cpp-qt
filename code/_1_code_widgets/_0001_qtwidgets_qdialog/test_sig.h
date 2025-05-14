#ifndef TEST_SIG_H
#define TEST_SIG_H

#include <QObject>

#include <QThread>
#include <QDebug>

class Test_Sig : public QObject
{
    Q_OBJECT
public:
    explicit Test_Sig(QObject *parent = nullptr):QObject(parent)
    {
        qDebug() << "[Created]" << this << QThread::currentThread();
    }
    ~Test_Sig()
    {
        qDebug() << "[Destructed]" << this << QThread::currentThread();
    }


public slots:
    void check_exec_quit()
    {
        qDebug() << QThread::currentThread() << "Exit called";
    }
};

#endif // TEST_SIG_H
