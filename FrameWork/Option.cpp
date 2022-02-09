
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
	/*퀘스트용버튼*/
	mission.Create("./resource/Img/UI/town_quest.png", false, D3DCOLOR_XRGB(0, 0, 0));
	///////////////////////////////////////////

	/*옵션메뉴버튼*/
	menuimg.Create("./resource/Img/UI/town_menu.png", false, D3DCOLOR_XRGB(0, 0, 0));
	/////////////////////////////////////////////

	/*가방메뉴버튼*/
	invenimg.Create("./resource/Img/UI/town_bag.png", false, D3DCOLOR_XRGB(0, 0, 0));
	/////////////////////////////////////////////
	menupopupimg.Create("./resource/Img/UI/menu_popup.png", false, D3DCOLOR_XRGB(0, 0, 0));		//메뉴팝업
	pointer.Create("./resource/Img/UI/pointer.png", false, D3DCOLOR_XRGB(0, 0, 0));							//포인터
	saveimg.Create("./resource/Img/UI/menu_save.png", false, D3DCOLOR_XRGB(0, 0, 0));					//저장하기 버튼
	optionimg.Create("./resource/Img/UI/menu_option.png", false, D3DCOLOR_XRGB(0, 0, 0));				//설정 버튼
	exitimg.Create("./resource/Img/UI/menu_quit.png", false, D3DCOLOR_XRGB(0, 0, 0));					//종료 버튼
	gobackimg.Create("./resource/Img/UI/goback.png", false, D3DCOLOR_XRGB(0, 0, 0));					//뒤로가기 버튼
	saving.Create("./resource/Img/UI/menu_save_saveslot.png", false, D3DCOLOR_XRGB(0, 0, 0));			//저장슬롯
	okimg.Create("./resource/Img/UI/menu_confirm.png", false, D3DCOLOR_XRGB(0, 0, 0));				//확인버튼
	cancelimg.Create("./resource/Img/UI/menu_cancle.png", false, D3DCOLOR_XRGB(0, 0, 0));				//취소버튼
	valleybutton.Create("./resource/Img/UI/beach_valley.png", false, D3DCOLOR_XRGB(0, 0, 0));			//계곡버튼
	lakebutton.Create("./resource/Img/UI/beach_lake.png", false, D3DCOLOR_XRGB(0, 0, 0));				//호수버튼
	seabutton.Create("./resource/Img/UI/beach_sea.png", false, D3DCOLOR_XRGB(0, 0, 0));				//바다버튼
	beach_goback.Create("./resource/Img/UI/beach_goback.png", false, D3DCOLOR_XRGB(0, 0, 0));		//마을로 돌아가기 버튼
	sound0p.Create("./resource/Img/UI/nonesound.png", false, D3DCOLOR_XRGB(0, 0, 0));					//음량조절 0%
	sound50p.Create("./resource/Img/UI/sound_half.png", false, D3DCOLOR_XRGB(0, 0, 0));				//음량조절 50%
	sound100p.Create("./resource/Img/UI/sound_full.png", false, D3DCOLOR_XRGB(0, 0, 0));				//음량조절 100%
	menupopupimg.Create("./resource/Img/UI/menu_popup.png", false, D3DCOLOR_XRGB(0, 0, 0));		//메뉴팝업
	pointer.Create("./resource/Img/UI/pointer.png", false, D3DCOLOR_XRGB(0, 0, 0));						//포인터
	okimg.Create("./resource/Img/UI/menu_confirm.png", false, D3DCOLOR_XRGB(0, 0, 0));				//확인버튼					
	unable_lake.Create("./resource/Img/UI/unable_lake.png", false, D3DCOLOR_XRGB(0, 0, 0));			//호수잠김
	unable_sea.Create("./resource/Img/UI/unable_sea.png", false, D3DCOLOR_XRGB(0, 0, 0));				//바다잠김
	cannotgo.Create("./resource/Img/UI/cannotgo.png", false, D3DCOLOR_XRGB(0, 0, 0));					//갈수없음 메세지
	opennewplace.Create("./resource/Img/UI/opennewplace.png", false, D3DCOLOR_XRGB(0, 0, 0));		//장소열림 메세지	

	save1_text.Create("./resource/Img/UI/save1.png", false, D3DCOLOR_XRGB(0, 0, 0));						//save1//변경
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
	PosSetting(0, -100, -100);  // 안보이게 
	// 메인화면 메뉴 화살표 좌표
	PosSetting(1, 1070, 70);  //메뉴
	PosSetting(2, 1070, 120); // 퀘스트
	PosSetting(3, 1070, 170); // 가방
	//-------------------------------

	//------------ 메뉴화면일때 --------------
	PosSetting(4, 370, 140); // 저장
	PosSetting(5, 370, 240); // 설정
	PosSetting(6, 370, 360); // 종료
	PosSetting(7, 370, 480); // 뒤로
	//-------------------------------

	//저장슬롯팝업 이미지와 포인터 보이기
	PosSetting(8, 370, 140); // 저장슬롯1
	PosSetting(9, 370, 240);// 저장슬롯2
	PosSetting(10, 370, 360);//3
	PosSetting(11, 370, 480);//확인
	PosSetting(12, 570, 480);// 취소
	//-------------------------------

	//장소버튼과 포인터 보이기
	PosSetting(13, 300, 240);//계곡
	PosSetting(14, 500, 240);// 호수
	PosSetting(15, 700, 240);//바다
	PosSetting(16, 450, 480);//마을로
	//-------------------------------


	PosSetting(20, 490, 480);//음량설정 확인버튼

	PosSetting(21, -100, -100);//무음
	PosSetting(22, -100, -100);//50%
	PosSetting(23, -100, -100);//100%


	//---------------------------------------
	quest.Update();
	inventory.Update();

	//---------------------------------------

	if (pause == false && turnonmenu == false && checkinventory == false && saveframeon == false && dealon == false && placeon==false&&soundon==false) //  메뉴에서 어떤게 뜨면 무조건 고양이 멈춤
		stopthecat = false;
	else
		stopthecat = true;

	if (tabhold == false && placeon == false && dealon == false)//수정
	{
		if (KeyDown(VK_TAB))
		{
			if (GetTickCount() - KeyTime > 200) // 오른쪽 위에 선택 가능하게하고 고양이를 멈추게함
			{
				if (power.startpowering == true || power.startfishing == true) //고기잡이할때 탭누르면 포인터 안보이게
					pointer_pos = 0;

				if (pause == false)
				{
					sound.m_but->Play(NULL); 
					pause = true;
				}
				else if (pause == true)
				{
					pause = false;//안움직여
					pointer_pos = 0;
					aaa = false;  // 한번만 실행되게 하는거. 이걸로 UI 겹치는것도 방지 

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
		//우측상단 메뉴,퀘스트,가방 버튼
		if (pointer_pos == 1)//메뉴버튼눌렀을때
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

		if (pointer_pos == 2)//퀘스트버튼눌렀을때
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
	
		if (pointer_pos == 3 && checkinventory == false)//가방버튼눌렀을때 
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
		//----------------------------------메뉴팝업창
		if (pointer_pos == 4)//저장 눌렀을때
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

		if (pointer_pos == 5)//설정 눌렀을때
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

		if (pointer_pos == 6)//종료 눌렀을때
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

		if (pointer_pos == 7) //뒤로 눌렀을때
		{
			//다 지워
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
		//----------------------------------저장창
		if (pointer_pos == 8)//저장슬롯 눌렀을때
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
		if (pointer_pos == 9)//저장슬롯 눌렀을때
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
		if (pointer_pos == 10)//저장슬롯 눌렀을때
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
		//if (pointer_pos == 11)//확인 눌렀을때
		//{
		//	if (GetTickCount() - KeyTime > 200)
		//	{
		//		sound.m_confirm->Play(NULL);
		//		KeyTime = GetTickCount();
		//	}
		//}
		if (pointer_pos == 12)//취소 눌렀을때
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
		//----------------------------------장소선택
		if (pointer_pos == 13)//계곡 눌렀을때
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

		if (pointer_pos == 14)//호수 눌렀을때
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
					//수정
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

		if (pointer_pos == 15)//바다 눌렀을때
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
					//수정
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
		if (pointer_pos == 16)//마을로 눌렀을때
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
		if (pointer_pos == 20)// 음량설정 - 확인
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
		if (pointer_pos == 21)// 음량설정 - 무음
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
		if (pointer_pos == 22)// 음량설정 - 50%
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
		if (pointer_pos == 23)// 음량설정 - 100%
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
	

	if (turnonmenu == true)  // 메뉴창에서 포인터 컨트롤
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


	if (saveframeon == true)  // 저장창에서 포인터 컨트롤
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


	if (KeyDown(VK_ESCAPE) && power.startpowering == false && power.startfishing == false&& g_Mng.n_Chap == NEWGAME) //게임안할때 esc누르면 마을옴.
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
		//수정
		cat.resetlake = false;
		cat.resetsea = false;


		queston = false;
		checkinventory = false;

	}
	if (power.startpowering == true || power.startfishing == true) //게임 중에
	{
		tabhold = true;
		pause = false;
		soundon = false;
		saveframeon = false;
		turnonmenu = false;
		queston = false;
		pointer_pos = 0;
	}
	
	if (placeon == true)  // 장소선택창에서 포인터 컨트롤
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
	//메뉴 버튼 이미지
	menuimg.Render(1100, 60, 0, 1, 1);						//메뉴 버튼 이미지
	mission.Render(1100, 110, 0, 1, 1);							//퀘스트 버튼 이미지
	invenimg.Render(1100, 160, 0, 1, 1);						//가방 버튼 이미지



	if (turnonmenu == true)
	{
		//메뉴팝업 이미지와 포인터 보이기
		menupopupimg.Render(350, 70, 0, 1, 1);

		saveimg.Render(410, 120, 0, 1, 1);//저장
		optionimg.Render(410, 240, 0, 1, 1);//설정
		exitimg.Render(410, 360, 0, 1, 1);//종료
		gobackimg.Render(490, 480, 0, 1, 1);
	}

	if (saveframeon == true)
	{
		if (!sql.mysql_Success)return;

		menupopupimg.Render(350, 70, 0, 1, 1);
			
		if (save1 == true)
			saveselected.Render(410, 120, 0, 1, 1);
		else saving.Render(410, 120, 0, 1, 1);	//저장슬롯1
			
		if (save2 == true)
			saveselected.Render(410, 240, 0, 1, 1);
		else  saving.Render(410, 240, 0, 1, 1);	//저장슬롯2

		if (save3 == true)
			saveselected.Render(410, 360, 0, 1, 1);
		else saving.Render(410, 360, 0, 1, 1);	//저장슬롯3

		save1_text.Render(480, 130, 0, 1, 1);	//변경
		save2_text.Render(480, 250, 0, 1, 1);
		save3_text.Render(480, 370, 0, 1, 1);
		okimg.Render(390, 480, 0, 1, 1);		//확인
		cancelimg.Render(610, 480, 0, 1, 1);	//취소

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
		//설정팝업에서의 포인터 보이기
		menupopupimg.Render(350, 70, 0, 1, 1);
		okimg.Render(490, 480, 0, 1, 1);	//확인

		if (mute == true)
			sound0p.Render(500, 180, 0, 1, 1);//무음
		if (halfsound == true)
			sound50p.Render(500, 180, 0, 1, 1);//50%
		if (fullsound == true)
			sound100p.Render(500, 180, 0, 1, 1);//100%
	}

	if (placeon == true)
	{
		//장소버튼과 포인터 보이기
		if (place1 == true)
		{
			valleybutton.Render(310, 240, 0, 1, 1);//계곡
			unable_lake.Render(510, 240, 0, 1, 1);//호수잠김
			unable_sea.Render(710, 240, 0, 1, 1);//바다잠김
			beach_goback.Render(470, 480, 0, 1, 1);//뒤로
		}

		if (place2 == true)
		{
			valleybutton.Render(310, 240, 0, 1, 1);//계곡
			lakebutton.Render(510, 240, 0, 1, 1);//호수
			unable_sea.Render(710, 240, 0, 1, 1);//바다잠김
			beach_goback.Render(470, 480, 0, 1, 1);//뒤로
		}

		if (place3 == true)
		{
			valleybutton.Render(310, 240, 0, 1, 1);//계곡
			lakebutton.Render(510, 240, 0, 1, 1);//호수
			seabutton.Render(710, 240, 0, 1, 1);//바다
			beach_goback.Render(470, 480, 0, 1, 1);//뒤로
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
		////메뉴팝업 이미지와 포인터 보이기
		//menupopupimg.Render(350, 70, 0, 1, 1);

		//saveimg.Render(410, 120, 0, 1, 1);//저장
		//optionimg.Render(410, 240, 0, 1, 1);//설정
		//exitimg.Render(410, 360, 0, 1, 1);//종료
		//gobackimg.Render(410, 480, 0, 1, 1);//뒤로
		//pointer.Render(370, 140, 0, 1, 1); pointer.Render(370, 240, 0, 1, 1); pointer.Render(370, 360, 0, 1, 1);		pointer.Render(370, 480, 0, 1, 1);

		////저장슬롯팝업 이미지와 포인터 보이기
		//menupopupimg.Render(350, 70, 0, 1, 1);

		//saving.Render(410, 120, 0, 1, 1);	//저장슬롯1
		//saving.Render(410, 240, 0, 1, 1);	//저장슬롯2
		//saving.Render(410, 360, 0, 1, 1);	//저장슬롯3
		//okimg.Render(390, 480, 0, 1, 1);	//확인
		//cancelimg.Render(610, 480, 0, 1, 1);//취소
		//pointer.Render(370, 140, 0, 1, 1); pointer.Render(370, 240, 0, 1, 1); pointer.Render(370, 360, 0, 1, 1);	pointer.Render(370, 480, 0, 1, 1);	pointer.Render(570, 480, 0, 1, 1);

		//if (soundon == true);
		////설정팝업에서의 포인터 보이기
		//menupopupimg.Render(350, 70, 0, 1, 1);
		//okimg.Render(490, 480, 0, 1, 1);	//확인

		//sound0p.Render(500, 180, 0, 1, 1);//무음
		//sound50p.Render(500, 180, 0, 1, 1);//50%
		//sound100p.Render(500, 180, 0, 1, 1);//100%

		//if (placeon == true);
		////장소버튼과 포인터 보이기
		//valleybutton.Render(310, 240, 0, 1, 1);//계곡
		//lakebutton.Render(510, 240, 0, 1, 1);//호수
		//seabutton.Render(710, 240, 0, 1, 1);//바다
		//beach_goback.Render(470, 480, 0, 1, 1);//뒤로
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