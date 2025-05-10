#ifndef TEST_PT_H
#define TEST_PT_H

#include <QObject>
#include <QDebug>   // print QString

class test_pt : public QObject
{
    Q_OBJECT
public:
    explicit test_pt(QObject *parent = nullptr);

    virtual ~test_pt();

signals:
};

#endif // TEST_PT_H
