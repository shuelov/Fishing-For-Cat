
#pragma once
#include "Include.h"

class Comeonfish
{
public:


	// ------------------- �������߰� -----------------
	Sprite bar_second;
	Sprite secondgameframe;
	Sprite game_fish;
	Sprite fishingline;
	Sprite pointer;

	// ------------------------------------------------

	Sprite perfect;
	Sprite good;
	Sprite bad;
	Sprite miss;

	bool showgrade;

	int grade; //1 : perfect 2. good 3. bad 4. miss
	bool aaa;
	bool aaa1;

	int pointer_y; // �ٸ� ����Ű�� ȭ��ǥ�� y��ǥ. 
	int fish_x; // ������� x��ǥ

	bool plusorminus; //ȭ��ǥ�� �ö󰥰��ΰ� ���������ΰ�

	int speed; // �Դٰ��ٰŸ��� ���ǵ� ����
	DWORD KeyTime;
	Comeonfish();
	~Comeonfish();

	void Init();
	void Update();
	void Draw();
};

extern Comeonfish comeonfish;