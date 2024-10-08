#pragma once

#include "DataManager.h"
#include "ClockSystem.h"
#include "CameraSystem.h"
#include "Sensors/BrakeSensor.h"
#include "Sensors/GPSSensor.h"
#include "Sensors/SpeedSensor.h"
#include "Sensors/ThrottleSensor.h"
#include "Sensors/SteeringSensor.h"
#include "Sensors/IMUSensor.h"
#include "RealTimeDriverMonitor.h"
#include <QObject>
#include <string>
#include "include/Sensors/SensorType.h"
#include "include/SensorData/SensorData.h"
#include "include/SensorData/SpeedSensorData.h"
#include "include/SensorData/SteeringSensorData.h"
#include "include/SensorData/ThrottleSensorData.h"
#include "include/SensorData/BrakeSensorData.h"
#include "include/SensorData/GPSSensorData.h"
#include "include/SensorData/IMUSensorData.h"
#include "include/SensorData/CameraSensorData.h"


class RealTimeDriverMonitor : public QObject{
    Q_OBJECT
public:
    RealTimeDriverMonitor(const std::string& dataDir);

    void startMonitoring();
    void stopMonitoring();

signals:
    void framesUpdated(const cv::Mat& frontFrame, const cv::Mat& leftFrame, const cv::Mat& rightFrame, const cv::Mat& backFrame);
    void sensorDataUpdated(const QString& brakeData, const QString& gpsData, const QString& speedData, const QString& throttleData, const QString& steeringData, const QString& imuData);



private:
    void tick(double currentTime);

    DataManager *dataManager;
    ClockSystem *clockSystem;

    BrakeSensor brakeSensor;
    GPSSensor gpsSensor;
    SpeedSensor speedSensor;
    ThrottleSensor throttleSensor;
    SteeringSensor steeringSensor;
    IMUSensor imuSensor;
    CameraSystem cameraSystem;

    bool monitoringStarted;

template<typename T>
std::optional<T> getSensorDataOrNull(SensorType type, double currentTime);
 

    
};
