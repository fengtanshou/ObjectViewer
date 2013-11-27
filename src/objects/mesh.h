#ifndef MESH_H
#define MESH_H

#include <QString>
#include <QVector>
#include <QVector3D>

#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QSharedPointer>

typedef QSharedPointer<QOpenGLShaderProgram> QOpenGLShaderProgramPtr;

class QOpenGLFunctions_4_3_Core;
class QOpenGLVertexArrayObject;

class Mesh
{

public:
    Mesh(const QString& name,
         const QVector<QVector3D>& positions,
         const QVector<QVector4D>& colors,
         const QVector<QVector2D>& texCoords,
         const QVector<QVector3D>& normals,
         const QVector<QVector3D>& tangents,
         const QOpenGLShaderProgramPtr& shader);

    ~Mesh();

    void init();
    void render();

    void setName(const QString& name) { m_name = name; }
    QString name() const { return m_name; }

private:
    void load();

    QOpenGLFunctions_4_3_Core * m_funcs;
    QOpenGLVertexArrayObject  * m_vao;

    QOpenGLBuffer m_vertexPositionBuffer;
    QOpenGLBuffer m_vertexColorBuffer;
    QOpenGLBuffer m_vertexTexCoordBuffer;
    QOpenGLBuffer m_vertexNormalBuffer;
    QOpenGLBuffer m_vertexTangentBuffer;

    QString m_name;

    QVector<QVector3D> m_positions;
    QVector<QVector4D> m_colors;
    QVector<QVector2D> m_texCoords;
    QVector<QVector3D> m_normals;
    QVector<QVector3D> m_tangents;

    QOpenGLShaderProgramPtr m_shader;

};

#endif // MESH_H
