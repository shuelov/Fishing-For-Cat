#pragma once
#include "Include.h"

typedef struct Kitten
{
	double dx, dy, dz, drx, dry, drz;	// 데미지존
};

class Cat //주인공에 대한 객체 

{

	int pos; // 향하는 위치 1.기본2.왼쪽3.오른쪽 4.낚시중


public:
	Cat(void);
	~Cat(void);
	int count = 0;
	RECT q_rc;
	char str[100]; //문자열
	Kitten m_cat;

	float x = 640, y = 550; // 마을에서의 위치
	Sprite cat_front;
	Sprite cat_right[3];	
	Sprite cat_left[3];	

	Sprite cat_story2[2];

	Sprite fishing_cat;

	bool aboard;		//장소이동용
	bool catmove;

	bool reset;			//마을에서 고양이 위치 리셋
	bool resetlake;		//호수에서 고양이 위치 리셋
	bool resetsea;		//바다에서 고양이 위치 리셋

	int story2_aniCount;
	int story3_aniCount;
	bool direction;
	
	DWORD KeyTime1; //시간용 
	DWORD KeyTime2; 


	int leftcount;	
	int rightcount;

	void Init();
	void Update();
	void Draw();

	void UpdateStory2();
	void DrawStory2();
	
};

extern Cat cat;