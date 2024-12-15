#include <iostream>
#include <nlohmann/json.hpp>
#include "ThreadSafeQueue.h"
#include "SensorGenerator.h"
#include "DataProcessor.h"
int main() {


    ThreadSafeQueue<SensorData> queue;

    SensorGenerator generator(queue);

    DataProcessor dataProcessor(queue);


    std::thread producer([&generator] {
        generator.generateData();
    });

    std::thread consumer([&dataProcessor] {
        dataProcessor.processData();
    });

    std::this_thread::sleep_for(std::chrono::seconds(10));
    generator.stop();
    dataProcessor.dataProcessingStop();

    //processing.join();
    producer.join();
    consumer.join();

    std::vector<SensorData> processedData = dataProcessor.getProcessedData();
    for (auto& data : processedData) {
        std::cout << "ID = " << data.id
                  << ", Temperature = " << data.value
                  << ", Time = " << data.timestamp << std::endl;
    }


    return 0;
}
