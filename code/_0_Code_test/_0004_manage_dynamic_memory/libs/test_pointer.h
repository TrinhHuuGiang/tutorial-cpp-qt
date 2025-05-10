#ifndef TEST_POINTER_H
#define TEST_POINTER_H

#include <QObject>
#include <QDebug>
#include <QString>

class test_pointer : public QObject
{
    Q_OBJECT
public:
    explicit test_pointer(QObject *parent = nullptr);

    virtual ~test_pointer();

    void message(QString str = "none");

signals:
};

#endif // TEST_POINTER_H
