#pragma once
#include "Include.h"


class Power

{


public:
	Power(void);
	~Power(void);
	Sprite powerbar; //파워바
	Sprite pointer; //화살표

	Sprite line_right_178; //낚시줄 이미지 
	Sprite line_right_356;
	Sprite line_right_600;

	Sprite line_left_178;
	Sprite line_left_356;
	Sprite line_left_600;



	DWORD KeyTime; // 시간관리용 변수


	float fishingline_x;  // 낚시줄이미지가 시작될 x좌표
	float fishingline_y;   // 낚시줄 이미지가 시작될 y좌표 
	int pointer_y; //막대바 화살이 가르킬 y좌표

	bool plusorminus; // 화살표가 올라갈지 내려갈지 결정함
	bool startfishing; //낚싯줄을 던진후에 본격적인 fishing의 시작
	bool startpowering;  //물고기를 낚은후에 false 로 바꿀거임/ 스페이스를 다시눌러도 파워바가 안뜨게 해줄변수 

	int pos;  // 막대바의 상태. 0 일경우 스톱 1일경우 움직임

	int howmuchpower;  // 낚시줄 던질 파워 1.제일낮음-178 2.중간-356 3.제일큼-600

	int direction; //낚시대를 던지는 방향 1.왼쪽 2. 오른쪽

	void Init();
	void Update();
	void Draw();
	void Changecal(); // 막대가 한계에 다다르면 계산을 바꿔줄함수

};

extern Power power;