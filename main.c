#include "game.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 400

int isFullScreen = 1;

int main(int argc, char **argv) {
  SDL_Event event;
  SDL_Rect rect1, rect2;
  SDL_Renderer *renderer;
  SDL_Texture *texture1, *texture2;
  SDL_Window *window;
  char *font_path;
  int quit;

  SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO);
  SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_WIDTH, 0, &window,
                              &renderer);
  TTF_Init();
  TTF_Font *font = TTF_OpenFont("jetbrains.ttf", 24);
  if (font == NULL) {
    ttfErrorHandler("Loading");
    exit(EXIT_FAILURE);
  }
  get_text_and_rect(renderer, 0, 0, "hello", font, &texture1, &rect1);
  get_text_and_rect(renderer, 0, rect1.y + rect1.h, "world", font, &texture2,
                    &rect2);

  quit = 0;
  while (!quit) {
    while (SDL_PollEvent(&event) == 1) {
      if (event.type == SDL_QUIT) {
        quit = 1;
      }
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    /* Use TTF textures. */
    SDL_RenderCopy(renderer, texture1, NULL, &rect1);
    SDL_RenderCopy(renderer, texture2, NULL, &rect2);

    SDL_RenderPresent(renderer);
  }

  /* Deinit TTF. */
  SDL_DestroyTexture(texture1);
  SDL_DestroyTexture(texture2);
  TTF_Quit();

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return EXIT_SUCCESS;
}
