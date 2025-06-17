#include "render.h"
#include "main.h"
Game game;

// npc;
Player player;
Npc npc;

Map map;

void Game::EnemyPop()
{
	int POS_X = GetRand(100);
	int POS_Y = GetRand(100);

	int rand = GetRand(3);

	
}

//---------------------------------------------------
//	‰Šú‰»ˆ—
//---------------------------------------------------
void Game::Init()
{

	map.Init();
	player.playerk = LoadGraph("data/player.png");
}
//---------------------------------------------------
//	XVˆ—
//---------------------------------------------------
void Game::Update()
{
	map.Updata();
	player.Update();
	npc.Update();
}
//---------------------------------------------------
//	•`‰æˆ—
//---------------------------------------------------
void Game::Render()
{
	map.Render();
	player.Render();
	npc.Render();
}
//---------------------------------------------------
//	I—¹ˆ—
//---------------------------------------------------
void Game::Exit()
{
}