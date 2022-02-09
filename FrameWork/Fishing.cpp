#pragma once
#include "Include.h"


Fishing fishing;



Fishing::Fishing(void)
{
	aaa = false;
	soundcount = true;
}

Fishing::~Fishing(void)
{
}

void Fishing::Init()
{
	srand((unsigned int)time(NULL));
	waitingtime = rand() % 15000 + 6000;
	randomfish_x = 618;
	drop_y = -250;
	controlbar_x = 590;

	vibration = 0;
	controlbar.Create("./resource/Img/UI/controlbar.png", false, D3DCOLOR_XRGB(0, 0, 0));
	controlbarinside.Create("./resource/Img/UI/controlbarinside.png", false, D3DCOLOR_XRGB(0, 0, 0));
	randomfish.Create("./resource/Img/Fish/randomfish_left.png", false, D3DCOLOR_XRGB(0, 0, 0));
	fail.Create("./resource/Img/UI/fail.png", false, D3DCOLOR_XRGB(0, 0, 0));
	success.Create("./resource/Img/UI/success.png", false, D3DCOLOR_XRGB(0, 0, 0));

	exclamation.Create("./resource/Img/UI/exclamation.png", false, D3DCOLOR_XRGB(0, 0, 0));
	frame_showfish.Create("./resource/Img/UI/menu_popup.png", false, D3DCOLOR_XRGB(0, 0, 0));
	showfishok.Create("./resource/Img/UI/menu_confirm.png", false, D3DCOLOR_XRGB(0, 0, 0));
	fishrod.Create("./resource/Img/UI/control_fishrod.png", false, D3DCOLOR_XRGB(0, 0, 0));
	goodfishrod.Create("./resource/Img/UI/control_goodfishrod.png", false, D3DCOLOR_XRGB(0, 0, 0));

	textbing.Create("./resource/Img/UI/textbing.png", false, D3DCOLOR_XRGB(0, 0, 0));
	textcruciancarp.Create("./resource/Img/UI/textcruciancarp.png", false, D3DCOLOR_XRGB(0, 0, 0));
	textfrog.Create("./resource/Img/UI/textfrog.png", false, D3DCOLOR_XRGB(0, 0, 0));
	texting.Create("./resource/Img/UI/texting.png", false, D3DCOLOR_XRGB(0, 0, 0));
	textjang.Create("./resource/Img/UI/textjang.png", false, D3DCOLOR_XRGB(0, 0, 0));
	textlopster.Create("./resource/Img/UI/textlopster.png", false, D3DCOLOR_XRGB(0, 0, 0));
	textsalmon.Create("./resource/Img/UI/textsalmon.png", false, D3DCOLOR_XRGB(0, 0, 0));
	textshark.Create("./resource/Img/UI/textshark.png", false, D3DCOLOR_XRGB(0, 0, 0));
	textocto.Create("./resource/Img/UI/textocto.png", false, D3DCOLOR_XRGB(0, 0, 0));
	texttrash.Create("./resource/Img/UI/texttrash.png", false, D3DCOLOR_XRGB(0, 0, 0));
	texttuna.Create("./resource/Img/UI/texttuna.png", false, D3DCOLOR_XRGB(0, 0, 0));
	textpressenter.Create("./resource/Img/UI/pressenter.png", false, D3DCOLOR_XRGB(0, 0, 0));
}

