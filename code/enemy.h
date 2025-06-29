#pragma once
#include "main.h"

struct EnemyStatus
{
	int HP;
	int ATK;
	int DEF;
	int RANGE;

	int POS_X;
	int POS_Y;
};

class Enemy {
public:

	EnemyStatus eStatus{};

	int eRoute[MAP_H][MAP_W];
	int Route_num;
	int mode;
	enum {
		出現,
		設定,
		動く,
	};

	Enemy(EnemyStatus data);

	void Update();
	void Render();

};