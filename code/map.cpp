#include "render.h"

extern Game game;
extern Map map;

void Map::Init() {
	Map_x = -925;
	Map_y = -1220;

	map_tip[0] = LoadGraph("data/zimen.png");
	map_tip[1] = LoadGraph("data/miti.png");
	map_tip[2] = LoadGraph("data/kabe.png");
	map_tip[3] = LoadGraph("data/mati.png");
	map_tip[4] = LoadGraph("data/mati.png");
	map_tip[5] = LoadGraph("data/mati.png");
	map_tip[6] = LoadGraph("data/mati.png");
	map_tip[7] = LoadGraph("data/mati.png");
	map_tip[8] = LoadGraph("data/mati.png");
	map_tip[9] = LoadGraph("data/mati.png");
}

void Map::Updata() {
	// 自分の見るマップ座標移動
	if (CheckHitKey(KEY_INPUT_UP)) {
		map.Map_y += 5;
	}
	if (CheckHitKey(KEY_INPUT_DOWN)) {
		map.Map_y -= 5;
	}
	if (CheckHitKey(KEY_INPUT_LEFT)) {
		map.Map_x += 5;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		map.Map_x -= 5;
	}
}

void Map::Render() {
	// 普通の地面 0
	// 町（中央） 1
	for (int h = 0; h < MAP_H; h++) {
		for (int w = 0; w < MAP_W; w++) {
			//	マップ番号を取得
			int num = game.map_data[h][w];
			//	場所(座標)を特定
			int x = w * 30;
			int y = h * 30;
			//	番号の画像を描画
			if (num == 10) num = 0;
			DrawGraph(x + map.Map_x, y + map.Map_y,map_tip[num], TRUE);
		}
	}

	for (int h = 0; h < MAP_H; h++) {
		for (int w = 0; w < MAP_W; w++) {
			//	マップ番号を取得
			int num = game.map_data[h][w];
			//	場所(座標)を特定
			int x = w * 30;
			int y = h * 30;
			//	番号の画像を描画
			if (num == 9)
				DrawGraph(x + map.Map_x, y + map.Map_y, map_tip[num], TRUE);
		}
	}
}