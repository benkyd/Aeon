cmake_minimum_required(VERSION 3.9)

project(yolo_benchmark)

add_executable(yolo_benchmark benchmark.cpp)
target_include_directories(yolo_benchmark PRIVATE "../include")

