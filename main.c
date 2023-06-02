#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GL/gl.h>

typedef int32_t i32;
typedef uint32_t u32;
typedef int32_t b32;

#define WIDTH 1200
#define HEIGHT 800

int main(int argc, char **argv) {

  u32 WindowFlags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
  SDL_Window *window = SDL_CreateWindow("Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, WindowFlags);
  assert(window);
  SDL_GLContext Context = SDL_GL_CreateContext(window);

}
