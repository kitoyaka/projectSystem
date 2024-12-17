//
// Created by rigry on 07.12.2024.
//

#include "SensorGenerator.h"

void SensorGenerator::generateData() {
    int id = 0;
    while(running)
    {
        SensorData data = {id++, generateRandomValue(), getCurrentTime()};
        dataQueue.push(data);
        std::this_thread::sleep_for(std::chrono::seconds (1));
    }
}

void SensorGenerator::stop() {
    running = false;
}

bool SensorGenerator::isStopped() { return stopped = true;}