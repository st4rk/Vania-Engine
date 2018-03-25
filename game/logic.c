#include "logic.h"


static void logic_updatePlayer(core* c, player* p) {

	switch (p->id) {
		case ENTITY_ALUCARD:
			alucard_table[p->curr_state](c, p);
		break;
	}

	if (p->tmr_1 < SDL_GetTicks()) {
		p->tmr_1 = SDL_GetTicks() + 50;

		if (player_getAnimFrame(p) < alucard_frames_per_anim[player_getAnim(p)]) {
			player_setAnimFrame(p, player_getAnimFrame(p) + 1);	
		} else {
				
			// we have a transition between animations!
			if (p->next_state != p->curr_state) {
				player_setAnim(p, p->next_state);
				p->curr_state = p->next_state;
			}

			player_setAnimFrame(p, p->next_start_frame);
			p->next_start_frame = 0;
		}
	}

}

void logic_run(core* c, player* p) {
	logic_updatePlayer(c, p);
}