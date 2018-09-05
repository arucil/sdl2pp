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

    void Renderer::copy(const Texture &texture, const optional<Rect> &srcRect, const optional<Rect> &destRect) {
        if (SDL_RenderCopy(handle, texture.get(), toPointer(srcRect), toPointer(destRect)) < 0) {
            SDL2PP_THROW("SDL_RenderCopy");
        }
    }

    void Renderer::setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
        if (SDL_SetRenderDrawColor(handle, r, g, b, a) < 0) {
            SDL2PP_THROW("SDL_SetRenderDrawColor");
        }
    }

    void Renderer::fill() {
        if (SDL_RenderFillRect(handle, nullptr) < 0) {
            SDL2PP_THROW("SDL_RenderFillRect");
        }
    }

    void Renderer::fillRect(const Rect &rect) {
        if (SDL_RenderFillRect(handle, &rect) < 0) {
            SDL2PP_THROW("SDL_RenderFillRect");
        }
    }

    void Renderer::drawRect(const sdl2pp::Rect &rect) {
        if (SDL_RenderDrawRect(handle, &rect) < 0) {
            SDL2PP_THROW("SDL_RenderDrawRect");
        }
    }

    void Renderer::drawLine(int x1, int y1, int x2, int y2) {
        if (SDL_RenderDrawLine(handle, x1, y1, x2, y2) < 0) {
            SDL2PP_THROW("SDL_RenderDrawLine");
        }
    }

    void Renderer::drawPoint(int x, int y) {
        if (SDL_RenderDrawPoint(handle, x, y) < 0) {
            SDL2PP_THROW("SDL_RenderDrawPoint");
        }
    }

}