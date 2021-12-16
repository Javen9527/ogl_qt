#pragma once

#include <QMatrix4x4>
#include <QTime>

namespace cam
{

class Camera
{
public:
    QMatrix4x4 getView();

    QMatrix4x4 getModel();

    QMatrix4x4 getProjection();
};

} // namespace cam

