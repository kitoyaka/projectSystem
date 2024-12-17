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
        std::cout << "Generated ID = " << data.id
                  << ", Temperature = " << data.value
                  << ", Time = " << data.timestamp << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds (1));
    }
}

void SensorGenerator::stop() {
    running = false;
}

bool SensorGenerator::isStopped() { return stopped = true;}