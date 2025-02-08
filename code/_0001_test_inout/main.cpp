// qt libs
// choose library and click F1 for more information
#include <QCoreApplication>
#include <QTextStream>
#include <QString>

int main(int argc, char *argv[])
{
    // initial event loop object
    // QCoreApplication a(argc, argv);

    // initial input/outut with stream object
    QTextStream qin(stdin);
    QTextStream qout(stdout);

    // string to save input
    QString name_str;

    // input information/ output something entered
    qout << "Input your name: ";
    qout.flush();

    // Window: sure that tick option 'Run in terminal'
    // at projects 'Run setting'
    // Because defaut run in CMD window will ignore QTextStream of 'stdin' :(
    name_str = qin.readLine();

    qout << "Your name is: " << name_str;
    qout.flush();

    // start event loop until get end signal
    // return a.exec();

    return 0;
}
