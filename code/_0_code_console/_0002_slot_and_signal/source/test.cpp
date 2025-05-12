/* ====================================================
 * Definitons
==================================================== */

#include "../libs/test.h"

using namespace std;


/* ====================================================
 * Codes
==================================================== */
// init
Test::Test(QObject *parent)
    : QObject{parent}
{}

// slots
void Test::do_stuff()
{
    cout<<"\nDoing stuff\n";

    // call signal
    emit close();

}
