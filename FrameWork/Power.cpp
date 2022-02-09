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

	if (KeyDown(VK_SPACE) && startpowering == true) //�����̽��� ������� ������ ���� /����
	{
		if (GetTickCount() - KeyTime > 200)
		{

			if (pos == 0)  //�������������� �����̰�
			{
				pos = 1;
			}
			else if (pos == 1)  //�����̴� ���̸� �������� ���߰�  ����ٿ� ȭ��ǥ�� �����
			{
				pos = 0;

				if (pointer_y < 246) // ���⼭ �Ŀ��� ������.
					howmuchpower = 3;
				else if (pointer_y >= 246 && pointer_y < 364)
					howmuchpower = 2;
				else if (pointer_y >= 364)
					howmuchpower = 1;

				if (cat.x <= 576)
					direction = 2; //�Ŀ� ������ �ڸ��� ��ǥ�� ���������� ������ �������� ������ ���Ѵ�
				else if (cat.x > 576)
					direction = 1;


				sound.m_throw->Play(NULL);	// ����
				sound.m_Game->Play(0, DSBPLAY_LOOPING);	// ����

				startfishing = true; // ������ ����
				option.tabhold = true;
				startpowering = false; // �Ŀ����� ��
			}
			KeyTime = GetTickCount();
		}
	}

	Changecal();


	if (KeyDown(VK_SPACE) && startpowering == false && startfishing == false && option.pause==false && option.checkinventory == false&&option.tabhold==false) // �����̽��ٸ� ������ �Ŀ�����ٸ� ���� ���� ������ �ٲ���
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
		if (direction == 1) // �������� ������ ���
		{
			if (howmuchpower == 1) // ������ �׸�
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
		if (direction == 2) // ���������� ������ ���
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





void Power::Changecal()  //ȭ��ǥ�� ��ǥ�� ���ѵ� ��ġ���� �����̰� �ϴ� �Լ�
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