#include <SDL2/SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char **argv) {
  // Window
  SDL_Window *window = NULL;

  // Event handler
  SDL_Event e;

  // Surface
  SDL_Surface *surface = NULL;

  // Initialize SDL
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL_ERROR: %s\n", SDL_GetError()); 
  }

  // Create the window
  SDL_WindowFlags WindowFlags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE; 

  window = SDL_CreateWindow( "Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, WindowFlags);
  if(window == NULL) {
    printf("Window could not be created %s\n", SDL_GetError());
  }

  surface = SDL_GetWindowSurface(window);

  // Fill the surface
  SDL_FillRect(surface, NULL, SDL_MapRGB( surface->format, 0xFF, 0x00, 0x00));

  SDL_UpdateWindowSurface(window);

  int running = 0;

  while(running == 0) {
    while(SDL_PollEvent(&e)) {
      if(e.type == SDL_QUIT){
        running = 1;
      }
    }
  }

}
