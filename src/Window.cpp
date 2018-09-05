#include "internal_define.h"
#include "Window.h"


namespace sdl2pp {

    Window::Window(const char *title, int x, int y, int w, int h, Uint32 flags) :
            handle(SDL_CreateWindow(title, x, y, w, h, flags)) {
        if (handle == nullptr) {
            SDL2PP_THROW("SDL_CreateWindow");
        }
    }

    Window &Window::operator=(Window &&other) noexcept {
        if (this == &other)
            return *this;
        this->~Window();
        handle = other.handle;
        other.handle = nullptr;
        return *this;
    }

    Window::~Window() {
        if (nullptr != handle) {
            SDL_DestroyWindow(handle);
        }
    }

    Size Window::getSize() const {
        Size sz;
        SDL_GetWindowSize(handle, &sz.w, &sz.h);
        return sz;
    }

    void Window::setSize(int w, int h) {
        SDL_SetWindowSize(handle, w, h);
    }

    int Window::getWidth() const {
        int w;
        SDL_GetWindowSize(handle, &w, nullptr);
        return w;
    }

    int Window::getHeight() const {
        int h;
        SDL_GetWindowSize(handle, nullptr, &h);
        return h;
    }

    void Window::setTitle(const char *title) {
        SDL_SetWindowTitle(handle, title);
    }

    const char *Window::getTitle() const {
        return SDL_GetWindowTitle(handle);
    }

    void Window::updateSurface() {
        if (SDL_UpdateWindowSurface(handle) < 0) {
            SDL2PP_THROW("SDL_UpdateWindowSurface");
        }
    }

}
