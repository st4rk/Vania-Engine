#include "text.h"


void text_init(text_t* t, SDL_Texture* f) {
	SDL_QueryTexture(f, NULL, NULL, &t->src.w, &t->src.h);

	t->src.w = t->src.w/20;//14;
	t->src.h = t->src.h/5;//18;

	t->src.x = 5*4;
	t->src.y = 12*4;

	t->dst.h = t->src.h*2;
	t->dst.w = t->src.w*2;
	t->dst.x = 0;
	t->dst.y = 0;

	t->font = f;
}

void text_render(core* c, text_t* t, const char* text, int x, int y) {
	
	t->dst.x = x;
	t->dst.y = y;

	for (int i = 0; i < strlen(text); i++) {
		t->dst.x += t->dst.w + 8;

		t->src.x = 5 * ((text[i] - 32) % 20);
		t->src.y = 12 * ((text[i] - 32) / 20);

		SDL_RenderCopy(c->m_render.m_renderer, t->font, &t->src, &t->dst);
	}
}