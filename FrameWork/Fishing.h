
#pragma once
#include "Include.h"


class Fishing
{


public:
	bool aaa;
	bool aaa2;
	bool aaa3;
	bool aaa4;
	bool aaa5;
	bool aaa6;
	bool aaa7;

	bool soundcount;
	bool dontstop;


	int waitingtime; // ����Ⱑ ��������� ��ٸ��ð� (�������� �Ұ���)
	int vibration;
	int checkfish; // ��������� üũ��
	int fishrodwidth; //���ô� �ٸ��Ų����� �浹 ó�� �߰� ����

	DWORD KeyTime;
	DWORD KeyTime2;
	bool signalforfish;// ����⿡�� ������� ��ȣ�� ��
	bool fishbitebait;

	
	bool startnewgame;


	bool failfishing; //���� �����ϰ�� 
	bool fortime;//�ð�������
	bool fortime2;//�ð�������
	bool fortime3; 
	bool fortime4; 

	bool feelingiscoming;
	bool retry;
	bool plusorminus;
	bool successfishing;
	bool showfish;
	
	bool justoneitem;

	float baitx; float baity; // �̳� ��ġ
	float controlbar_x; // ��Ʈ�ѹ� ��ġ
	float randomfish_x; // ��Ʈ�ѹٿ� �ִ� ����� ��ġ
	float drop_y;

	Sprite controlbar;
	Sprite controlbarinside;
	Sprite randomfish;
	Sprite success;
	Sprite fail;

	Sprite exclamation;
	Sprite frame_showfish;
	Sprite showfishok;
	Sprite fishrod;
	Sprite goodfishrod;

	//"?? ȹ��!"�̹���
	Sprite textbing;
	Sprite textcruciancarp;
	Sprite textfrog;
	Sprite texting;
	Sprite textjang;
	Sprite textlopster;
	Sprite textsalmon;
	Sprite textshark;
	Sprite texttrash;
	Sprite texttuna;
	Sprite textocto;

	Sprite textpressenter;

	// ------------------- �������߰� -----------------
	Sprite bar_second;
	Sprite secondgameframe;
	Sprite game_fish;
	Sprite fishingline;
	// ------------------------------------------------
	Fishing(void);
	~Fishing(void);
	void Init();
	void Update();
	void Draw();


};

extern Fishing fishing;
