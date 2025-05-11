/* ===========================================================
 * Note: Qt using UTF16 default for QChar
 * - QString
 * - QChar
 *
=========================================================== */

/* ===========================================================
 * Definitions
=========================================================== */
#include <QCoreApplication>
#include <QString>
#include <QDebug>

/* ===========================================================
 * Main code
=========================================================== */
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    // init QString
    qDebug() <<"=====================";
    QString line = "Hello";
    int size = line.size();

    qDebug() << "String 1:" << line;
    qDebug() << "- Size" << size;

    for(int i=0; i< size; i++ )
        qDebug() << "["<<i<<"]"<< line.at(i); // if index > sizeof(line) -> crash program
                                              // else return QChar

    // compare, search
    qDebug() <<"=====================";
    QString line_2 = "hello";
    qDebug() << "String 2:" << line_2;

    qDebug() << "Compare CaseInsensitive with String 1: "<< line_2.compare(line, Qt::CaseInsensitive);
    qDebug() << "Compare CaseSensitive String 2 with String 1: "<< line_2.compare(line, Qt::CaseSensitive);
    qDebug() << "Compare CaseSensitive String 1 with String 2: "<< line.compare(line_2, Qt::CaseSensitive);

    qDebug() << "Containt CaseSensitive \"EL\" ?  - " << line_2.contains("EL", Qt::CaseSensitive);
    qDebug() << "Containt CaseInsensitive \"EL\" ?  - " << line_2.contains("EL", Qt::CaseInsensitive);

    qDebug() << "Endwith CaseSensitive \"LO\" ?  - " << line_2.endsWith("LO", Qt::CaseSensitive);
    qDebug() << "Endwith CaseInsensitive \"LO\" ?  - " << line_2.endsWith("LO", Qt::CaseInsensitive);

    qDebug() << "Search index \"ll\" = [" << line_2.indexOf("ll") << "]";

    int idx_l = line_2.indexOf("l");
    qDebug() << "Search index 'l' = [" << idx_l << "]";

    idx_l = line_2.indexOf("l", idx_l+1);
    qDebug() << "Search index second 'l' = [" << idx_l << "]";

    idx_l = line_2.indexOf("l", idx_l+1);
    qDebug() << "Search index third 'l' = [" << idx_l << "]";


    // Modify
    qDebug() <<"=====================";
    qDebug() << "Append String 2 in to String 1: " << line.append(line_2);

    qDebug() << "UPPER String 1: " << line.toUpper();
    qDebug() << "LOWER String 1: " << line.toLower();

    qDebug() << "Get middle from position [3] and get 6 value in String 1: ";
    qDebug() << "- [" << line.mid(3, 6) << "]";


    return a.exec();
}
