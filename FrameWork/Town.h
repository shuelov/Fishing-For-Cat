#pragma once
#include "Include.h"

class Town : public Chap
{

public:
	Town();
	//Town(int stage);
	~Town();

	float speed;
	float alpha;


	Sprite town_cloud[99]; // ����

	int scene;					// �̹��� ��� ����
	int direction;				// �̹��� ���� ����

	int m_town;
	bool once;//����
	Sprite town_fishshop;
	Sprite town_day;
	Sprite town_night;


	DWORD KeyTime;			// �ð�������

	bool show;					//ĳ���� show
	bool op;						//��� �ɼ��� ���� ����
	bool dealon;

	bool transfer;

	RECT m_rc;
	double m_Left;
	double m_High;
	char str[100]; //���ڿ�

	 /*Seller npc;*/
	bool travel;
	float distance;

	virtual void Init();
	virtual void Update(double frame);
	virtual void Draw();
	virtual void OnMessage(MSG* msg);
};

extern Town town;