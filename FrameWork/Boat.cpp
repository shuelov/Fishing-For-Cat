
#pragma once
#include "Include.h"

Boat boat;



Boat::Boat(void)
{
	movingboat = 0;
}

Boat::~Boat(void)
{
}

void Boat::Init()
{
	ship.Create("./resource/Img/Boat/ship.png", false, D3DCOLOR_XRGB(0, 0, 0));
	boat.Create("./resource/Img/Boat/boat.png", false, D3DCOLOR_XRGB(0, 0, 0));

}

void Boat::Update()
{
	x = cat.x - 60 ; // 고양이 좌표에 맞춰서 배 좌표 맞춤
	y = cat.y - 65 +movingboat;
	if (GetTickCount() - KeyTime > 350)   //바다에 있는것처럼 배가 약간씩 흔들리게
	{
		if (plusorminus == true)
			movingboat++;
		if (plusorminus == false)
			movingboat--;
		if (movingboat >= 5)
			plusorminus = false;
		if (movingboat <= -5 )
			plusorminus = true;
		KeyTime = GetTickCount();
	}
}



void Boat::Draw()
{
	if(map.m_Stage==3)
		ship.Render(x, y, 0, 1, 1);
	if (map.m_Stage == 2)
		boat.Render(x, y, 0, 1, 1);
}