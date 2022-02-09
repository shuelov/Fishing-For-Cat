#pragma once

#ifndef __Option_H__
#define __Option_H__

class Option : public Chap
{

	/////////////////
	Sprite mission;					//퀘스트용메뉴
	Sprite menuimg;				//옵션메뉴
	Sprite invenimg;				//가방메뉴

	Sprite pointer;					//포인터

	Sprite menupopupimg;		//메뉴팝업
	Sprite saveimg;					//저장하기버튼
	Sprite optionimg;				//설정버튼
	Sprite exitimg;					//종료버튼
	Sprite gobackimg;				//뒤로가기버튼
	

	Sprite saving;					//저장슬롯

	Sprite okimg;					//확인버튼
	Sprite cancelimg;				//취소버튼


	Sprite valleybutton;
	Sprite lakebutton;
	Sprite seabutton;

	Sprite unable_lake;			//호수잠김
	Sprite unable_sea;				//바다잠김

	Sprite cannotgo;				//"아직 갈 수 없음"
	Sprite opennewplace;			//"새로운 장소 열림"



	Sprite beach_goback;

	Sprite sound0p;				//음량조절 0%
	Sprite sound50p;				//음량조절 50%
	Sprite sound100p;				//음량조절 100%

	Sprite save1_text;
	Sprite save2_text;
	Sprite save3_text;

	Sprite savedimg;
	Sprite saveselected;

public:
	
	int pointer_pos;
	int pointer_x;
	int pointer_y;

	bool checkinventory;

	bool temp;

	bool pause; // 탭을 눌렀을때 고양이 스톱, 왼쪽위에 포인터 보이기
	bool turnonmenu;// 메뉴 on / off
	bool stopthecat;  // 고양이를 멈추게할 스위치
	bool tabhold;
	bool saveframeon;
	bool dealon;

	bool soundon;  //옵션- 사운드설정
	bool placeon; // m 눌렀을때 나오는 장소이동
	bool queston; // 퀘스트온
	bool mute;
	bool halfsound;
	bool fullsound;
	bool place1;
	bool place2;
	bool place3;

	bool unlocklake;	//기본값 false일 시 계곡만 갈수있는 상태, 호수랑 바다는 잠김. true일시 호수도 갈 수 있음
	bool unlocksea;	//기본값 false일 시 계곡과 호수만 갈 수 있음, 바다는 잠김. true일 시 다 갈 수 있음

	bool showerrormsg;//"아직 갈 수 없음"
	bool shownewmsg;//"새로운 장소 열림"
	bool msgonoff;


	float timeflow = 0;
	float speed = 3000;


	int nottwotime;

	bool aaa;
	bool save_ok;
	bool save1;
	bool save2;
	bool save3;


	DWORD KeyTime;

	Option();
	~Option();

	virtual void Init();
	virtual void Update(double frame);
	virtual void Draw();

	virtual void OnMessage(MSG* msg);

	void PosSetting(int _pos, int _x, int _y);
};

extern Option option;
#endif