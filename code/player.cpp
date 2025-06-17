#include "render.h"

extern Game game;

extern Player player;

extern Map map;

void Player::Update() {
	if (CheckHitKey(KEY_INPUT_W)) {
		player.POS_Y -= 1;
	}
	if (CheckHitKey(KEY_INPUT_A)) {
		player.POS_X -= 1;
	}
	if (CheckHitKey(KEY_INPUT_S)) {
		player.POS_Y += 1;
	}
	if (CheckHitKey(KEY_INPUT_D)) {
		player.POS_X += 1;
	}

}

void Player::Render() {
	DrawGraph(POS_X * 30 + map.Map_x, POS_Y * 30 + map.Map_y, playerk, true);

}