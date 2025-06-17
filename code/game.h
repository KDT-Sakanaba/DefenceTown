#pragma once
#include "main.h"
#include <vector>
#include "enemy.h"
#include "npc.h"
#include <memory>

class Game {
public:

// chara
	//std::vector<Enemy> ken;
	//std::vector<Enemy> yumi;
	//std::vector<Enemy> tate;

	//EnemyStatus edata[3]{
	//	20,20,20,4,0,0,
	//	15,25,20,6,0,0,
	//	25,10,25,3,0,0
	//};

	std::vector<std::shared_ptr<Enemy>> enemys;
	//std::vector<Enemy> kovolt;
	//std::vector<Enemy> element;
	//std::vector<Enemy> gorem;

	EnemyStatus edata[4]{
		20,20,10,5,0,0,
		20,20,20,3,0,0,
		15,30,20,7,0,0,
		25,10,25,3,0,0
	};


// map	
	int map_data[MAP_H][MAP_W] =
	{
#include "map/map.txt"
	};

// UI


// その他
	int Mouse_X;
	int Mouse_Y;
//---------------------------------------------------------------------------------
//	マウスの座標を取得する
//---------------------------------------------------------------------------------
	int GetMouseX()
	{
		int mouse_x;
		int mouse_y;
		GetMousePoint(&mouse_x, &mouse_y);
		return mouse_x;
	}
	int GetMouseY()
	{
		int mouse_x;
		int mouse_y;
		GetMousePoint(&mouse_x, &mouse_y);
		return mouse_y;
	}


	void EnemyPop();

	void Init();
	void Update();
	void Render();
	void Exit();
};