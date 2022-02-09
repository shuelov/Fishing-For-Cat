#pragma once
#include "Include.h"

Deal deal;

Deal::Deal()
{
	soundcount = true;

}

Deal::~Deal()
{}

void Deal::Init()
{
	dealer.Create("./resource/Img/UI/deal_owner.png", false, D3DCOLOR_XRGB(0, 0, 0));
	dealers_bag.Create("./resource/Img/UI/deal_itemlist_bag.png", false, D3DCOLOR_XRGB(0, 0, 0));
	dealers_itemframe1.Create("./resource/Img/UI/deal_itemlist_item.png", false, D3DCOLOR_XRGB(0, 0, 0));
	dealers_itemframe2.Create("./resource/Img/UI/deal_itemlist_item.png", false, D3DCOLOR_XRGB(0, 0, 0));
	dealers_itemframe3.Create("./resource/Img/UI/deal_itemlist_item.png", false, D3DCOLOR_XRGB(0, 0, 0));
	dealers_left.Create("./resource/Img/UI/inventory_page_left.png", false, D3DCOLOR_XRGB(0, 0, 0));
	dealers_right.Create("./resource/Img/UI/inventory_page_right.png", false, D3DCOLOR_XRGB(0, 0, 0));


	bag.Create("./resource/Img/UI/deal_bag.png", false, D3DCOLOR_XRGB(0, 0, 0));
	mybag.Create("./resource/Img/UI/deal_itemlist_bag.png", false, D3DCOLOR_XRGB(0, 0, 0));
	myitemframe1.Create("./resource/Img/UI/deal_itemlist_item.png", false, D3DCOLOR_XRGB(0, 0, 0));
	myitemframe2.Create("./resource/Img/UI/deal_itemlist_item.png", false, D3DCOLOR_XRGB(0, 0, 0));
	myitemframe3.Create("./resource/Img/UI/deal_itemlist_item.png", false, D3DCOLOR_XRGB(0, 0, 0));
	myleft.Create("./resource/Img/UI/inventory_page_left.png", false, D3DCOLOR_XRGB(0, 0, 0));
	myright.Create("./resource/Img/UI/inventory_page_right.png", false, D3DCOLOR_XRGB(0, 0, 0));

	purchase.Create("./resource/Img/UI/deal_purchase.png", false, D3DCOLOR_XRGB(0, 0, 0));
	sell.Create("./resource/Img/UI/deal_sell.png", false, D3DCOLOR_XRGB(0, 0, 0));
	cancle.Create("./resource/Img/UI/menu_cancle.png", false, D3DCOLOR_XRGB(0, 0, 0));

	pointer.Create("./resource/Img/UI/pointer.png", false, D3DCOLOR_XRGB(0, 0, 0));
	
	askrealsell.Create("./resource/Img/UI/deal_itemlist_bag.png", false, D3DCOLOR_XRGB(0, 0, 0));
	askrealbuy.Create("./resource/Img/UI/deal_itemlist_bag.png", false, D3DCOLOR_XRGB(0, 0, 0));
	okay.Create("./resource/Img/UI/menu_confirm.png", false, D3DCOLOR_XRGB(0, 0, 0));
	cancle.Create("./resource/Img/UI/menu_cancle.png", false, D3DCOLOR_XRGB(0, 0, 0));

	money.Create("./resource/Img/UI/coin.png", false, D3DCOLOR_XRGB(0, 0, 0));

	deal_confirm.Create("./resource/Img/UI/deal_confirm.png", false, D3DCOLOR_XRGB(0, 0, 0));
	deal_cancel.Create("./resource/Img/UI/deal_cancel.png", false, D3DCOLOR_XRGB(0, 0, 0));
	deal_problem.Create("./resource/Img/UI/deal_problem.png", false, D3DCOLOR_XRGB(0, 0, 0));

	pointer_pos = 0;
	
}

