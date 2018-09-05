#ifdef SDL2PP_USE_IMAGE
#include <SDL2/SDL_image.h>
#endif

#include "internal_define.h"
#include "Surface.h"


namespace sdl2pp {


    Surface::Surface(const std::string &path) : Surface(path.c_str()) {
    }

    Surface::Surface(const char *path) {
#ifdef SDL2PP_USE_IMAGE
        handle = IMG_Load(path);
        if (nullptr == handle) {
            SDL2PP_IMG_THROW("IMG_Load");
        }
#else
        handle = SDL_LoadBMP(path);
        if (nullptr == handle) {
            SDL2PP_THROW("SDL_LoadBMP");
        }
#endif
    }

    Surface::Surface(SDL_Surface *surface) : handle(surface) {}

    Surface::~Surface() {
        if (nullptr != handle) {
            SDL_FreeSurface(handle);
        }
    }

    Surface &Surface::operator=(Surface &&other) noexcept {
        if (this == &other)
            return *this;
        this->~Surface();
        handle = other.handle;
        other.handle = nullptr;
        return *this;
    }

    void Surface::blit(const Surface &src, const optional<const Rect> &srcRect, const optional<Rect> &destRect) {
        if (SDL_BlitSurface(src.get(), toPointer(srcRect), handle, toPointer(destRect)) < 0) {
            SDL2PP_THROW("SDL_BlitSurface");
        }
    }

    Surface Surface::convert(const SDL_PixelFormat *format, Uint32 flags) {
        auto surface = SDL_ConvertSurface(handle, format, flags);

        if (nullptr == surface) {
            SDL2PP_THROW("SDL_ConvertSurface");
        }

        return Surface(surface);
    }

}