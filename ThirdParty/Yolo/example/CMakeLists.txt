cmake_minimum_required(VERSION 3.9)

project(yolo_example)

add_executable(yolo_example example.cpp)
target_include_directories(yolo_example PRIVATE "../include")

