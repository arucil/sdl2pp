#ifndef SDL2PP_MACROS_H
#define SDL2PP_MACROS_H

#include <sstream>
#include "define.h"
#include "Exception.h"

#define SDL2PP_THROW(function) \
    do { \
        std::ostringstream sout; \
        sout << function ": " << SDL_GetError(); \
        throw Exception(sout.str()); \
    } while (false)

#define SDL2PP_IMG_THROW(function) \
    do { \
        std::ostringstream sout; \
        sout << function ": " << IMG_GetError(); \
        throw Exception(sout.str()); \
    } while (false)

namespace sdl2pp {

    template <typename T>
    inline T *toPointer(const optional<T> &opt) {
        return opt ? &*opt : nullptr;
    }

}

#endif //SDL2PP_MACROS_H
