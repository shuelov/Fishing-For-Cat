#pragma once
#include "Include.h"

Town town;

Town::Town()
{
	show = false;				//bool�� show false�� �ʱ�ȭ : ĳ���� �Ⱥ��̴� ����
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

	town_day.Create("./resource/Img/Map/town_morning.png", false, D3DCOLOR_XRGB(0, 0, 0));	// ���� �� ȭ��


	for (int i = 0; i<99; i++)	// ���� ����
	{
		sprintf_s(FileName, "./resource/img/map/map_extra/town/c%02d.png", i);
		town_cloud[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}


	option.Init();



	cat.Init();
	deal.Init();
	sound.InitEtc();	// ����


}

void Town::Update(double frame)
{
	sound.StopEtc();	// ����
	sound.PlayEtc();	// ����	

	npc.Update();


	option.Update(200);
	


	cat.Update();
	


	//--------------------------------���� �׽�Ʈ�� �ڵ�-------------------------------
	if (KeyDown('Z') && option.pause == false && npc.selling == true)			//����										//z Ű������ ������ 
	{
		//option.tabhold = true;//����

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
				if (once == false)//����
				{
					option.place1 = true;
					once = false;
				}
				KeyTime = GetTickCount();
			}
		}
	}

	if (GetTickCount() - KeyTime > 200)	 // ����
	{
		if (direction == true)
			scene += 1;		// ���� ��� ����
		if (scene >= 99)
			scene = 0;		// ���� ��� ����

							//if (direction == false)
							//	scene -= 1;		// ���� ��� ����
		if (scene <= 0)
			direction = true;
		KeyTime = GetTickCount();
	}
}

void Town::Draw()
{
	town_day.Render(0, 0, 0, 1.6, 2); 
	town_cloud[scene].Render(-65, -24, 0, 1, 1); 

	npc.Draw();	// NPC ���
	option.Draw();															 //�޴�,����Ʈ,���� ��ư ���̱� ����


		cat.Draw();															//����� ������ ���� �� ����̵� ��ư ������ �� �׽�Ʈ�ϱ� ���� ����
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
