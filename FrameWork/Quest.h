#pragma once

class Quest
{


public:
	bool once;//������

	int count; // ����� �� �� ��Ҵ��� ����� ��. �̼��ϳ� �Ϸ��ؼ� ���� �̼ǵ� �� �����ϱ�


	Sprite mission1img;
	Sprite mission2img;
	Sprite mission3img;
	Sprite missionfinishimg;


	bool missionnum1; //�̼�1
	bool missionnum2; //�̼�2
	bool missionnum3; //�̼�3
	bool missionfinish; //�̼ǿϷ�
	int resetcount = 0;//ī��Ʈ�ʱ�ȭ

	int num_mission = 1;


	DWORD KeyTime; // �ð�������

	Sprite mission;

	bool check;  //����Ʈ �ϷῩ�� false�϶��� ������, true�϶��� �Ϸ�

	RECT q_rc;

	char str[100]; //���ڿ�

	Quest(void);
	~Quest(void);

	void Init();
	void Update();
	void Draw();

};

extern Quest quest;