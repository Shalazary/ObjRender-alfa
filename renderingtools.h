#ifndef RENDERINGTOOLS_H
#define RENDERINGTOOLS_H

#include <QPoint>
#include <QPointF>

namespace RenderingTools {

int worldToScreanX(float left, float right, int screanWhight, float worldX);
int worldToScreanY(float top, float bottom, int screanHight, float worldY);
QPoint worldToScrean(float left, float right, float top, float bottom, int screanWhight, int screanHight, QPointF p);
}
#endif // RENDERINGTOOLS_H
