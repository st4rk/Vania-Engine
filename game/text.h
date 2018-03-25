#ifndef _TEXT_H_
#define _TEXT_H_


#include "../core/core.h"

typedef struct text_t {
	SDL_Rect src;
	SDL_Rect dst;
	SDL_Texture* font;
} text_t;


extern void text_init(text_t *t, SDL_Texture* f);
extern void text_render(core* c, text_t* t, const char* text, int x, int y);

#endif