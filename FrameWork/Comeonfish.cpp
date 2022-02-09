#pragma once
#include "Include.h"

Comeonfish comeonfish;

Comeonfish::Comeonfish()
{}

Comeonfish::~Comeonfish()
{}

void Comeonfish::Init()
{
	srand((unsigned int)time(NULL));
	//speed =( rand() % 23) + 13;
	speed = 6;
	// ----------게임추가-------------------------
	bar_second.Create("./resource/Img/UI/bar_second.png", false, D3DCOLOR_XRGB(0, 0, 0));
	secondgameframe.Create("./resource/Img/UI/game_back.png", false, D3DCOLOR_XRGB(0, 0, 0));
	game_fish.Create("./resource/Img/UI/game_fish.png", false, D3DCOLOR_XRGB(0, 0, 0));
	fishingline.Create("./resource/Img/UI/game_fishing.png", false, D3DCOLOR_XRGB(0, 0, 0));
	pointer.Create("./resource/Img/UI/pointer.png", false, D3DCOLOR_XRGB(0, 0, 0));
	//-------------------------------------------

	perfect.Create("./resource/Img/UI/perfect.png", false, D3DCOLOR_XRGB(0, 0, 0));
	good.Create("./resource/Img/UI/good.png", false, D3DCOLOR_XRGB(0, 0, 0));
	bad.Create("./resource/Img/UI/bad.png", false, D3DCOLOR_XRGB(0, 0, 0));
	miss.Create("./resource/Img/UI/miss.png", false, D3DCOLOR_XRGB(0, 0, 0));

	pointer_y = 470;// 화살표의 맨처음값, 바의 중간에 맞춰놓음
	fish_x = 900;
}

void Comeonfish::Update()
{
	if (aaa == false)
	{
	
		if (fishing.failfishing == false)
		{
			fish_x++;

			//화살표 왔다갔다 거리게 해주는곳
			if (plusorminus == true)
				pointer_y += speed;
			if (plusorminus == false)
				pointer_y -= speed;
			if (pointer_y <= 295)
				plusorminus = true;
			if (pointer_y > 645)
				plusorminus = false;
			//----------------------------
		}
	}


	if (KeyDown(VK_SPACE) && aaa == false && fishing.failfishing == false)
	{
		// 화살표의 y좌표에 따라 물고기의 위치가 +되거나 - 된다. 여기서 난이도 조절가능.
		if (GetTickCount() - KeyTime > 400)
		{
			if (pointer_y < 350 || pointer_y>630)		// 가장끝자리 -> miss
			{
				fish_x += 80;
				showgrade = true;
				grade = 4; 
			}
			else if (pointer_y < 400 || pointer_y >580) 
			{
				fish_x += 50;
				showgrade = true;
				grade = 3;
			}
			else if (pointer_y < 450 || pointer_y >530)
			{
				fish_x -= 70;
				showgrade = true;
				grade = 2; 

			}
			else										// perfect;
			{
				fish_x -= 140;
				showgrade = true; 
				grade = 1; 
			}

			//----------미끼의 종류에 따라 난이도가 바뀐다.---------------
			if (inventory.usingbaitcode == 12)
				speed = (rand() % 9) + 7;
			if (inventory.usingbaitcode == 13)
				speed = (rand() % 8) + 6;
			if (inventory.usingbaitcode == 14)
				speed = (rand() % 7) + 5;
			if (inventory.usingbaitcode == 0)
				speed = (rand() % 8) + 6;


			KeyTime = GetTickCount();
		}
	}
	if (fish_x > 1200)
	{
		fish_x = fish_x;
		showgrade = false; 
		grade = 0; 
		// ------------낚시실패시 처리해야할것들 들어간드아
		fishing.failfishing = true;
		//------------------------------------------------

	}
	if (fish_x <= 360) 
	{
		if (aaa == false)
		{
			KeyTime = GetTickCount();
			aaa = true;
			if (fish_x <= 360)
				fish_x = 360;
		}
		if (GetTickCount() - KeyTime>2000 && aaa == true)
			aaa1 = true;

	}
	if (aaa1 == true)
	{
		fishing.signalforfish = true;
		fishing.startnewgame = false;
		showgrade = false;  //0209
		grade = 0; //0209
	}

}


void Comeonfish::Draw()
{
	//-----------------새게임 추가---------------------

	secondgameframe.Render(50, 300, 0, 1, 1);
	game_fish.Render(fish_x , 470, 0, 1, 1);
	fishingline.Render(0, 400, 0, 1, 1);
	bar_second.Render(1100, 330, 0, 1, 1);
	pointer.Render(1050, pointer_y, 0, 1, 1);

	//------------------------------------------------

	if (showgrade == true)
	{
		if (grade == 1)
			perfect.Render(500, 300, 0, 1, 1);
		else if (grade == 2)
			good.Render(500, 300, 0, 1, 1);
		else if (grade == 3)
			bad.Render(500, 300, 0, 1, 1);
		else if (grade == 4)
			miss.Render(500, 300, 0, 1, 1);
	}
}