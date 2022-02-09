
#pragma once
#include "Include.h"

Option option;

Option::Option()
{

}

Option::~Option()
{
}

void Option::Init()
{
	/*����Ʈ���ư*/
	mission.Create("./resource/Img/UI/town_quest.png", false, D3DCOLOR_XRGB(0, 0, 0));
	///////////////////////////////////////////

	/*�ɼǸ޴���ư*/
	menuimg.Create("./resource/Img/UI/town_menu.png", false, D3DCOLOR_XRGB(0, 0, 0));
	/////////////////////////////////////////////

	/*����޴���ư*/
	invenimg.Create("./resource/Img/UI/town_bag.png", false, D3DCOLOR_XRGB(0, 0, 0));
	/////////////////////////////////////////////
	menupopupimg.Create("./resource/Img/UI/menu_popup.png", false, D3DCOLOR_XRGB(0, 0, 0));		//�޴��˾�
	pointer.Create("./resource/Img/UI/pointer.png", false, D3DCOLOR_XRGB(0, 0, 0));							//������
	saveimg.Create("./resource/Img/UI/menu_save.png", false, D3DCOLOR_XRGB(0, 0, 0));					//�����ϱ� ��ư
	optionimg.Create("./resource/Img/UI/menu_option.png", false, D3DCOLOR_XRGB(0, 0, 0));				//���� ��ư
	exitimg.Create("./resource/Img/UI/menu_quit.png", false, D3DCOLOR_XRGB(0, 0, 0));					//���� ��ư
	gobackimg.Create("./resource/Img/UI/goback.png", false, D3DCOLOR_XRGB(0, 0, 0));					//�ڷΰ��� ��ư
	saving.Create("./resource/Img/UI/menu_save_saveslot.png", false, D3DCOLOR_XRGB(0, 0, 0));			//���彽��
	okimg.Create("./resource/Img/UI/menu_confirm.png", false, D3DCOLOR_XRGB(0, 0, 0));				//Ȯ�ι�ư
	cancelimg.Create("./resource/Img/UI/menu_cancle.png", false, D3DCOLOR_XRGB(0, 0, 0));				//��ҹ�ư
	valleybutton.Create("./resource/Img/UI/beach_valley.png", false, D3DCOLOR_XRGB(0, 0, 0));			//����ư
	lakebutton.Create("./resource/Img/UI/beach_lake.png", false, D3DCOLOR_XRGB(0, 0, 0));				//ȣ����ư
	seabutton.Create("./resource/Img/UI/beach_sea.png", false, D3DCOLOR_XRGB(0, 0, 0));				//�ٴٹ�ư
	beach_goback.Create("./resource/Img/UI/beach_goback.png", false, D3DCOLOR_XRGB(0, 0, 0));		//������ ���ư��� ��ư
	sound0p.Create("./resource/Img/UI/nonesound.png", false, D3DCOLOR_XRGB(0, 0, 0));					//�������� 0%
	sound50p.Create("./resource/Img/UI/sound_half.png", false, D3DCOLOR_XRGB(0, 0, 0));				//�������� 50%
	sound100p.Create("./resource/Img/UI/sound_full.png", false, D3DCOLOR_XRGB(0, 0, 0));				//�������� 100%
	menupopupimg.Create("./resource/Img/UI/menu_popup.png", false, D3DCOLOR_XRGB(0, 0, 0));		//�޴��˾�
	pointer.Create("./resource/Img/UI/pointer.png", false, D3DCOLOR_XRGB(0, 0, 0));						//������
	okimg.Create("./resource/Img/UI/menu_confirm.png", false, D3DCOLOR_XRGB(0, 0, 0));				//Ȯ�ι�ư					
	unable_lake.Create("./resource/Img/UI/unable_lake.png", false, D3DCOLOR_XRGB(0, 0, 0));			//ȣ�����
	unable_sea.Create("./resource/Img/UI/unable_sea.png", false, D3DCOLOR_XRGB(0, 0, 0));				//�ٴ����
	cannotgo.Create("./resource/Img/UI/cannotgo.png", false, D3DCOLOR_XRGB(0, 0, 0));					//�������� �޼���
	opennewplace.Create("./resource/Img/UI/opennewplace.png", false, D3DCOLOR_XRGB(0, 0, 0));		//��ҿ��� �޼���	

	save1_text.Create("./resource/Img/UI/save1.png", false, D3DCOLOR_XRGB(0, 0, 0));						//save1//����
	save2_text.Create("./resource/Img/UI/save2.png", false, D3DCOLOR_XRGB(0, 0, 0));						//save2
	save3_text.Create("./resource/Img/UI/save3.png", false, D3DCOLOR_XRGB(0, 0, 0));						//save3

	savedimg.Create("./resource/Img/UI/savedimg.png", false, D3DCOLOR_XRGB(0, 0, 0));
	saveselected.Create("./resource/Img/UI/saveselected.png", false, D3DCOLOR_XRGB(0, 0, 0));

	 inventory.Init();
	 quest.Init();
	 pointer_pos = 0;
	 nottwotime = 0;
}


