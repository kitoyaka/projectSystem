cmake_minimum_required(VERSION 3.29)
project(projectSys)

set(CMAKE_CXX_STANDARD 20)
include(FetchContent)

FetchContent_Declare(
        nlohmann_json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.11.2  # Вказуємо версію
)
FetchContent_MakeAvailable(nlohmann_json)

include_directories("${CMAKE_BINARY_DIR}/_deps/nlohmann_json-src/include")
add_executable(projectSys main.cpp
        data/SensorGenerator.cpp
        data/SensorGenerator.h
        data/DataProcessor.cpp
        data/DataProcessor.h
        storage/JsonStorage.cpp
        storage/JsonStorage.h
        data/ThreadSafeQueue.h)
