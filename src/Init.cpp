#include "internal_define.h"
#include "Init.h"


namespace sdl2pp {

    Init::Init(Uint32 flags) {
        if (SDL_Init(flags) < 0) {
            SDL2PP_THROW("SDL_Init");
        }
    }

    Init::~Init() {
        SDL_Quit();
    }

}