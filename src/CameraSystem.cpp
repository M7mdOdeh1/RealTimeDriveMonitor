#include "../include/CameraSystem.h"
#include <iostream>

CameraSystem::CameraSystem(const std::string& baseDir, DataManager* dataManager)
    : frontCamera("Front Camera", baseDir + "/1/left", [dataManager](double time_stamp, const cv::Mat& frame) { 
        dataManager->addData(SensorType::FrontCamera, time_stamp, std::any(frame.clone()));
    }),
      leftCamera("Left Camera", baseDir + "/0/left", [dataManager](double time_stamp, const cv::Mat& frame) { 
        dataManager->addData(SensorType::LeftCamera, time_stamp, std::any(frame.clone()));
    }),
      rightCamera("Right Camera", baseDir + "/2/left", [dataManager](double time_stamp, const cv::Mat& frame) { 
        dataManager->addData(SensorType::RightCamera, time_stamp, std::any(frame.clone()));
    }),
      backCamera("Back Camera", baseDir + "/3/left", [dataManager](double time_stamp, const cv::Mat& frame) { 
        dataManager->addData(SensorType::BackCamera, time_stamp, std::any(frame.clone()));
    })
{}

void CameraSystem::start(double frameTime) {


    frontCamera.start(frameTime);
    leftCamera.start(frameTime);
    rightCamera.start(frameTime);
    backCamera.start(frameTime);

}

void CameraSystem::stop() {
    frontCamera.stop();
    leftCamera.stop();
    rightCamera.stop();
    backCamera.stop();
}