void Deal::Update()
{
	PosSetting(0, 70, 185);  //���� ����.�������� ��ġ������ ��� ���� //����������ĭ1��
	PosSetting(1, 70, 295);  // ���� ������ĭ2��
	PosSetting(2, 70, 405);  // ���� ������ĭ3��
	PosSetting(3, 70, 480); // ���� ������ �ڷ�
	PosSetting(4, 380, 480); // ���� ������ ������
	//----------------------------------------------------
	PosSetting(5, 750, 185); // �� ���� ������ĭ 1��
	PosSetting(6, 750, 295); // �� ���� ������ĭ 2��
	PosSetting(7, 750, 405); //  �� ���� ������ĭ 3��
 	PosSetting(8, 750, 480); // �� ���� ������ �ڷ�
	PosSetting(9, 1060, 480); // �� ���� ������ ������
	PosSetting(10, 490, 650); // �� ���� ������ �ڷ�
	//-----------------------------------------------------
	PosSetting(20, 490, 350); // ��¥ ����?/ �Ǹ�? Ȯ��
	PosSetting(21, 490, 450); // ��¥ ����? / �Ǹ�? ��� 



	//-----------------Ű �������� �������� ��ġ ����-------------------
	if (reallybuy == false&&reallysell==false)
		pointer_pos = pointer_pos % 11;

	if (pointer_pos < 0) // �����Ͱ� 0���Ϸ� �������� 10������ �ٽð��� 
		pointer_pos = 10;
	if (pointer_pos >= 0 && pointer_pos <= 2)// 0,1,2�� �����Ͱ������� �翷Ű�� ��Ʈ��
	{
		if (KeyDown(VK_RIGHT))
		{
			if (GetTickCount() - KeyTime > 200)
			{
				sound.m_but->Play(NULL);
				pointer_pos+=5;
				KeyTime = GetTickCount();
			}
		}
		if (KeyDown(VK_LEFT))
		{
			if (GetTickCount() - KeyTime > 200)
			{
				sound.m_but->Play(NULL);
				pointer_pos += 5;
				KeyTime = GetTickCount();
			}
		}
	}

	if (pointer_pos >= 5 && pointer_pos <= 7) //5,6,7����������  �翷Ű�� �����ϰ�
	{
		if (KeyDown(VK_LEFT))
		{
			if (GetTickCount() - KeyTime > 200)
			{
				sound.m_but->Play(NULL);
				pointer_pos -= 5;
				KeyTime = GetTickCount();
			}
		}
		if (KeyDown(VK_RIGHT))
		{
			if (GetTickCount() - KeyTime > 200)
			{
				sound.m_but->Play(NULL);
				pointer_pos-=5;
				KeyTime = GetTickCount();
			}
		}
	}
	if (pointer_pos==3 || pointer_pos==8) // ������ �ѱ���� ���� �����ʿ���Ű 
	{
		if (KeyDown(VK_RIGHT))
		{
			if (GetTickCount() - KeyTime > 200)
			{
				sound.m_but->Play(NULL);
				pointer_pos++;
				KeyTime = GetTickCount();
			}
		}
	}
	if (pointer_pos == 4 || pointer_pos==9)// ������ �ѱ��Ű���� �����ʿ���Ű 
	{
		if (KeyDown(VK_LEFT))
		{
			if (GetTickCount() - KeyTime > 200)
			{
				sound.m_but->Play(NULL);
				pointer_pos--;
				KeyTime = GetTickCount();
			}
		}
	}
	if (pointer_pos == 4)// ������ �ѱ��Ű���� �����ʿ���Ű 
	{
		if (KeyDown(VK_RIGHT))
		{
			if (GetTickCount() - KeyTime > 200)
			{
				sound.m_but->Play(NULL); 
				pointer_pos=8;
				KeyTime = GetTickCount();
			}
		}
	}
	if (pointer_pos == 8)// ������ �ѱ��Ű���� �����ʿ���Ű 
	{
		if (KeyDown(VK_LEFT))
		{
			if (GetTickCount() - KeyTime > 200)
			{
				sound.m_but->Play(NULL);
				pointer_pos = 4;
				KeyTime = GetTickCount();
			}
		}
	}

	if (KeyDown(VK_DOWN))
	{
		if (GetTickCount() - KeyTime > 200)
		{
			pointer_pos++;
			sound.m_but->Play(NULL);
			KeyTime = GetTickCount();
		}
	}

	if (KeyDown(VK_UP))
	{
		if (GetTickCount() - KeyTime > 200)
		{
			pointer_pos--;
			sound.m_but->Play(NULL);
			KeyTime = GetTickCount();
		}
	}
	
	//--------------------------------------------------------------------


	//���� �� spaceŰ ����
	if (KeyDown(VK_SPACE))
	{
		sound.m_confirm->Play(NULL);
		if (pointer_pos == 0 || pointer_pos==1 || pointer_pos==2)  // ����
		{
			if (GetTickCount() - KeyTime > 200)
			{
				if (savepointer == false)
				{
					temp = pointer_pos;
					savepointer = true;
				}
				reallybuy = true;
				KeyTime = GetTickCount();

			}
		}
		if (pointer_pos == 3) // ���� ������ ���ʳѱ��
		{
			if (GetTickCount() - KeyTime > 200)
			{
				if (dealer_page >= 1)
					dealer_page -= 1;
				else
					dealer_page = dealer_page;
				KeyTime = GetTickCount();
			}
		}
		if (pointer_pos == 4) // ���� ������ �����ʳѱ�� 
		{
			if (GetTickCount() - KeyTime > 200)
			{
				if (dealer_page < 1)
					dealer_page += 1;
				else
					dealer_page = dealer_page;
				KeyTime = GetTickCount();
			}
		}

		if (pointer_pos == 5 || pointer_pos == 6 || pointer_pos == 7)   //�Ǹ� 
		{
			if (GetTickCount() - KeyTime > 200)
			{
				if (savepointer == false)
				{
					temp = pointer_pos;
					savepointer = true;

					for (int i = 0; i < 6; i++)
					{
						if (temp == 5 && my_page == i)
						{
							numberofproduct = inventory.codeframe[0 + (i * 3)];

						}
						if (temp == 6 && my_page == i)
						{
							numberofproduct = inventory.codeframe[1 + (i * 3)];


						}
						if (temp == 7 && my_page == i)
						{
							numberofproduct = inventory.codeframe[2 + (i * 3)];

						}
					}
					reallysell = true;
					if (numberofproduct == 0) // �ƹ��͵� ���� ��ĭ �� ���
					{
						Reset();
					}
				}
			
				KeyTime = GetTickCount();

			}
		}

		if (pointer_pos == 8) // �� ������ ���ʳѱ��
		{
			if (GetTickCount() - KeyTime > 200)
			{
				if (my_page >0)
					my_page -= 1;
				else
					my_page = my_page;
				KeyTime = GetTickCount();
			}
		}  
		if (pointer_pos == 9) // �� ������ �����ʳѱ�� 
		{
			if (GetTickCount() - KeyTime > 200)
			{
				if (my_page < 6)
					my_page += 1;
				else
					dealer_page = dealer_page;
				KeyTime = GetTickCount();
			}
		}




		if (pointer_pos == 20) // ������ž�? ���� ��ٸ� ������ ��� or�Ǵٸ� ������ ��� 
		{
			if (reallybuy == true)
			{
				if (temp == 0 && dealer_page == 0) //��������ġ�� �������� ������ ������ Ȯ���Ѵ�.����� 12�� ������
				{
					priceofproduct = item.item_bait.buy_price;
					numberofproduct = item.item_bait.code;

				}
				if (temp == 1 && dealer_page == 0)
				{
					priceofproduct = item.item_ricecake.buy_price;
					numberofproduct = item.item_ricecake.code;

				}
				if (temp == 2 && dealer_page == 0)
				{
					priceofproduct = item.item_shirimp.buy_price;
					numberofproduct = item.item_shirimp.code;
				}
				if (temp == 0 && dealer_page == 1) // ���ô� 
				{
					priceofproduct = item.item_fishingrod.buy_price;
					numberofproduct = item.item_fishingrod.code;
				}
				if (temp == 1 && dealer_page == 1) // �������ô�
				{
					priceofproduct = item.item_goodfishingrod.buy_price;
					numberofproduct = item.item_goodfishingrod.code;
				}
			
				if (temp == 2 && dealer_page == 1) //�����۾���. ������
				{
					Reset();
				}

					if (inventory.money - priceofproduct >= 0) // ����  ����Ҷ�
					{
						if (bbb1 == false)
						{
							bbb1 = true;
							if (bbb2 == false)
							{
								inventory.money -= priceofproduct;  //�� ����
								bbb2 = true; 
								item.GetItem(numberofproduct, 1); // �����۳ִ´�.
							}
							successbuy = true;
						}
					}
					else if(inventory.money - priceofproduct < 0) // ���̾�����
					{
						notenoughmoney = true;  //���� ���� â����
					}
				
			} //�춧 ó���Һκ�

			if (reallysell == true)
			{
	
				if (bbb1 == false) //Ȥ�ó� ������ ���������� �ѹ��� �����ְ� ���ش�.
				{
					bbb1 = true;
					if (bbb2 == false)  //���� ������ó���� �Ǵºκ� 
					{
						bbb2 = true;
						item.SellItem(numberofproduct, 1); //��������
						item.OutItem(numberofproduct, 1); // �������� ����.
					}
					successsell = true;
				}
				
			}//����� �ȶ� 
		}
		if (pointer_pos == 21 && (reallybuy == true||reallysell==true) )
		{
			//�ʱ�ȭ		
			if (GetTickCount() - KeyTime > 200)
			{
				Reset();
				KeyTime = GetTickCount();
				
			}
		}
	}
	if (reallybuy == true || reallysell == true ) // ��¥ ��ž�?/��¥ �Ȱž�? ���� ���� Ű ��Ʈ��
	{
		if (changepos == false)
		{
			pointer_pos = 21;
			changepos = true;
		}
		if (KeyDown(VK_UP))
		{
			if (GetTickCount() - KeyTime > 200)
			{
				if (pointer_pos == 21)
					pointer_pos = 20;
				else
					pointer_pos = 21;
				KeyTime = GetTickCount();
			}
		}
		if (KeyDown(VK_DOWN))
		{
			if (GetTickCount() - KeyTime > 200)
			{
				if (pointer_pos == 21)
					pointer_pos = 20;
				else
					pointer_pos = 21;
				KeyTime = GetTickCount();
			}
			
		}
	}


	SetRect(&q_rc, 850, 570, 110, 110); // ��
	sprintf_s(str, "%d ", inventory.money);

}



