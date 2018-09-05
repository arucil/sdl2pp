#ifndef SDL2PP_EVENTDISPATCHER_H
#define SDL2PP_EVENTDISPATCHER_H

#include <functional>
#include "define.h"


namespace sdl2pp {

#define SDL2PP_LIST_EVENTS1                                     \
    EVENT_ACTION(SDL_QUIT, quitEvent, quit) \
    EVENT_ACTION(SDL_WINDOWEVENT, windowEvent, window) \
    EVENT_ACTION(SDL_SYSWMEVENT, sysWMEvent, syswm) \
    EVENT_ACTION(SDL_KEYDOWN, keyDownEvent, key) \
    EVENT_ACTION(SDL_KEYUP, keyUpEvent, key) \
    EVENT_ACTION(SDL_TEXTEDITING, textEditingEvent, edit) \
    EVENT_ACTION(SDL_TEXTINPUT, textInputEvent, text) \
    EVENT_ACTION(SDL_MOUSEMOTION, mouseMotionEvent, motion) \
    EVENT_ACTION(SDL_MOUSEBUTTONDOWN, mouseButtonDownEvent, button) \
    EVENT_ACTION(SDL_MOUSEBUTTONUP, mouseButtonUpEvent, button) \
    EVENT_ACTION(SDL_MOUSEWHEEL, mouseWheelEvent, wheel) \
    EVENT_ACTION(SDL_JOYAXISMOTION, joyAxisMotion, jaxis) \
    EVENT_ACTION(SDL_JOYBALLMOTION, joyBallMotion, jball) \
    EVENT_ACTION(SDL_JOYHATMOTION, joyHatMotion, jhat) \
    EVENT_ACTION(SDL_JOYBUTTONDOWN, joyButtonDown, jbutton) \
    EVENT_ACTION(SDL_JOYBUTTONUP, joyButtonUp, jbutton) \
    EVENT_ACTION(SDL_JOYDEVICEADDED, joyDeviceAdded, jdevice) \
    EVENT_ACTION(SDL_JOYDEVICEREMOVED, joyDeviceRemoved, jdevice) \
    EVENT_ACTION(SDL_CONTROLLERAXISMOTION, controllerAxisMotion, caxis) \
    EVENT_ACTION(SDL_CONTROLLERBUTTONDOWN, controllerButtonDown, cbutton) \
    EVENT_ACTION(SDL_CONTROLLERBUTTONUP, controllerButtonUp, cbutton) \
    EVENT_ACTION(SDL_CONTROLLERDEVICEADDED, controllerDeviceAdded, cdevice) \
    EVENT_ACTION(SDL_CONTROLLERDEVICEREMOVED, controllerDeviceRemoved, cdevice) \
    EVENT_ACTION(SDL_CONTROLLERDEVICEREMAPPED, controllerDeviceRemapped, cdevice) \
    EVENT_ACTION(SDL_FINGERDOWN, fingerDown, tfinger) \
    EVENT_ACTION(SDL_FINGERUP, fingerUp, tfinger) \
    EVENT_ACTION(SDL_FINGERMOTION, fingerMotion, tfinger) \
    EVENT_ACTION(SDL_DOLLARGESTURE, dollarGesture, dgesture) \
    EVENT_ACTION(SDL_DOLLARRECORD, dollarRecord, dgesture) \
    EVENT_ACTION(SDL_MULTIGESTURE, multiGesture, mgesture) \
    EVENT_ACTION(SDL_DROPFILE, dropFileEvent, drop) \
    EVENT_ACTION(SDL_AUDIODEVICEADDED, audioDeviceAdded, adevice) \
    EVENT_ACTION(SDL_AUDIODEVICEREMOVED, audioDeviceRemoved, adevice) \
    EVENT_ACTION(SDL_USEREVENT, userEvent, user)

#define SDL2PP_LIST_EVENTS0                                     \
    EVENT_ACTION(SDL_KEYMAPCHANGED, keyMapChangedEvent, none) \
    EVENT_ACTION(SDL_CLIPBOARDUPDATE, clipboardUpdate, none)


    class EventDispatcher {
    public:

#define EVENT_ACTION(event,var,member)          std::function<void (const decltype(SDL_Event::member) &)> var;

        SDL2PP_LIST_EVENTS1

#define EVENT_ACTION(event,var,member)          std::function<void ()> var;

        SDL2PP_LIST_EVENTS0

#undef EVENT_ACTION

    public:
        bool poll();

    private:
        void dispatchEvent(const SDL_Event &);
    };

}

#endif //SDL2PP_EVENTDISPATCHER_H
