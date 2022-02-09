#pragma once
//#include <windows.h>
//#include <mmsystem.h>
#include "Include.h" 
const int TICKS_PER_SECOND = 60;
const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
const int MAX_FRAMESKIP = 5;
int loops;
float interpolation;
// 버퍼 추가
char buffer[128] = {0,0,0,0};
char ch[3] = {0,0,0}; //D  strcat_s 사용법 틀림 최소 널이 들어갈수 있도록 해줘야함
////////////////////////////////////
LRESULT CALLBACK WndProc( HWND g_hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	WNDCLASSEX wc ;
	HWND g_hWnd ;
	wc.hInstance = GetModuleHandle( NULL ) ;
	wc.cbSize = sizeof( wc ) ;
	wc.style = CS_CLASSDC ;
	wc.cbClsExtra = NULL ;
	wc.cbWndExtra = NULL ;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH) ;
	wc.hCursor = LoadCursor( wc.hInstance, IDC_ARROW ) ;
	wc.hIcon = LoadIcon( wc.hInstance, IDI_APPLICATION ) ;
	wc.hIconSm = LoadIcon( wc.hInstance, IDI_APPLICATION ) ;
	wc.lpfnWndProc = WndProc ;
	wc.lpszClassName ="Game" ;
	wc.lpszMenuName = NULL ;

	RegisterClassEx( &wc ) ;

	/* ---------------------------------------------------
	/////////////////// 정가운데 출력 ////////////////////

				프로그램을 모니터의 정가운데
				출력하게 해 주는 코드입니다.

	//////////////////////////////////////////////////////
	----------------------요-기-서-부-터-----------------*/
	RECT rt = {0, 0, SCREEN_WITH, SCREEN_HEIGHT};
	int W = rt.right - rt.left;
	int H = rt.bottom - rt.top;
	int X = (GetSystemMetrics(SM_CXSCREEN)/2) - SCREEN_WITH/2;
	int Y = ( (GetSystemMetrics(SM_CYSCREEN)/2) - SCREEN_HEIGHT/2 );
	/*---------------------요-기-까-지-------------------*/

	g_hWnd = CreateWindowEx( NULL, wc.lpszClassName, 
		"Fishing 4 Cat", 
		WS_EX_TOPMOST | WS_POPUP,
		X, Y, W, H,
		NULL, NULL, wc.hInstance, NULL ) ;


	dv_font.Create(g_hWnd);
	sound.g_pSoundManager = new CSoundManager();                           //사운드 매니저 생성
	sound.g_pSoundManager->Initialize(g_hWnd, DSSCL_PRIORITY);            //사운드 매니저 초기화
	sound.g_pSoundManager->SetPrimaryBufferFormat(2, 22050, 16);			// 사운드 버퍼 포맷 설정 ( 채널수, 음질, 비트수)

	
	//g_SoundManager.Initialize(g_hWnd, DSSCL_PRIORITY);
	//g_SoundManager.SetPrimaryBufferFormat(2,22050,16);

	ShowWindow( g_hWnd, SW_SHOW ) ;
	UpdateWindow( g_hWnd ) ;
	ShowCursor(FALSE);    //마우스 커서 날리는 함수 FALSE 일시 커서날라감
	 
	///////////////////////////////////////////////////////////////////
	ZeroMemory(&msg, sizeof(MSG));
	//TRACE("REV ====== %s ========= \n\n", buffer);
	/////////// 챕터 초기화 /////////////////
	g_Mng.chap[LOGO] = new Logo;
	g_Mng.chap[MENU] = new Menu; //로비
	g_Mng.chap[NEWGAME] = new Game; //게임 화면
	g_Mng.chap[STORY] = new Story; //스토리 화면
	g_Mng.chap[OVER] = new Over;
	g_Mng.chap[TOWN] = new Town;
	g_Mng.chap[OPTION] = new Option;	//옵션

	/////////////////////////////////////////

	for(int i=0; i<TOTALCHAP; i++)
		g_Mng.chap[i]->Init();

	while( msg.message != WM_QUIT )
	{
		if(PeekMessage(&msg,NULL,0,0,PM_NOREMOVE))
		{
			if(GetMessage(&msg, NULL, 0, 0))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			
			static DWORD next_game_tick = GetTickCount();
			static DWORD next_game_tick1 = GetTickCount();


			
			loops = 0;
		
			static int aa;
			bool b = false;

			while( GetTickCount() > next_game_tick && loops < MAX_FRAMESKIP) 
			{
				interpolation = float( GetTickCount() + SKIP_TICKS - next_game_tick ) / float( SKIP_TICKS );
				/*if(Gmanager.m_Pause == false)*/ g_Mng.chap[g_Mng.n_Chap]->Update(interpolation);
				if(b == false)
				{
					aa = interpolation;
					b = true;
				}
				g_Mng.chap[g_Mng.n_Chap]->OnMessage(&msg);
				next_game_tick += SKIP_TICKS;
				loops++;
			}

			

			dv_font.Device9->BeginScene();
			dv_font.Device9->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 255, 255), 0, 0);


			g_Mng.chap[g_Mng.n_Chap]->Draw();

			dv_font.Device9->EndScene();
			dv_font.Device9->Present(NULL, NULL, NULL, NULL);
			
		}
	}

	return msg.wParam;

}

LRESULT CALLBACK WndProc( HWND g_hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	switch( uMsg )
	{

	case WM_DESTROY:
         PostQuitMessage( 0 );
         return 0;
	case WM_CHAR:
		 ch[0] = wParam;
		 strcat_s( buffer,ch);
		  if( strstr( buffer,"p") != NULL ) 

			if(GetTickCount() - key.KeyTime > 200)
			{
				//Gmanager.m_Pause = !Gmanager.m_Pause;

				key.KeyTime = GetTickCount();
			}
			//else if (strstr(buffer, "s") != NULL)
			//{
			//	// 데이타 베이스 저장
			//	sql.save();
			//}
        ZeroMemory( &buffer, sizeof(buffer) );
		break;

	case WM_KEYDOWN:
		if (wParam == VK_SPACE)
		{
			if (option.pointer_pos == 11)//확인 눌렀을때
			{

				option.save_ok = true;
				sound.m_confirm->Play(NULL);

				if (option.save1 == true)
					sql.save();
				else if (option.save2 == true)
					sql.save2();
				else if (option.save3 == true)
					sql.save3();

		/*		option.save1 = false;
				option.save2 = false;
				option.save3 = false;*/
				//MessageBox(NULL, TEXT("물약"), TEXT("물약"), MB_OK);
			}

		}




	}
	return DefWindowProc( g_hWnd, uMsg, wParam, lParam ) ;
}
