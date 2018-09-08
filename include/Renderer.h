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

        void copy(const Texture &, const optional<Rect> &srcRect, const optional<Rect> &destRect);

        void setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

        void setDrawBlendMode(SDL_BlendMode);

        SDL_BlendMode getDrawBlendMode() const;

        void fill();

        void fillRect(const Rect &);

        void drawRect(const Rect &);

        void drawLine(int x1, int y1, int x2, int y2);

        void drawPoint(int x, int y);

    private:
        SDL_Renderer *handle;
    };

}


#endif //SDL2PP_RENDERER_H
