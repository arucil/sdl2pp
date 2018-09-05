#ifndef SDL2PP_MACROS_H
#define SDL2PP_MACROS_H

#include <sstream>
#include <SDL2/SDL.h>

#define SDL2PP_THROW(function) \
    do { \
        std::ostringstream sout; \
        sout << function ": " << SDL_GetError(); \
        throw Exception(sout.str()); \
    } while (false)

#define SDL2PP_ALIAS(name) typedef SDL_ ## name name;

SDL2PP_ALIAS(Point)
SDL2PP_ALIAS(Rect)

#endif //SDL2PP_MACROS_H
