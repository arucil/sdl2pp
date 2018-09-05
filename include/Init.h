#ifndef SDL2PP_INIT_H
#define SDL2PP_INIT_H

#include "define.h"


namespace sdl2pp {

    class Init {
    public:
        explicit Init(Uint32 flags);

        ~Init();

        Init(const Init &) = delete;
        Init &operator=(const Init &) = delete;
        Init(Init &&) = delete;
        Init &operator=(Init &&) = delete;
    };

}


#endif //SDL2PP_INIT_H
