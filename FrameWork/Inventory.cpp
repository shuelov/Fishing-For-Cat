
#pragma once
#include "Include.h"

Inventory inventory;

Inventory::Inventory(void)
{

	stStop = false;
}

Inventory::~Inventory(void)
{

}

void Inventory::Init()
{
	inventory_frame.Create("./resource/Img/UI/deal_itemlist_bag.png", false, D3DCOLOR_XRGB(0, 0, 0));
	item_frame.Create("./resource/Img/UI/deal_itemlist_item.png", false, D3DCOLOR_XRGB(0, 0, 0));
	item_frame2.Create("./resource/Img/UI/deal_itemlist_item.png", false, D3DCOLOR_XRGB(0, 0, 0));
	item_frame3.Create("./resource/Img/UI/deal_itemlist_item.png", false, D3DCOLOR_XRGB(0, 0, 0));
	inventory_page_right.Create("./resource/Img/UI/inventory_page_right.png", false, D3DCOLOR_XRGB(0, 0, 0));
	inventory_page_left.Create("./resource/Img/UI/inventory_page_left.png", false, D3DCOLOR_XRGB(0, 0, 0));

	goback.Create("./resource/Img/UI/goback.png", false, D3DCOLOR_XRGB(0, 0, 0));
	pointer.Create("./resource/Img/UI/pointer.png", false, D3DCOLOR_XRGB(0, 0, 0));
	coin.Create("./resource/Img/UI/coin.png", false, D3DCOLOR_XRGB(0, 0, 0));


	morethanzero = 0;

	frame, nowpage = 0;

	for (i = 0; i < 16;i++)
		codeframe[i] = 0;
	pointer_pos = 1;


	usingfishrodcode = 0;
	usingbaitcode = 0;
}

