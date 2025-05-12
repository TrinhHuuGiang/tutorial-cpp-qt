

#include "dialog.h"

#include <QApplication>
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main thread");

    Dialog w;
    w.show();
    return a.exec();
}
