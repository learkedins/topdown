#include <SDL2/SDL.h>
#include <stdio.h>

#define WIDTH 1200
#define HEIGHT 800

int main(int argc, char **argv) {
  SDL_Window *window = NULL;
  SDL_Event* event = NULL;

  (void)argc; (void)argv;

  if(SDL_Init(SDL_INIT_VIDEO) != 0) {
    fprintf(stderr, "Failed to initialize: %s\n", SDL_GetError()); 
    return 1;
  }

  window = SDL_CreateWindow("RPG",
                          SDL_WINDOWPOS_UNDEFINED,
                          SDL_WINDOWPOS_UNDEFINED,
                          WIDTH,
                          HEIGHT,
                          SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE );

  if(window == NULL) {
    fprintf(stderr, "SDL Window failed to initialize: %s\n", SDL_GetError());
    return 1;
  }

  while(SDL_PollEvent(event)) {
    if(event->type == SDL_QUIT){
      SDL_DestroyWindow(window);
      SDL_Quit();
    }
  }

  return 0;
}
