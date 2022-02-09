#pragma once

class Quest
{


public:
	bool once;//수정함

	int count; // 물고기 몇 개 잡았는지 계산할 때. 미션하나 완료해서 다음 미션들어갈 때 리셋하기


	Sprite mission1img;
	Sprite mission2img;
	Sprite mission3img;
	Sprite missionfinishimg;


	bool missionnum1; //미션1
	bool missionnum2; //미션2
	bool missionnum3; //미션3
	bool missionfinish; //미션완료
	int resetcount = 0;//카운트초기화

	int num_mission = 1;


	DWORD KeyTime; // 시간관리용

	Sprite mission;

	bool check;  //퀘스트 완료여부 false일때는 진행중, true일때는 완료

	RECT q_rc;

	char str[100]; //문자열

	Quest(void);
	~Quest(void);

	void Init();
	void Update();
	void Draw();

};

extern Quest quest;