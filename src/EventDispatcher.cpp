#include "internal_define.h"
#include "EventDispatcher.h"


namespace sdl2pp {

    bool EventDispatcher::poll() {
        SDL_Event e;
        if (SDL_PollEvent(&e)) {
            dispatchEvent(e);
            return true;
        } else {
            return false;
        }
    }

    void EventDispatcher::dispatchEvent(const SDL_Event &e) {
        switch (e.type) {
        default:
            break;

#define EVENT_ACTION(event,var,member)              \
    case event: \
        if (var) \
            var(e.member); \
        break;

        SDL2PP_LIST_EVENTS1

#define EVENT_ACTION(event,var,member)              \
    case event: \
        if (var) \
            var(); \
        break;

#undef EVENT_ACTION

        }
    }

}