void Fishing::Update()
{

	if (KeyDown('1'))
	{
		if (GetTickCount() - KeyTime > 200)
		{
			map.m_Stage = 1;
			KeyTime = GetTickCount();
		}
	}

	if (KeyDown('2'))
	{
		if (GetTickCount() - KeyTime > 200)
		{
			map.m_Stage = 2;
			KeyTime = GetTickCount();
		}

	}

	if (KeyDown('3'))
	{
		if (GetTickCount() - KeyTime > 200)
		{
			map.m_Stage = 3;
			KeyTime = GetTickCount();
		}

	}
	if (power.startfishing == true)  //낚시가 시작됐을때 
	{
		if (power.direction == 1) // 낚시 거리와 방향에따라 미끼의 위치를 잡는다. 왼쪽으로 던질때 
		{
			baitx = power.fishingline_x;
			baity = power.fishingline_y + 70;
		}
		else if (power.direction == 2) //오른쪽으로 던질때 미끼위치
		{
			if (power.howmuchpower == 1)
				baitx = power.fishingline_x + 178;
			else if (power.howmuchpower == 2)
				baitx = power.fishingline_x + 356;
			else if (power.howmuchpower == 3)
				baitx = power.fishingline_x + 600;

			baity = cat.y +75 + 75;
		}


		if (aaa2 == false)
		{
			KeyTime = GetTickCount();
			aaa2 = true;
		}

		if (power.startfishing == true && fortime2 == false)  // 미끼를 던지고 랜덤의 몇초간 기다린다.
		{
			if (GetTickCount() - KeyTime > waitingtime)// 난이도 수정 : 원래 waitingtime 들어가야 
			{
				fortime2 = true;
			}
		}

		if (fortime2 == true&& aaa3==false) //기다리면 느낌이오고

			feelingiscoming = true;


		if (aaa3 == false&&feelingiscoming==true)
		{
			sound.m_splash->Play(0, DSBPLAY_LOOPING);
			KeyTime = GetTickCount();
			aaa3 = true;
		}

		if (feelingiscoming== true && fortime3 == false)  // feel이오고 몇초간 스페이스바를 눌러 겜시작안하면 실패
		{
			sound.m_splash->Play(0, DSBPLAY_LOOPING);
			if (KeyDown(VK_SPACE))
			{
				if (GetTickCount() - KeyTime > 200)
				{
					startnewgame = true;
					feelingiscoming = false;
					comeonfish.KeyTime = GetTickCount();
				}
			}
			if (GetTickCount() - KeyTime > 1000)
			{
				fortime3 = true;
			}
		}

		if (fortime3 == true)
		{
			if (plusorminus == false)
				vibration++;
			else if (plusorminus == true)
				vibration--;
			if (vibration > 3)
				plusorminus = true;
			if (vibration < -3)
				plusorminus = false;
		}

		if (aaa4 == false && fortime3==true)
		{
			KeyTime = GetTickCount();
			aaa4 = true;
		}

		if (feelingiscoming == true && fortime4 == false&&aaa4==true) 
		{
			if (KeyDown(VK_SPACE))
			{
				if (GetTickCount() - KeyTime > 200)
				{
					startnewgame = true;
					feelingiscoming = false;
				}
			}
			if (GetTickCount() - KeyTime > 800) // 느낌표가 떴는데 스페이스바 안누름? -> fail
			{
				fortime4 = true;
				sound.m_Game->Stop();	
				sound.m_splash->Stop();	
			}

		}
		if(fortime4==true&&feelingiscoming==true)
			failfishing = true;

	}

	if (startnewgame == true)
	{
		comeonfish.Update();
		sound.m_Game->Stop();
		sound.m_splash->Stop();
		sound.m_fishing->Play(0, DSBPLAY_LOOPING);
		sound.m_spin->Play(0, DSBPLAY_LOOPING);
	}

	
	//if (signalforfish == true && fish.catchfishloc == true) // 물고기가 미끼의 위치로 이동
	//{
	//	if (baitx - fish.control_x >=0)
	//		fish.control_x += 0.5;
	//	else if (baitx - fish.control_x <= 0)
	//		fish.control_x -= 0.5;
	//	if(baity- fish.control_y+90 <=0)
	//		fish.control_y -= 0.2;
	//}
	
	if (power.startfishing == true&& failfishing==false&& signalforfish==true&& successfishing==false&& startnewgame==false)  //컨트롤바 안에 물고기의 움직임
	{

		if (aaa == false)
		{
			KeyTime = GetTickCount();
			aaa = true;
		}

		if (power.startfishing == true && fortime == false) 
		{
			if (GetTickCount() - KeyTime > 3000) //3초만 기다렸다가 시작 
			{
				fortime = true;
			}
		}

		if (fortime) // 3초 지난뒤 물고기가 움직임
		{
			float fishspeed;
			int randomdirection;

			if (GetTickCount() - KeyTime2 > 50)  // 난이도 조절부분
			{
				if(map.m_Stage==1) 
					fishspeed = rand() % 3 + 1;
				else if(map.m_Stage==2)
					fishspeed = rand() % 4 + 1;
				else if (map.m_Stage == 3)
					fishspeed = rand() % 5 + 1;

				randomdirection = rand() % 2;
				if (randomdirection == 0)
					if (randomfish_x == 475)
						randomfish_x = randomfish_x;
					else
						randomfish_x -= fishspeed;
				if (randomdirection == 1)
					if (randomfish_x == 825)
						randomfish_x = randomfish_x;
					else
						randomfish_x += fishspeed;

				KeyTime2 = GetTickCount();
			}
			


			if (randomfish_x < controlbar_x)  // 컨트롤바에 고기가 닿을경우 실패
				failfishing = true;
			if (randomfish_x + 48 > controlbar_x + 100 + fishrodwidth)
				failfishing = true;

			if (aaa5 == false)
			{
				KeyTime = GetTickCount();
				aaa5 = true;
			}

			if (aaa5=true&&fortime==true)  
			{
				if (GetTickCount() - KeyTime > 5000)  // 여기부분을 수정하면 몇초동안버텨야성공할지 수정가능// 난이도 수정 :
				{
					successfishing = true;
				}
			}
		}




		if (KeyDown(VK_LEFT)&&signalforfish==true)   
			controlbar_x--;

		if (KeyDown(VK_RIGHT)&&signalforfish==true)
			controlbar_x++;


	}

	if (failfishing == true)   //낚시실패시 실패로고띄우고 리셋
	{


		drop_y = 159;//놓침

		if (aaa6 == false)
		{
			KeyTime = GetTickCount();
			aaa6 = true;
		}

		if (aaa6 = true)
		{

			if (GetTickCount() - KeyTime > 2000)  //
			{
				if (soundcount == true)	// 수정
				{
					sound.m_fishing->Stop();
					sound.m_spin->Stop();
					sound.m_fail->Play(NULL);
					soundcount = false;
				}

				drop_y = drop_y;
				retry = true;
				soundcount = true;
			}
		}
			


	}
	if (successfishing == true)  //낚시 성공시 성공로고 띄우고 리셋
	{
		//			if (fish.control_x >= -300 && fish.control_x<1300)
		//				fish.control_x += 5;

		drop_y = 159;//잡힘

		if (soundcount == true)	
		{
			sound.m_fishing->Stop();
			sound.m_spin->Stop();
			sound.m_success->Play(NULL);
			soundcount = false;
		}
		if (aaa6 == false)
		{
			KeyTime = GetTickCount();
			//	checkfish = rand() % 100;
			if (quest.missionnum1 == true)
			checkfish = 16; //난이도 수정 //수정

			if (quest.missionnum2 == true)
			checkfish = 81; //난이도 수정 //수정

			if (quest.missionnum3 == true)
			checkfish = 41; //난이도 수정 //수정

			aaa6 = true;
		}

		if (aaa6 == true)
		{

			if (GetTickCount() - KeyTime > 1000)  
			{
				showfish = true;
			}
		}  

		if (showfish == true)
		{
			if (checkfish < 15)//쓰레기일확률(모든맵)
			{
				if (aaa7 == false)
				{
					item.GetItem(9, 1);
					aaa7 = true;
					soundcount = true;
				}
			}

			if (map.m_Stage == 1)//계곡일경우
			{
				if (checkfish >= 15 && checkfish < 55) //붕어확률
				{
					if (aaa7 == false)
					{
						item.GetItem(1, 1);
						if (quest.missionnum1 == true && quest.count < 10)
						{
							quest.count++;
						}
						aaa7 = true;
					}
				}

				if (checkfish >= 55 && checkfish < 80)  //가재확률 
				{
					if (aaa7 == false)
					{
						item.GetItem(3, 1);
						aaa7 = true;
					}
				}
				if (checkfish >= 80 && checkfish < 100) //장어추가
				{
					if (aaa7 == false)
					{
						item.GetItem(2, 1);
						aaa7 = true;
					}
				}
			}

			if (map.m_Stage == 2)//호수일경우
			{
				if (aaa7 == false)
				{
					if (checkfish >= 15 && checkfish < 55) //개구리확률
					{
						item.GetItem(5, 1);
					}

					if (checkfish >= 55 && checkfish < 80)  //빙어확률 
					{
						item.GetItem(4, 1);
					}
					if (checkfish >= 80 && checkfish < 100) //잉어확률
					{
						item.GetItem(6, 1);
						if (quest.missionnum2 == true && quest.count < 10)
						{
							quest.count++;
						}
					}
					aaa7 = true;
				}
			}
			if (map.m_Stage == 3)//바다일경우
			{
				if (aaa7 == false)
				{
					if (checkfish >= 15 && checkfish < 40) //문어확률
					{
						item.GetItem(7, 1);
					}

					if (checkfish >= 40 && checkfish < 60)  //연어확률 
					{
						item.GetItem(11, 1);
						if (quest.missionnum3 == true && quest.count < 10)
						{
							quest.count++;
						}
					}
					if (checkfish >= 60 && checkfish < 80) //상어확률
					{	
						item.GetItem(8, 1);
					}
					if (checkfish >= 80 && checkfish < 100) //참치확률
					{
						item.GetItem(10, 1);
					}
					aaa7 = true;
					inventory.Reset();
				}
			}
			

			if (KeyDown(VK_RETURN))
			{
				sound.m_confirm->Play(NULL);
				if (GetTickCount() - KeyTime > 200)
					retry = true;

				KeyTime = GetTickCount();
			}
			
		}
		
	}

	if (retry == true&& failfishing==true )  // 낚시실패시 리셋시키는부분
	{
		waitingtime = rand() % 15000 + 6000;
		signalforfish=false;// 물고기에게 잡히라는 신호를 줌
		fishbitebait = false;


		fortime = false;//시간관리용
		fortime2 = false;//시간관리용
		fortime3 = false;
		fortime4 = false;

		aaa = false;
		aaa2 = false;
		aaa3 = false;
		aaa4 = false;
		aaa5 = false;
		aaa6 = false; 
		feelingiscoming = false;
		plusorminus = false;
		drop_y = 0;
		soundcount = true;

		randomfish_x = 618;

		option.tabhold = false;
		//파워바 관련 리셋----------------
		power.plusorminus = false;
		power.startfishing = false;
		power.startpowering = false;
		power.pointer_y = 480;
		power.pos = 0;
		//--------------------------------

		//추가된게임 관련 리셋-------------------------------
		startnewgame = false;
		comeonfish.aaa = false;
		comeonfish.aaa1 = false;
		comeonfish.fish_x = 900;
	
		//------------------------------

		power.KeyTime = GetTickCount();

		fish.catchfishloc=false;	
		retry = false;
		failfishing = false;
	}
	if (retry == true && successfishing == true)  // 낚시성공시 리셋시키는부분
	{
		waitingtime = rand() % 15000 + 6000;
		power.plusorminus = false;
		power.startfishing = false;
		power.startpowering = false;
		power.pointer_y = 480;
		power.pos = 0;

		drop_y = 0;


		soundcount = true;
		signalforfish = false;// 물고기에게 잡히라는 신호를 줌
		fishbitebait = false;


		fortime = false;//시간관리용
		fortime2 = false;//시간관리용
		fortime3 = false;
		fortime4 = false;

		//추가된게임 관련 리셋-------------------------------
		startnewgame = false;
		comeonfish.aaa = false;
		comeonfish.aaa1 = false;
		comeonfish.fish_x =900;

		//------------------------------


		power.KeyTime = GetTickCount();
		aaa = false;
		aaa2 = false;
		aaa3 = false;
		aaa4 = false;
		aaa5 = false;
		aaa6 = false;
		aaa7 = false;

		feelingiscoming = false;
		plusorminus = false;
		showfish = false;
		randomfish_x = 618;
		option.tabhold = false;

		fish.catchfishloc = false;
		retry = false;
		successfishing = false;
	
	}
	//-----------아이템, 맵에따른 난이도 수정부분 -----------------------------

	if (inventory.usingfishrodcode == 0)  // 사용중인 낚시대에 따라 충돌처리범위 수정
		fishrodwidth = 0;
	else if (inventory.usingfishrodcode == 15)
		fishrodwidth = 50;
	else if (inventory.usingfishrodcode == 16)
		fishrodwidth = 80;

	//-------------------------------------------------------------------------
}

