#include "MainWindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    ui.graphicsView->setScene(&m_scene);
    m_scene.addItem(&m_pixmap);

    ui.graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    connect(&m_camera, SIGNAL(matReady(cv::Mat)),
        SLOT(processFrame(cv::Mat)));
}

MainWindow::~MainWindow()
{}

void MainWindow::on_turnOnButton_pressed() {
    m_camera.run();
}

void MainWindow::on_pauseButton_pressed() {
    m_camera.stop();
}

void MainWindow::on_turnOffButton_pressed() {
    m_camera.stop();
    m_pixmap.setPixmap(QPixmap());
}

void MainWindow::processFrame(const cv::Mat& frame) {
    m_faceDetector.process(frame);
    m_image = QImage(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
    m_pixmap.setPixmap(QPixmap::fromImage(m_image.rgbSwapped()));
}
