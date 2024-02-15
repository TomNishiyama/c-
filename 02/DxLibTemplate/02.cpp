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
	// �`����ʂ𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);
	

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//---------------------------------------
		// �X�V
		//---------------------------------------
	

		//---------------------------------------
		// �`��
		//---------------------------------------
		ClearDrawScreen();

		//--------------------
		// ����������
		//-------------------

			// 32�r�b�gRGB�F���
			unsigned int rgbValue = COLOR_ARRAY[0];

			// ��(R)�A��(G)�A��(B)�̐������擾
			unsigned char red = (rgbValue >> 16) & 0xFF;
			unsigned char green = (rgbValue >> 8) & 0xFF;
			unsigned char blue = rgbValue & 0xFF;

			// ���ʂ̕\��
			DrawFormatString(15,15,GetColor(255,255,255),"��(R): %d" , static_cast<int>(red));
			DrawFormatString(15,30,GetColor(255,255,255),"��(G): %d" , static_cast<int>(green));
			DrawFormatString(15,45,GetColor(255,255,255),"��(B): %d" , static_cast<int>(blue));
			//"��(G): " << static_cast<int>(green)
		//	"��(B): " << static_cast<int>(blue) 


		//--------------------
		// �������܂łɏ������L�q
		//--------------------

		ScreenFlip();
	}

	DxLib_End();

	return 0;
}