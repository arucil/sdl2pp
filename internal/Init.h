#ifndef SDL2PP_INIT_H
#define SDL2PP_INIT_H

#include <SDL2/SDL.h>
#include "Exception.h"
#include "macros.h"


namespace sdl2pp {

    class Init {
    public:
        explicit Init(Uint32 flags) {
            if (SDL_Init(flags) < 0) {
                SDL2PP_THROW("SDL_Init");
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


#endif //SDL2PP_INIT_H
