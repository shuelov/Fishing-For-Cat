#pragma once

#include "Include.h"

Logo::Logo()
{
}

Logo::~Logo()
{
}

void Logo::Init()
{
	speed = 600;
	alpha = 0;

	loadimg.Create("./resource/Img/logo/logo.png", false, D3DCOLOR_XRGB(0, 0, 0));
	//g_SoundManager.Create(&Sound1, (LPWSTR)L"sound/hatnim.wav", 0, GUID_NULL);
	sound.InitEtc();
}

void Logo::Update(double frame)
{
	sound.PlayEtc();	
	alpha += speed * frame / 250;

	if( alpha >= 255 )
	{
		alpha = 255;
		speed = -speed;
	}

	if(alpha <= 0) {
		 g_Mng.n_Chap = MENU;
		 sound.StopEtc();
	}

}

void Logo::Draw()
{

	loadimg.SetColor(255,255,255, alpha);  // 색상 변경
	loadimg.Draw( 390 , 120 ) ;  //이미지출력
}

void Logo::OnMessage( MSG* msg )
{
}