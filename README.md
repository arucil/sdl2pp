# sdl2pp
(**Work in Progress**) C++ wrapper for SDL2.

# Example

```C++
#define SDL2PP_USE_IMAGE
#include <experimental/optional>
#include "sdl2pp.h"

using namespace sdl2pp;
using namespace std::experimental;

int main() {
    try {
        /* RAII-based library initialization / finalization; So as  */
        Init init(SDL_INIT_VIDEO);
        InitImage initImage(IMG_INIT_PNG);
        
        /* Create SDL objects via constructors */
        Window window("SDL2PP", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                400, 300, SDL_WINDOW_SHOWN);
        Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);
        Texture texture(renderer, "assets/background.png");
        
        bool quit = false;
        
        EventDispatcher e;
        
        /* Handle events with lambda expressions */
        /* Note that an alias QuitEvent to SDL_QuitEvent is provided for convenience,
         * so are some other types. See the source code for details.
         */
        e.quit = [&quit](const QuitEvent &event) {
            quit = true;
        };
        
        while (!quit) {
            while (e.poll()) {}
            
            renderer.setDrawColor(0xff, 0x80, 0x80, 0xff);
            
            /* Overloaded member functions are provided */
            renderer.fill(); // Overloading fillRect()
            
            /* Replace nullable pointers with std::optional's */
            renderer.copy(texture, nullopt, nullopt);
            renderer.present();
        }
        /* Exception handling instead of error code checking */
    } catch (const Exception &e) {
        SDL_Log("%s\n", e.what());
    }
    
    return 0;
}

```

# Feature

Currently supported wrappers are the following
- SDL
  - Library initialization / finalization
  - Graphics
      - SDL_Window
      - SDL_Surface
      - SDL_Renderer
      - SDL_Texture
  - Lambda expression based event handling
- SDL_image
  - Library initialization / finalization


If you want to use `SDL2_image` features, define `SDL2PP_USE_IMAGE` macro in compiler options.
