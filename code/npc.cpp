#include "render.h"

//extern Npc npc;

Npc::Npc(NpcStatus data)
{
	nStatus = data;
}

void Npc::Update() {
	if (mode == �o��) {
		for (int h = 0; h < MAP_H; h++) {
			for (int w = 0; w < MAP_W; w++) {
				nRoute[h][w] = 999;
			}
		}

		Route_num = 1;		//���[�g�����߂邽�߂�
		nRoute[48][48] = 1;	//�S�[���n�_
		mode = �ݒ�;			//���ɍs��
	}


	if (mode == �ݒ�) {
		// ���[�g�z���S�����Ă�����
		while (Route_num < 100) {
			for (int h = 0; h < MAP_H; h++) {
				for (int w = 0; w < MAP_W; w++) {
					//	�R�F��̔ԍ�����������
					if (nRoute[h][w] == Route_num) {
						//	�R�F��̔ԍ��̏㉺���E���u��̔ԍ��{�P�v�ɂ���
						//	�����Ƃ��āu�ׂ��z����v�u�ʂ��ꏊ�v�u��̔ԍ����傫���v
						if (w + 1 <= MAP_W - 1 && nRoute[h][w + 1] <= 1 && nRoute[h][w + 1] > Route_num)
							nRoute[h][w + 1] = Route_num + 1;	//	�E
						if (w - 1 >= 0 && nRoute[h][w - 1] <= 1 && nRoute[h][w - 1] > Route_num)
							nRoute[h][w - 1] = Route_num + 1;	//	�E
						if (h + 1 <= MAP_H - 1 && nRoute[h + 1][w] <= 1 && nRoute[h + 1][w] > Route_num)
							nRoute[h + 1][w] = Route_num + 1;	//	��
						if (h - 1 >= 0 && nRoute[h - 1][w] <= 1 && nRoute[h - 1][w] > Route_num)
							nRoute[h - 1][w] = Route_num + 1;	//	��
					}
					if (nRoute[h][w] == 2)
						nRoute[h][w] = 1000;
				}
			}
			//	�S�F��̔ԍ����P���₵�Ď��̃X�y�[�X�L�[�Ŏg��
			Route_num++;
		}
		mode = ����;
	}

	if (mode == ����) {

		//	���m�o�b�̂��郋�[�g�ԍ�
		int nRoute_centnR = nRoute[nStatus.POS_Y][nStatus.POS_X];

		//	���̂m�o�b�̏㉺���E�̃��[�g�̒l
		int nRoute_next[4];
		nRoute_next[0] = nRoute[nStatus.POS_Y][nStatus.POS_X + 1];	//	�E
		nRoute_next[1] = nRoute[nStatus.POS_Y][nStatus.POS_X - 1];	//	��
		nRoute_next[2] = nRoute[nStatus.POS_Y + 1][nStatus.POS_X];	//	��
		nRoute_next[3] = nRoute[nStatus.POS_Y - 1][nStatus.POS_X];	//	��

		for (int i = 0; i < 4; i++) {
			if (nRoute_next[i] == 999) {
				nStatus.POS_X = (GetRand(100));
				nStatus.POS_Y = (GetRand(100));
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
			if (nRoute_centnR > nRoute_next[num]) {
				//	�i�݂��������̒l���|�C���g�ԍ��ɑ���
				nStatus.POS_X = (nStatus.POS_X + move_w[num]);
				nStatus.POS_Y = (nStatus.POS_Y + move_h[num]);
				//	�i�ޕ��������������̂Ń��[�v�͏I��
				break;
			}
		}

	}
}

void Npc::Render() {

}

