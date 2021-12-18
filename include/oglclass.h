#pragma once

#include <QOpenGLWidget>

#ifdef __APPLE__
#include <QOpenGLFunctions>
#else
#include <QOpenGLFunctions_3_3_Core>
#endif

#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>

#include <QTimer>
#include <QPoint>
#include <QMouseEvent>

#include <vector>
#include <memory>

#include "utility.h"
#include "camera.h"

#ifdef __APPLE__
class oglClass : public QOpenGLWidget, QOpenGLFunctions
#else
class oglClass : public QOpenGLWidget, QOpenGLFunctions_3_3_Core
#endif
{
    Q_OBJECT

public:
    typedef std::shared_ptr<QOpenGLTexture> TexturePtr;

public:
    explicit oglClass(QWidget *parent = nullptr);
    ~oglClass();

protected:
    void paintGL() override;
    void initializeGL() override;
    void resizeGL(int w, int h) override;

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QTimer m_timer;

    cam::Camera m_cam;
    unsigned int m_vao;
    unsigned int m_vbo;
    unsigned int m_ebo;

    QOpenGLShaderProgram m_shaderProg;
    std::vector<TexturePtr> m_texArray;

    bool   m_scribbling;
    QPoint m_lastCursorPos;

signals:

public slots:
    void on_timeout();
};


