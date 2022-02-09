#pragma once
#include "Include.h"

class Map
{

public :
	Map();
	Map(int stage);
	~Map();


	Sprite valley;
	Sprite lake;
	Sprite sea;

	Sprite valley_floor;
	Sprite valley_drop;


	Sprite lake_floor;
	Sprite lake_fish1[2];
	Sprite lake_fish2[2];
	Sprite lake_fish3;
	Sprite lake_wave;


	Sprite sea_floor;
	Sprite sea_sora1;
	Sprite sea_sora2;
	Sprite sea_sora3;
	Sprite sea_sora4;
	Sprite sea_turtle1;
	Sprite sea_turtle2;


	Sprite beach_goback;
	

	Sprite valley_ston;


	int m_Stage;


	DWORD KeyTime; // 시간관리용


	int scene1;	// 장면 변경1
	int scene2;	// 장면 변경2

	float move1; // 이미지 움직임1
	int move2; // 이미지 움직임2
	int move3; // 이미지 움직임3
	int move4; // 이미지 움직임4


	bool transfer;
	bool move = true;


	bool direction1;  // 이미지 이동 방향 변경1
	bool direction2;  // 이미지 이동 방향 변경2
	bool direction3;  // 이미지 이동 방향 변경3
	bool direction4;  // 이미지 이동 방향 변경4

	int turn1;	// 이미지 반전1
	int turn2;	// 이미지 반전2
	int turn3;	// 이미지 반전3


	int sel = 0;

	bool choose;


	bool changemap1;
	bool changemap2;
	bool changemap3;



	void Init();
	void Update(double frame);
	void Update();
	void Draw();
};

extern Map map;