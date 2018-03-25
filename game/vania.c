#include "vania.h"

void vania_loadGameData(vania* v) {
	player* p = &v->m_player;
	core* c = &v->m_core;
	text_t* t = &v->m_text;

	SDL_Texture* p_texture = NULL;

	p_texture = render_getTexture(&c->m_render, "data/sprites/3.png");

	if (!p_texture) {
		printf("Olha o pau quebrando\n");
		exit(0);
	}

	player_init(p, p_texture);

	p_texture = render_getTexture(&c->m_render, "data/font/2.png");

	if (!p_texture) {
		printf("Olha o pau quebrando\n");
		exit(0);
	}

	text_init(t, p_texture);



	FILE* xml_file = fopen("data/test.xml", "r");



	/* Parse the document
	 *
	 * Watch out: Remember not to free the source until you have freed the
	 *     document itself. If you have to free the source before, supply a
	 *     copy to xml_parse_document which can be freed together with the
	 *     document (`free_buffer' argument to `xml_document_free')
	 */
	struct xml_document* document = xml_open_document(xml_file);

	/* You _have_ to check the result of `xml_parse_document', if it's 0
	 * then the source could not be parsed. If you think this is a bug in
	 * xml.c, than use a debug build (cmake -DCMAKE_BUILD_TYPE=Debug) which
	 * will verbosely tell you about the parsing process
	 */
	if (!document) {
		printf("Could parse document\n");
		exit(EXIT_FAILURE);
	}
	struct xml_node* root = xml_document_root(document);


	/* Say Hello World :-)
	 */
	struct xml_node* root_hello = xml_node_child(root, 0);
	struct xml_string* hello = xml_node_name(root_hello);
	struct xml_string* world = xml_node_content(root_hello);

	/* Watch out: `xml_string_copy' will not 0-terminate your buffers! (but
	 *     `calloc' will :-)
	 */
	unsigned char* hello_0 = calloc(xml_string_length(hello) + 1, sizeof(uint8_t));
	unsigned char* world_0 = calloc(xml_string_length(world) + 1, sizeof(uint8_t));
	xml_string_copy(hello, hello_0, xml_string_length(hello));
	xml_string_copy(world, world_0, xml_string_length(world));

	printf("%s %s\n", hello_0, world_0);
	free(hello_0);
	free(world_0);


	/* Extract amount of Root/This children
	 */
	struct xml_node* root_this = xml_node_child(root, 1);
	printf("Root/This has %lu children\n", (unsigned long)xml_node_children(root_this));


	/* Remember to free the document or you'll risk a memory leak
	 */
	xml_document_free(document, false);
	exit(0);
}


void vania_init() {
	vania m_vania;

	m_vania.tmr_100 = 0;

	core_init(&m_vania.m_core);

	vania_loadGameData(&m_vania);

	/**
	 * game engine main loop
	 */
	while (m_vania.m_core.isMainLoop) {
		SDL_RenderClear(m_vania.m_core.m_render.m_renderer);

		core_keyboard(&m_vania.m_core);

		logic_run(&m_vania.m_core, &m_vania.m_player);

		text_render(&m_vania.m_core, &m_vania.m_text, "VAMPIRAO 2018\0", 128, 128);

		SDL_RenderCopyEx(m_vania.m_core.m_render.m_renderer, m_vania.m_player.m_texture, &m_vania.m_player.src, &m_vania.m_player.dst, 0.0, NULL, m_vania.m_player.flip);		
		
		SDL_RenderPresent(m_vania.m_core.m_render.m_renderer);

		SDL_Delay(10);
	}
}
