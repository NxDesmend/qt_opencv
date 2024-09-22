#include "camera.h"

#include <QTimerEvent>

void Camera::run() {
    if (!m_videoCapture) {
        m_videoCapture.reset(new cv::VideoCapture(m_cameraIndex));
    }
    if (m_videoCapture->isOpened()) {
        m_timer.start(0, this);
        emit started();
    }
}

void Camera::stop()
{
    m_timer.stop();
}

void Camera::timerEvent(QTimerEvent* ev)
{
    if (ev->timerId() != m_timer.timerId())
        return;
    cv::Mat frame;
    if (!m_videoCapture->read(frame)) // Blocks until a new frame is ready
    {
        m_timer.stop();
        return;
    }
    emit matReady(frame);
}

