#include "oglclass.h"

#include <QDebug>

// global
static const float DATA[] =
{
    // vertex       // tex
    -0.5, -0.5, 0,  0, 0,
     0.5, -0.5, 0,  1, 0,
     0.5,  0.5, 0,  1, 1,
    -0.5,  0.5, 0,  0, 1
};

static const unsigned int INDICES[] =
{
  0, 1, 2,
  2, 3, 0
};

oglClass::oglClass(QWidget *parent)
    : QOpenGLWidget(parent)
{
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(on_timeout()));
    m_timer.start(100);
}

oglClass::~oglClass()
{
    makeCurrent();
    glDeleteBuffers(1, &m_vbo);
    glDeleteBuffers(1, &m_ebo);
    glDeleteVertexArrays(1, &m_vao);

    for(auto tex : m_texArray)
        tex->destroy();

    doneCurrent();
}

void oglClass::initializeGL()
{
    // initialize
    initializeOpenGLFunctions();

    // shader program
    {
        m_shaderProg.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/vertex.vs");
        m_shaderProg.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/vertex.fs");
        if(!m_shaderProg.link())
            qDebug() << "ERR:" << m_shaderProg.log();
    }

    // buffer data
    {
        glGenVertexArrays(1, &m_vao);
        glBindVertexArray(m_vao);

        glGenBuffers(1, &m_vbo);
        glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(DATA), DATA, GL_STATIC_DRAW);

        glGenBuffers(1, &m_ebo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(INDICES), INDICES, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
    }

    // texture
    {
        psTexture tex = std::make_shared<QOpenGLTexture>(QImage(":/textures/tex1.jpg").mirrored());
        m_texArray.push_back(tex);

        tex = std::make_shared<QOpenGLTexture>(QImage(":/textures/tex2.jpg").mirrored());
        m_texArray.push_back(tex);

        m_shaderProg.bind();
        m_shaderProg.setUniformValue("texture0", 0);
        m_shaderProg.setUniformValue("texture1", 1);
    }

    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);// DO NOT bind ebo
        glBindVertexArray(0);
    }
}

void oglClass::paintGL()
{
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    m_shaderProg.bind();
    for(unsigned int i = 0; i < m_texArray.size(); ++i)
        m_texArray[i]->bind(i);

    glBindVertexArray(m_vao);

    m_shaderProg.setUniformValue("model", m_cam.getModel());

    //glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}

void oglClass::resizeGL(int w, int h)
{
    UNUSED(w);
    UNUSED(h);
}


void oglClass::on_timeout()
{
    update();
}


