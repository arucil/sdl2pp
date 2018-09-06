#ifndef SDL2PP_TEXTURE_H
#define SDL2PP_TEXTURE_H

#include <string>
#include "define.h"


namespace sdl2pp {

    class Renderer;
    class Surface;


    class Texture {
    public:

#ifdef SDL2PP_USE_IMAGE
        Texture(const Renderer &, const std::string &path);

        Texture(const Renderer &, const char *path);
#endif

        explicit Texture(const Renderer &, const Surface &);

        Texture(const Texture &) = delete;

        Texture(Texture &&other) noexcept : handle(other.handle) {
            other.handle = nullptr;
        }

        ~Texture();

    public:
        Texture &operator=(const Texture &) = delete;

        Texture &operator=(Texture &&other) noexcept;

    public:
        SDL_Texture *get() const {
            return handle;
        }

        void setBlendMode(SDL_BlendMode);

        SDL_BlendMode getBlendMode() const;

        void setAlphaMod(Uint8 alpha);

        Uint8 getAlphaMod() const;

    private:
        SDL_Texture *handle;
    };

}

#endif //SDL2PP_TEXTURE_H
