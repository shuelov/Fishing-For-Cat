#pragma once
#include "Include.h"

Power power;

Power::Power(void)
{
	pointer_y = 480;
	pos = 0;
	startpowering = false;
}
Power::~Power(void)
{

}
void Power::Init()
{
	powerbar.Create("./resource/Img/UI/bar.png", false, D3DCOLOR_XRGB(0, 0, 0));
	pointer.Create("./resource/Img/UI/pointer.png", false, D3DCOLOR_XRGB(0, 0, 0));

	line_left_178.Create("./resource/Img/UI/fishingline/fishingline_left_178.png", false, D3DCOLOR_XRGB(0, 0, 0));
	line_left_356.Create("./resource/Img/UI/fishingline/fishingline_left_356.png", false, D3DCOLOR_XRGB(0, 0, 0));
	line_left_600.Create("./resource/Img/UI/fishingline/fishingline_left_600.png", false, D3DCOLOR_XRGB(0, 0, 0));

	line_right_178.Create("./resource/Img/UI/fishingline/fishingline_right_178.png", false, D3DCOLOR_XRGB(0, 0, 0));
	line_right_356.Create("./resource/Img/UI/fishingline/fishingline_right_356.png", false, D3DCOLOR_XRGB(0, 0, 0));
	line_right_600.Create("./resource/Img/UI/fishingline/fishingline_right_600.png", false, D3DCOLOR_XRGB(0, 0, 0));
}
void Power::Update()
{

	if (KeyDown(VK_SPACE) && startpowering == true) //스페이스를 누를경우 포인터 멈춤 /시작
	{
		if (GetTickCount() - KeyTime > 200)
		{

			if (pos == 0)  //움직이지않으면 움직이고
			{
				pos = 1;
			}
			else if (pos == 1)  //움직이는 중이면 움직임을 멈추고  막대바와 화살표를 감춘다
			{
				pos = 0;

				if (pointer_y < 246) // 여기서 파워가 결정됨.
					howmuchpower = 3;
				else if (pointer_y >= 246 && pointer_y < 364)
					howmuchpower = 2;
				else if (pointer_y >= 364)
					howmuchpower = 1;

				if (cat.x <= 576)
					direction = 2; //파워 결정된 자리의 좌표로 오른쪽으로 던질지 왼쪽으로 던질지 정한다
				else if (cat.x > 576)
					direction = 1;


				sound.m_throw->Play(NULL);	// 수정
				sound.m_Game->Play(0, DSBPLAY_LOOPING);	// 수정

				startfishing = true; // 낚시의 시작
				option.tabhold = true;
				startpowering = false; // 파워링의 끝
			}
			KeyTime = GetTickCount();
		}
	}

	Changecal();


	if (KeyDown(VK_SPACE) && startpowering == false && startfishing == false && option.pause==false && option.checkinventory == false&&option.tabhold==false) // 스페이스바를 누르면 파워막대바를 띄우게 조건 변수를 바꿔줌
	{
		if (GetTickCount() - KeyTime > 200 && option.checkinventory == false)
		{
			//MessageBox(NULL, (LPCSTR)"", (LPCSTR)"", NULL);
			startpowering = true;

			KeyTime = GetTickCount();
		}
	}



}

void Power::Draw()
{
	if (startpowering == true && startfishing==false)
	{
		powerbar.Render(1100, 150, 0, 1, 1);
		pointer.Render(1050, pointer_y, 0, 1, 1);
	}
	if (startpowering == false && startfishing==true)
	{
		fishingline_y = cat.y + 75;
		if (direction == 1) // 왼쪽으로 던지는 경우
		{
			if (howmuchpower == 1) // 낚시줄 그림
			{
				fishingline_x = cat.x - 178 + 64;
				line_left_178.Render(fishingline_x, fishingline_y, 0, 1, 1);  
			}
			else if (howmuchpower == 2)
			{
				fishingline_x = cat.x - 356 + 64;
				line_left_356.Render(fishingline_x, fishingline_y, 0, 1, 1);
			}
			else if (howmuchpower == 3)
			{
				fishingline_x = cat.x - 600 + 64;
				line_left_600.Render(fishingline_x, fishingline_y, 0, 1, 1);
			}
		}
		if (direction == 2) // 오른쪽으로 던지는 경우
		{
			fishingline_x = cat.x + 64;
			if (howmuchpower == 1)
			{
				line_right_178.Render(fishingline_x, fishingline_y, 0, 1, 1);
			}
			else if (howmuchpower == 2)
			{
				line_right_356.Render(fishingline_x, fishingline_y, 0, 1, 1);
			}
			else if (howmuchpower == 3)
			{
				line_right_600.Render(fishingline_x, fishingline_y, 0, 1, 1);
			}
		}
	}






}





void Power::Changecal()  //화살표의 좌표를 제한된 위치에서 움직이게 하는 함수
{
	if (pos == 1)
	{
		if (plusorminus == true)
			pointer_y += 11;
		if (plusorminus == false)
			pointer_y -= 11;


		if (pointer_y <= 130)
			plusorminus = true;
		if (pointer_y > 480)
			plusorminus = false;
	}

}