#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>

#include <QTimer>
#include <QPoint>
#include <QMouseEvent>

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
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

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


