/* ==============================================================
 * Note:
 * - Example using signal, slot in UI
 *  + in UI, right click on Widget you want and choose 'Go to slot'
 *  + then using C++ code for logic
 * - Warn:
 *  + Always run UI in main thread, because it need send sigal
 *  exit to right main thread, without app will hanging or crash
 *  when close
 *  + exec() only call 1 time.
============================================================== */

#include "dialog.h"

#include <QApplication>
#include <QObject>
#include <QDebug>

#include <QThread>
#include "test_sig.h"


int main(int argc, char *argv[])
{
    int ret;

    QApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main thread");

    Test_Sig test;
    QObject::connect(&a, &QApplication::aboutToQuit, &test ,&Test_Sig::check_exec_quit, Qt::QueuedConnection);

    Dialog w; // << tôi sẽ truyền con trỏ đến state enum vào đây
    // nêu user muốn đổi giao diện khác thì tại thời điểm exec
    w.show();

    ret = a.exec(); // ở đây khi kết thúc thì tôi check
    // và check exec ok tôi check đến con trỏ state enum
    // nếu nó là state end thì tôi cho end, còn không thì tôi
    // quay lại vòng trên theo 1 loop hoặc cơ chế vòng lặp để
    // nạp đúng dialog mới theo ý người dùng

    qDebug() << "exec return:" << ret << QThread::currentThread();

    return 0;
}
