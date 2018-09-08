#include "internal_define.h"
#include "Event.h"


namespace sdl2pp {

    bool Event::pushEvent(SDL_Event &event) {
        int ret = SDL_PushEvent(&event);
        if (ret > 0) {
            return true;
        } else if (ret == 0) {
            return false;
        } else {
            SDL2PP_THROW("SDL_PollEvent");
        }
    }

}