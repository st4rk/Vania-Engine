#include "render.h"


int render_init(render *r) {
	int result = 0;
	r->m_window = NULL;
	r->m_renderer = NULL;

	result = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);


	if (result) {
		printf("An error ocurred while trying to initialize the SDL\n");
		printf("Error: %s\n", SDL_GetError());

		// <-- error on initialize
		return 0x1;
	}	


	// <-- create a window
	r->m_window = SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, GAME_WIDTH, GAME_HEIGHT, SDL_WINDOW_SHOWN);

	if (!r->m_window) {
		printf("An error ocurred while trying to create the window!\n");
		printf("Error: %s\n", SDL_GetError());

		// <-- error on create window
		return 0x2;
	}

	r->m_renderer = SDL_CreateRenderer(r->m_window, -1, SDL_RENDERER_ACCELERATED);

	if (!r->m_renderer) {
		printf("An error ocurred while trying to create the rendere!\n");
		printf("Error: %s\n", SDL_GetError());

		// <-- error on create renderer
		return 0x3;
	}

	SDL_SetRenderDrawColor(r->m_renderer, 0x0, 0x0, 0x0, 0x0);


	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)){
		printf("An error ocurred while trying to initialize SDL_image\n");
		printf("Error: %s\n", IMG_GetError());

		// <-- error on init img
		return 0x4;
	}

	// <-- works!
	return 0x0;
}


int render_quit(render *r) {

	SDL_DestroyWindow(r->m_window);
	SDL_DestroyRenderer(r->m_renderer);
	r->m_window = NULL;
	r->m_renderer = NULL;

	IMG_Quit();
	SDL_Quit();

	return 0x0;
}


SDL_Texture* render_getTexture(render* r, const char* dir) {
	SDL_Texture* m_texture = NULL;

	SDL_Surface* m_surface = IMG_Load( dir );

	if (!m_surface) {
		printf("An error ocurred loading: %s\n", dir);
		printf("Error: %s\n", IMG_GetError());
		return NULL;
	}

	m_texture = SDL_CreateTextureFromSurface(r->m_renderer, m_surface);

	if (!m_texture) {
		printf("An error ocurred while trying to create a texture from surface!\n");
		printf("Error: %s\n", SDL_GetError());
		SDL_FreeSurface( m_surface );
		return NULL;
	}

	SDL_FreeSurface ( m_surface );

	return m_texture;
}