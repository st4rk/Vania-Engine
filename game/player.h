#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "../core/core.h"
#include "../core/render.h"

// <-- all game enties ID

#define ENTITY_ALUCARD 0

#define TOTAL_WIDTH_FRAMES 16
#define TOTAL_HEIGHT_FRAMES 16


// <-- anime frames

#define ANIM_WALKING_RIGHT 0
#define ANIM_WALKING_LEFT  6


typedef struct player {
	u32 hp;
	u32 id;

	u32 next_state;
	u32 next_start_frame;
	u32 curr_state;
	u32 curr_anim;
	u32 curr_anim_frame;
	SDL_RendererFlip flip;
	u32 tmr_1;

	bool isInMov;

	SDL_Texture* m_texture;
	SDL_Rect src;
	SDL_Rect dst;
} player;


extern void player_init(player* p, SDL_Texture* t);

extern void player_setX(player* p, u32 x);
extern void player_setY(player* p, u32 y);
extern void player_setAnim(player* p, u32 n);
extern void player_setAnimFrame(player* p, u32 f);
extern void player_setIsMov(player* p, bool m);

extern u32 player_getX(player* p);
extern u32 player_getY(player* p);
extern u32 player_getAnim(player* p);
extern u32 player_getAnimFrame(player* p);
extern bool player_getIsInMov(player* p);

#endif