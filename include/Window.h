#ifndef SDL2PP_WINDOW_H
#define SDL2PP_WINDOW_H

#include <string>
#include "define.h"
#include "Size.h"


namespace sdl2pp {

    class Window {
    public:
        Window(const char *title, int x, int y, int w, int h, Uint32 flags);

        Window(const Window &) = delete;

        Window(Window &&other) noexcept : handle(other.handle) {
            other.handle = nullptr;
        }

        ~Window();

    public:
        Window &operator=(const Window &) = delete;

        Window &operator=(Window &&other) noexcept;

    public:
        SDL_Window *get() const {
            return handle;
        }

        Size getSize() const;

        void setSize(const Size &size) {
            setSize(size.w, size.h);
        }

        void setSize(int w, int h);

        int getWidth() const;

        int getHeight() const;

        void setTitle(const char *title);

        void setTitle(const std::string &title) {
            setTitle(title.c_str());
        }

        const char *getTitle() const;

        void updateSurface();

    private:
        SDL_Window *handle;
    };

}

#endif //SDL2PP_WINDOW_H
