#include "dxlib.h"

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

const unsigned int COLOR_ARRAY[] =
{
	16711680,
	65280,
	255,
	16711935,
	16776960,
	65535,
	15790320
};
const int COLOR_ARRAY_LENGTH = sizeof(COLOR_ARRAY) / sizeof(COLOR_ARRAY[0]);





int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);
	ChangeWindowMode(true);
	if (DxLib_Init() == -1)
	{
		return -1;
	}
	// 描画先画面を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);
	

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//---------------------------------------
		// 更新
		//---------------------------------------
	

		//---------------------------------------
		// 描画
		//---------------------------------------
		ClearDrawScreen();

		//--------------------
		// ↓ここから
		//-------------------

			// 32ビットRGB色情報
			unsigned int rgbValue = COLOR_ARRAY[0];

			// 赤(R)、緑(G)、青(B)の成分を取得
			unsigned char red = (rgbValue >> 16) & 0xFF;
			unsigned char green = (rgbValue >> 8) & 0xFF;
			unsigned char blue = rgbValue & 0xFF;

			// 結果の表示
			DrawFormatString(15,15,GetColor(255,255,255),"赤(R): %d" , static_cast<int>(red));
			DrawFormatString(15,30,GetColor(255,255,255),"赤(G): %d" , static_cast<int>(green));
			DrawFormatString(15,45,GetColor(255,255,255),"赤(B): %d" , static_cast<int>(blue));
			//"緑(G): " << static_cast<int>(green)
		//	"青(B): " << static_cast<int>(blue) 


		//--------------------
		// ↑ここまでに処理を記述
		//--------------------

		ScreenFlip();
	}

	DxLib_End();

	return 0;
}