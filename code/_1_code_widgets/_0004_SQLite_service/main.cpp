/* ================================================================
 * Note:
 * Function
 * A. Get database
 * Case - Get a copy database (template) saved from 'qrc'
 * Case - Get new database
 *
 * B. Modify Table
 * Case - Create new table
 * Case - Drop table
 *
 * C. Data manipulation
 * Case - Select query
 * Case - Insert query
 * Case - Update query
 * Case - Delete query
 *
 * D. Transaction (BEGIN, SAVEPOINT , RELEASE, ROLLBACK, ROLLBACK TO, COMMIT)
 *
 *
================================================================ */

/*
 * Features:
 * - template_db.db can't use immediately, because 'qresource' is read only
 *      - Copy to current execute folder and wrap in a temporary folder
 * - Modify on a new database DB_FILE_1
 */

/* ================================================================
 * Note: Libraries
 * A. QSqlDatabase
 *
 * B. QSqlQuery
 *
 * C. QSqlError
 *
 * D. QFile
 *
================================================================ */

/* ================================================================
 * Definitions
================================================================ */
#include "mainwindow.h"

#include <QApplication>



#define DB_TEMP_FOLDER "DB/"
#define DB_FILE_1      "db_1.db"

/* ================================================================
 * Code
================================================================ */
int main(int argc, char *argv[])
{
    // start
    QApplication a(argc, argv);

    // ui
    MainWindow w;
    w.show();


    // ok
    return a.exec();
}
