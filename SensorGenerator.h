//
// Created by rigry on 07.12.2024.
//

#ifndef PROJECTSYS_SENSORGENERATOR_H
#define PROJECTSYS_SENSORGENERATOR_H

#include <chrono>
#include <thread>
#include <iostream>
#include "ThreadSafeQueue.h"


struct SensorData
{
    int id;
    double value;
    std::string timestamp;
};

class SensorGenerator {
public:
    SensorGenerator(ThreadSafeQueue<SensorData>& queue) : dataQueue(queue) {};

    void generateData();
    void stop();

private:
    ThreadSafeQueue<SensorData>& dataQueue;
    bool running = true;

    double generateRandomValue()
    {
        return static_cast<double>(rand()) / RAND_MAX * 100.0;
    }

    std::string getCurrentTime()
    {
        std::time_t now = std::time(nullptr);
        char buf[100];
        strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
        return std::string(buf);
    }

};


#endif //PROJECTSYS_SENSORGENERATOR_H
