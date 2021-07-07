#ifndef OBJDATA_H
#define OBJDATA_H

#include <QVector>
#include <QVector2D>
#include <QVector3D>
#include <QString>

namespace ObjReadingTools {
class ObjData
{
public:
    QVector<QVector3D> polygonVertices(int ind) const;
    QVector<QVector2D> polygonTexCoords(int ind) const;
    QVector<QVector3D> polygonNormals(int ind) const;
    int nPoligons() const;
    bool save(const QString &filename, QString &errMsg) const;
    bool read(const QString &filename, QString &errMsg);
private:
    QVector<QVector3D> m_vertices;
    QVector<QVector2D> m_texCoords;
    QVector<QVector3D> m_normals;
    QVector<QVector<int>> m_polygonsVertexIndices;
    QVector<QVector<int>> m_polygonsTexCoords;
    QVector<QVector<int>> m_polygonsNormals;
    int m_nPoligons = 0;
    float m_sizeX;
    float m_sizeY;
    float m_sizeZ;
};
namespace Utils {
bool parseVertices(const QString &body, QVector3D &vertices, QString &errMsg);
bool parseTexCoords(const QString &body, QVector2D &texCoords, QString &errMsg);
bool parseNormals(const QString &body, QVector3D &normals, QString &errMsg);
bool parseFace(QString body, QVector<int> &verticesInd, QVector<int> &texCodsInd, QVector<int> &normalsInd, QString &errMsg);
}
}

#endif // OBJDATA_H
