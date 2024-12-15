//
// Created by rigry on 07.12.2024.
//

#include "DataProcessor.h"
#include <iostream>

void DataProcessor::processData() {
    SensorData data;

    while(running || dataQueue.pop(data))
    {
        if(filterData(data))
        {
            processedData.push_back(data);
        }
    }

}

void DataProcessor::dataProcessingStop() {
     running = false;
}

bool DataProcessor::filterData(SensorData &data) {
    return data.value > 5 && data.value < 25;
}

void DataProcessor::aggregateData(SensorData &data) {

    // coming soon

}

std::vector<SensorData> DataProcessor::getProcessedData() {
    return processedData;
}