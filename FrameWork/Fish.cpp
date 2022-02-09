
#pragma once
#include "Include.h"

Fish fish;

Fish::Fish()
{
}


Fish::~Fish()
{
}

void Fish::Init()
{

	randomfish_left1.Create("./resource/Img/Fish/randomfish_left.png", false, D3DCOLOR_XRGB(0, 0, 0));
	randomfish_left2.Create("./resource/Img/Fish/randomfish_left.png", false, D3DCOLOR_XRGB(0, 0, 0));
	randomfish_left3.Create("./resource/Img/Fish/randomfish_left.png", false, D3DCOLOR_XRGB(0, 0, 0));
	randomfish_right1.Create("./resource/Img/Fish/randomfish_right.png", false, D3DCOLOR_XRGB(0, 0, 0));
	randomfish_right2.Create("./resource/Img/Fish/randomfish_right.png", false, D3DCOLOR_XRGB(0, 0, 0));
	randomfish_right3.Create("./resource/Img/Fish/randomfish_right.png", false, D3DCOLOR_XRGB(0, 0, 0));
	valley_ston.Create("./resource/Img/Map/valley_ston.png", false, D3DCOLOR_XRGB(0, 0, 0)); // 계곡 돌


	x, x2, x3 = -100;

	i, j = 0;
	srand((unsigned int)time(NULL));

	pos1,pos2, pos3 = 0;

	//cat_story1.Create("./resource/Img/Character/cat_down.png", false, D3DCOLOR_XRGB(0, 0, 0));	// Story에서 웅크린 고양이

}

void Fish::Update()
{

	if (plusorminus == true)   // 화면끝까지 갔을때 물고기의 방향 바꿔줌  물고기1의 움직임
		i += speed;
	if (plusorminus == false)
		i -= speed;   

	if (plusorminus2 == true) //2의 움직임
		j += speed2;
	if (plusorminus2 == false)
		j -= speed2;

	if (plusorminus3 == true ) // 3의 움직임
		k += speed3;
	if (plusorminus3 == false)
		k -= speed3;




	if (map.m_Stage == 1)
	{
		if (i <= 0)   //화면 끝까지 나갔을때 y좌표, 스피드 랜덤으로 변경
		{
			plusorminus = true;
			pos1 = 2;
			y = rand() % 600 + 470;
			speed = rand() % 8 + 1;
		}
		if (i >= 1400)
		{
			pos1 = 1;
			plusorminus = false;
			y = rand() % 600 + 470;
			speed = rand() % 8 + 1;
		}
		if (j <= 0)
		{
			pos2 = 2;
			plusorminus2 = true;
			y2 = rand() % 600 + 470;
			speed2 = rand() % 8 + 1;
		}
		if (j >= 1400)
		{
			pos2 = 1;
			plusorminus2 = false;
			y2 = rand() % 600 + 470;
			speed2 = rand() % 8 + 1;
		}
		if (k <= 0)
		{
			pos3 = 2;
			plusorminus3 = true;
			y3 = rand() % 600 + 470;
			speed3 = rand() % 8 + 1;
		}
		if (k >= 1400)
		{
			pos3 = 1;
			plusorminus3 = false;
			y3 = rand() % 600 + 470;
			speed3 = rand() % 8 + 1;
		}
	}
	if (map.m_Stage == 2)
	{
		if (i <= 0)   //화면 끝까지 나갔을때 y좌표, 스피드 랜덤으로 변경
		{
			plusorminus = true;
			pos1 = 2;
			y = rand() % 600 + 400;
			speed = rand() % 8 + 1;
		}
		if (i >= 1400)
		{
			pos1 = 1;
			plusorminus = false;
			y = rand() % 600 + 400;
			speed = rand() % 8 + 1;
		}
		if (j <= 0)
		{
			pos2 = 2;
			plusorminus2 = true;
			y2 = rand() % 600 + 400;
			speed2 = rand() % 8 + 1;
		}
		if (j >= 1400)
		{
			pos2 = 1;
			plusorminus2 = false;
			y2 = rand() % 600 + 400;
			speed2 = rand() % 8 + 1;
		}
		if (k <= 0)
		{
			pos3 = 2;
			plusorminus3 = true;
			y3 = rand() % 600 + 400;
			speed3 = rand() % 8 + 1;
		}
		if (k >= 1400)
		{
			pos3 = 1;
			plusorminus3 = false;
			y3 = rand() % 600 + 400;
			speed3 = rand() % 8 + 1;
		}
	}
	if (map.m_Stage == 3)
	{
		if (i <= 0)   //화면 끝까지 나갔을때 y좌표, 스피드 랜덤으로 변경
		{
			plusorminus = true;
			pos1 = 2;
			y = rand() % 600 + 320;
			speed = rand() % 8 + 1;
		}
		if (i >= 1400)
		{
			pos1 = 1;
			plusorminus = false;
			y = rand() % 600 + 320;
			speed = rand() % 8 + 1;
		}
		if (j <= 0)
		{
			pos2 = 2;
			plusorminus2 = true;
			y2 = rand() % 600 + 320;
			speed2 = rand() % 8 + 1;
		}
		if (j >= 1400)
		{
			pos2 = 1;
			plusorminus2 = false;
			y2 = rand() % 600 + 320;
			speed2 = rand() % 8 + 1;
		}
		if (k <= 0)
		{
			pos3 = 2;
			plusorminus3 = true;
			y3 = rand() % 600 + 320;
			speed3 = rand() % 8 + 1;
		}
		if (k >= 1400)
		{
			pos3 = 1;
			plusorminus3 = false;
			y3 = rand() % 600 + 320;
			speed3 = rand() % 8 + 1;
		}
	}
	//if (fishing.signalforfish == true&& catchfishloc==false)
	//{
	//	control_x = x3 + k;
	//	control_y = y3;
	//	catchfishloc = true;
	//	pos3 = 3;
	//}


}

void Fish::Draw()
{
	//평소때의 물고기 움직임


	if (pos1==1)
		randomfish_left1.Render(x + i, y, 0, 1, 1);
	if(pos2==1)
		randomfish_left2.Render(x2 + j, y2, 0, 1, 1);
	if(pos3==1)
		randomfish_left3.Render(x3 + k, y3, 0, 1, 1);

	if(pos1==2)
		randomfish_right1.Render(x + i, y, 0, 1, 1);
	if(pos2==2)
		randomfish_right2.Render(x2 + j, y2, 0, 1, 1);
	if(pos3==2)
		randomfish_right3.Render(x3 + k, y3, 0, 1, 1);

	if (map.m_Stage == 1)
		valley_ston.Render(0, 30, 0, 2, 2);

}

