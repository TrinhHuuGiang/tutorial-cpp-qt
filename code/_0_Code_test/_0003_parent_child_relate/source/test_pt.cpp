#include "../libs/test_pt.h"
using namespace std;



test_pt::test_pt(QObject *parent)
    : QObject{parent}
{
    qDebug() << "[Created]" << this << "is child of" << this->parent();
}

test_pt::~test_pt()
{
    qDebug() << "[Deleted]" << this;
}
