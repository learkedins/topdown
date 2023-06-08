#include "game.h"

int fullScreen = 0;

void drawText(SDL_Renderer *renderer, int x, int y, char *text, TTF_Font *font,
              SDL_Texture **texture, SDL_Rect *rect) {
  int textWidth, textHeight;
  SDL_Surface *surface;
  SDL_Color textColor = {255, 255, 255, 0};

  surface = TTF_RenderText_Solid(font, text, textColor);
  *texture = SDL_CreateTextureFromSurface(renderer, surface);
  textWidth = surface->w;
  textHeight = surface->h;
  SDL_FreeSurface(surface);
  rect->x = x;
  rect->y = y;
  rect->w = textWidth;
  rect->h = textHeight;
}

void drawRectangle(SDL_Renderer *renderer, int x, int y, int w, int h,
                   SDL_Rect *rect) {

  int rectWidth, rectHeight;
  rect->x = x;
  rect->y = y;
  rect->w = w;
  rect->h = h;
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderDrawRect(renderer, rect);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
};
