#pragma once
#include "Include.h"

Town town;

Town::Town()
{
	show = false;				//bool형 show false로 초기화 : 캐릭터 안보이는 상태
	op = false;
	//speed = 600;
	//alpha = 0;
	scene = 0;


}
//Town::Town(int stage)
//{
//	m_Stage = stage;
//}

Town::~Town()
{
}

void Town::Init()
{
	npc.Init();

	int i, j;
	char FileName[256];

	town_day.Create("./resource/Img/Map/town_morning.png", false, D3DCOLOR_XRGB(0, 0, 0));	// 마을 낮 화면


	for (int i = 0; i<99; i++)	// 마을 구름
	{
		sprintf_s(FileName, "./resource/img/map/map_extra/town/c%02d.png", i);
		town_cloud[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}


	option.Init();



	cat.Init();
	deal.Init();
	sound.InitEtc();	// 수정


}

void Town::Update(double frame)
{
	sound.StopEtc();	// 수정
	sound.PlayEtc();	// 수정	

	npc.Update();


	option.Update(200);
	


	cat.Update();
	


	//--------------------------------상점 테스트용 코드-------------------------------
	if (KeyDown('Z') && option.pause == false && npc.selling == true)			//수정										//z 키누르면 상점뜸 
	{
		//option.tabhold = true;//수정

		if (GetTickCount() - KeyTime > 200)
		{
			dealon=true;
			option.dealon = true;

			KeyTime = GetTickCount();
		}
	}
	if(dealon==true)
		deal.Update();
	if (KeyDown(VK_SPACE)&&dealon==true&&deal.pointer_pos==10)													 
	{
		if (GetTickCount() - KeyTime > 200)
		{
			dealon = false;
			option.dealon = false;
			option.tabhold = false;


			KeyTime = GetTickCount();
		}
	}
	//--------------------------------------------------------------------------------


	if (cat.aboard == true && transfer == true)
	{
		if (KeyDown('M'))
		{
			if (GetTickCount() - KeyTime > 200)
			{
				option.placeon = true;
				option.pointer_pos = 13;
				if (once == false)//수정
				{
					option.place1 = true;
					once = false;
				}
				KeyTime = GetTickCount();
			}
		}
	}

	if (GetTickCount() - KeyTime > 200)	 // 수정
	{
		if (direction == true)
			scene += 1;		// 구름 장면 변경
		if (scene >= 99)
			scene = 0;		// 구름 장면 변경

							//if (direction == false)
							//	scene -= 1;		// 구름 장면 변경
		if (scene <= 0)
			direction = true;
		KeyTime = GetTickCount();
	}
}

void Town::Draw()
{
	town_day.Render(0, 0, 0, 1.6, 2); 
	town_cloud[scene].Render(-65, -24, 0, 1, 1); 

	npc.Draw();	// NPC 출력
	option.Draw();															 //메뉴,퀘스트,가방 버튼 보이기 위함


		cat.Draw();															//고양이 끝으로 갔을 때 장소이동 버튼 나오는 지 테스트하기 위해 넣음
		load.Draw();
		if (cat.aboard == true)
		{
			op = true;

			if (op == true)
			{

				if (1050 < cat.m_cat.dx < 1100)
				{
					transfer = true;
				}

				if (cat.m_cat.dx<1050)
				{
					transfer = false;
				}

				if (transfer == true)
				{
					SetRect(&m_rc, 1152, 500, 1152 + 200, 550 + 200);
					dv_font.Fonts->DrawTextA(NULL, "PRESS 'M'", -1, &m_rc, DT_LEFT, D3DCOLOR_ARGB(255, 255, 255, 255));
				}

			}
		}


	if (dealon == true)
	{
		deal.Draw();
	}

}

void Town::OnMessage(MSG* msg)
{
}
