
#pragma once
#include "Include.h"

class Fish
{

public:
	Fish();
	~Fish();

	DWORD KeyTime;
	int i, j, k; //��ǥ �����
	int speed, speed2, speed3;  //����� ���ǵ� 

	bool plusorminus, plusorminus2, plusorminus3;  //����� ���⺯���

	bool catchfishloc;

	int x, y; // ����� ��ġ
	int x2, y2;
	int x3, y3;


	float control_x, control_y;
	int pos1; //������� ����. 1.������ ���絹�ƴٴѴ�. 2.�������� ���鼭 �ٴѴ�.  3.�̳������� �ٰ�����.
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
