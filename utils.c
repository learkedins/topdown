#include "main.h"

void errorHandler(char text[]) {
  fprintf(stderr, "%s failed to initialize: %s\n", text, SDL_GetError());
};

void ttfErrorHandler(char text[]) {
  fprintf(stderr, "%s failed to initialize: %s\n", text, TTF_GetError());
};
