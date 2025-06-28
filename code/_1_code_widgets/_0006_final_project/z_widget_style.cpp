/*
    Copyright (C) 2025  Giang Trinh

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

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
