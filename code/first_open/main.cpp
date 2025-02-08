#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int i = 10;
    while(i--)
    {
        std::cout<<"Hello ooo"<<std::endl;
    }

    return a.exec();
}
