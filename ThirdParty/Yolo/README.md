# YOLO: You Only Log Once

The super simple BLAZING FAST c++ logging library

```cpp
#include "yolo/yolo.hpp"

yolo::info("Hello, World! {}", 42);
```

The simplest possible form of module logging for super speed

```cpp
auto mod = yolo::registerModule("MODULE", "\001bansi;m");
yolo::debug(mod, "This is a debug message {}", "Incredible!");
```

