#pragma once

#include "Include.h"
Menu menu;
static DWORD KeyTime = GetTickCount();

Menu::Menu()
{
	effect_Count = 0;
	choose = true;
	soundcount = true;
}

Menu::~Menu()
{
}

void Menu::Init()
{
	sql.Init();
	count = 0;
	alpha = 0;
	menuimg.Create("./resource/Img/Map/Lobby.png", false, D3DCOLOR_XRGB(0, 0, 0));
	logo.Create("./resource/Img/Logo/logo.png", false, D3DCOLOR_XRGB(0, 0, 0));
	newgame.Create("./resource/Img/UI/newgame.png", false, D3DCOLOR_XRGB(0, 0, 0));
	loadgame.Create("./resource/Img/UI/loadgame.png", false, D3DCOLOR_XRGB(0, 0, 0));
	quit.Create("./resource/Img/UI/quit.png", false, D3DCOLOR_XRGB(0, 0, 0));
	pointer.Create("./resource/Img/Fish/cruciancarp.png", false, D3DCOLOR_XRGB(0, 0, 0));

	saving.Create("./resource/Img/UI/menu_save_saveslot.png", false, D3DCOLOR_XRGB(0, 0, 0));			//로드슬롯
	menupopupimg.Create("./resource/Img/UI/menu_popup.png", false, D3DCOLOR_XRGB(0, 0, 0));		//메뉴팝업
	load1_text.Create("./resource/Img/UI/load1.png", false, D3DCOLOR_XRGB(0, 0, 0));						//로드1
	load2_text.Create("./resource/Img/UI/load2.png", false, D3DCOLOR_XRGB(0, 0, 0));						//로드2
	load3_text.Create("./resource/Img/UI/load3.png", false, D3DCOLOR_XRGB(0, 0, 0));						//로드3
	goback.Create("./resource/Img/UI/goback.png", false, D3DCOLOR_XRGB(0, 0, 0));							//뒤로가기 버튼

	char FileName[256];

	for (int i = 0; i<46; i++)
	{
		sprintf_s(FileName, "./resource/Img/effect/light/1%04d.png", i);
		light[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}

	turn = true;
	sound.InitEtc();
	load.Init();
}

void Menu::Update(double frame)
{
	sound.PlayEtc();

	if (choose == true)
	{
		if (KeyDown(VK_RETURN) || KeyDown(VK_SPACE))
		{
			if (GetTickCount() - KeyTime > 200)
			{
				if (select % 3 == 0)  // 새게임일 경우 이동
				{
					if (g_Mng.n_Chap == MENU)
					{
						sound.m_confirm->Play(NULL);
						//load.load();//수정
						
						g_Mng.n_Chap = STORY;
					}
				}
				if (select % 3 == 1)
				{
					sound.m_confirm->Play(NULL);
					loadon = true;
					choose = false;
					//불러오기
				}
				if (select % 3 == 2)
				{
					sound.m_confirm->Play(NULL);
					exit(1);//수정함
							//종료
				}

				KeyTime = GetTickCount();
			}
		}
	}

	if (loadon == true) //수정 단락 다 붙여넣기하면될듯
	{
		if (KeyDown(VK_RETURN) || KeyDown(VK_SPACE))
		{

			if (GetTickCount() - KeyTime > 200)
			{
				sound.m_confirm->Play(NULL);
				if (loading % 4 == 0)   //
				{
					load.load1();
					loadon = false;
					g_Mng.n_Chap = TOWN;
				}
				else if (loading % 4 == 1)
				{
					load.load2();
					loadon = false;
					g_Mng.n_Chap = TOWN;
				}
				else if (loading % 4 == 2)
				{
					load.load3();
					loadon = false;
					g_Mng.n_Chap = TOWN;
				}
				else if (loading % 4 == 3)
				{
					loadon = false;
					choose = true;
					loading = 0;
				}
				KeyTime = GetTickCount();
			}
		}

		if (KeyDown(VK_DOWN))
		{
			if (GetTickCount() - KeyTime > 200)
			{
				sound.m_but->Play(NULL);
				loading++;
				if (loading >= 3)
					loading = 3;
				KeyTime = GetTickCount();
			}
		}

		if (KeyDown(VK_UP))
		{
			if (GetTickCount() - KeyTime > 200)
			{
				loading--;
				sound.m_but->Play(NULL);
				if (loading <= 0)
					loading = 0;
				KeyTime = GetTickCount();
			}

		}
	}

	else
	{
		if (KeyDown(VK_DOWN))
		{
			if (GetTickCount() - KeyTime > 200)
			{
				sound.m_but->Play(NULL);
				select++;
				KeyTime = GetTickCount();
			}

		}

		if (KeyDown(VK_UP))
		{
			if (GetTickCount() - KeyTime > 200)
			{
				sound.m_but->Play(NULL);
				select--;
				KeyTime = GetTickCount();
			}

		}
	}

	if (GetTickCount() - KeyTime > 300)
	{
		if (turn == true)
			effect_Count += 1;
		if (effect_Count >= 45)
			turn = false;

		if (turn == false)
			effect_Count -= 1;
		if (effect_Count <= 0)
			turn = true;

		KeyTime = GetTickCount();
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

void Menu::Draw()
{

	menuimg.Render(0, 0, 0, 2, 2); //이미지출력  (이미지가 작아 2배로 크게한 상황)
	logo.Render(390, 120, 0, 1, 1);
	newgame.Render(540, 400, 0, 1, 1);
	loadgame.Render(540, 500, 0, 1, 1);
	quit.Render(540, 600, 0, 1, 1);
	light[effect_Count].Render(0, 1, 0, 4, 2);

	if (select % 3 == 0)   // 화살표의 방향이 '새 게임'일 경우의 좌표
	{
		pointer.Render(480, 410, 0, 1, 1);
		select = 3;
	}
	else if (select % 3 == 1)
	{
		pointer.Render(480, 510, 0, 1, 1);
		select = 1;
	}
	else if (select % 3 == 2)
	{
		pointer.Render(480, 610, 0, 1, 1);
		select = 2;
	}

	if (loadon == true)
	{
		menupopupimg.Render(390, 70, 0, 1, 1);

		saving.Render(450, 130, 0, 1, 1);	//저장슬롯1
		saving.Render(450, 250, 0, 1, 1);	//저장슬롯2
		saving.Render(450, 370, 0, 1, 1);	//저장슬롯3

		load1_text.Render(510, 130, 0, 1, 1);
		load2_text.Render(510, 250, 0, 1, 1);
		load3_text.Render(510, 370, 0, 1, 1);
		goback.Render(540, 490, 0, 1, 1);


		if (loading % 4 == 0)   // 화살표의 방향이 '새 게임'일 경우의 좌표
		{
			pointer.Render(380, 120, 0, 1, 1);
			loading = 0;
		}
		else if (loading % 4 == 1)
		{
			pointer.Render(380, 240, 0, 1, 1);
			loading = 1;
		}
		else if (loading % 4 == 2)
		{
			pointer.Render(380, 360, 0, 1, 1);
			loading = 2;
		}
		else if (loading % 4 == 3)
		{
			pointer.Render(480, 490, 0, 1, 1);
			loading = 3;
		}

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

void Menu::OnMessage(MSG* msg)  //'메뉴'일때만 메세지 받음 
{
	//char aaa[256];
	//_itoa_s_s(msg->message, aaa,2);
	//dv_font.DrawString(aaa, 10 , 210 ) ;   
	//PostQuitMessage(0);

	switch (msg->message)
	{
	case WM_KEYDOWN:
		switch (msg->wParam) {
		case VK_F2:
			//MessageBox(NULL, "", "", 0);
			if (g_Mng.n_Chap == MENU) {

				g_Mng.n_Chap = NEWGAME;
				//sound.m_Bk1->Play(0, DSBPLAY_LOOPING);

			}
			break;
		}

	}

}