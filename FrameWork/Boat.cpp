
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
	x = cat.x - 60 ; // ����� ��ǥ�� ���缭 �� ��ǥ ����
	y = cat.y - 65 +movingboat;
	if (GetTickCount() - KeyTime > 350)   //�ٴٿ� �ִ°�ó�� �谡 �ణ�� ��鸮��
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