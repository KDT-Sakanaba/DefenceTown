#include "DxLib.h"
#include "main.h"
#include "game.h"

extern Game game;

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// ��ʃT�C�Y��ς�����
	ChangeWindowMode(TRUE);

	SetGraphMode(SCREEN_W, SCREEN_H, 32);

	//���O�t�@�C���������o���Ȃ��悤�ɂ���
	SetOutApplicationLogValidFlag(false);

	//�E�B���h�E�̃^�C�g���ύX
	SetMainWindowText("Vertical Havoc");

	//�w�i�F�̕ύX
	SetBackgroundColor(128, 128, 128);


	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	// ����ʂɕ`�悷��
	SetDrawScreen(DX_SCREEN_BACK);

	// �Q�[���̏���������
	game.Init();

	while (ProcessMessage() == 0)
	{

		ClearDrawScreen();

		// �Q�[���̍X�V����
		game.Update();
		// �Q�[���̕`�揈��
		game.Render();

		// escape �L�[���������� ��ʂ̏I��
		if (CheckHitKey(KEY_INPUT_ESCAPE))	break;

		ScreenFlip();
	}

	// �Q�[���̏I������
	game.Exit();

	DxLib_End();			// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}