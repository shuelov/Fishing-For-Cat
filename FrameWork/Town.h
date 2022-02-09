#pragma once
#include "Include.h"

class Town : public Chap
{

public:
	Town();
	//Town(int stage);
	~Town();

	float speed;
	float alpha;


	Sprite town_cloud[99]; // 수정

	int scene;					// 이미지 장면 변경
	int direction;				// 이미지 방향 변경

	int m_town;
	bool once;//수정
	Sprite town_fishshop;
	Sprite town_day;
	Sprite town_night;


	DWORD KeyTime;			// 시간관리용

	bool show;					//캐릭터 show
	bool op;						//장소 옵션을 위해 넣음
	bool dealon;

	bool transfer;

	RECT m_rc;
	double m_Left;
	double m_High;
	char str[100]; //문자열

	 /*Seller npc;*/
	bool travel;
	float distance;

	virtual void Init();
	virtual void Update(double frame);
	virtual void Draw();
	virtual void OnMessage(MSG* msg);
};

extern Town town;