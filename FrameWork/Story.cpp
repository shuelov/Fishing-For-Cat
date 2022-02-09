#pragma once

#include "Include.h"


Story::Story()
{
	soundcount = true;
	m_Story = 0;

	speed = 400;
	alpha = 0;

	speed2 = 400;
	alpha2 = 0;

	textcount1 = 0;
	textcount2 = 1;	// ����

	story3_aniCount = 0;

	// story 3 ���� ����� ��ġ,����,ũ��
	x1 = 180;
	y1 = 375;
	radion1 = 0;
	sx1 = 1;
	sy1 = 1;
	//x1 = 315;
	//y1 = 350;
	//radion1 = 0;
	//sx1 = 0.9;
	//sy1 = 0.9;

	// story 3 ���� �Ķ����� ��ġ,����,ũ��
	x2 = 290;
	y2 = 350;
	radion2 = 5;
	sx2 = 0;
	sy2 = 0.4;

	direction = true; // ����
	sx3 = 0;			// ����
}

Story::~Story()
{
}

void Story::Init()	// ����
{
	loding.Create("./resource/Img/Map/loading.png", false, D3DCOLOR_XRGB(0, 0, 0));	// �ε� �̹���
	prologue.Create("./resource/Img/Map/prologue.png", false, D3DCOLOR_XRGB(0, 0, 0));	// "�븣����..." �̹���
	town_night.Create("./resource/Img/Map/town_night.png", false, D3DCOLOR_XRGB(0, 0, 0));	// ���� �� �̹���
	town_fishshop.Create("./resource/Img/Map/fishshop.png", false, D3DCOLOR_XRGB(0, 0, 0));	// �������� �̹���

	char FileName[256];

	for (int i = 0; i<8; i++)	// �ؽ�Ʈ �ڽ�+����	// ����
	{
		sprintf_s(FileName, "./resource/Img/UI/story/story%02d.png", i);
		textbox[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}

	for (int k = 0; k<3; k++)
	{
		sprintf_s(FileName, "./resource/Img/Character/cat_story%02d.png", k);
		cat_story3[k].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}

	fan.Create("./resource/Img/effect/fan.png", false, D3DCOLOR_XRGB(0, 0, 0));	// �Ķ����� �̹���
	fan_effect.Create("./resource/Img/effect/fan_effect.png", false, D3DCOLOR_XRGB(0, 0, 0));	// �Ķ����� Ÿ�� ȿ�� // ����
	sound.InitEtc();	// ����
}

void Story::Update(double frame)
{
	sound.StopEtc();	// ����
	sound.PlayEtc();	// ����

	if (m_Story == 0)
	{
		alpha += speed * frame / 200;

		if (alpha >= 255)
		{
			alpha = 255;
			speed = -speed;
		}
		else if (alpha <= 0) {
			m_Story = 1;	// �ε� �̹������� ���� ȭ������ �̵�
		}
	}

	else if (m_Story == 1)
	{
		alpha2 += speed2 * frame / 200;

		if (alpha2 >= 255)
		{
			alpha2 = 255;
			speed2 = -speed2;
		}
		else if (alpha2 <= 0)
		{
			//if (soundcount == false)
			//{
			//	KeyTime1 = GetTickCount();
			//	soundcount = true;
			//	
			//}
			m_Story = 2;	// ���ѷα� �̹������� ���� ȭ������ �̵�
		}
	}


	else if (m_Story == 2)
	{
		if (soundcount == true)	// ����
		{
			sound.m_hungry->Play(NULL);
			soundcount = false;
		}

		cat.UpdateStory2();
		sound.m_wind->Play(0, DSBPLAY_LOOPING);	// ����


		if (KeyDown(VK_RETURN))
		{
			if (GetTickCount() - KeyTime > 100)
			{
				textcount1 += 1;		// textbox[] ī��Ʈ ����

				if (textcount1 == 1)
				{
					sound.m_wind->Stop();	// ����
					m_Story = 3;	// ��ȭ �Ϸ� �� ���� ���丮�� �̵�
				}
				KeyTime = GetTickCount();
			}
		}
	}

	else if (m_Story == 3) // ����
	{
		sound.m_fishshop->Play(0, DSBPLAY_LOOPING);	// ����

		if (GetTickCount() - KeyTime > 190)
		{
			// ����� �밢������ �̵�
			if (x1 <= 315)
			{
				x1 += 7.5;
				y1 -= 1.5;
				sx1 -= 0.007;
				sy1 -= 0.007;

				if (direction == true)
					story3_aniCount += 1;

				if (story3_aniCount >= 3)
					direction = false;

				if (direction == false)
					story3_aniCount -= 1;

				if (story3_aniCount <= 0)
					direction = true;
			}

			if (x1 == 315)
				sx2 += 0.4;	// ����� ������ ���� �� �Ķ����� ���

							// �Ķ����� ������1
			if (sx2 > 0)
			{
				if (x2 < 313)
				{
					x2 += 0.23;
					y2 += 0.08;
					radion2 += 0.008;
					sx2 += 0.006;
					sy2 += 0.006;
					if (soundcount == false)	// ����
					{
						sound.m_fan->Play(NULL);
						soundcount = true;
					}
					return;
				}

				// ����� Ÿ�� �� Ÿ�� ȿ�� ���
				if (x2 > 313)
				{
					sx3 = 1.5;
				}

			}
			if (sx3 > 0)
			{
				// �Ķ����� ������2
				if (x2 < 313)
				{
					x2 += 0.23;
					y2 += 0.08;
					radion2 += 0.008;
					sx2 += 0.006;
					sy2 += 0.006;
					return;
				}

				if (x2 == 313)
				{
					sx3 += 1.5;
					return;
				}

				if (x2 < 365)
				{
					x2 += 0.8;
					y2 -= 0.5;
					radion2 += 0.004;
					return;
				}
				if (x2 < 380)
				{
					x2 += 0.7;
					radion2 += 0.006;
					return;
				}
				if (x2 < 460)
				{
					x2 += 0.6;
					y2 += 0.48;
					radion2 += 0.003;
					enter = true;
					return;
				}
			}

			KeyTime = GetTickCount();
		}
		if (KeyDown(VK_RETURN)&& enter == true)
		{
			if (GetTickCount() - KeyTime1 > 150)
				textcount2 += 1;		// textbox[] ī��Ʈ ����

				if (textcount2 == 8)	// textbox[] 8�̸� TOWN ���� �̵� 	// ����
				{
					sound.m_fishshop->Stop();	// ����
					g_Mng.n_Chap = TOWN;	// ��ȭ �Ϸ� �� TOWN���� �̵�
				}
				KeyTime1 = GetTickCount();
				
		}
	}
}

void Story::Draw()
{
	if (m_Story == 0)
	{
		loding.Render(0, 0, 0, 2, 2);
	}

	if (m_Story == 1)
	{
		prologue.Render(0, 0, 0, 1, 1);
	}

	if (m_Story == 2)
	{
		town_night.Render(0, 0, 0, 1.6, 2);	// ����
		cat.DrawStory2();
		textbox[textcount1].Render(300, -200, 0, 0.6, 0.6);		// ����
	}

	if (m_Story == 3)
	{
		town_fishshop.Render(0, 0, 0, 2, 2);
		cat_story3[story3_aniCount].Render(x1, y1, radion1, sx1, sy1);
		fan_effect.Render(340, 370, -40, sx3, 1.5);	
		fan.Render(x2, y2, radion2, sx2, sy2);
		textbox[textcount2].Render(0, 0, 0, 1, 1);
	}

}

void Story::OnMessage(MSG* msg)
{

}