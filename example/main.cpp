#include "oglwindow.h"

#include <QSurfaceFormat>

#include <QApplication>

int main(int argc, char *argv[])
{
    // macOs platform you may get error: #version 330 is not supported.
    // solution for this: https://stackoverflow.com/questions/17390970/qt5-opengl-glsl-version-error?fbclid=IwAR3FuY9ZGkce1rFBBIJ2SRcXe1JGzciHprHYcGGzg4wPNBbkcxCNcO2l26A
    QSurfaceFormat glFormat;
    glFormat.setVersion(3, 3);
    glFormat.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(glFormat);

    QApplication a(argc, argv);

    OglWindow w;
    w.show();

    return a.exec();
}
