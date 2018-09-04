#ifndef SDL2PP_EXCEPTION_H
#define SDL2PP_EXCEPTION_H

#include <stdexcept>

namespace sdl2pp {

class Exception : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

}

#endif //SDL2PP_EXCEPTION_H
