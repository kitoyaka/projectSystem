//
// Created by rigry on 07.12.2024.
//

#include "DataProcessor.h"
#include <iostream>

void DataProcessor::processData() {
    while (!generator.isStopped() || !dataQueue.empty()) {
        SensorData data;
        if (dataQueue.pop(data)) {
            if(data.value > 5 && data.value < 25) {
                processedData.push_back(data);
            }
        }
    }
    std::cout << "Processing completed." << std::endl;
}


void DataProcessor::dataProcessingStop() {
     running = false;
}

bool DataProcessor::filterData(SensorData &data) {
    return data.value > 5 && data.value < 25;
}

bool DataProcessor::stop() { return running = false;}

void DataProcessor::aggregateData(SensorData &data) {

    // coming soon

}

std::vector<SensorData> DataProcessor::getProcessedData() {
    return processedData;
}