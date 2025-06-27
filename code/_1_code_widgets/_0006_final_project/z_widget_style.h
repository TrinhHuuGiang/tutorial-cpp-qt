#ifndef Z_WIDGET_STYLE_H
#define Z_WIDGET_STYLE_H

/* ==========================================================================
 * Definitions
========================================================================== */

#include <QSvgRenderer> // add Svg in CMakeLists
#include <QPixmap>
#include <QPainter>
#include <QString>
#include <QSize>


// ==========================font
#define MAIN_APP_DEFAULT_FONT_SIZE    16 // pt

#define MAIN_APP_DEFAULT_REGULAR_FONT ":/font/rsrc/Font/Roboto/static/Roboto-Regular.ttf"
#define MAIN_APP_DEFAULT_BOLD_FONT ":/font/rsrc/Font/Roboto/static/Roboto-Bold.ttf"
#define MAIN_APP_DEFAULT_ITALIC_FONT ":/font/rsrc/Font/Roboto/static/Roboto-Italic.ttf"



// ==========================button
#define BTN_STYLE_DESIGN \
    "\
        QPushButton {\
                border: 1px solid black;\
                border-radius: 3px;\
        }\
        \
        QPushButton:hover {\
            background-color: #e0e0e0;\
        }\
        \
        QPushButton:pressed {\
            background-color: #d0d0d0;\
            border-style: inset;\
        }\
        \
        QPushButton:focus {\
        background-color: #dcfafa;\
        border: 2px solid #007acc;\
        }\
    "


// ========================== scroll bar size
#define SCROLLBAR_SIZE_DESIGN \
        "\
        QScrollBar:vertical {\
                width: 20px;\
            }\
        QScrollBar:horizontal {\
                height: 20px;\
            }\
        "



// ========================== group box outline
#define GROUPBOX_OUTLINE_DESIGN \
    "\
    QGroupBox {\
        border: 2px solid #DAA520;\
        border-radius: 6px;\
        margin-top: 16px;\
    }\
    QGroupBox::title {\
        subcontrol-origin: margin;\
        padding: 0 3px;\
        font-weight: bold;\
        color: #DAA520;\
    }\
    "


/* ==========================================================================
 * APIs
========================================================================== */
/*
 * Convert svg to pixmap
 */
QPixmap renderSvgToPixmap(const QString &svgFilePath, const QSize &targetSize);





#endif // Z_WIDGET_STYLE_H
