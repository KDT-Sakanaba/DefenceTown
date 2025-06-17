#include "DxLib.h"
#include "main.h"
#include "game.h"

extern Game game;

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 画面サイズを変えたい
	ChangeWindowMode(TRUE);

	SetGraphMode(SCREEN_W, SCREEN_H, 32);

	//ログファイルを書き出さないようにする
	SetOutApplicationLogValidFlag(false);

	//ウィンドウのタイトル変更
	SetMainWindowText("Vertical Havoc");

	//背景色の変更
	SetBackgroundColor(128, 128, 128);


	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	// 裏画面に描画する
	SetDrawScreen(DX_SCREEN_BACK);

	// ゲームの初期化処理
	game.Init();

	while (ProcessMessage() == 0)
	{

		ClearDrawScreen();

		// ゲームの更新処理
		game.Update();
		// ゲームの描画処理
		game.Render();

		// escape キーを押したら 画面の終了
		if (CheckHitKey(KEY_INPUT_ESCAPE))	break;

		ScreenFlip();
	}

	// ゲームの終了処理
	game.Exit();

	DxLib_End();			// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}