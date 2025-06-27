/* ==========================================================================
 * Definition
========================================================================== */

#include "z_widget_style.h"




/* ==========================================================================
 * Code
========================================================================== */

/*
 * Convert svg to pixmap
 */
QPixmap renderSvgToPixmap(const QString &svgFilePath, const QSize &targetSize)
{
    QSvgRenderer renderer(svgFilePath);
    if (!renderer.isValid()) {
        // not a SVG available, return empty pixmap
        return QPixmap();
    }

    QPixmap pixmap(targetSize);
    pixmap.fill(Qt::transparent);  // render transparent background

    QPainter painter(&pixmap);
    renderer.render(&painter);
    painter.end();

    return pixmap;
}
