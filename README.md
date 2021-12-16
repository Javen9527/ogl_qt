# ogl_qt
This is a repo for my opengl on qt platform

-------------------------------------------------------------------------------

## 先澄清几个概念

### gui 模块

- QT += gui 模块主要包含两个类：QWindow、QGuiApplication
- `QOpenGLWindow` 类
    * QOpenGLWindow属于QWindow的一个子类（subclass/enhanced），特别用于OpenGL绘制；
    * QOpenGLWindow能创建并使用与QOpenGLWidget兼容的API，但与QOpenGLWidget不同的是，
    QOpenGLWindow不依赖widgets模块，且性能更好；
    * 其也与传统的QGLWidget的API兼容；

### widgets 模块

- QT += widgets
- `QOpenGLWidget` 类
    * 属于widgets模块（与QOpenGLWindow所属模块（gui）不同）

### opengl 模块

- QT += opengl 该模块已经obsolet
- `QGLWidget` 类
    * 不推荐使用

-------------------------------------------------------------------------------

## QT 项目管理

### pro 文件（qmake）

- 目录结构
    * example
        * 案例代码
        * .pro
        * .qrc
        * .ui
    * include
    * src
    * resources
