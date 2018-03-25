#ifndef _CORE_H_
#define _CORE_H_


#include <stdio.h>
#include <stdlib.h>

#include "render.h"
#include "utils.h"


#define KEY_RIGHT 0x1
#define KEY_LEFT  0x2
#define KEY_SPACE 0x4

typedef struct core {
	bool isMainLoop;


	u32 keysPressed;

	render m_render;
} core;


extern void core_init(core* c);

void core_keyboard();



#endif