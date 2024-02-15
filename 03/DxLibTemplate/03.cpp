#include "dxlib.h"
#include "image.inc"

const int WINDOW_WIDTH = 1024;
const int WINDOW_HEIGHT = 576;

static unsigned int pixelArray[PIXEL_NUM];

void initPixelArray();
void writeScreen();

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
	
	int screen = MakeScreen(IMAGE_WIDTH, IMAGE_HEIGHT, FALSE);
	initPixelArray();
	
	//==========================================================
	// ↓ 各ピクセルの色データの合成と書き込みはここで行う！
	//==========================================================



	//==========================================================
	// ↑ 各ピクセルの色データの合成と書き込みはここで行う！
	//==========================================================

	SetDrawScreen(screen);
	writeScreen();
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
		int x = (WINDOW_WIDTH - IMAGE_WIDTH) / 2;
		int y = (WINDOW_HEIGHT - IMAGE_HEIGHT) / 2;
		DrawGraph( x, y, screen, FALSE );

		ScreenFlip();
	}
	DeleteGraph( screen );

	DxLib_End();

	return 0;
}

void initPixelArray()
{
	for (int i = 0; i < PIXEL_NUM; i++)
	{
		unsigned char brightness = rand() % 256;
		unsigned char* pPixel = (unsigned char*)(pixelArray + i);
		for (int j = 0; j < 3; j++)
		{
			pPixel[j] = brightness;
		}
	}
	return;
}

void writeScreen()
{
	for (int i = 0; i < PIXEL_NUM; i++)
	{
		int row = i / IMAGE_WIDTH;
		int col = i % IMAGE_WIDTH;
		DrawPixel(col, row, pixelArray[i]);
	}
	return;
}
