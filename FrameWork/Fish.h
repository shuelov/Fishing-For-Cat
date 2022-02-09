
#pragma once
#include "Include.h"

class Fish
{

public:
	Fish();
	~Fish();

	DWORD KeyTime;
	int i, j, k; //좌표 변경용
	int speed, speed2, speed3;  //물고기 스피드 

	bool plusorminus, plusorminus2, plusorminus3;  //물고기 방향변경용

	bool catchfishloc;

	int x, y; // 물고기 위치
	int x2, y2;
	int x3, y3;


	float control_x, control_y;
	int pos1; //물고기의 상태. 1.왼쪽을 보며돌아다닌다. 2.오른쪽을 보면서 다닌다.  3.미끼쪽으로 다가간다.
	int pos2;
	int pos3;

	Sprite randomfish_left1;
	Sprite randomfish_left2;
	Sprite randomfish_left3;

	Sprite randomfish_right1;
	Sprite randomfish_right2;
	Sprite randomfish_right3;

	Sprite valley_ston;


	void Init();
	void Update();
	void Draw();


};

extern Fish fish;
