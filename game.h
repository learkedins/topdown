#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>

void errorHandler(char text[]);
void ttfErrorHandler(char text[]);

/* Window related */
void toggleFullScreen(SDL_Window *window, int currentState);
void get_text_and_rect(SDL_Renderer *renderer, int x, int y, char *text,
                       TTF_Font *font, SDL_Texture **texture, SDL_Rect *rect);
