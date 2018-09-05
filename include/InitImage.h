#ifndef SDL2PP_INITIMAGE_H
#define SDL2PP_INITIMAGE_H

#include "define.h"

#ifdef SDL2PP_USE_IMAGE

#include <SDL2/SDL_image.h>

namespace sdl2pp {

    class InitImage {
    public:
        explicit InitImage(int flags);

        ~InitImage();

        InitImage(const InitImage &) = delete;
        InitImage &operator=(const InitImage &) = delete;
        InitImage(InitImage &&) = delete;
        InitImage &operator=(InitImage &&) = delete;
    };

}

#endif

#endif //SDL2PP_INITIMAGE_H
