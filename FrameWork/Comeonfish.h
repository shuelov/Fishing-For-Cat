
#pragma once
#include "Include.h"

class Comeonfish
{
public:


	// ------------------- 새게임추가 -----------------
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

	int pointer_y; // 바를 가리키는 화살표의 y좌표. 
	int fish_x; // 물고기의 x좌표

	bool plusorminus; //화살표가 올라갈것인가 내려갈것인가

	int speed; // 왔다갔다거리는 스피드 조절
	DWORD KeyTime;
	Comeonfish();
	~Comeonfish();

	void Init();
	void Update();
	void Draw();
};

extern Comeonfish comeonfish;