void Option::Update(double frame)
{
	PosSetting(0, -100, -100);  // �Ⱥ��̰� 
	// ����ȭ�� �޴� ȭ��ǥ ��ǥ
	PosSetting(1, 1070, 70);  //�޴�
	PosSetting(2, 1070, 120); // ����Ʈ
	PosSetting(3, 1070, 170); // ����
	//-------------------------------

	//------------ �޴�ȭ���϶� --------------
	PosSetting(4, 370, 140); // ����
	PosSetting(5, 370, 240); // ����
	PosSetting(6, 370, 360); // ����
	PosSetting(7, 370, 480); // �ڷ�
	//-------------------------------

	//���彽���˾� �̹����� ������ ���̱�
	PosSetting(8, 370, 140); // ���彽��1
	PosSetting(9, 370, 240);// ���彽��2
	PosSetting(10, 370, 360);//3
	PosSetting(11, 370, 480);//Ȯ��
	PosSetting(12, 570, 480);// ���
	//-------------------------------

	//��ҹ�ư�� ������ ���̱�
	PosSetting(13, 300, 240);//���
	PosSetting(14, 500, 240);// ȣ��
	PosSetting(15, 700, 240);//�ٴ�
	PosSetting(16, 450, 480);//������
	//-------------------------------


	PosSetting(20, 490, 480);//�������� Ȯ�ι�ư

	PosSetting(21, -100, -100);//����
	PosSetting(22, -100, -100);//50%
	PosSetting(23, -100, -100);//100%


	//---------------------------------------
	quest.Update();
	inventory.Update();

	//---------------------------------------

	if (pause == false && turnonmenu == false && checkinventory == false && saveframeon == false && dealon == false && placeon==false&&soundon==false) //  �޴����� ��� �߸� ������ ����� ����
		stopthecat = false;
	else
		stopthecat = true;

	if (tabhold == false && placeon == false && dealon == false)//����
	{
		if (KeyDown(VK_TAB))
		{
			if (GetTickCount() - KeyTime > 200) // ������ ���� ���� �����ϰ��ϰ� ����̸� ���߰���
			{
				if (power.startpowering == true || power.startfishing == true) //��������Ҷ� �Ǵ����� ������ �Ⱥ��̰�
					pointer_pos = 0;

				if (pause == false)
				{
					sound.m_but->Play(NULL); 
					pause = true;
				}
				else if (pause == true)
				{
					pause = false;//�ȿ�����
					pointer_pos = 0;
					aaa = false;  // �ѹ��� ����ǰ� �ϴ°�. �̰ɷ� UI ��ġ�°͵� ���� 

				}
				KeyTime = GetTickCount();
			}
		}
	}

	if (pause == true)
	{
		if (aaa == false)
		{
			pointer_pos = 1;
		}
		aaa = true;
	}

	if (pause == true && turnonmenu == false)
	{	
		if (KeyDown(VK_DOWN))
		{
			if (GetTickCount() - KeyTime > 200)
			{
				sound.m_but->Play(NULL);	
				if (pointer_pos < 3)
					pointer_pos++;
				else
					pointer_pos = pointer_pos;
				KeyTime = GetTickCount();
			}
		}


		if (KeyDown(VK_UP))
		{
			if (GetTickCount() - KeyTime > 200)
			{
				sound.m_but->Play(NULL);	
				if (pointer_pos > 1)
					pointer_pos--;
				else
					pointer_pos = pointer_pos;
				KeyTime = GetTickCount();
			}
		}
	}
	if (KeyDown(VK_SPACE))
	{
		//������� �޴�,����Ʈ,���� ��ư
		if (pointer_pos == 1)//�޴���ư��������
		{
			if (GetTickCount() - KeyTime > 200)
			{
				sound.m_confirm->Play(NULL);
				turnonmenu = true;
				pause = false;
				tabhold = true;
				pointer_pos = 4;
				KeyTime = GetTickCount();
			}
		}

		if (pointer_pos == 2)//����Ʈ��ư��������
		{
			if (GetTickCount() - KeyTime > 200)
			{
				sound.m_confirm->Play(NULL); 
				if (queston == false)
					queston = true;
				else
					queston = false;
				KeyTime = GetTickCount();
			}
		}
	
		if (pointer_pos == 3 && checkinventory == false)//�����ư�������� 
		{
			if (GetTickCount() - KeyTime > 200)
			{
				sound.m_confirm->Play(NULL);
				power.startpowering = false;
				checkinventory = true;

				inventory.KeyTime = GetTickCount();
				inventory.Reset();
				KeyTime = GetTickCount();
			}
		}
		//-----------------------------------------------
		//----------------------------------�޴��˾�â
		if (pointer_pos == 4)//���� ��������
		{
			if (GetTickCount() - KeyTime > 200)
			{
				sound.m_confirm->Play(NULL);
				saveframeon = true;
				turnonmenu = false;
				pointer_pos = 8;
				KeyTime = GetTickCount();
			}
		}

		if (pointer_pos == 5)//���� ��������
		{
			if (GetTickCount() - KeyTime > 200)
			{
				sound.m_confirm->Play(NULL);
				soundon = true;
				turnonmenu = false;
				if(mute==true)
					pointer_pos = 21;
				else if (halfsound == true)
					pointer_pos = 22;
				else if (fullsound == true)
					pointer_pos = 23;
				else
					pointer_pos = 21;
			
				KeyTime = GetTickCount();
			}
		}				

		if (pointer_pos == 6)//���� ��������
		{
			if (GetTickCount() - KeyTime > 200)
			{
				sound.m_confirm->Play(NULL);
				exit(1);													
				//g_Mng.n_Chap = MENU;
				//menu.load1 = false;
				//menu.load2 = false;
				//menu.load3 = false;
				sound.m_town->Stop();
				KeyTime = GetTickCount();
			}
		}

		if (pointer_pos == 7) //�ڷ� ��������
		{
			//�� ����
			sound.m_confirm->Play(NULL);
			pause = false;
			turnonmenu = false;
			stopthecat = false;
			tabhold = false;
			saveframeon = false;
			pointer_pos = 0;
			aaa = false;
			save_ok = false;
			power.KeyTime = GetTickCount();
		}
		//-----------------------------------------------
		//----------------------------------����â
		if (pointer_pos == 8)//���彽�� ��������
		{
			if (GetTickCount() - KeyTime > 200)
			{
				save1 = true;
				save2 = false;
				save3 = false;
				sound.m_confirm->Play(NULL);
				KeyTime = GetTickCount();
			}
		}
		if (pointer_pos == 9)//���彽�� ��������
		{
			if (GetTickCount() - KeyTime > 200)
			{
				save1 = false;
				save2 = true;
				save3 = false;
				sound.m_confirm->Play(NULL);
				KeyTime = GetTickCount();
			}
		}
		if (pointer_pos == 10)//���彽�� ��������
		{
			if (GetTickCount() - KeyTime > 200)
			{
				save1 = false;
				save2 = false;
				save3 = true;
				sound.m_confirm->Play(NULL);
				KeyTime = GetTickCount();
			}
		}
		//if (pointer_pos == 11)//Ȯ�� ��������
		//{
		//	if (GetTickCount() - KeyTime > 200)
		//	{
		//		sound.m_confirm->Play(NULL);
		//		KeyTime = GetTickCount();
		//	}
		//}
		if (pointer_pos == 12)//��� ��������
		{
			if (GetTickCount() - KeyTime > 200)
			{
				sound.m_confirm->Play(NULL);
				save1 = false;
				save2 = false;
				save3 = false;
				saveframeon = false;
				turnonmenu = true;
			
				pointer_pos = 4;
				KeyTime = GetTickCount();
				power.KeyTime = GetTickCount();
			}
		}
		//-----------------------------------------------
		//----------------------------------��Ҽ���
		if (pointer_pos == 13)//��� ��������
		{
			if (GetTickCount() - KeyTime > 200)
			{
				sound.m_confirm->Play(NULL);
				map.m_Stage = 1;
				g_Mng.n_Chap = NEWGAME;
				placeon = false;			
				sound.StopEtc(); 
				sound.m_valley->Play(0, DSBPLAY_LOOPING); 
				pointer_pos = 0;
				KeyTime = GetTickCount();
				power.KeyTime = GetTickCount();
			}
		}

		if (pointer_pos == 14)//ȣ�� ��������
		{
			if (quest.missionnum2 == true)
				unlocklake = true;

			if (unlocklake == true || unlocksea == true)
			{
				if (GetTickCount() - KeyTime > 200)
				{
					sound.m_confirm->Play(NULL);
					map.m_Stage = 2;
					g_Mng.n_Chap = NEWGAME;
					sound.StopEtc(); 
					sound.m_birdlake->Play(0, DSBPLAY_LOOPING); 
					placeon = false;
					pointer_pos = 0;
					//����
					map.changemap2 = false;
					KeyTime = GetTickCount();
					power.KeyTime = GetTickCount();
				}
			}
			else
			{
				if (GetTickCount() - KeyTime > 200)
				{
					if (showerrormsg == false)
						showerrormsg = true;

					else if (showerrormsg == true)
						showerrormsg = false;
					KeyTime = GetTickCount();
				}
			}
		}

		if (pointer_pos == 15)//�ٴ� ��������
		{
			if (quest.missionnum3 == true)
			{
				unlocklake = false;
				unlocksea = true;
			}
			if (unlocksea == true && unlocklake == false)
			{
		
				if (GetTickCount() - KeyTime > 200)
				{
					sound.m_confirm->Play(NULL);
					map.m_Stage = 3;
					g_Mng.n_Chap = NEWGAME;
					placeon = false;
					sound.StopEtc();
					sound.m_ocean->Play(0, DSBPLAY_LOOPING); 
					sound.m_boat->Play(0, DSBPLAY_LOOPING); 
					pointer_pos = 0;
					//����
					map.changemap3 = false;
					KeyTime = GetTickCount();
					power.KeyTime = GetTickCount();
				}
			}
			else
			{
				if (GetTickCount() - KeyTime > 200)
				{
					if (showerrormsg == false)
						showerrormsg = true;

					else if (showerrormsg == true)
						showerrormsg = false;
					KeyTime = GetTickCount();
				}
			}
		}
		if (pointer_pos == 16)//������ ��������
		{
			if (GetTickCount() - KeyTime > 200)
			{
				sound.m_confirm->Play(NULL);
				placeon = false;
				pointer_pos = 0;
				sound.StopEtc();
				KeyTime = GetTickCount();
			}
		}


		//-----------------------------------------------
		if (pointer_pos == 20)// �������� - Ȯ��
		{
			if (GetTickCount() - KeyTime > 200)
			{
				sound.m_confirm->Play(NULL);
				soundon = false;
				turnonmenu = true;
				pointer_pos = 4;
				KeyTime = GetTickCount();
		}
	}
		if (pointer_pos == 21)// �������� - ����
		{
			if (GetTickCount() - KeyTime > 200)
			{
				sound.m_confirm->Play(NULL);
				pointer_pos = 20;
				mute = true;
				halfsound = false;
				fullsound = false;

				KeyTime = GetTickCount();
			}
		}
		if (pointer_pos == 22)// �������� - 50%
		{
			if (GetTickCount() - KeyTime > 200)
			{
				sound.m_confirm->Play(NULL);
				pointer_pos = 20;
				mute = false;
				halfsound = true;
				fullsound = false;
				KeyTime = GetTickCount();
			}
		}
		if (pointer_pos == 23)// �������� - 100%
		{
			if (GetTickCount() - KeyTime > 200)
			{
				sound.m_confirm->Play(NULL);
				pointer_pos = 20;
				mute = false;
				halfsound = false;
				fullsound = true;
				KeyTime = GetTickCount();


			}
		}
	}
	

	if (turnonmenu == true)  // �޴�â���� ������ ��Ʈ��
	{

		if (KeyDown(VK_DOWN))
		{
			if (GetTickCount() - KeyTime > 200)
			{
				sound.m_but->Play(NULL);
				if (pointer_pos < 7)
					pointer_pos++;
				else
					pointer_pos = pointer_pos;
				KeyTime = GetTickCount();
			}
		}
		if (KeyDown(VK_UP))
		{
			if (GetTickCount() - KeyTime > 200)
			{
				sound.m_but->Play(NULL);
				if (pointer_pos >4)
					pointer_pos--;
				else
					pointer_pos = pointer_pos;
				KeyTime = GetTickCount();
			}
		}
	}


	if (saveframeon == true)  // ����â���� ������ ��Ʈ��
	{

		if (KeyDown(VK_DOWN))
		{
			if (GetTickCount() - KeyTime > 200)
			{
				sound.m_but->Play(NULL);
				if (pointer_pos < 12)
					pointer_pos++;
				else
					pointer_pos = pointer_pos;
				KeyTime = GetTickCount();
			}
		}
		if (KeyDown(VK_UP))
		{
			if (GetTickCount() - KeyTime > 200)
			{
				sound.m_but->Play(NULL);
				if (pointer_pos >8)
					pointer_pos--;
				else
					pointer_pos = pointer_pos;
				KeyTime = GetTickCount();
			}
		}
	}


	if (KeyDown(VK_ESCAPE) && power.startpowering == false && power.startfishing == false&& g_Mng.n_Chap == NEWGAME) //���Ӿ��Ҷ� esc������ ������.
	{

		tabhold = false;
		//
		dealon = false;
		cat.reset = true;
		saveframeon = false;
		turnonmenu = false;
		soundon = false;
		placeon = false;
		g_Mng.n_Chap = TOWN;
		KeyTime = GetTickCount();
		pointer_pos = 0;
		aaa = false;

		//sound.m_spin->Stop();
		//sound.m_fishing->Stop();
		//����
		cat.resetlake = false;
		cat.resetsea = false;


		queston = false;
		checkinventory = false;

	}
	if (power.startpowering == true || power.startfishing == true) //���� �߿�
	{
		tabhold = true;
		pause = false;
		soundon = false;
		saveframeon = false;
		turnonmenu = false;
		queston = false;
		pointer_pos = 0;
	}
	
	if (placeon == true)  // ��Ҽ���â���� ������ ��Ʈ��
	{
		if (KeyDown(VK_DOWN))
		{
			if (GetTickCount() - KeyTime > 200)
			{
				if (pointer_pos < 16)
				{
					pointer_pos++;
					sound.m_but->Play(NULL);
				}
				else
					pointer_pos = pointer_pos;
				KeyTime = GetTickCount();
			}
		}
		if (KeyDown(VK_UP))
		{
			if (GetTickCount() - KeyTime > 200)
			{
				if (pointer_pos > 13)
				{
					pointer_pos--;
					sound.m_but->Play(NULL);
				}
				else
					pointer_pos = pointer_pos;
				KeyTime = GetTickCount();
			}
		}

		if (KeyDown(VK_RIGHT))
		{
			if (GetTickCount() - KeyTime > 200)
			{
				if (pointer_pos < 16)
				{
					pointer_pos++;
					sound.m_but->Play(NULL);
				}
				else
					pointer_pos = pointer_pos;
				KeyTime = GetTickCount();
			}
		}
		if (KeyDown(VK_LEFT))
		{
			if (GetTickCount() - KeyTime > 200)
			{
				if (pointer_pos > 13)
				{
					pointer_pos--;
					sound.m_but->Play(NULL);
				}
				else
					pointer_pos = pointer_pos;
				KeyTime = GetTickCount();
			}
		}
	}


	if (soundon == true)
	{
		power.startpowering = false;
		power.startfishing = false;
		if (pointer_pos == 21)
		{
			mute = true;
			halfsound = false;
			fullsound = false;
		}
		if (pointer_pos == 22)
		{
			mute = false;
			halfsound = true;
			fullsound = false;
		}
		if (pointer_pos == 23)
		{
			mute = false;
			halfsound = false;
			fullsound = true;
		}
		if (KeyDown(VK_UP))
		{
			if (GetTickCount() - KeyTime > 200)
			{

				if (pointer_pos < 23)
				{
					sound.m_but->Play(NULL);
					pointer_pos++;
				}
				else
					pointer_pos = pointer_pos;
				KeyTime = GetTickCount();
			}
		}
		if (KeyDown(VK_DOWN))
		{
			if (GetTickCount() - KeyTime > 200)
			{
				if (pointer_pos > 21)
				{
					sound.m_but->Play(NULL);
					pointer_pos--;
				}
				else
					pointer_pos = pointer_pos;
				KeyTime = GetTickCount();
			}
		}

		if (KeyDown(VK_LEFT))
		{
			if (GetTickCount() - KeyTime > 200)
			{
				if (pointer_pos < 23)
				{
					sound.m_but->Play(NULL);
					pointer_pos++;
				}
				else
					pointer_pos = pointer_pos;
				KeyTime = GetTickCount();
			}
		}
		if (KeyDown(VK_RIGHT))
		{
			if (GetTickCount() - KeyTime > 200)
			{
				if (pointer_pos > 21)
				{
					sound.m_but->Play(NULL);
					pointer_pos--;
				}
				else
					pointer_pos = pointer_pos;
				KeyTime = GetTickCount();
			}
		}
	}

	if (checkinventory == true)
	{
		pointer_pos = 0;
	}
}



