#ifndef SDL2PP_EVENT_H
#define SDL2PP_EVENT_H

#include "define.h"

namespace sdl2pp {

    class Event {
    public:
        Event() = delete;

    public:
        /**
         *
         * @return if succeed
         */
        static bool pushEvent(SDL_Event &);
    };

}

#endif //SDL2PP_EVENT_H
