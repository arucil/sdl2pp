#ifndef SDL2PP_INIT_H
#define SDL2PP_INIT_H

#include <SDL2/SDL.h>
#include <sstream>
#include "Exception.h"


#define SDL2PP_THROW(function) \
    do { \
        std::ostringstream sout; \
        sout << function ": " << SDL_GetError(); \
        throw Exception(sout.str()); \
    } while (false)

namespace sdl2pp {

    class Init {
    public:
        explicit Init(Uint32 flags) {
            if (SDL_Init(flags) < 0) {
                SDL2PP_THROW("SDL_Init()");
            }
        }

        ~Init() {
            SDL_Quit();
        }

        Init(const Init &) = delete;
        Init &operator=(const Init &) = delete;
        Init(Init &&) = delete;
        Init &operator=(Init &&) = delete;
    };

}

#undef SDL2PP_THROW

#endif //SDL2PP_INIT_H
