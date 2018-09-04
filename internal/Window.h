#ifndef SDL2PP_WINDOW_H
#define SDL2PP_WINDOW_H

#include <SDL2/SDL.h>
#include "Exception.h"
#include "macros.h"

namespace sdl2pp {

    class Window {
    public:
        Window(const char *title, int x, int y, int w, int h, Uint32 flags):
                handle(SDL_CreateWindow(title, x, y, w, h, flags)) {
            if (handle == nullptr) {
                SDL2PP_THROW("SDL_CreateWindow");
            }
        }

        Window(const Window &) = delete;

        Window(Window &&other) noexcept : handle(other.handle) {
            other.handle = nullptr;
        }

        ~Window() {
            if (nullptr != handle) {
                SDL_DestroyWindow(handle);
            }
        }

    public:
        Window &operator=(const Window &) = delete;

        Window &operator=(Window &&other) noexcept {
            if (this == &other)
                return *this;
            this->~Window();
            handle = other.handle;
            other.handle = nullptr;
            return *this;
        }

    public:
        SDL_Window *get() const {
            return handle;
        }

        int getWidth() const {
            int w;
            SDL_GetWindowSize(handle, &w, nullptr);
            return w;
        }

        int getHeight() const {
            int h;
            SDL_GetWindowSize(handle, nullptr, &h);
            return h;
        }

    private:
        SDL_Window *handle;
    };

}

#endif //SDL2PP_WINDOW_H
