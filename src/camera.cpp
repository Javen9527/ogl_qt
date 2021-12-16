#include "camera.h"


namespace cam
{

QMatrix4x4 Camera::getView()
{
    QMatrix4x4 view;
    return view;
}

QMatrix4x4 Camera::getModel()
{
    QMatrix4x4 model;
    unsigned int time = QTime::currentTime().msec();
    model.rotate(time, .0f, .0f, 1.0f);
    return model;
}

QMatrix4x4 Camera::getProjection()
{
    QMatrix4x4 proj;
    return proj;
}

} // namepsace cam
