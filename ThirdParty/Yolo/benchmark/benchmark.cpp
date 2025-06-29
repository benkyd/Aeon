#include <iostream>
#include <chrono>

#include "yolo/yolo.hpp"

int main() 
{
    const int iterations = 1000000;
    int x = 42;
    int y = 123;
    
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i)
    {
        yolo::info("value for x is {} and value for y is {}", x, y);
    }
    auto end = std::chrono::high_resolution_clock::now();
    
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    
    std::cout << "Total time taken: " << elapsed << " ns\n";
    std::cout << "Average time per call: " << static_cast<double>(elapsed) / iterations << " ns\n";
    return 0;
}