void Deal ::Draw()
{
	//-------------npc ����--------------
	dealer.Render(100, 100, 0, 1, 1);
	dealers_bag.Render(100, 150, 0, 1, 1);
	dealers_itemframe1.Render(120, 160, 0, 1, 1);
	dealers_itemframe2.Render(120, 270, 0, 1, 1);
	dealers_itemframe3.Render(120, 380, 0, 1, 1);
	dealers_left.Render(120, 480, 0, 1, 1);
	dealers_right.Render(430, 480, 0, 1, 1);
	//------------------------------------
	//============�� ����=================
	bag.Render(980, 100, 0, 1, 1);
	mybag.Render(780, 150, 0, 1, 1);
	myitemframe1.Render(800, 160, 0, 1, 1);
	myitemframe2.Render(800, 270, 0, 1, 1);
	myitemframe3.Render(800, 380, 0, 1, 1);
	myright.Render(1110, 480, 0, 1, 1);
	myleft.Render(800, 480, 0, 1, 1);
	//=====================================
	purchase.Render(540, 200, 0, 1, 1);
	sell.Render(540, 400, 0, 1, 1);
	cancle.Render(540, 650, 0, 1, 1);
	money.Render(780, 550, 0, 1, 1);
	dv_font.Fonts->DrawText(NULL, str, 100, &q_rc, DT_NOCLIP, D3DCOLOR_XRGB(0, 0, 0));
	//=====================================

	if (dealer_page == 0)
	{
		item.DrawItem(12, 120, 160, 1, 1);
		item.Showname(12, 220, 160);
		item.ShowBuyPrice(12, 220, 210);

		item.DrawItem(13, 120, 270, 1, 1);
		item.Showname(13, 220, 270);
		item.ShowBuyPrice(13, 220, 320);

		item.DrawItem(14, 120, 380, 1, 1);
		item.Showname(14, 220, 380);
		item.ShowBuyPrice(14, 220, 430);
	}

	if (dealer_page == 1)
	{
		item.DrawItem(15, 120, 160, 1, 1);
		item.Showname(15, 220, 160);
		item.ShowBuyPrice(15, 220, 210);

		item.DrawItem(16, 120, 270, 1, 1);
		item.Showname(16, 220, 270);
		item.ShowBuyPrice(16, 220, 320);

	}




	//--------------------�����ִ� �������� �׸���-------------------------
	if (my_page == 0)
	{
		item.DrawItem(inventory.codeframe[0], 800, 160, 1, 1);
		item.Showname(inventory.codeframe[0], 900, 160);
		item.Showhowmany(inventory.codeframe[0], 900, 210);
		item.ShowSellPrice(inventory.codeframe[0], 1000, 210);
		item.DrawItem(inventory.codeframe[1], 800, 270, 1, 1);
		item.Showname(inventory.codeframe[1], 900, 270);
		item.Showhowmany(inventory.codeframe[1], 900, 320);
		item.ShowSellPrice(inventory.codeframe[1], 1000, 320);
		item.DrawItem(inventory.codeframe[2], 800, 370, 1, 1);
		item.Showname(inventory.codeframe[2], 900, 380);
		item.Showhowmany(inventory.codeframe[2], 900, 420);
		item.ShowSellPrice(inventory.codeframe[2], 1000, 420);
	}
	if (my_page == 1)
	{
		item.DrawItem(inventory.codeframe[3], 800, 160, 1, 1);
		item.Showname(inventory.codeframe[3], 900, 160);
		item.DrawItem(inventory.codeframe[4], 800, 270, 1, 1);
		item.Showname(inventory.codeframe[4], 900, 270);
		item.DrawItem(inventory.codeframe[5], 800, 370, 1, 1);
		item.Showname(inventory.codeframe[5], 900, 380);

		item.Showhowmany(inventory.codeframe[3], 900, 210);
		item.Showhowmany(inventory.codeframe[4], 900, 320);
		item.Showhowmany(inventory.codeframe[5], 900 , 420);

		item.ShowSellPrice(inventory.codeframe[3], 1000, 210);
		item.ShowSellPrice(inventory.codeframe[4], 1000, 320);
		item.ShowSellPrice(inventory.codeframe[5], 1000, 420);

	}
	if (my_page == 2)
	{
		item.DrawItem(inventory.codeframe[6], 800, 160, 1, 1);
		item.Showname(inventory.codeframe[6], 900, 160);
		item.DrawItem(inventory.codeframe[7], 800, 270, 1, 1);
		item.Showname(inventory.codeframe[7], 900, 270);
		item.DrawItem(inventory.codeframe[8], 800, 370, 1, 1);
		item.Showname(inventory.codeframe[8], 900, 380);

		item.Showhowmany(inventory.codeframe[6], 900, 210);
		item.Showhowmany(inventory.codeframe[7], 900, 320);
		item.Showhowmany(inventory.codeframe[8], 900, 420);

		item.ShowSellPrice(inventory.codeframe[6], 1000, 210);
		item.ShowSellPrice(inventory.codeframe[7], 1000, 320);
		item.ShowSellPrice(inventory.codeframe[8], 1000, 420);
	}
	if (my_page == 3)
	{
		item.DrawItem(inventory.codeframe[9], 800, 160, 1, 1);
		item.Showname(inventory.codeframe[9], 900, 160);
		item.DrawItem(inventory.codeframe[10], 800, 270, 1, 1);
		item.Showname(inventory.codeframe[10], 900, 270);
		item.DrawItem(inventory.codeframe[11], 800, 370, 1, 1);
		item.Showname(inventory.codeframe[11], 900, 380);

		item.Showhowmany(inventory.codeframe[9], 900, 210);
		item.Showhowmany(inventory.codeframe[10], 900, 320);
		item.Showhowmany(inventory.codeframe[11], 900, 420);

		item.ShowSellPrice(inventory.codeframe[9], 1000, 210);
		item.ShowSellPrice(inventory.codeframe[10], 1000, 320);
		item.ShowSellPrice(inventory.codeframe[11], 1000, 420);

	}
	if (my_page == 4)
	{
		item.DrawItem(inventory.codeframe[12], 800, 160, 1, 1);
		item.Showname(inventory.codeframe[12], 900, 160);
		item.DrawItem(inventory.codeframe[13], 800, 270, 1, 1);
		item.Showname(inventory.codeframe[13], 900, 270);
		item.DrawItem(inventory.codeframe[14], 800, 370, 1, 1);
		item.Showname(inventory.codeframe[14], 900, 380);

		item.Showhowmany(inventory.codeframe[12], 900, 210);
		item.Showhowmany(inventory.codeframe[13], 900, 320);
		item.Showhowmany(inventory.codeframe[14], 900, 420);


		item.ShowSellPrice(inventory.codeframe[12], 1000, 210);
		item.ShowSellPrice(inventory.codeframe[13], 1000, 320);
		item.ShowSellPrice(inventory.codeframe[14], 1000, 420);
	}
	if (my_page == 5)
	{
		item.DrawItem(inventory.codeframe[15], 800, 160, 1, 1);
		item.Showname(inventory.codeframe[15], 900, 160);
		item.DrawItem(inventory.codeframe[16], 800, 270, 1, 1);
		item.Showname(inventory.codeframe[16], 900, 270);


		item.Showhowmany(inventory.codeframe[15], 900, 210);
		item.Showhowmany(inventory.codeframe[16], 900, 320);


		item.ShowSellPrice(inventory.codeframe[15], 1000, 210);
		item.ShowSellPrice(inventory.codeframe[16], 1000, 320);


	}


	if (reallybuy == true)
	{

		askrealbuy.Render(440, 150, 0, 1, 1);
		okay.Render(540, 350, 0, 1, 1);
		cancle.Render(540, 450, 0, 1, 1);
		dv_font.DrawString("�����Ͻðڽ��ϱ�?", 530, 230);
	}
	if (reallysell == true)
	{
		askrealsell.Render(440, 150, 0, 1, 1);
		okay.Render(540, 350, 0, 1, 1);
		cancle.Render(540, 450, 0, 1, 1);
		dv_font.DrawString("�Ǹ��Ͻðڽ��ϱ�?", 530, 230);
	}


	if (notenoughmoney == true)
	{
		Reset();
		if (aaa1 == false)
		{
			KeyTime = GetTickCount();
			aaa1 = true;
		}
		deal_problem.Render(470, 250, 0, 1, 1);
		//dv_font.DrawString("���� �����մϴ�.", 500, 210);
		if (GetTickCount() - KeyTime > 500)
		{
			//���⼭ �ʱ�ȭ �Ǿ����
			
			notenoughmoney = false;
			aaa1 = false;
		}

	}
	if (successbuy == true)
	{
		Reset();
		if (aaa2 == false)
		{
			KeyTime = GetTickCount();
			inventory.Reset();
			aaa2 = true;
		}

		sound.m_confirm->Stop();	// ����
		if (soundcount == true)	// ����
		{
			sound.m_money->Play(0, NULL);
			soundcount = false;
		}
		deal_confirm.Render(480, 180, 0, 1, 1);
		//dv_font.DrawString("���Ű� ���������� ó���Ǿ����ϴ�", 500, 210);
		if (GetTickCount() - KeyTime > 500)
		{
			//���⼭ �ʱ�ȭ �Ǿ���� 
			successbuy = false;
			aaa2 = false;
			soundcount = true;		
		}
	}

	if (successsell == true)
	{
		Reset();
		if (aaa2 == false)
		{
			KeyTime = GetTickCount();
			inventory.Reset();
			aaa2 = true;
		}
		sound.m_confirm->Stop();
		if (soundcount == true)	
		{
			sound.m_money->Play(0, NULL);
			soundcount = false;
		}
		deal_confirm.Render(480, 180, 0, 1, 1);
		//dv_font.DrawString("�ǸŰ� ���������� ó���Ǿ����ϴ�", 500, 210);
		if (GetTickCount() - KeyTime > 500)
		{
			//���⼭ �ʱ�ȭ �Ǿ���� 
			successsell = false;
			aaa2 = false;
			soundcount = true;	
		}
	}
	pointer.Render(pointer_x, pointer_y, 0, 1, 1);
}


void Deal::PosSetting(int _pos, int _x, int _y)
{
	if (pointer_pos == _pos)
	{
		this->pointer_x = _x;
		this->pointer_y = _y;
	}
}

void Deal::Reset() // �ʱ�ȭ�� ����� 
{

	reallysell=false;  // ��¥ �Ȱųİ� ����� true�Ǵ� 
	reallybuy=false; // ��¥ ��ųİ� ����� true �Ǵ� 
	changepos=false; //��¥�Ұųİ� ����� ���
	pointer_pos = temp;
	bbb1 = false;
	bbb2 = false;
	savepointer = false;

	
}
