// Note:
// - In Projects, go to 'Run Setting' and check on option
//   'Run in terminal' before run program. Otherwise program
//   can't run because missing dll library


/* ===============================================
 * Definition
 ===============================================*/
#include "main.h"

using namespace std;

/* ===============================================
 * Variables
 ===============================================*/


/* ===============================================
 * Prototypes
 ===============================================*/
static void input_normal_form();
static void input_qt_form();

/* ===============================================
 * Main code
 ===============================================*/
int main(int argc, char *argv[])
{
    // init
    QCoreApplication a(argc, argv);

    // main code
    input_normal_form();

    cerr << "\n";

    for(int i = 0; i<20;i++) cerr << "=";

    cerr << "\n";

    input_qt_form();

    // return if not want exec
    return 0;

    // enter event loop
    return a.exec();
}

/* ===============================================
 * Define Code
 ===============================================*/
static void input_normal_form()
{
    string input_form;

    cout << "Cpp form\n";

    cout << "Input your name:\n => ";
    getline(cin, input_form);            // "\n" auto delete form stdin

    // :) use this if u don't believe
    // cin.ignore();                        // default delim == \n, and ignore any content until \n and \n

    cout << "Output your name:\n => " << input_form << "\n";
}


static void input_qt_form()
{
    QString input_form;

    QTextStream qin(stdin);
    QTextStream qerr(stderr);

    qerr << "Input your name:\n => ";
    qerr.flush();

    input_form = qin.readLine();

    qerr << "Output your name:\n => " << input_form << "\n";
    qerr.flush();
}
