#pragma once

#include <QObject>
#include <QScopedPointer>
#include <QBasicTimer>

#include "opencv2/opencv.hpp"

class Camera : public QObject {
	Q_OBJECT
public:
	Camera() {
	}
	~Camera() {
	}

	void run();
	void stop();

private:
	void timerEvent(QTimerEvent* ev);

private:
	int m_cameraIndex{0};
	QScopedPointer<cv::VideoCapture> m_videoCapture;
	QBasicTimer m_timer;
signals:
	void started();

	void matReady(const cv::Mat&);
};
