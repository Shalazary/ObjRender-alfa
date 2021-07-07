#ifndef DRAWINGTOOLS_H
#define DRAWINGTOOLS_H

#include <QPoint>
#include <QImage>
#include <QColor>

namespace DrawingTools {
void drawLine(QImage &image, QPoint p1, QPoint p2, QColor color = QColor("white"));
void drawLine(QImage &image, int x1, int y1, int x2, int y2, QColor color = QColor("white"));
void drawTriangel(QImage &image, QPoint p1, QPoint p2, QPoint p3, QColor color = QColor("white"));
}

#endif // DRAWINGTOOLS_H
