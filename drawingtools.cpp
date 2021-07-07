#include "drawingtools.h"

void DrawingTools::drawLine(QImage &image, int x1, int y1, int x2, int y2, QColor color)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    float a = 0;
    if(std::abs(dx) > std::abs(dy)) {
        if (x1 > x2) {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }
        a = (float)dy / dx;
        float y = y1;
        for(int x = x1; x <= x2; ++x) {
            image.setPixelColor(x, y, color);
            y += a;
        }
    } else {
        if(y1 > y2) {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }
        a = (float)dx / dy;
        float x = x1;
        for(int y = y1; y <= y2; ++y) {
            image.setPixelColor(x, y, color);
            x += a;
        }
    }
}

void DrawingTools::drawLine(QImage &image, QPoint p1, QPoint p2, QColor color) {
    DrawingTools::drawLine(image, p1.x(), p1.y(), p2.x(), p2.y(), color);
}

void DrawingTools::drawTriangel(QImage &image, QPoint p1, QPoint p2, QPoint p3, QColor color)
{
    if(p1.y() > p2.y())
        std::swap(p1, p2);
    if(p2.y() > p3.y())
        std::swap(p2, p3);
    if(p1.y() > p2.y())
        std::swap(p1, p2);

    int a1 = 0;
    int b1 = 0;
    int a2 = 0;
    int b2 = 0;

    a1 = p2.y() - p1.y();
    b1 = p2.x() - p1.x();
    a2 = p3.y() - p1.y();
    b2 = p3.x() - p1.x();
    if(a1 != 0)
        for(int y = p1.y(); y <= p2.y(); ++y) {
            int x1 = (float)(y - p1.y()) / a1 * b1 + p1.x();
            int x2 = (float)(y - p1.y()) / a2 * b2 + p1.x();
            if(x1 > x2)
                std::swap(x1, x2);
            for(int x = x1; x <= x2; ++x)
                image.setPixelColor(x, y, color);
        }

    a1 = p3.y() - p2.y();
    b1 = p3.x() - p2.x();
    if(a1 != 0)
        for(int y = p2.y(); y <= p3.y(); ++y) {
            int x1 = (float)(y - p2.y()) / a1 * b1 + p2.x();
            int x2 = (float)(y - p1.y()) / a2 * b2 + p1.x();
            if(x1 > x2)
                std::swap(x1, x2);
            for(int x = x1; x <= x2; ++x)
                image.setPixelColor(x, y, color);
        }
}
