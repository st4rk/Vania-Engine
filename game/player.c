#include "player.h"

void player_init(player* p, SDL_Texture* t) {

	SDL_QueryTexture(t, NULL, NULL, &p->src.w, &p->src.h);
	p->src.w = p->src.w / TOTAL_WIDTH_FRAMES;
	p->src.h = p->src.h / TOTAL_HEIGHT_FRAMES;

	p->src.x = 0;
	p->src.y = 0;

	p->dst.h = p->src.h * 2;
	p->dst.w = p->src.w * 2;

	p->dst.x = 0; 
	p->dst.y = 512-64-p->src.h;

	p->tmr_1 = 0;
	p->id = ENTITY_ALUCARD;
	p->next_state = 0;
	p->next_start_frame = 0;
	p->curr_state = 0;
	p->curr_anim = 0;
	p->curr_anim_frame = 0;
	p->isInMov = 0;
	p->flip = 0;
	p->m_texture = t;
}

void player_setX(player* p, u32 x) {
	p->dst.x = x;
}

void player_setY(player* p, u32 y) {
	p->dst.y = y;
}

void player_setAnim(player* p, u32 n) {
	p->curr_anim = n;
	p->src.y = p->src.h * n;
}

void player_setAnimFrame(player* p, u32 f) {
	p->curr_anim_frame = f;
	p->src.x = p->src.w * f;	
}

void player_setIsMov(player* p, bool m) {
	p->isInMov = m;
}

u32 player_getX(player* p) {
	return p->dst.x;
}

u32 player_getY(player* p) {
	return p->dst.y;
}

u32 player_getAnim(player* p) {
	return p->curr_anim;
}

bool player_getIsInMov(player* p) {
	return p->isInMov;
}
u32 player_getAnimFrame(player* p) {
	return p->curr_anim_frame;
}