void Inventory::Update()
{
	PosSetting(1, 415, 110); // �κ��丮 1
	PosSetting(2, 415, 220); // �κ��丮 2
	PosSetting(3, 415, 330); // �κ��丮 3
	PosSetting(4, 415, 430); // ������  -1
	PosSetting(5, 710, 430); // ������ +1
	PosSetting(6, 490, 520); // �ڷ�


		SetRect(&q_rc, 500, 55, 110, 110); // ��
		sprintf_s(str, "%d ", inventory.money);

		
		if (KeyDown(VK_LEFT) && option.checkinventory == true) 
		{
			if (GetTickCount() - KeyTime > 200)
			{
				if (pointer_pos == 1)
					pointer_pos = pointer_pos;
				else
				{
					pointer_pos--;
					sound.m_but->Play(NULL);
				}

				KeyTime = GetTickCount();
			}
		}
		if (KeyDown(VK_RIGHT) && option.checkinventory == true) //
		{
			if (GetTickCount() - KeyTime > 200)
			{
				if (pointer_pos == 6)
					pointer_pos = pointer_pos;
				else
				{
					pointer_pos++;
					sound.m_but->Play(NULL);
				}
					
				KeyTime = GetTickCount();
			}
		}
		if (KeyDown(VK_UP) && option.checkinventory == true)
		{
			if (GetTickCount() - KeyTime > 200)
			{
				if (pointer_pos == 1)
					pointer_pos = pointer_pos;
				else {
					pointer_pos--;
					sound.m_but->Play(NULL);
				}
				KeyTime = GetTickCount();
			}
		}
		if (KeyDown(VK_DOWN) && option.checkinventory == true)
		{
			if (GetTickCount() - KeyTime > 200)
			{
				if (pointer_pos == 4)
					pointer_pos = 6;
				else if (pointer_pos == 6)
					pointer_pos = pointer_pos;
				else if (pointer_pos < 4 && pointer_pos>0)
				{
					pointer_pos++;
					sound.m_but->Play(NULL);
				}
				KeyTime = GetTickCount();
			}
		}

		if (KeyDown(VK_SPACE) && option.checkinventory == true)//�����̽� ������
		{
			if (pointer_pos == 4 ) //������������ �̵�     //����
			{
				if (GetTickCount() - KeyTime > 200)
				{
					if (nowpage >= 1)
					{
						nowpage -= 1;
					}
					KeyTime = GetTickCount();
				}
			}

			if (pointer_pos == 5) //�������������� �̵�
			{
				if (GetTickCount() - KeyTime > 200)
				{
					if (nowpage <= 6)
					{
						nowpage += 1;
					}
					KeyTime = GetTickCount();
				}
			}

			sound.m_confirm->Play(NULL);
			if(pointer_pos == 6) // �ڷ� ������
			{
				
				if (GetTickCount() - KeyTime > 200)
				{ 
					power.KeyTime = GetTickCount();
					stStop = false;
					//------ ������â ������ ó�������� �ʱ�ȭ -------

	 
					morethanzero = 0;
	
					frame, nowpage = 0;
	
					option.tabhold = false;

					option.checkinventory = false;
					
					option.pause = false;

					option.aaa = false;
	
					//-----------------------------------------------
					KeyTime = GetTickCount();
				}
			}

			//-------------������ �������� ���ô��̸� ���˴븦 (�����)���� �ٲ���------------------
			if (GetTickCount() - KeyTime > 200 && option.checkinventory==true)
			{
				for (int i = 0; i < 5; i++)// ������ ����ŭ
				{
					for (int j = 1; j < 4; j++)  // j��° ���ý� 
					{
						if (pointer_pos == j) //j�� ���ý�
						{
							if (nowpage == i)  // ���� �κ��� i��° �������� j��°������ ���ý� ���˴��ΰ� ��ĵ�ؼ� ������ιٲ��ִ°���
							{
								if (codeframe[(3 * i) + j - 1] == 15)
								{
									if (usingfishrodcode == 15)
										usingfishrodcode = 0;
									else if (usingfishrodcode == 16 || usingfishrodcode == 0)
										usingfishrodcode = 15;
								}
								if (codeframe[(3 * i) + j - 1] == 16)
								{
									if (usingfishrodcode == 16)
										usingfishrodcode = 0;
									else if (usingfishrodcode == 15 || usingfishrodcode == 0)
										usingfishrodcode = 16;
								}
								//------ �̳� �ٲ��ִ� ��------------------------------
								if (codeframe[(3 * i) + j - 1] == 12)
								{
									if (usingbaitcode == 12)
										usingbaitcode = 0;
									else if (usingbaitcode == 13 || usingbaitcode == 0||usingbaitcode==14 )
										usingbaitcode = 12;
								}
								if (codeframe[(3 * i) + j - 1] == 13)
								{
									if (usingbaitcode == 13)
										usingbaitcode = 0;
									else if (usingbaitcode == 14 || usingbaitcode == 0 || usingbaitcode == 12)
										usingbaitcode = 13;
								}

								if (codeframe[(3 * i) + j - 1] == 14)
								{
									if (usingbaitcode == 14)
										usingbaitcode = 0;
									else if (usingbaitcode == 12 || usingbaitcode == 0 || usingbaitcode == 13)
										usingbaitcode = 14;
								}
								//-------------------------------------------
							}
						}
					}
				}
				KeyTime = GetTickCount();
			}
			//-------------------------------------------------------------------------------------------------
		
		
		
		}



	


		//--------------------------�κ��丮 �����---------------
		//if (aaa1 == false)
		//{
		//	item.GetItem(2, 3);
		//	item.GetItem(12, 5);
		//	item.GetItem(15, 1);
		//	aaa1 = true;
		//}

		
		//--------------------------------------------------------

		//--------------------------����̰� �����ִ°��� Ȯ�� ---------------
		if (justonetime[0] == false)
		{
			if (item.item_cruciancarp.howmany > 0)
			{
				codeframe[morethanzero] = 1;
				morethanzero += 1;
			}
			justonetime[0] = true;
		}

		if (justonetime[1] == false)
		{
			if (item.item_jang.howmany > 0)
			{
				codeframe[morethanzero] = 2;
				morethanzero += 1;
			}
			justonetime[1] = true;
		}

		if (justonetime[2] == false)
		{
			if (item.item_lobster.howmany > 0)
			{
				codeframe[morethanzero] = 3;
				morethanzero += 1;
			}
			justonetime[2] = true;

		}
		if (justonetime[3] == false)
		{
			if (item.item_bing.howmany > 0)
			{
				codeframe[morethanzero] = 4;
				morethanzero += 1;
			}
			justonetime[3] = true;
		}

		if (justonetime[4] == false)
		{
			if (item.item_frog.howmany > 0)
			{
				codeframe[morethanzero] = 5;
				morethanzero += 1;
			}
			justonetime[4] = true;
		}
		if (justonetime[5] == false)
		{
			if (item.item_ing.howmany > 0)
			{
				codeframe[morethanzero] = 6;
				morethanzero += 1;
			}
			justonetime[5] = true;
		}
		if (justonetime[6] == false)
		{
			if (item.item_octopus.howmany > 0)
			{
				codeframe[morethanzero] = 7;
				morethanzero += 1;
			}
			justonetime[6] = true;
		}
		if (justonetime[7] == false)
		{
			if (item.item_shark.howmany > 0)
			{
				codeframe[morethanzero] = 8;
				morethanzero += 1;
			}
			justonetime[7] = true;
		}
		if (justonetime[8] == false)
		{
			if (item.item_trash.howmany > 0)
			{
				codeframe[morethanzero] = 9;
				morethanzero += 1;
			}
			justonetime[8] = true;
		}
		if (justonetime[9] == false)
		{
			if (item.item_tuna.howmany > 0)
			{
				codeframe[morethanzero] = 10;
				morethanzero += 1;
			}
			justonetime[9] = true;
		}
		if (justonetime[10] == false)
		{
			if (item.item_yeon.howmany > 0)
			{
				codeframe[morethanzero] = 11;
				morethanzero += 1;
			}
			justonetime[10] = true;
		}
		if (justonetime[11] == false)
		{
			if (item.item_bait.howmany > 0)
			{
				codeframe[morethanzero] = 12;
				morethanzero += 1;
			}
			justonetime[11] = true;
		}
		if (justonetime[12] == false)
		{
			if (item.item_ricecake.howmany > 0)
			{
				codeframe[morethanzero] = 13;
				morethanzero += 1;
			}
			justonetime[12] = true;
		}
		if (justonetime[13] == false)
		{
			if (item.item_shirimp.howmany > 0)
			{
				codeframe[morethanzero] = 14;
				morethanzero += 1;
			}
			justonetime[13] = true;
		}
		if (justonetime[14] == false)
		{
			if (item.item_fishingrod.howmany > 0)
			{
				codeframe[morethanzero] = 15;
				morethanzero += 1;
			}
			justonetime[14] = true;
		}
		if (justonetime[15] == false)
		{
			if (item.item_goodfishingrod.howmany > 0)
			{
				codeframe[morethanzero] = 16;
				morethanzero += 1;
			}
			justonetime[15] = true;
		}
		//-------------------����̰� 0���ٸ��̰����ִ¾����ۼ� Ȯ�� ��---------------------
	}




