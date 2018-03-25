#ifndef _VANIA_H_
#define _VANIA_H_


#include "../core/core.h"
#include "../core/xml.h"


#include "player.h"
#include "logic.h"
#include "text.h"

typedef struct vania {

	u32 tmr_100;

	text_t m_text;
	core   m_core;
	player m_player;
} vania;

extern void vania_init();
extern void vania_end();

void vania_loadGameData();

#endif