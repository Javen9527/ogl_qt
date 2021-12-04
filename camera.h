#pragma once

#include <QMatrix4x4>
#include <QTime>

class Camera
{
public:
    //QMatrix4x4 getView();

    QMatrix4x4 getModel()
    {
        QMatrix4x4 view;
        unsigned int time = QTime::currentTime().msec();
        view.rotate(time, .0f, .0f, 1.0f);
        return view;
    }
    void getPorjection() {}
};

//////////////// IMPLEMENTATION ////////////////


