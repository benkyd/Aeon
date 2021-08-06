#ifndef AEON_DISPLAY_H_
#define AEON_DISPLAY_H_

namespace Aeon::Core {

class Display
{
public:
    Display();

    static inline Display& getInstance()
    {
        static Display instance;
        return instance;
    }

private:
    Display( Display const& ) = delete;
    void operator=( Display const& ) = delete;
};

}

#endif
