#include "yolo/yolo.hpp"

int main(int, char**)
{
    int x = 12;
    int y = 3;
    yolo::info("value for x is {} and value for y is {}", x, y);

    auto mod = yolo::registerModule("COMPONENT", "\u001b[35;1m");
    yolo::info(mod, "value for x is {} and value for y is {}", x, y);
    yolo::warn(mod, "value for x is {} and value for y is {}", x, y);
    yolo::error(mod, "value for x is {} and value for y is {}", x, y);
    yolo::debug(mod, "value for x is {} and value for y is {}", x, y);

    return 0;  
}

