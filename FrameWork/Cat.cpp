#pragma once
#include "Include.h"

Cat cat;

Cat::Cat(void)
{
	direction = true;
}


Cat::~Cat(void)
{

}

void Cat::Init()
{
	pos = 1;
	char FileName[256];


	cat_front.Create("./resource/Img/Character/catfront.png", false, D3DCOLOR_XRGB(0, 0, 0));
	//cat_right.Create("./resource/Img/Character/catright.png", false, D3DCOLOR_XRGB(0, 0, 0));
	fishing_cat.Create("./resource/Img/Character/fishing_cat.png", false, D3DCOLOR_XRGB(0, 0, 0));

	for (int i = 0; i<3; i++)  
	{
		sprintf_s(FileName, "./resource/Img/Character/catright%02d.png", i);
		cat_right[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}

	for (int i = 0; i<3; i++)   
	{
		sprintf_s(FileName, "./resource/Img/Character/catleft%02d.png", i);
		cat_left[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}


	for (int i = 0; i<2; i++)
	{
		sprintf_s(FileName, "./resource/Img/Character/cat_down%02d.png", i);
		cat_story2[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
}
void Cat::Update()
{
	if (reset == true)
	{
		x = 640, y = 550; // ���������� ��ġ
		reset = false;
	}

	if (resetlake == true)//ȣ������ ����� ��ġ ����
	{
		x = 640, y = 300;
		resetlake = false;
	}

	if (resetsea == true)		//�ٴٿ��� ����� ��ġ ����
	{
		x = 640, y = 200;
		resetsea = false;
	}

	if (x >= 1100)	//������ ���� �� ���, ȣ��, �ٴ� ��ư ���� �� �� �ְ� ȭ�� ���� //////////////////
	{
		aboard = true;
	}
	if (x < 1100)	//������ ���� �� ���, ȣ��, �ٴ� ��ư ���� �� �� �ְ� ȭ�� ���� //////////////////
	{
		aboard = false;
	}


	if (option.stopthecat == false)
	{
		if (KeyDown(VK_LEFT) && power.startpowering == false && power.startfishing == false) // ����Ű�� �������� ������ �����߿� �������̰�!
		{
			pos = 2; //����ٲ�
			if (GetTickCount() - KeyTime1 > 20)
			{
				if (x <= 0)
				{
					x = x;
					m_cat.dx = x;
				}
				else if (Gmanager.m_GameStart == true || Gmanager.m_GameStart == false)
				{
					x -= 5;
					m_cat.dx = x;
				}
				KeyTime1 = GetTickCount();
			}

			if (GetTickCount() - KeyTime2 > 100)	
			{
				if (leftcount <= 0)
					direction = true;

				if (direction == true)
				{
					leftcount += 1;
				}

				if (leftcount >= 3)
					direction = false;

				if (direction == false)
				{
					leftcount -= 1;
				}
				KeyTime2 = GetTickCount();
			}

		}


		if (KeyDown(VK_RIGHT) && power.startpowering == false && power.startfishing == false) //������Ű �������� ������ �����߿� �������̱��

		{
			pos = 3; //���� �ٲ�
			if (GetTickCount() - KeyTime1 > 20) // �̺κ����� ����� ���ǵ�ٲܼ����� 
			{
				if (cat.x >= 1152)
				{
					x = x;
					m_cat.dx = x;
				}
				else if (Gmanager.m_GameStart == true || Gmanager.m_GameStart == false)
				{
					x += 5;
					m_cat.dx = x;
				}
				KeyTime1 = GetTickCount();
			}

			if (GetTickCount() - KeyTime2 > 100)	//0208
			{
				if (rightcount <= 0)
					direction = true;

				if (direction == true)
				{
					rightcount += 1;
				}

				if (rightcount >= 3)
					direction = false;

				if (direction == false)
				{
					rightcount -= 1;
				}
				KeyTime2 = GetTickCount();
			}
		}
	}
	
	if (power.startfishing == true)
	{
		pos = 4;
	}


}

void Cat::UpdateStory2()	// story 2 ���� �����
{
	if (GetTickCount() - KeyTime1 > 350)
	{
		if (direction == true)
		{
			story2_aniCount += 1;
		}
		if (story2_aniCount >= 2)
			direction = false;

		if (direction == false)
		{
			story2_aniCount -= 1;
		}
		if (story2_aniCount <= 0)
			direction = true;

		KeyTime1 = GetTickCount();
	}
}


void Cat::Draw()
{
	if (Gmanager.m_GameStart == true && pos == 1 || Gmanager.m_GameStart == false && pos == 1) // ���1�϶� �׸��� ȭ�� //////////////////
		cat_front.Render(x, y, 0, 1, 1);

	else if (Gmanager.m_GameStart == true && pos == 2 || Gmanager.m_GameStart == false && pos == 2) //��� �����϶� //////////////////
	{
		cat_left[leftcount].Render(x, y, 0, 1, 1);	

		if (GetTickCount() - KeyTime1 > 350)  //��� �ٽ� 1�ε��ƿü��ְ� �ð��� �е� pos �� 1�� �ٲ���
		{
			if (Gmanager.m_GameStart == true || Gmanager.m_GameStart == false) //////////////////
			{
				pos = 1;
			}
			KeyTime1 = GetTickCount();
		}
	}
	else if (Gmanager.m_GameStart == true && pos == 3 || Gmanager.m_GameStart == false && pos == 3) //��� �������϶� //////////////////
	{
		cat_right[rightcount].Render(x, y, 0, 1, 1);

		if (GetTickCount() - KeyTime1 > 350)  //��� �ٽ� 1�ε��ƿü��ְ� �ð��� �е� pos �� 1�� �ٲ���
		{
			if (Gmanager.m_GameStart == true || Gmanager.m_GameStart == false) //////////////////
			{
				pos = 1;
			}
			KeyTime1 = GetTickCount();
		}
	}

	else if (Gmanager.m_GameStart == true && pos == 4)
	{
		fishing_cat.Render(x, y, 0, 1, 1);
	}


	if (g_Mng.n_Chap == STORY)   // Story���� ��µǴ� ����� �ȴ� �̹���
	{
		if (Gmanager.m_GameStart == true && pos == 1) // ���1�϶� �׸��� ȭ��
			cat_front.Render(x, y, 0, 1, 1);

		else if (Gmanager.m_GameStart == true && pos == 2) //��� �����϶�
		{

		}
		else if (Gmanager.m_GameStart == true && pos == 3) //��� �������϶�
		{

		}
	}



}

void Cat::DrawStory2()	// m_Story 2 ���� ������ ��ũ�� ����� ���
{
	{
		cat_story2[story2_aniCount].Render(600, 570, 0, 1, 1);
	}
}
