#include "render.h"

//extern Npc npc;

Npc::Npc(NpcStatus data)
{
	nStatus = data;
}

void Npc::Update() {
	if (mode == 出現) {
		for (int h = 0; h < MAP_H; h++) {
			for (int w = 0; w < MAP_W; w++) {
				nRoute[h][w] = 999;
			}
		}

		Route_num = 1;		//ルートを決めるために
		nRoute[48][48] = 1;	//ゴール地点
		mode = 設定;			//次に行く
	}


	if (mode == 設定) {
		// ルート配列を全部見ていって
		while (Route_num < 100) {
			for (int h = 0; h < MAP_H; h++) {
				for (int w = 0; w < MAP_W; w++) {
					//	３：基準の番号を見つけたら
					if (nRoute[h][w] == Route_num) {
						//	３：基準の番号の上下左右を「基準の番号＋１」にする
						//	条件として「隣が配列内」「通れる場所」「基準の番号より大きい」
						if (w + 1 <= MAP_W - 1 && nRoute[h][w + 1] <= 1 && nRoute[h][w + 1] > Route_num)
							nRoute[h][w + 1] = Route_num + 1;	//	右
						if (w - 1 >= 0 && nRoute[h][w - 1] <= 1 && nRoute[h][w - 1] > Route_num)
							nRoute[h][w - 1] = Route_num + 1;	//	右
						if (h + 1 <= MAP_H - 1 && nRoute[h + 1][w] <= 1 && nRoute[h + 1][w] > Route_num)
							nRoute[h + 1][w] = Route_num + 1;	//	下
						if (h - 1 >= 0 && nRoute[h - 1][w] <= 1 && nRoute[h - 1][w] > Route_num)
							nRoute[h - 1][w] = Route_num + 1;	//	上
					}
					if (nRoute[h][w] == 2)
						nRoute[h][w] = 1000;
				}
			}
			//	４：基準の番号を１増やして次のスペースキーで使う
			Route_num++;
		}
		mode = 動く;
	}

	if (mode == 動く) {

		//	今ＮＰＣのいるルート番号
		int nRoute_centnR = nRoute[nStatus.POS_Y][nStatus.POS_X];

		//	そのＮＰＣの上下左右のルートの値
		int nRoute_next[4];
		nRoute_next[0] = nRoute[nStatus.POS_Y][nStatus.POS_X + 1];	//	右
		nRoute_next[1] = nRoute[nStatus.POS_Y][nStatus.POS_X - 1];	//	左
		nRoute_next[2] = nRoute[nStatus.POS_Y + 1][nStatus.POS_X];	//	下
		nRoute_next[3] = nRoute[nStatus.POS_Y - 1][nStatus.POS_X];	//	上

		for (int i = 0; i < 4; i++) {
			if (nRoute_next[i] == 999) {
				nStatus.POS_X = (GetRand(100));
				nStatus.POS_Y = (GetRand(100));
				mode = 1;
			}
		}

		//	次に進むときの方向
		int move_w[4] = { 1, -1, 0,  0 };
		int move_h[4] = { 0,  0, 1, -1 };

		//	上下左右のどこから見始めるかの値をランダムに決めます
		int start = GetRand(3);	//	０：右　１：左　２：下　３：上
		//	上下左右の４回繰り返す
		for (int i = 0; i < 4; i++) {
			//	何番目を見るか
			int num = (i + start) % 4;
			//	num 番目の値が小さかったらそっちに進む
			if (nRoute_centnR > nRoute_next[num]) {
				//	進みたい方向の値をポイント番号に足す
				nStatus.POS_X = (nStatus.POS_X + move_w[num]);
				nStatus.POS_Y = (nStatus.POS_Y + move_h[num]);
				//	進む方向が見つかったのでループは終了
				break;
			}
		}

	}
}

void Npc::Render() {

}

