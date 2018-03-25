#include "core.h"


void core_keyboard(core* c) {
	SDL_Event event;


	while (SDL_PollEvent(&event)) {

		switch (event.type) {
			case SDL_QUIT: {
				printf("its over anakin i have the high ground\n");

				render_quit(&c->m_render);

				SDL_Quit();
				exit(0);
			}
			break;

			case SDL_KEYUP: {
				c->keysPressed = 0;
			}
			break;

			case SDL_KEYDOWN: {
				c->keysPressed = 0;

				switch ( event.key.keysym.sym ) {
					case SDLK_LEFT:
						c->keysPressed |= KEY_LEFT;
					break;

					case SDLK_RIGHT:
						c->keysPressed |= KEY_RIGHT;
					break;

					case SDLK_SPACE:
						c->keysPressed |= KEY_SPACE;
					break;
				}
			}
			break;

			default:
				printf("An unknown event: %d\n", event.type);
			break;
		}
	}
}


void core_init(core* c) {
	c->isMainLoop = true;
	c->keysPressed = 0;
	render_init(&c->m_render);
}