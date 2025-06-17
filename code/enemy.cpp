#include "render.h"

Enemy::Enemy(EnemyStatus data)
{
	eStatus = data;
}


void Enemy::Update() {
	if (mode == �o��) {
		for (int h = 0; h < MAP_H; h++) {
			for (int w = 0; w < MAP_W; w++) {
				eRoute[h][w] = 999;
			}
		}

		Route_num = 1;		//���[�g�����߂邽�߂�
		eRoute[48][48] = 1;	//�S�[���n�_
		mode = �ݒ�;			//���ɍs��
	}

	if (mode == �ݒ�) {
		// ���[�g�z���S�����Ă�����
		while (Route_num < 100) {
			for (int h = 0; h < MAP_H; h++) {
				for (int w = 0; w < MAP_W; w++) {
					//	�R�F��̔ԍ�����������
					if (eRoute[h][w] == Route_num) {
						//	�R�F��̔ԍ��̏㉺���E���u��̔ԍ��{�P�v�ɂ���
						//	�����Ƃ��āu�ׂ��z����v�u�ʂ��ꏊ�v�u��̔ԍ����傫���v
						if (w + 1 <= MAP_W - 1 && eRoute[h][w + 1] <= 1 && eRoute[h][w + 1] > Route_num)
							eRoute[h][w + 1] = Route_num + 1;	//	�E
						if (w - 1 >= 0 && eRoute[h][w - 1] <= 1 && eRoute[h][w - 1] > Route_num)
							eRoute[h][w - 1] = Route_num + 1;	//	�E
						if (h + 1 <= MAP_H - 1 && eRoute[h + 1][w] <= 1 && eRoute[h + 1][w] > Route_num)
							eRoute[h + 1][w] = Route_num + 1;	//	��
						if (h - 1 >= 0 && eRoute[h - 1][w] <= 1 && eRoute[h - 1][w] > Route_num)
							eRoute[h - 1][w] = Route_num + 1;	//	��
					}
					if (eRoute[h][w] == 2)
						eRoute[h][w] = 1000;
				}
			}
			//	�S�F��̔ԍ����P���₵�Ď��̃X�y�[�X�L�[�Ŏg��
			Route_num++;
		}
		mode = ����;
	}

	if (mode == ����) {

		//	���m�o�b�̂��郋�[�g�ԍ�
		int eRoute_center = eRoute[eStatus.POS_Y][eStatus.POS_X];

		//	���̂m�o�b�̏㉺���E�̃��[�g�̒l
		int eRoute_next[4];
		eRoute_next[0] = eRoute[eStatus.POS_Y][eStatus.POS_X + 1];	//	�E
		eRoute_next[1] = eRoute[eStatus.POS_Y][eStatus.POS_X - 1];	//	��
		eRoute_next[2] = eRoute[eStatus.POS_Y + 1][eStatus.POS_X];	//	��
		eRoute_next[3] = eRoute[eStatus.POS_Y - 1][eStatus.POS_X];	//	��

		for (int i = 0; i < 4; i++) {
			if (eRoute_next[i] == 999) {
				eStatus.POS_X = (GetRand(100));
				eStatus.POS_Y = (GetRand(100));
				mode = 1;
			}
		}

		//	���ɐi�ނƂ��̕���
		int move_w[4] = { 1, -1, 0,  0 };
		int move_h[4] = { 0,  0, 1, -1 };

		//	�㉺���E�̂ǂ����猩�n�߂邩�̒l�������_���Ɍ��߂܂�
		int start = GetRand(3);	//	�O�F�E�@�P�F���@�Q�F���@�R�F��
		//	�㉺���E�̂S��J��Ԃ�
		for (int i = 0; i < 4; i++) {
			//	���Ԗڂ����邩
			int num = (i + start) % 4;
			//	num �Ԗڂ̒l�������������炻�����ɐi��
			if (eRoute_center > eRoute_next[num]) {
				//	�i�݂��������̒l���|�C���g�ԍ��ɑ���
				eStatus.POS_X = (eStatus.POS_X + move_w[num]);
				eStatus.POS_Y = (eStatus.POS_Y + move_h[num]);
				//	�i�ޕ��������������̂Ń��[�v�͏I��
				break;
			}
		}

	}
}

void Enemy::Render() {

}
