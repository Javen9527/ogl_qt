#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>

#include <QTimer>

#include <vector>
#include <memory>

#include "utility.h"
#include "camera.h"

class oglClass : public QOpenGLWidget, QOpenGLFunctions
{
    Q_OBJECT

public:
    typedef std::shared_ptr<QOpenGLTexture> TexturePtr;

public:
    explicit oglClass(QWidget *parent = nullptr);
    ~oglClass();

protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();

private:
    QTimer m_timer;

    cam::Camera m_cam;
    unsigned int m_vao;
    unsigned int m_vbo;
    unsigned int m_ebo;

    QOpenGLShaderProgram m_shaderProg;
    std::vector<TexturePtr> m_texArray;

signals:

public slots:
    void on_timeout();
};


