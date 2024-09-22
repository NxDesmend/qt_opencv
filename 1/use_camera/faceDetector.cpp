#include "faceDetector.h"
#include <opencv2/objdetect/objdetect.hpp>
#include <QDir>

FaceDetector::FaceDetector() {
    m_facecascadeFilename = "resources/haarcascade_frontalface_default.xml";
    m_eyecascadeFilename = "resources/haarcascade_eye.xml";
    loadFiles(m_facecascadeFilename.toStdString().c_str(),
        m_eyecascadeFilename.toStdString().c_str());
}

void FaceDetector::process(const cv::Mat& frame) {
    cv::Mat grey_image;
    cv::cvtColor(frame, grey_image, CV_BGR2GRAY);
    cv::equalizeHist(grey_image, grey_image);

    std::vector<cv::Rect> faces;

    faceCascade.detectMultiScale(grey_image, faces, 1.1, 2, 0 | cv::CASCADE_SCALE_IMAGE,
        cv::Size(frame.cols / 4, frame.rows / 4));
    for (size_t i = 0; i < faces.size(); i++)
    {
        cv::rectangle(frame, faces[i], cv::Scalar(255, 0, 255));
    }
}

void FaceDetector::loadFiles(cv::String faceCascadeFilename,
    cv::String eyeCascadeFilename)
{
    // TODO: Add in a try catch statement here
    if (!faceCascade.load(faceCascadeFilename))
    {
        std::cout << "Error Loading" << faceCascadeFilename << std::endl;
    }
}