#include <iostream>
#include <nlohmann/json.hpp>
#include "ThreadSafeQueue.h"
#include "SensorGenerator.h"

int main() {
    ThreadSafeQueue<SensorData> queue;

    SensorGenerator generator(queue);

    std::thread producer([&generator] {
        generator.generateData();
    });

    std::thread consumer([&queue] {
        for (int i = 0; i < 10; ++i) {
            SensorData data;
        }
    });

    std::this_thread::sleep_for(std::chrono::seconds(3));

    generator.stop();

    producer.join();
    consumer.join();
    return 0;
}
