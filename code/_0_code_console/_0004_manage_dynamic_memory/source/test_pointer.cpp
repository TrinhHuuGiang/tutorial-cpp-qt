#include "../libs/test_pointer.h"

test_pointer::test_pointer(QObject *parent)
    : QObject{parent}
{
    qDebug()<< "[Created]" << this;
}

test_pointer::~test_pointer()
{
    qDebug()<< "[Deleted]" << this;
}

void test_pointer::message(QString str)
{
    qDebug() << str ;
}
