#include "internal_define.h"
#include "InitImage.h"


#ifdef SDL2PP_USE_IMAGE

namespace sdl2pp {

    InitImage::InitImage(int flags) {
        if ((IMG_Init(flags) & flags) != flags) {
            SDL2PP_IMG_THROW("IMG_Init");
        }
    }

    InitImage::~InitImage() {
        IMG_Quit();
    }

}

#endif
