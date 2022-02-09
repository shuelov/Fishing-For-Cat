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


	DWORD KeyTime; // �ð�������


	int scene1;	// ��� ����1
	int scene2;	// ��� ����2

	float move1; // �̹��� ������1
	int move2; // �̹��� ������2
	int move3; // �̹��� ������3
	int move4; // �̹��� ������4


	bool transfer;
	bool move = true;


	bool direction1;  // �̹��� �̵� ���� ����1
	bool direction2;  // �̹��� �̵� ���� ����2
	bool direction3;  // �̹��� �̵� ���� ����3
	bool direction4;  // �̹��� �̵� ���� ����4

	int turn1;	// �̹��� ����1
	int turn2;	// �̹��� ����2
	int turn3;	// �̹��� ����3


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