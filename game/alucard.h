#ifndef _ALUCARD_H_
#define _ALUCARD_H_


#include "../core/core.h"
#include "player.h"

#define ALUCARD_STATE_STOPPED       0
#define ALUCARD_STATE_IDLE          1
#define ALUCARD_STATE_BEGIN_WALKING 2
#define ALUCARD_STATE_WALKING       3
#define ALUCARD_STATE_BACKDASH      4

extern void (*alucard_table[])(core* c, player* p);
extern const u32 alucard_frames_per_anim[5];

#endif