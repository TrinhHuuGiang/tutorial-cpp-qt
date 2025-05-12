#ifndef TEST_H
#define TEST_H


/* ====================================================
 * Definitons
==================================================== */
#include <QObject>
#include <iostream>


/* ====================================================
 * Class
==================================================== */
class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);


signals: // protect, no define
    void close();

public slots:
    void do_stuff();
};

#endif // TEST_H
