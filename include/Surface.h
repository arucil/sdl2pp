#ifndef SDL2PP_SURFACE_H
#define SDL2PP_SURFACE_H

#include <string>
#include "define.h"


namespace sdl2pp {

    class Surface {
    public:
        explicit Surface(const std::string &path);
        explicit Surface(const char *path);

        explicit Surface(SDL_Surface *);

        Surface(const Surface &) = delete;

        Surface(Surface &&other) noexcept : handle(other.handle) {
            other.handle = nullptr;
        }

        ~Surface();

    public:
        Surface &operator=(const Surface &) = delete;

        Surface &operator=(Surface &&other) noexcept;

    public:
        SDL_Surface *get() const {
            return handle;
        }

        SDL_Surface &operator*() {
            return *handle;
        }

        SDL_Surface *operator->() {
            return handle;
        }

        const SDL_Surface &operator*() const {
            return *handle;
        }

        const SDL_Surface *operator->() const {
            return handle;
        }

        void blit(const Surface &src, const optional<const Rect> &srcRect, const optional<Rect> &destRect);

        Surface convert(const SDL_PixelFormat *, Uint32 flags);

    private:
        SDL_Surface *handle;
    };

}

#endif //SDL2PP_SURFACE_H
