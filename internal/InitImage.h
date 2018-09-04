#ifndef SDL2PP_INITIMAGE_H
#define SDL2PP_INITIMAGE_H

#include <SDL2/SDL_image.h>
#include <sstream>
#include "Exception.h"

namespace sdl2pp {

    class InitImage {
    public:
        explicit InitImage(int flags) {
            if ((IMG_Init(flags) & flags) != flags) {
                std::ostringstream sout;
                sout << "IMG_Init: " << IMG_GetError();
                throw Exception(sout.str());
            }
        }

        ~InitImage() {
            IMG_Quit();
        }

        InitImage(const InitImage &) = delete;
        InitImage &operator=(const InitImage &) = delete;
        InitImage(InitImage &&) = delete;
        InitImage &operator=(InitImage &&) = delete;
    };

}

#endif //SDL2PP_INITIMAGE_H
