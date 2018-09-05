#include "internal_define.h"
#include "Window.h"
#include "Texture.h"
#include "Renderer.h"

namespace sdl2pp {

    Renderer::Renderer(const Window &window, int index, Uint32 flags) :
            handle(SDL_CreateRenderer(window.get(), index, flags)) {
        if (nullptr == handle) {
            SDL2PP_THROW("SDL_CreateRenderer");
        }
    }

    Renderer &Renderer::operator=(Renderer &&other) noexcept {
        if (this == &other)
            return *this;
        this->~Renderer();
        handle = other.handle;
        other.handle = nullptr;
        return *this;
    }

    Renderer::~Renderer() {
        if (nullptr != handle) {
            SDL_DestroyRenderer(handle);
        }
    }

    void Renderer::clear() {
        if (SDL_RenderClear(handle) < 0) {
            SDL2PP_THROW("SDL_RenderClear");
        }
    }

    void Renderer::present() {
        SDL_RenderPresent(handle);
    }

    void Renderer::copy(const Texture &texture, const optional<const Rect> &srcRect, const optional<const Rect> &destRect) {
        if (SDL_RenderCopy(handle, texture.get(), toPointer(srcRect), toPointer(destRect)) < 0) {
            SDL2PP_THROW("SDL_RenderCopy");
        }
    }

}