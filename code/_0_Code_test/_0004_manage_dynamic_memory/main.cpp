/* ===========================================================
 * Content:
 * A. QScopedPointer
 * - Perpose:
 *  + Used to define a new QObject wrapped in a QScopedPointer.
 *  + You don’t need to manually delete the QObject;
 *      the QScopedPointer will automatically delete it
 *      when it goes out of scope and its destructor is called.
 * B. QSharedPointer
 * - Perpose:
 *  + A QObject is not limited to being owned by only one manager,
 *      unlike with QScopedPointer.
 *  + With QSharedPointer, a QObject can be managed by multiple managers.
 *  + The QObject will only be deleted when all shared owners go
 *      out of scope or release their references.
 *  + QSharedPointer supports this shared ownership mechanism.
 * C. Note:
 * - each QScopedPointer and QSharedPointer only link 1 pointer
 *  at a time
 * - First QSharedPointer can use construct function to save share pointer but
 *  other QSharedPointer link to the same share pointer
 *  have to use operator "=" because QSharedPointer
 *  need check someone is connect this pointer
=========================================================== */



/* ===========================================================
 * Definitions
=========================================================== */
#include <QCoreApplication>
#include <QScopedPointer>
#include <QDebug>

#include "libs/test_pointer.h"


/* ===========================================================
 * Main code
=========================================================== */
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // scope
    qDebug() << "===================";
    qDebug() << "Main\n{";
    qDebug() << "\tScope 1\n\t{";
    qDebug() << "\t\tScope 2\n\t\t{";
    qDebug() << "\t\t}";
    qDebug() << "\t}";
    qDebug() << "\tScope 3\n\t{";
    qDebug() << "\t}";
    qDebug() << "}";

    qDebug() << "===================";
    qDebug() << "Main Scope";

    qDebug() << "Creating shared pointer";
    test_pointer* sh_pointer = new test_pointer;
    sh_pointer->setObjectName("shared_ptr");
    qDebug()<<"Set name: "<< sh_pointer;

    QScopedPointer<test_pointer> main_sp(new test_pointer);
    main_sp->setObjectName("main_ptr");
    qDebug()<<"Set name: "<< main_sp.data();

    {
        qDebug() << "Scope 1";
        QScopedPointer<test_pointer> scope1(new test_pointer);
        scope1->setObjectName("scope1_ptr");
        qDebug()<<"Set name: "<< scope1.data();

        QSharedPointer<test_pointer> scope1_shd(sh_pointer);
        qDebug() << "[Link]" << "scope1_sharedpointer with shared pointer";

        {
            qDebug() << "Scope 2";
            QScopedPointer<test_pointer> scope2(new test_pointer);
            scope2->setObjectName("scope2_ptr");
            qDebug()<<"Set name: "<< scope2.data();

            QSharedPointer<test_pointer> scope2_shd = scope1_shd;
            qDebug() << "[Link]" << "scope2_sharedpointer with shared pointer";


            qDebug() << "Out Scope 2";
        }
        qDebug() << "Out Scope 1";
    }

    {
        qDebug() << "Scope 3";
        QScopedPointer<test_pointer> scope3(new test_pointer);
        scope3->setObjectName("scope3_ptr");
        qDebug() << "Out Scope 3";
    }

    qDebug() << "Out Main Scope";

    return 0;

    return a.exec();
}








