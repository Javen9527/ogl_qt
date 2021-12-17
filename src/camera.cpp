#include "camera.h"


namespace cam
{

Camera::Camera(QVector3D position, QVector3D worldUp, float yaw, float pitch)
{
    m_attrib.position = position;
    m_attrib.worldUp = worldUp;

    m_attrib.yaw = yaw;
    m_attrib.pitch = pitch;

    m_attrib.zoom = DefaultSetting::ZOOM;
    m_attrib.speed = DefaultSetting::SPEED;
    m_attrib.sensitivity = DefaultSetting::SENSITIVITY;
}

Camera::Camera(float px, float py, float pz, float wx, float wy, float wz, float yaw, float pitch)
{

    m_attrib.position = QVector3D(px, py, pz);
    m_attrib.worldUp = QVector3D(wx, wy, wz);

    m_attrib.yaw = yaw;
    m_attrib.pitch = pitch;

    m_attrib.zoom = DefaultSetting::ZOOM;
    m_attrib.speed = DefaultSetting::SPEED;
    m_attrib.sensitivity = DefaultSetting::SENSITIVITY;
}

float Camera::getZoom() const
{
    return m_attrib.zoom;
}

QMatrix4x4 Camera::getView()
{
    QMatrix4x4 view;
    view.lookAt(m_attrib.position, m_attrib.position + m_attrib.front, m_attrib.up);
    return view;
}

void Camera::processKeyboard(CameMove direction, float deltaTime)
{
    float velocity = m_attrib.speed * deltaTime;
    switch (direction)
    {
        case CameMove::eForward:
            m_attrib.position += m_attrib.front * velocity;
        case CameMove::eBackward:
            m_attrib.position -= m_attrib.front * velocity;
        case CameMove::eLeft:
            m_attrib.position -= m_attrib.right * velocity;
        case CameMove::eRight:
            m_attrib.position += m_attrib.right * velocity;
        default:
            return;
    }
}

void Camera::processMouseMovement(float xOffset, float yOffset, bool constrainPitch)
{
    m_attrib.yaw   += xOffset * m_attrib.sensitivity;
    m_attrib.pitch += yOffset * m_attrib.sensitivity;

    if(constrainPitch)
    {
        if(m_attrib.pitch > 89.0f)
            m_attrib.pitch = 89.0f;
        if(m_attrib.pitch < -89.0f)
            m_attrib.pitch = -89.0f;
    }

    updateCamera();
}

void Camera::processMouseScroll(float yOffset)
{
    m_attrib.zoom -= yOffset;

    if(m_attrib.zoom < 1.0f)
        m_attrib.zoom = 1.0f;
    if(m_attrib.zoom > 45.0f)
        m_attrib.zoom = 45.0f;
}

////// private //////

void Camera::updateCamera()
{
    QVector3D front;
    front.setX(cos(qDegreesToRadians(m_attrib.yaw)) * cos(qDegreesToRadians(m_attrib.pitch)));
    front.setY(sin(qDegreesToRadians(m_attrib.pitch)));
    front.setZ(sin(qDegreesToRadians(m_attrib.yaw)) * cos(qDegreesToRadians(m_attrib.pitch)));
    m_attrib.front = front.normalized();

    m_attrib.right = QVector3D::normal(m_attrib.front, m_attrib.worldUp);
    m_attrib.up = QVector3D::normal(m_attrib.right, m_attrib.front);
}

} // namepsace cam
