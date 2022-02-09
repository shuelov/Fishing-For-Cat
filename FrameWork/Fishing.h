
#pragma once
#include "Include.h"


class Fishing
{


public:
	bool aaa;
	bool aaa2;
	bool aaa3;
	bool aaa4;
	bool aaa5;
	bool aaa6;
	bool aaa7;

	bool soundcount;
	bool dontstop;


	int waitingtime; // 물고기가 잡히기까지 기다릴시간 (랜덤으로 할거임)
	int vibration;
	int checkfish; // 잡힌물고기 체크용
	int fishrodwidth; //낚시대 다른거꼈을때 충돌 처리 추가 구간

	DWORD KeyTime;
	DWORD KeyTime2;
	bool signalforfish;// 물고기에게 잡히라는 신호를 줌
	bool fishbitebait;

	
	bool startnewgame;


	bool failfishing; //낚시 실패일경우 
	bool fortime;//시간관리용
	bool fortime2;//시간관리용
	bool fortime3; 
	bool fortime4; 

	bool feelingiscoming;
	bool retry;
	bool plusorminus;
	bool successfishing;
	bool showfish;
	
	bool justoneitem;

	float baitx; float baity; // 미끼 위치
	float controlbar_x; // 컨트롤바 위치
	float randomfish_x; // 컨트롤바에 있는 물고기 위치
	float drop_y;

	Sprite controlbar;
	Sprite controlbarinside;
	Sprite randomfish;
	Sprite success;
	Sprite fail;

	Sprite exclamation;
	Sprite frame_showfish;
	Sprite showfishok;
	Sprite fishrod;
	Sprite goodfishrod;

	//"?? 획득!"이미지
	Sprite textbing;
	Sprite textcruciancarp;
	Sprite textfrog;
	Sprite texting;
	Sprite textjang;
	Sprite textlopster;
	Sprite textsalmon;
	Sprite textshark;
	Sprite texttrash;
	Sprite texttuna;
	Sprite textocto;

	Sprite textpressenter;

	// ------------------- 새게임추가 -----------------
	Sprite bar_second;
	Sprite secondgameframe;
	Sprite game_fish;
	Sprite fishingline;
	// ------------------------------------------------
	Fishing(void);
	~Fishing(void);
	void Init();
	void Update();
	void Draw();


};

extern Fishing fishing;
