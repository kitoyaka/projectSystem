//
// Created by rigry on 07.12.2024.
//

#ifndef PROJECTSYS_DATAPROCESSOR_H
#define PROJECTSYS_DATAPROCESSOR_H
#include "ThreadSafeQueue.h"
#include "SensorGenerator.h"
#include <fstream>
#include <vector>

class DataProcessor {
public:
    DataProcessor(ThreadSafeQueue<SensorData>& enteredQueue, SensorGenerator& generatorRef) : dataQueue(enteredQueue), generator(generatorRef) {};

    void processData();
    bool filterData(SensorData& data);
    void aggregateData(SensorData& data);
    void dataProcessingStop();
    bool stop();
    std::vector<SensorData> getProcessedData();

private:
    ThreadSafeQueue<SensorData>& dataQueue;
    SensorGenerator& generator;
    std::vector<SensorData> processedData;
    bool running;
};


#endif //PROJECTSYS_DATAPROCESSOR_H
