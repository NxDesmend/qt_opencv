#pragma once

#include <QtWidgets/QMainWindow>
#include <QGraphicsProxyWidget>
#include <QFileDialog>

#include "ui_MainWindow.h"
#include "camera.h"
#include "faceDetector.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_turnOnButton_pressed();
    void on_pauseButton_pressed();
    void on_turnOffButton_pressed();
    void processFrame(const cv::Mat& frame);

private:
    Ui::MainWindow ui;

    QGraphicsScene m_scene;
    QGraphicsPixmapItem m_pixmap;
    QImage m_image;
    Camera m_camera;
    FaceDetector m_faceDetector;
};
