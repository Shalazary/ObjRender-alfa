#include "viewport.h"
#include "objreadingtools.h"
#include "drawingtools.h"

Viewport::Viewport(int width, int hight) :
    m_width(width),
    m_hight(hight)
{}

Viewport::Viewport(float left, float right, float bottom, float top) :
    m_left(left),
    m_right(right),
    m_bottom(bottom),
    m_top(top)
{}

Viewport::Viewport(float left, float right, float bottom, float top, int width, int hight) :
    m_left(left),
    m_right(right),
    m_bottom(bottom),
    m_top(top),
    m_width(width),
    m_hight(hight)
{}

void Viewport::addModel(const ObjReadingTools::ObjData &model)
{
    m_models.append(model);
}

void Viewport::addModel(const QString &filename)
{
    ObjReadingTools::ObjData model;
    QString errMsg;
    if(model.read(filename, errMsg))
        m_models.append(model);
}

QImage Viewport::render() const
{
    QImage image(m_width, m_hight, QImage::Format_RGB32);
    image.fill(Qt::black);
    for(const ObjReadingTools::ObjData &model : m_models)
        renderModel(model, image);
    return image;
}

int Viewport::worldToScreanX(float x) const
{
    return (float)(x - m_left) / (m_right - m_left) * m_width;
}

int Viewport::worldToScreanY(float y) const
{
    return (float)(m_top - y) / (m_top - m_bottom) * m_hight;
}

QPoint Viewport::worldToScrean(float x, float y) const
{
    return QPoint(worldToScreanX(x), worldToScreanY(y));
}

QPoint Viewport::worldToScrean(QPointF p) const
{
    return QPoint(worldToScreanX(p.x()), worldToScreanY(p.y()));
}

void Viewport::renderModel(const ObjReadingTools::ObjData &model, QImage &image) const
{
    for(int i = 1; i <= model.nPoligons(); ++i) {
        QVector<QVector3D> poligonVertices = model.polygonVertices(i);
        int nVertices = poligonVertices.size();
        /*
        for(int j = 0; j < nVertices - 1; ++j) {
            DrawingTools::drawLine(
                image,
                worldToScrean(QPointF(poligonVertices[j].x(), poligonVertices[j].y())),
                worldToScrean(QPointF(poligonVertices[j + 1].x(), poligonVertices[j + 1].y())));
        }
        DrawingTools::drawLine(
            image,
            worldToScrean(QPointF(poligonVertices[0].x(), poligonVertices[0].y())),
            worldToScrean(QPointF(poligonVertices[nVertices - 1].x(), poligonVertices[nVertices - 1].y())));
        */
        QVector3D normal = QVector3D::normal(poligonVertices[1] - poligonVertices[0], poligonVertices[2] - poligonVertices[0]);
        float intensity = QVector3D::dotProduct(normal, m_lightDirection);
        if(intensity > 0)
            DrawingTools::drawTriangel(
               image,
               worldToScrean(QPointF(poligonVertices[0].x(), poligonVertices[0].y())),
               worldToScrean(QPointF(poligonVertices[1].x(), poligonVertices[1].y())),
               worldToScrean(QPointF(poligonVertices[2].x(), poligonVertices[2].y())),
               QColor(255 * intensity, 255 * intensity, 255 * intensity));
    }
}
