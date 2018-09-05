#ifndef SDL2PP_RENDERER_H
#define SDL2PP_RENDERER_H

#include "define.h"


namespace sdl2pp {

    class Window;
    class Texture;


    class Renderer {
    public:
        Renderer(const Window &window, int index, Uint32 flags);

        Renderer(const Renderer &) = delete;

        Renderer(Renderer &&other) noexcept : handle(other.handle) {
            other.handle = nullptr;
        }

        ~Renderer();

    public:
        Renderer &operator=(const Renderer &) = delete;

        Renderer &operator=(Renderer &&other) noexcept;

    public:
        SDL_Renderer *get() const {
            return handle;
        }

        void clear();

        void present();

        void copy(const Texture &, const optional<const Rect> &srcRect, const optional<const Rect> &destRect);

    private:
        SDL_Renderer *handle;
    };

}


#endif //SDL2PP_RENDERER_H
