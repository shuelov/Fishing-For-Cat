#pragma once
#include "Include.h"

Map map;

Map::Map()
{
}
Map::Map(int stage)
{

	m_Stage = stage;
	move1 = 0;
	move2 = 0;
	move3 = 0;
	scene1 = 0;
	scene2 = 0;
	turn1 = 1;
	turn2 = 1;
}

Map::~Map()
{
}

void Map::Init()
{
	choose = true;
	int i, j;
	char FileName[256];
	valley.Create("./resource/Img/Map/valley.png", false, D3DCOLOR_XRGB(0, 0, 0)); // ��� ���
	lake.Create("./resource/Img/Map/lake.png", false, D3DCOLOR_XRGB(0, 0, 0)); // ȣ�� ���
	sea.Create("./resource/Img/Map/sea.png", false, D3DCOLOR_XRGB(0, 0, 0)); // �ٴ� ���

	valley_floor.Create("./resource/Img/Map/map_extra/valley/valley_floor.png", false, D3DCOLOR_XRGB(0, 0, 0)); // ��� �ٴ�
	valley_drop.Create("./resource/Img/Map/map_extra/valley/drop.png", false, D3DCOLOR_XRGB(0, 0, 0)); // ��� �����

	lake_floor.Create("./resource/Img/Map/map_extra/lake/lake_floor.png", false, D3DCOLOR_XRGB(0, 0, 0)); // ȣ�� �ٴ�
	lake_wave.Create("./resource/Img/Map/map_extra/lake/wave.png", false, D3DCOLOR_XRGB(0, 0, 0)); // ȣ�� ����

	for (int i = 0; i<2; i++)	// ȣ�� �����1
	{
		sprintf_s(FileName, "./resource/Img/Map/map_extra/lake/fish1_%02d.png", i);
		lake_fish1[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}

	for (int i = 0; i<2; i++)	// ȣ�� �����2
	{
		sprintf_s(FileName, "./resource/Img/Map/map_extra/lake/fish2_%02d.png", i);
		lake_fish2[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}

	lake_fish3.Create("./resource/Img/Map/map_extra/lake/fish3.png", false, D3DCOLOR_XRGB(0, 0, 0)); // ȣ�� �����3

	sea_floor.Create("./resource/Img/Map/map_extra/sea/sea_floor.png", false, D3DCOLOR_XRGB(0, 0, 0)); // �ٴ� �ٴ�

	sea_sora1.Create("./resource/Img/Map/map_extra/sea/sora.png", false, D3DCOLOR_XRGB(0, 0, 0)); // �ٴ� �Ҷ�1
	sea_sora2.Create("./resource/Img/Map/map_extra/sea/sora.png", false, D3DCOLOR_XRGB(0, 0, 0)); // �ٴټҶ�2

	sea_turtle1.Create("./resource/Img/Map/map_extra/sea/turtle.png", false, D3DCOLOR_XRGB(0, 0, 0)); // �ٴ� �ź���1
	sea_turtle2.Create("./resource/Img/Map/map_extra/sea/turtle.png", false, D3DCOLOR_XRGB(0, 0, 0)); // �ٴ� �ź���2

	beach_goback.Create("./resource/Img/UI/gobacktotown.png", false, D3DCOLOR_XRGB(0, 0, 0));		//������ ���ư��� ��ư//����

}

void Map::Update(double frame)
{

	if (m_Stage == 1)
	{
		if (GetTickCount() - KeyTime > 100)
		{
			if (direction1 == true)
				move1 -= 1;		// ����� ���� �̵�
			if (move1 <= -80)
				direction1 = false;

			if (direction1 == false)
				move1 += 1;		// ����� ���� �̵�;
			if (move1 >= 100)
				direction1 = true;
			KeyTime = GetTickCount();
		}
	}

	if (m_Stage == 2)
	{
		if (GetTickCount() - KeyTime > 5)
		{
			// ���� �̵� (��<->��)
			if (direction1 == true)
				move1 -= 1;
			if (move1 <= -80)
				direction1 = false;

			if (direction1 == false)
				move1 += 1;
			if (move1 >= 80)
				direction1 = true;

			// ����� 1 ������ (��<->�� / �̹��� �� �ݺ� / ȭ�� ������ �¿� ����)
			if (direction2 == true)
				move2 -= 2;
			if (move2 <= -550)
			{
				direction2 = false;
				turn1 = -1;
			}

			if (direction2 == false)
				move2 += 2;
			if (move2 >= 850)
			{
				direction2 = true;
				turn1 = +1;
			}

			//if (scene1 < -1)
			//	scene1 += 1;
			//if (scene1 < 2)
			//	scene1 -= 1;

			// ����� 2 ������ (��<->�� / �̹��� �� �ݺ� / ȭ�� ������ �¿� ����)
			if (direction3 == true)
				move3 -= 2;
			if (move3 <= -80)
			{
				direction3 = false;
				turn2 = -1;
			}

			if (direction3 == false)
				move3 += 2;
			if (move3 >= 1320)
			{
				direction3 = true;
				turn2 = +1;
			}

			// ����� 3 ������ (��<->�� / �̹��� �� �ݺ� / ȭ�� ������ �¿� ����)
			if (direction4 == true)
				move4 -= 2;
			if (move4 <= -1260)
			{
				direction4 = false;
				turn3 = -1;
			}

			if (direction4 == false)
				move4 += 2;
			if (move4 >= 50)
			{
				direction4 = true;
				turn3 = +1;
			}
			KeyTime = GetTickCount();
		}
	}

	if (m_Stage == 3)
	{
		if (GetTickCount() - KeyTime > 5)
		{
			// �Ҷ� ������ (��<->��)
			if (direction1 == true)
				move1 += 0.1;
			if (move1 >= 5)
				direction1 = false;

			if (direction1 == false)
				move1 -= 0.1;
			if (move1 <= 0)
				direction1 = true;

			// �ź��� 1 ������ (��<->�� / ȭ�� ������ �¿� ����)
			if (direction2 == true)
				move2 += 2;
			if (move2 >= 1350)
			{
				direction2 = false;
				turn1 = -1;
			}

			if (direction2 == false)
				move2 -= 2;
			if (move2 <= 0)
			{
				direction2 = true;
				turn1 = +1;
			}

			// �ź��� 2 ������ (��<->�� / ȭ�� ������ �¿� ����)
			if (direction3 == true)
				move3 -= 2;

			if (move3 <= -1350)
			{
				direction3 = false;
				turn2 = -1;
			}

			if (direction3 == false)
				move3 += 2;
			if (move3 >= 0)
			{
				direction3 = true;
				turn2 = +1;
			}
			KeyTime = GetTickCount();
		}
	}


	else if (sel % 4 == 2)
	{
		if (GetTickCount() - KeyTime > 200)
		{
			/*check = !check;*/
			KeyTime = GetTickCount();
			//�ڷΰ���
			transfer = false;
			sel = 0;
		}
	}


	if (KeyDown(VK_DOWN))
	{
		if (GetTickCount() - KeyTime > 200)
		{
			sel++;
			KeyTime = GetTickCount();
		}

	}

	if (KeyDown(VK_UP))
	{
		if (GetTickCount() - KeyTime > 200)
		{
			sel--;
			KeyTime = GetTickCount();
		}

	}


}

void Map::Update()
{
}
void Map::Draw()
{


	if (m_Stage == 1)
	{
		valley.Render(0, 0, 0, 2, 2.1);

		valley_drop.Render(100 + move1, 50, 0, 1, 1);
		valley_floor.Render(150, 0, 0, 0.9, 1);
		beach_goback.Render(0, 0, 0, 1, 1);

		cat.x = 300; cat.y = 300;
		if (changemap1 == false)   // ���� ����� ó�� ����̰� ���� ��ġ ����.
		{

			changemap1 = true;
			changemap2 = false;
			changemap3 = false;
		}
	}

	else if(m_Stage==2)
	{
		lake.Render(0, 0, 0, 2, 2.1);
		lake_floor.Render(0, 0, 0, 1, 1);
		lake_wave.Render(-10 + move1, 0, 0, 1, 1);
		lake_fish1[scene1].Render(500 + move2, 500, 0, 1 * turn1, 1);
		lake_fish2[scene2].Render(100 + move3, 580, 0, 1 * turn2, 1);
		lake_fish3.Render(1250 + move4, 680, 0, 1 * turn3, 1);
		beach_goback.Render(0, 0, 0, 1, 1);//����
		if (changemap2 == false)   // ���� ����� ó�� ����̰� ���� ��ġ ����.
		{
			cat.resetlake = true;
			//cat.x = 640; cat.y = 300;
			changemap1 = false; 
			changemap2 = true;
			changemap3 = false;
		}
	}
	else if (m_Stage == 3)
	{

		if (changemap3 == false)
		{
			cat.resetsea = true;
			//cat.x = 640; cat.y = 200;
			changemap1 = false;
			changemap2 = false;
			changemap3 = true;
		}

		sea.Render(0, 0, 0, 1.5, 2);
		sea_turtle1.Render(-10 + move2, 400, 0, 0.7 * turn1, 0.7);
		sea_turtle2.Render(1300 + move3, 600, 0, -0.7 * turn2, 0.7);

		sea_floor.Render(0, 0, 0, 1, 1);

		sea_sora1.Render(620 + move1, 705, 0, 0.8, 0.8);
		sea_sora2.Render(920 + move1, 695, 0, 1, 1);
		beach_goback.Render(0, 0, 0, 1, 1);//����
	}

	


}
