#include "game.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_video.h>

#define WINDOW_WIDTH 300
#define WINDOW_HEIGHT 300

int main(int argc, char **argv) {
  SDL_Event event;
  SDL_Rect rect1, rect2, rect3;
  SDL_Renderer *renderer;
  SDL_Texture *texture1, *texture2;
  SDL_Window *window;

  char *font_path;
  int running;

  int fullscreen = 0;

  SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO);
  SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window,
                              &renderer);
  TTF_Init();
  TTF_Font *font = TTF_OpenFont("assets/fonts/jetbrains.ttf", 24);
  if (font == NULL) {
    ttfErrorHandler("Loading");
    exit(EXIT_FAILURE);
  }

  running = 1;
  while (running) {
    while (SDL_PollEvent(&event) == 1) {
      if (event.type == SDL_QUIT)
        running = 0;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
  }

  TTF_Quit();

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return EXIT_SUCCESS;
}
