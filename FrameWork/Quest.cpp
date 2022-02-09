
#pragma once
#include "Include.h"

Quest quest;

Quest::Quest(void)
{
	quest.missionnum1 = true;
	once = true;

}         

Quest::~Quest(void)
{

}

void Quest::Init()
{
	mission1img.Create("./resource/Img/UI/quest1.png", false, D3DCOLOR_XRGB(0, 0, 0));		//미션1 대화상자;
	mission2img.Create("./resource/Img/UI/quest2.png", false, D3DCOLOR_XRGB(0, 0, 0));		//미션2 대화상자;
	mission3img.Create("./resource/Img/UI/quest3.png", false, D3DCOLOR_XRGB(0, 0, 0));		//미션3 대화상자;
	missionfinishimg.Create("./resource/Img/UI/questfinish.png", false, D3DCOLOR_XRGB(0, 0, 0));		//미션완료 대화상자;
}

void Quest::Update()
{
	if (once == true)//수정
	{
		if (num_mission == 1)
		{
			missionnum1 = true; //미션1
			missionnum2 = false; //미션2
			missionnum3 = false; //미션3
		}
		if (num_mission == 2)
		{
			missionnum1 = false; //미션1
			missionnum2 = true; //미션2
			missionnum3 = false; //미션3
		}
		if (num_mission == 3)
		{
			missionnum1 = false; //미션1
			missionnum2 = false; //미션2
			missionnum3 = true; //미션3
		}
		if (num_mission == 4)
		{
			missionnum1 = false; //미션1
			missionnum2 = false; //미션2
			missionnum3 = false; //미션3
			missionfinish = true;
		}
		once = false;
	}
	if (check == false)	//퀘스트 완료여부 false일때는 진행중, true일때는 완료
	{
		if (missionnum1 == true)
		{
			num_mission = 1;
			if (count == 1)
			{
				resetcount = 1;
			}
		}
		else if (missionnum2 == true)
		{
			num_mission = 2;
			if (count == 1)
			{
				resetcount = 2;
			}
		}
		else if (missionnum3 == true)
		{
			num_mission = 3;
			if (count == 1)
			{
				resetcount = 3;
			}

		}
	}

	if (resetcount == 1)
	{

		if (missionnum1 == true)
			count = 0;
		missionnum1 = false;
		missionnum2 = true;
		option.shownewmsg = true;  //새로운 장소 열림 메세지 나타남
		option.place1 = false;
		option.place2 = true;
		option.place3 = false;

	}

	if (resetcount == 2)
	{

		if (missionnum2 == true)
			count = 0;
		missionnum2 = false;
		missionnum3 = true;
		option.shownewmsg = true; //새로운 장소 열림 메세지 나타남
		option.place1 = false;
		option.place2 = false;
		option.place3 = true;

	}

	if (resetcount == 3)
	{

		if (missionnum3 == true)
			count = 0;
		missionnum3 = false;
		option.place3 = false;
		missionfinish = true;
		num_mission = 4;//수정

	}

	if (missionfinish == true)
		check = true;

}

void Quest::Draw()
{


	//SetRect(&q_rc, 750, 130, 110, 110 ); // int xLeft, yTop, xRight, yBottom
	//ZeroMemory(str, 100);
	//sprintf_s(str, " 퀘스트 \n \n 연어: %d / %d 마리", missionnum, 10); //문자열 대입
	//dv_font.Fonts->DrawText(NULL, str, 100, &q_rc, DT_NOCLIP, D3DCOLOR_XRGB(0, 0, 0));
	// (THIS_ LPD3DXSPRITE pSprite, LPCSTR pString, INT Count, LPRECT pRect, DWORD Format, D3DCOLOR Color) 

	if (check == false)
	{
		SetRect(&q_rc, 840, 180, 110, 110); // int xLeft, yTop, xRight, yBottom
		ZeroMemory(str, 100);


		if (missionnum1 == true)
		{
			mission1img.Render(770, 40, 0, 1, 1);
			sprintf_s(str, " %d %d ", count, 1); //지금까지 잡힌 수, 잡아야하는 물고기수 붕어
			dv_font.Fonts->DrawText(NULL, str, 100, &q_rc, DT_NOCLIP, D3DCOLOR_XRGB(0, 0, 0));
		}
		if (missionnum2 == true)
		{
			mission2img.Render(770, 40, 0, 1, 1);
			sprintf_s(str, " %d %d ", count, 1); // 지금까지 잡힌 수, 잡아야하는 물고기수 잉어
			dv_font.Fonts->DrawText(NULL, str, 100, &q_rc, DT_NOCLIP, D3DCOLOR_XRGB(0, 0, 0));
		}
		if (missionnum3 == true)
		{
			mission3img.Render(770, 40, 0, 1, 1);
			sprintf_s(str, " %d %d ", count, 1); //지금까지 잡힌 수, 잡아야하는 물고기수 연어
			dv_font.Fonts->DrawText(NULL, str, 100, &q_rc, DT_NOCLIP, D3DCOLOR_XRGB(0, 0, 0));

		}
	}

	if (check == true && missionfinish == true)
		missionfinishimg.Render(770, 40, 0, 1, 1);
}