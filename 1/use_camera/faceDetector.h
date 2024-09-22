#pragma once

#include <opencv2/imgproc/types_c.h>
#include <QString>
#include "opencv2/opencv.hpp"

class FaceDetector {
public:
	FaceDetector();
	~FaceDetector() {
	}

	void process(const cv::Mat& frame);
private:
	void loadFiles(cv::String faceCascadeFilename,
		cv::String eyeCascadeFilename);
private:
	cv::CascadeClassifier faceCascade;

	QString m_facecascadeFilename;
	QString m_eyecascadeFilename;
};
