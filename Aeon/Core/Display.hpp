#ifndef AEON_CORE_DISPLAY_H_
#define AEON_CORE_DISPLAY_H_

namespace Aeon::Core {

class Display
{
public:
    Display();

    static inline Display& GetInstance()
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
