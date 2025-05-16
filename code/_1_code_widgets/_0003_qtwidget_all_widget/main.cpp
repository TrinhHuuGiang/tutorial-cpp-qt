/* ================================================================
 * Note content:
 * A. Window 1 - introduce buttons
 *  - Push button: Click me clicke me :)
 *  - Tool button: When size shorter minsize auto swap missing content by "..."
 *  - Radio button:
 *      + All 'radio' in must in a group layout (Grid, Form)
 *      + When click on a 'radio' other 'radio'uncheck
 *  - Check box:
 *      + Feel free, check box is check independent with other
 *  - Command Link button:
 *      + Alway have icon ' => ', suggest click me and go next content
 *  - Dialog Box button:
 *      + Creat button and Dialog Box will manage for you
 *      + Dialog box button can't split line and will make overflow layout
 *          so wrap it in a 'scroll area'
 *
 * B. Window 2 - introduce item view / item widgets
 *  - List widget:
 *      + add any widget on it and interract by click
 *  - List view:
 *      + This is a part of MVC (Model - View - Control) model
 *      + You must have a model (QStringListModel)
 *      + List view only check and update data to View
 *      + Any change on treview data have to handle by
 *          'Control' by other logic on 'Model'
 *  - Other example: treeview, tableview, treewidget, tabelwidget
 *
 *  - Note about Model for (treeview, tableview, treewidget):
 *      + base model is 'QAbstractItemModel' allow use derived from it
 *          and rewrite a model using for 3 type view
 *      + 'QStandardItemModel' is derived, is standard of Qt using
 *          and using "QStandardItem" to add item into Model
 *         ~ With 'list view'  only display first column, no display child
 *         ~ With 'table view' only display parent, no child
 *         ~ With 'tree view'  only display parent-child of first column,
 *          other colum active like additive infomation.
 *
 * C. Window 3 - introduce containers
 * D. Window 4 - introduce input widgets
 * E. Window 5 - introduce display widgets
================================================================ */


/* ================================================================
 * Definitions
================================================================ */
#include <QApplication>

#include "window_1.h"
#include "window_2.h"

/* ================================================================
 * Main
================================================================ */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Window_1 w;
    // w.show();

    Window_2 w;
    w.show();

    // Window_3 w;
    // w.show();

    // Window_4 w;
    // w.show();

    // Window_5 w;
    // w.show();

    return a.exec();
}
