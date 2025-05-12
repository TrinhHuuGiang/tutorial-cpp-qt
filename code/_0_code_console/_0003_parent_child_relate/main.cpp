/*==================================================================
 * Note
 * Content:
 *
 * A. Using QDebug
 * - Qt defines many Qt-specific classes. To log information
 *   about these classes, we use the debug object provided by 'QDebug'.
 * - Syntax: qDebug() << QString, QList, QMap, ... or
 *   any QObject-derived class that supports printing via operator<<.
 *
 * B. Parent-child Relationship
 * - QObject uses a metadata system to manage parent-child relationships.
 * - If a parent object is deleted, all of its children are automatically
 *   deleted as well. This helps with memory management in Qt.
 */

/*==================================================================
 * Definition
==================================================================*/
#include <QCoreApplication>
#include <QDebug>

#include "libs/test_pt.h"

using namespace std;
/*==================================================================
 * Definition
==================================================================*/

int main(int argc, char *argv[])
{
    // QCoreApplication a(argc, argv);

    // create parent
    qDebug() << "===============";
    qDebug() << "Creating parent";
    test_pt* parent = new test_pt;
    parent->setObjectName("Parent");
    qDebug() << parent;

    qDebug() << "===============";
    qDebug() << "Creating child\n";
    test_pt* child_1 = new test_pt(parent);
    child_1->setObjectName("child_1");
    qDebug()<<child_1;

    qDebug() << "===============";
    qDebug() << "Creating child";
    test_pt* child_2 = new test_pt(child_1);
    child_2->setObjectName("child_2");
    qDebug()<<child_2;

    qDebug() << "===============";
    qDebug() << "Deleting parent";

    delete parent;

    return 0;
    // return a.exec();
}
