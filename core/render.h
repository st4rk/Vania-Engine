#ifndef _RENDER_H_
#define _RENDER_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "settings.h"
#include "utils.h"

typedef struct render {
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
} render;


extern int render_init(render *r);
extern int render_quit(render *r);
extern SDL_Texture* render_getTexture(render *r, const char* dir);
#endif