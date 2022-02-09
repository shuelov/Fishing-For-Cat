#pragma once

#include "Include.h"

static DWORD KeyTime = GetTickCount();

Inputname::Inputname()
{
}

Inputname::~Inputname()
{
}

void Inputname::Init()
{


	count = 0;
	alpha = 0;
	menuimg.Create("./resource/Img/Map/Lobby.png", false, D3DCOLOR_XRGB(0, 0, 0));
	Input.Create("./resource/Img/Name/Input.png", false, D3DCOLOR_XRGB(0, 0, 0));
	Ok.Create("./resource/Img/Name/Ok.png", false, D3DCOLOR_XRGB(0, 0, 0));
	Back.Create("./resource/Img/Name/Back.png", false, D3DCOLOR_XRGB(0, 0, 0));
	pointer.Create("./resource/Img/Name/pointer.png", false, D3DCOLOR_XRGB(0, 0, 0));


}

void Inputname::Update(double frame)
{


	key.Update();


	if (KeyDown(VK_RETURN))
	{
		if (GetTickCount() - KeyTime > 200)
		{
			if (select % 3 == 0)  // 새게임일 경우 이동
			{

			}
			if (select % 3 == 1)
			{
				if (g_Mng.n_Chap = NAME)
				{

					g_Mng.n_Chap = STORY;
				}
			}
			if (select % 3 == 2)
			{
				if (g_Mng.n_Chap = NAME)
				{

					g_Mng.n_Chap = MENU;
				}

			}

			KeyTime = GetTickCount();
		}
	}


	if (KeyDown(VK_DOWN))
	{
		if (GetTickCount() - KeyTime > 200)
		{
			select++;
			KeyTime = GetTickCount();
		}

	}

	if (KeyDown(VK_UP))
	{
		if (GetTickCount() - KeyTime > 200)
		{
			select--;
			KeyTime = GetTickCount();
		}

	}

	//if (xx.xxx > 100 * xxx.xxx)
	//{
	//	if (GetTickCount() - CoinTime > 100)
	//	{
	//		count++;
	//		CoinTime = GetTickCount();
	//	}
	//	if (count > 1) count = 0;
	//}


}

void Inputname::Draw()
{
	menuimg.Render(0, 0, 0, 2, 2); //
	Input.Render(350, 300, 0, 0.5, 0.5); //이미지출력  
	Ok.Render(330, 410, 0, 1, 1);
	Back.Render(640, 410, 0, 1, 1);


	if (select % 3 == 0)   // 화살표의 방향이 '입력'일 경우의 좌표
	{
		pointer.Render(320, 300, 0, 1, 1);
		select = 3;
	}
	else if (select % 3 == 1)
	{
		pointer.Render(300, 410, 0, 1, 1); //확인 (시작하기)
		select = 1;
	}
	else if (select % 3 == 2)
	{
		pointer.Render(600, 410, 0, 1, 1); //뒤로 (메인으로)
		select = 2;
	}
	//dv_font.DrawString("로비", 200, 210);   //글자출력

	//if (GetTickCount() - AlTime > 100)
	//{
	//	alpha++;
	//	AlTime = GetTickCount();
	//}

	//if (alpha == 0) menuimg[2].SetColor(255, 255, 255, 255);
	//if (alpha == 1) menuimg[2].SetColor(255, 255, 255, 0);

	//if (xxx.xxx == 0) menuimg[2].Draw(407, 336);
	//else if (count < 2) menuimg[count].Draw(412, 276);

}

void Inputname::OnMessage(MSG* msg)  //'메뉴'일때만 메세지 받음 
{
	//char aaa[256];
	//_itoa_s(msg->message, aaa,2);
	//dv_font.DrawString(aaa, 10 , 210 ) ;   
	//PostQuitMessage(0);

	switch (msg->message)
	{
	case WM_KEYDOWN:
		switch (msg->wParam) {
		case VK_F2:
			//MessageBox(NULL, "", "", 0);
			if (g_Mng.n_Chap = NAME) {

				g_Mng.n_Chap = MENU;
				//sound.m_Bk1->Play(0, DSBPLAY_LOOPING);

			}
			break;
		}

	}

}