void Option::Draw()
{
	//�޴� ��ư �̹���
	menuimg.Render(1100, 60, 0, 1, 1);						//�޴� ��ư �̹���
	mission.Render(1100, 110, 0, 1, 1);							//����Ʈ ��ư �̹���
	invenimg.Render(1100, 160, 0, 1, 1);						//���� ��ư �̹���



	if (turnonmenu == true)
	{
		//�޴��˾� �̹����� ������ ���̱�
		menupopupimg.Render(350, 70, 0, 1, 1);

		saveimg.Render(410, 120, 0, 1, 1);//����
		optionimg.Render(410, 240, 0, 1, 1);//����
		exitimg.Render(410, 360, 0, 1, 1);//����
		gobackimg.Render(490, 480, 0, 1, 1);
	}

	if (saveframeon == true)
	{
		if (!sql.mysql_Success)return;

		menupopupimg.Render(350, 70, 0, 1, 1);
			
		if (save1 == true)
			saveselected.Render(410, 120, 0, 1, 1);
		else saving.Render(410, 120, 0, 1, 1);	//���彽��1
			
		if (save2 == true)
			saveselected.Render(410, 240, 0, 1, 1);
		else  saving.Render(410, 240, 0, 1, 1);	//���彽��2

		if (save3 == true)
			saveselected.Render(410, 360, 0, 1, 1);
		else saving.Render(410, 360, 0, 1, 1);	//���彽��3

		save1_text.Render(480, 130, 0, 1, 1);	//����
		save2_text.Render(480, 250, 0, 1, 1);
		save3_text.Render(480, 370, 0, 1, 1);
		okimg.Render(390, 480, 0, 1, 1);		//Ȯ��
		cancelimg.Render(610, 480, 0, 1, 1);	//���

		if (save_ok == true)
		{

				savedimg.Render(480, 180, 0, 1, 1);

			if (save_ok == true)
				if (GetTickCount() - KeyTime > 900)
				{
				save_ok = false;
				KeyTime = GetTickCount();
				}
		}
		

	}

	if (soundon == true)
	{
		//�����˾������� ������ ���̱�
		menupopupimg.Render(350, 70, 0, 1, 1);
		okimg.Render(490, 480, 0, 1, 1);	//Ȯ��

		if (mute == true)
			sound0p.Render(500, 180, 0, 1, 1);//����
		if (halfsound == true)
			sound50p.Render(500, 180, 0, 1, 1);//50%
		if (fullsound == true)
			sound100p.Render(500, 180, 0, 1, 1);//100%
	}

	if (placeon == true)
	{
		//��ҹ�ư�� ������ ���̱�
		if (place1 == true)
		{
			valleybutton.Render(310, 240, 0, 1, 1);//���
			unable_lake.Render(510, 240, 0, 1, 1);//ȣ�����
			unable_sea.Render(710, 240, 0, 1, 1);//�ٴ����
			beach_goback.Render(470, 480, 0, 1, 1);//�ڷ�
		}

		if (place2 == true)
		{
			valleybutton.Render(310, 240, 0, 1, 1);//���
			lakebutton.Render(510, 240, 0, 1, 1);//ȣ��
			unable_sea.Render(710, 240, 0, 1, 1);//�ٴ����
			beach_goback.Render(470, 480, 0, 1, 1);//�ڷ�
		}

		if (place3 == true)
		{
			valleybutton.Render(310, 240, 0, 1, 1);//���
			lakebutton.Render(510, 240, 0, 1, 1);//ȣ��
			seabutton.Render(710, 240, 0, 1, 1);//�ٴ�
			beach_goback.Render(470, 480, 0, 1, 1);//�ڷ�
		}

		if (showerrormsg == true)
		{
			cannotgo.Render(480, 340, 0, 1, 1);
		}

		if (shownewmsg == true)
		{
			opennewplace.Render(480, 340, 0, 1, 1);
		}

	}


	if (checkinventory == true)
	{
		inventory.Draw();
	}

	if (queston == true && pointer_pos == 2)
	{
		quest.Draw();
	}

	pointer.Render(pointer_x, pointer_y, 0, 0.5, 0.5);

	if (temp == true)
	{
		////�޴��˾� �̹����� ������ ���̱�
		//menupopupimg.Render(350, 70, 0, 1, 1);

		//saveimg.Render(410, 120, 0, 1, 1);//����
		//optionimg.Render(410, 240, 0, 1, 1);//����
		//exitimg.Render(410, 360, 0, 1, 1);//����
		//gobackimg.Render(410, 480, 0, 1, 1);//�ڷ�
		//pointer.Render(370, 140, 0, 1, 1); pointer.Render(370, 240, 0, 1, 1); pointer.Render(370, 360, 0, 1, 1);		pointer.Render(370, 480, 0, 1, 1);

		////���彽���˾� �̹����� ������ ���̱�
		//menupopupimg.Render(350, 70, 0, 1, 1);

		//saving.Render(410, 120, 0, 1, 1);	//���彽��1
		//saving.Render(410, 240, 0, 1, 1);	//���彽��2
		//saving.Render(410, 360, 0, 1, 1);	//���彽��3
		//okimg.Render(390, 480, 0, 1, 1);	//Ȯ��
		//cancelimg.Render(610, 480, 0, 1, 1);//���
		//pointer.Render(370, 140, 0, 1, 1); pointer.Render(370, 240, 0, 1, 1); pointer.Render(370, 360, 0, 1, 1);	pointer.Render(370, 480, 0, 1, 1);	pointer.Render(570, 480, 0, 1, 1);

		//if (soundon == true);
		////�����˾������� ������ ���̱�
		//menupopupimg.Render(350, 70, 0, 1, 1);
		//okimg.Render(490, 480, 0, 1, 1);	//Ȯ��

		//sound0p.Render(500, 180, 0, 1, 1);//����
		//sound50p.Render(500, 180, 0, 1, 1);//50%
		//sound100p.Render(500, 180, 0, 1, 1);//100%

		//if (placeon == true);
		////��ҹ�ư�� ������ ���̱�
		//valleybutton.Render(310, 240, 0, 1, 1);//���
		//lakebutton.Render(510, 240, 0, 1, 1);//ȣ��
		//seabutton.Render(710, 240, 0, 1, 1);//�ٴ�
		//beach_goback.Render(470, 480, 0, 1, 1);//�ڷ�
		//pointer.Render(300, 240, 0, 1, 1); pointer.Render(500, 240, 0, 1, 1);	pointer.Render(700, 240, 0, 1, 1);			pointer.Render(450, 480, 0, 1, 1);

	}

}


void Option::OnMessage(MSG* msg)
{
	//char aaa[256];
	//_itoa_s_s(msg->message, aaa,2);
	//dv_font.DrawString(aaa, 10 , 210 ) ;   
	//PostQuitMessage(0);



	//switch (msg->message)
	//{
	//case WM_KEYDOWN:
	//	switch (msg->wParam) {
	//	case VK_F2:
	//		//MessageBox(NULL, "", "", 0);
	//		if (g_Mng.n_Chap = MENU) {

	//			g_Mng.n_Chap = NEWGAME;
	//			//sound.m_Bk1->Play(0, DSBPLAY_LOOPING);

	//		}
	//		break;
	//	}

	}
void Option::PosSetting(int _pos, int _x, int _y)
{
	if (pointer_pos == _pos)
	{
		this->pointer_x = _x;
		this->pointer_y = _y;
	}
}