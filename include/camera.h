#pragma once

#include <QMatrix4x4>
#include <QVector3D>
#include <QTime>
#include <QtMath>

namespace cam
{

enum CameMove
{
    eForward,
    eBackward,
    eLeft,
    eRight
};

struct DefaultSetting
{
    constexpr static float YAW         = -90.0f;
    constexpr static float PITCH       =  0.0f;

    constexpr static float ZOOM        =  45.0f; // mouse sroll
    constexpr static float SPEED       =  2.5f; // keyboard
    constexpr static float SENSITIVITY =  0.1f; // mouse movement
};

///////////////////////////////////////////////

class Camera
{
public:
    Camera(QVector3D position, QVector3D worldUp, float yaw = DefaultSetting::YAW, float pitch = DefaultSetting::PITCH);
    Camera(float px, float py, float pz, float wx, float wy, float wz, float yaw = DefaultSetting::YAW, float pitch = DefaultSetting::PITCH);

    float getZoom() const;
    QMatrix4x4 getView();
    void processKeyboard(CameMove direction, float deltaTime);
    void processMouseMovement(float xOffset, float yOffset, bool constrainPitch = true);
    void processMouseScroll(float yOffset);

private:
    struct CamAttrib
    {
        QVector3D position;
        QVector3D worldUp;
        QVector3D front; // calculated by yaw and pitch
        QVector3D right;
        QVector3D up;

        float yaw;
        float pitch;

        float zoom;
        float speed;
        float sensitivity;
    };

    void updateCamera();

private:
    CamAttrib m_attrib;
};

} // namespace cam

