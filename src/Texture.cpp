#ifdef SDL2PP_USE_IMAGE
#include <SDL2/SDL_image.h>
#endif

#include "internal_define.h"
#include "Renderer.h"
#include "Surface.h"
#include "Texture.h"


namespace sdl2pp {

#ifdef SDL2PP_USE_IMAGE

    Texture::Texture(const Renderer &renderer, const std::string &path) : Texture(renderer, path.c_str()) {
    }

    Texture::Texture(const Renderer &renderer, const char *path) :
            handle(IMG_LoadTexture(renderer.get(), path)) {
        if (nullptr == handle) {
            SDL2PP_IMG_THROW("IMG_LoadTexture");
        }
    }

#endif

    Texture::Texture(const Renderer &renderer, const Surface &surface) :
            handle(SDL_CreateTextureFromSurface(renderer.get(), surface.get())) {
        if (nullptr == handle) {
            SDL2PP_THROW("SDL_CreateTextureFromSurface");
        }
    }

    Texture::~Texture() {
        if (nullptr != handle) {
            SDL_DestroyTexture(handle);
        }
    }

    Texture &Texture::operator=(Texture &&other) noexcept {
        if (this == &other)
            return *this;
        this->~Texture();
        handle = other.handle;
        other.handle = nullptr;
        return *this;
    }


    void Texture::setBlendMode(SDL_BlendMode mode) {
        if (SDL_SetTextureBlendMode(handle, mode) < 0) {
            SDL2PP_THROW("SDL_SetTextureBlendMode");
        }
    }

    SDL_BlendMode Texture::getBlendMode() const {
        SDL_BlendMode mode;
        if (SDL_GetTextureBlendMode(handle, &mode) < 0) {
            SDL2PP_THROW("SDL_GetTextureBlendMode");
        }
    }

    void Texture::setAlphaMod(Uint8 alpha) {
        if (SDL_SetTextureAlphaMod(handle, alpha) < 0) {
            SDL2PP_THROW("SDL_SetTextureAlphaMod");
        }
    }

    Uint8 Texture::getAlphaMod() const {
        Uint8 alpha;
        if (SDL_GetTextureAlphaMod(handle, &alpha) < 0) {
            SDL2PP_THROW("SDL_GetTextureAlphaMod");
        }
    }

}