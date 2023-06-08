#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>

void errorHandler(char text[]);
void ttfErrorHandler(char text[]);

/* Window related */
void toggleFullScreen(SDL_Window *window);

/*
 * How to display a font
 * Make a new texture and generate a new rect
 * call drawText and fulfill all of the parameter
 * use SDL_RenderCopty(renderer, texture, NULL, &rect) in the main loop
 * destroy the texture outside of the main loop
 */
void drawText(SDL_Renderer *renderer, int x, int y, char *text, TTF_Font *font,
              SDL_Texture **texture, SDL_Rect *rect);

void drawRectangle(SDL_Renderer *renderer, int x, int y, int w, int h,
                   SDL_Rect *rect);

/* TODO: make an efficient way to show sprite and render them into the window */
