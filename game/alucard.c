#include "alucard.h"

// <-- total frames per animation
const u32 alucard_frames_per_anim[5] = {
	5,  // stopped
	7, // idle
	14, // begin walking
	15, // walking
	12, // backdash
};


static void stopped(core* c, player* p) {

	if (p->curr_state == ALUCARD_STATE_STOPPED) {

		if ((c->keysPressed & KEY_LEFT) || (c->keysPressed & KEY_RIGHT)) {
			p->next_state = ALUCARD_STATE_BEGIN_WALKING;
			
			if (c->keysPressed & KEY_LEFT) {
				p->flip = SDL_FLIP_HORIZONTAL;
			} else {
				p->flip = 0;
			}		
		}

		if (c->keysPressed & KEY_SPACE) {
			p->next_state = ALUCARD_STATE_BACKDASH;
			p->next_start_frame = 4;
		}
	}

}

// TODO: Do I really need it? I guess I can make idle/stopped one single thing
// anyway let's see later
static void idle(core* c, player* p) {

	if (p->curr_state == ALUCARD_STATE_IDLE) {
		p->next_state = ALUCARD_STATE_STOPPED;
	} else {
		if (p->curr_state == ALUCARD_STATE_STOPPED) {
			if ((c->keysPressed & KEY_LEFT) || (c->keysPressed & KEY_RIGHT)) {
				p->next_state = ALUCARD_STATE_BEGIN_WALKING;
			}
		}
	}
}

static void walking(core* c, player* p) {

	if (p->next_state != ALUCARD_STATE_BACKDASH) {
		if (p->next_state != ALUCARD_STATE_IDLE) {
			if (!(c->keysPressed & (KEY_RIGHT | KEY_LEFT))) {
				p->next_state = ALUCARD_STATE_IDLE;
			}
		}
	}


	if (c->keysPressed & KEY_SPACE) {
		p->next_state = ALUCARD_STATE_BACKDASH;
	}

	// <-- check if we came from begin walking and change
	// <-- the next state to walking, so we have updating
	// <-- in the animation
	if (p->next_state == ALUCARD_STATE_BEGIN_WALKING) {
		p->next_state = ALUCARD_STATE_WALKING;
	}


	if (!p->flip) {
		player_setX(p,player_getX(p) + 1);
	} else {
		player_setX(p, player_getX(p) - 1);
	}
}

static void backdash(core* c, player* p) {
	if (!p->next_start_frame) {
		if (c->keysPressed & KEY_SPACE) {
			p->next_start_frame = 5;
		} else {
			p->next_state = ALUCARD_STATE_IDLE;
		}
	} 
}

void (*alucard_table[])(core* c, player* p) = {
	&stopped, &idle, &walking, &walking, &backdash
};