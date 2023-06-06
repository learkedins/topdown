#### How to display a font

Make a new texture and generate a new rect.

call `get_text_and_rect` and fulfill all of the parameter.

use `SDL_RenderCopy(renderer, texture, NULL, &rect)` in the main loop to render.

Don't forget to use DestroyTexture outside the main loop.