void Fishing::Draw()
{
	if (power.startfishing== true && signalforfish == true) 
	{
		controlbar.Render(475, 50, 0, 1, 1);
		if(inventory.usingfishrodcode==0)  // 사용자가 쓰고있는 낚시대에 따라 컨트롤바 크기가 달라짐.
			controlbarinside.Render(controlbar_x, 43, 0, 1, 1);
		if(inventory.usingfishrodcode==15)
			fishrod.Render(controlbar_x, 43, 0, 1, 1);
		if (inventory.usingfishrodcode ==16)
			goodfishrod.Render(controlbar_x, 43, 0, 1, 1);
		randomfish.Render(randomfish_x, 43, 0, 0.5, 0.5);
	}


	if (startnewgame == true)
		comeonfish.Draw();

	if (failfishing == true)
		fail.Render(450, drop_y + 150, 0, 1.5, 1.5);

	if (feelingiscoming == true)
		exclamation.Render(baitx - 24 + vibration, baity - 48, 0, 0.5, 0.5);

	//if(successfishing==true)
	//	success.Render(450, drop_y, 0, 2, 2);//수정


	if (showfish == true)
	{
		frame_showfish.Render(390, 134, 0, 1, 1);
		//showfishok.Render(540, 530, 0, 1, 1);//수정
		success.Render(450, drop_y, 0, 2, 2);
		textpressenter.Render(450, 460, 0, 1.9, 1.9);


		if (checkfish < 15)//쓰레기일확률(모든맵)
		{
			//인벤토리에 쓰레기를 +1하고 쓰레기 사진 보여주는 코드 추가해야할 부분
			item.DrawItem(9, 545, 280, 3, 3);
			/*item.Showname(9, 590, 450);*/
			texttrash.Render(440, 400, 0, 2, 2);
			if (aaa == false)
			{
				aaa7 = true;
			}
		}
		
		if (map.m_Stage == 1)//계곡일경우
		{
			if (checkfish >= 15 && checkfish < 55) //붕어확률
			{
				item.DrawItem(1, 545, 280, 3, 3);
				/*item.Showname(1, 590, 450);*/
				textcruciancarp.Render(440, 400, 0, 2, 2);
				//붕어 인벤토리 추가 코드 
			}

			if (checkfish >= 55 && checkfish < 80)  //가재확률 
			{
				item.DrawItem(3, 545, 280, 3, 3);
				//item.Showname(3, 590, 450);
				textlopster.Render(440, 400, 0, 2, 2);
				//가재 추가
			}
			if (checkfish >= 80 && checkfish < 100) //장어추가
			{
				item.DrawItem(2, 545, 280, 3, 3);
				/*item.Showname(2, 590, 450);*/
				textjang.Render(440, 400, 0, 2, 2);
				//장어추가
			}
		}

		if (map.m_Stage == 2)//호수일경우
		{
			if (checkfish >= 15 && checkfish < 55) //개구리확률
			{
				item.DrawItem(5, 545, 280, 3, 3);
				/*item.Showname(5, 590, 450);*/
				textfrog.Render(440, 400, 0, 2, 2);
				//개구리 인벤토리 추가 코드 
			}

			if (checkfish >= 55 && checkfish < 80)  //빙어확률 
			{
				item.DrawItem(4, 545, 280, 3, 3);
				/*	item.Showname(4, 590, 450);*/
				textbing.Render(440, 400, 0, 2, 2);
			
				//빙어 추가
			}
			if (checkfish >= 80 && checkfish < 100) //잉어확률
			{
				item.DrawItem(6, 545, 280, 3, 3);
				/*	item.Showname(6, 590, 450);*/
				texting.Render(440, 400, 0, 2, 2);
				//잉어추가
			}
		}
		if (map.m_Stage == 3)//바다일경우
		{
			if (checkfish >= 15 && checkfish < 40) //문어확률
			{
				item.DrawItem(7, 545, 280, 3, 3);
				/*item.Showname(7, 590, 450);*/
				textocto.Render(440, 400, 0, 2, 2);
				//문어 인벤토리 추가 코드 
				if (aaa == false)
				{
					aaa7 = true;
					item.GetItem(9, 1);//수정은 아니고 원래 있던건데 이거 이상함 9번은 쓰레기인데
				}
			}

			if (checkfish >= 40 && checkfish < 60)  //연어확률 
			{
				item.DrawItem(11, 525, 190, 3, 3); //수정540,240
				/*item.Showname(11, 590, 450);*/
				textsalmon.Render(440, 400, 0, 2, 2);
			}
			if (checkfish >= 60 && checkfish < 80) //상어확률
			{
				item.DrawItem(8, 490, 220, 3, 3); //수정
				/*			item.Showname(8, 590, 450);*/
				textshark.Render(440, 400, 0, 2, 2);
			}
			if (checkfish >= 80 && checkfish < 100) //참치확률
			{
				item.DrawItem(10, 510, 180, 3, 3);//수정
				/*item.Showname(10, 590, 450);*/
				texttuna.Render(440, 400, 0, 2, 2);
			}
		}
	}



}

