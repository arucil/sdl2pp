#ifndef SDL2PP_MACROS_H
#define SDL2PP_MACROS_H

#include <sstream>

#define SDL2PP_THROW(function) \
    do { \
        std::ostringstream sout; \
        sout << function ": " << SDL_GetError(); \
        throw Exception(sout.str()); \
    } while (false)

#endif //SDL2PP_MACROS_H
