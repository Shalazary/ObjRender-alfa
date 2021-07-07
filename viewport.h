#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <QString>
#include <QImage>
#include <QVector>
#include <QPoint>

#include "objreadingtools.h"

class Viewport
{
public:
    Viewport() = default;
    Viewport(int width, int hight);
    Viewport(float left, float right, float bottom, float top);
    Viewport(float left, float right, float bottom, float top, int width, int hight);

    void addModel(const ObjReadingTools::ObjData &model);
    void addModel(const QString &filename);

    QImage render() const;

private:
    float m_left = -1;
    float m_right = 1;
    float m_bottom = -1;
    float m_top = 1;

    int m_width = 1080;
    int m_hight = 1080;

    QVector<ObjReadingTools::ObjData> m_models;

    QVector3D m_lightDirection = {0, 0, 1};

    int worldToScreanX(float x) const;
    int worldToScreanY(float y) const;
    QPoint worldToScrean(float x, float y) const;
    QPoint worldToScrean(QPointF p) const;

    void renderModel(const ObjReadingTools::ObjData &model, QImage &image) const;
};

#endif // VIEWPORT_H
