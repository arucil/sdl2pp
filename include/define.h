#ifndef SDL2PP_DEFINE_H
#define SDL2PP_DEFINE_H

#include <experimental/optional>
#include <SDL2/SDL.h>

namespace sdl2pp {

    using std::experimental::optional;

#define SDL2PP_ALIAS(name)              typedef SDL_ ## name name;

    SDL2PP_ALIAS(Point)
    SDL2PP_ALIAS(Rect)

#undef SDL2PP_ALIAS
}

#endif //SDL2PP_DEFINE_H
