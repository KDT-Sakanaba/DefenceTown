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
//	初期化処理
//---------------------------------------------------
void Game::Init()
{

	map.Init();
	player.playerk = LoadGraph("data/player.png");
}
//---------------------------------------------------
//	更新処理
//---------------------------------------------------
void Game::Update()
{
	map.Updata();
	player.Update();
	npc.Update();
}
//---------------------------------------------------
//	描画処理
//---------------------------------------------------
void Game::Render()
{
	map.Render();
	player.Render();
	npc.Render();
}
//---------------------------------------------------
//	終了処理
//---------------------------------------------------
void Game::Exit()
{
}