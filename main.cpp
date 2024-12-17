#include <iostream>
#include <nlohmann/json.hpp>
#include "data/ThreadSafeQueue.h"
#include "data/SensorGenerator.h"
#include "data/DataProcessor.h"
int main() {


    ThreadSafeQueue<SensorData> queue;

    SensorGenerator generator(queue);

    DataProcessor dataProcessor(queue, generator);


    std::thread producer([&generator] {
        generator.generateData();
    });

    std::this_thread::sleep_for(std::chrono::seconds(10));
    generator.stop();
    std::cout<< "Stopping generator..." << std::endl;
    producer.join();



    std::thread consumer([&dataProcessor] {
        dataProcessor.processData();
    });
    dataProcessor.stop();
    consumer.join();

    std::vector<SensorData> processedData = dataProcessor.getProcessedData();
    for (const auto& data : processedData) {
        std::cout << "Final ID = " << data.id
                  << ", Temperature = " << data.value
                  << ", Time = " << data.timestamp << std::endl;
    }


    return 0;
}
