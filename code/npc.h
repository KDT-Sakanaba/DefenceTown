#pragma once
#include "main.h"

struct NpcStatus
{
	int HP;
	int ATK;
	int DEF;
	int RANGE;

	int POS_X;
	int POS_Y;

};

class Npc {

public:

	int GOLL_X;
	int GOLL_Y;


	NpcStatus nStatus{};

	int nRoute[MAP_H][MAP_W];
	int Route_num;
	int mode;
	enum {
		èoåª,
		ê›íË,
		ìÆÇ≠,
	};

	Npc(NpcStatus data);

	void Update();
	void Render();


	Npc() = default;
};