void Inventory::Draw()
{

	inventory_frame.Render(440, 100, 0, 1, 1);
	item_frame.Render(465, 110, 0, 1, 1);
	item_frame2.Render(465, 220, 0, 1, 1);	
	item_frame3.Render(465, 330, 0, 1, 1);
	inventory_page_right.Render(760, 430, 0, 1, 1);
	inventory_page_left.Render(465, 430, 0, 1, 1);

	goback.Render(540, 520, 0, 1, 1);  //�ڷ� Ű
	pointer.Render(pointer_x, pointer_y, 0, 1, 1);
	coin.Render(440, 35, 0, 1, 1);		

	dv_font.Fonts->DrawText(NULL, str, 100, &q_rc, DT_NOCLIP, D3DCOLOR_XRGB(0, 0, 0));

		//--------------------�����ִ� �������� �׸���-------------------------
		if (nowpage == 0)
		{
			item.DrawItem(codeframe[0], 475, 120, 1, 1);
			item.Showname(codeframe[0], 575, 120);
			item.Showhowmany(codeframe[0], 575, 170);
			item.DrawItem(codeframe[1], 475, 230, 1, 1);
			item.Showname(codeframe[1], 575, 230);
			item.Showhowmany(codeframe[1], 575, 280);
			item.DrawItem(codeframe[2], 475, 330, 1, 1);
			item.Showname(codeframe[2], 575, 340);
			item.Showhowmany(codeframe[2], 575, 380);
		}
		if (nowpage == 1)
		{
			item.DrawItem(codeframe[3], 475, 120, 1, 1);
			item.Showname(codeframe[3], 575, 120);
			item.DrawItem(codeframe[4], 475, 230, 1, 1);
			item.Showname(codeframe[4], 575, 230);
			item.DrawItem(codeframe[5], 475, 330, 1, 1);
			item.Showname(codeframe[5], 575, 340);

			item.Showhowmany(codeframe[3], 575, 170);
			item.Showhowmany(codeframe[4], 575, 280);
			item.Showhowmany(codeframe[5], 575, 380);

		}
		if (nowpage == 2)
		{
			item.DrawItem(codeframe[6], 475, 120, 1, 1);
			item.Showname(codeframe[6], 575, 120);
			item.DrawItem(codeframe[7], 475, 230, 1, 1);
			item.Showname(codeframe[7], 575, 230);
			item.DrawItem(codeframe[8], 475, 330, 1, 1);
			item.Showname(codeframe[8], 575, 340);

			item.Showhowmany(codeframe[6], 575, 170);
			item.Showhowmany(codeframe[7], 575, 280);
			item.Showhowmany(codeframe[8], 575, 380);
		}
		if (nowpage == 3)
		{
			item.DrawItem(codeframe[9], 475, 120, 1, 1);
			item.Showname(codeframe[9], 575, 120);
			item.DrawItem(codeframe[10], 475, 230, 1, 1);
			item.Showname(codeframe[10], 575, 230);
			item.DrawItem(codeframe[11], 475, 330, 1, 1);
			item.Showname(codeframe[11], 575, 340);

			item.Showhowmany(codeframe[9], 575, 170);
			item.Showhowmany(codeframe[10], 575, 280);
			item.Showhowmany(codeframe[11], 575, 380);
		}
		if (nowpage == 4)
		{
			item.DrawItem(codeframe[12], 475, 120, 1, 1);
			item.Showname(codeframe[12], 575, 120);
			item.DrawItem(codeframe[13], 475, 230, 1, 1);
			item.Showname(codeframe[13], 575, 230);
			item.DrawItem(codeframe[14], 475, 330, 1, 1);
			item.Showname(codeframe[14], 575, 340);


			item.Showhowmany(codeframe[12], 575, 170);
			item.Showhowmany(codeframe[13], 575, 280);
			item.Showhowmany(codeframe[14], 575, 380);
		}
		if (nowpage == 5)
		{
			item.DrawItem(codeframe[15], 475, 120, 1, 1);
			item.Showname(codeframe[15], 575, 120);
			item.DrawItem(codeframe[16], 475, 230, 1, 1);
			item.Showname(codeframe[16], 575, 230);

			item.Showhowmany(codeframe[15], 575, 170);
			item.Showhowmany(codeframe[16], 575, 280);
		}



		//-----------------�����ִ� ������ �׸��� ��--------------------------
	}


void Inventory::Reset()
{
	for (int i = 0; i < 16; i++)
	{
		morethanzero = 0;
		codeframe[i] = 0;
		justonetime[i] = 0;
	}
}

void Inventory::PosSetting(int _pos, int _x, int _y)
{
	if (pointer_pos == _pos)
	{
		this->pointer_x = _x;
		this->pointer_y = _y;
	}
}