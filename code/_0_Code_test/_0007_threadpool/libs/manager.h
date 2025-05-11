#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <QDebug>

#include <QThread>

#include "worker.h"

class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(QObject *parent = nullptr);
    virtual ~Manager();
    void work_start();

signals:
    void work_start_now();

public slots:
    void work_salary();

};

#endif // MANAGER_H
