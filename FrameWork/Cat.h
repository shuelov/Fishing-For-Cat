#pragma once
#include "Include.h"

typedef struct Kitten
{
	double dx, dy, dz, drx, dry, drz;	// ��������
};

class Cat //���ΰ��� ���� ��ü 

{

	int pos; // ���ϴ� ��ġ 1.�⺻2.����3.������ 4.������


public:
	Cat(void);
	~Cat(void);
	int count = 0;
	RECT q_rc;
	char str[100]; //���ڿ�
	Kitten m_cat;

	float x = 640, y = 550; // ���������� ��ġ
	Sprite cat_front;
	Sprite cat_right[3];	
	Sprite cat_left[3];	

	Sprite cat_story2[2];

	Sprite fishing_cat;

	bool aboard;		//����̵���
	bool catmove;

	bool reset;			//�������� ����� ��ġ ����
	bool resetlake;		//ȣ������ ����� ��ġ ����
	bool resetsea;		//�ٴٿ��� ����� ��ġ ����

	int story2_aniCount;
	int story3_aniCount;
	bool direction;
	
	DWORD KeyTime1; //�ð��� 
	DWORD KeyTime2; 


	int leftcount;	
	int rightcount;

	void Init();
	void Update();
	void Draw();

	void UpdateStory2();
	void DrawStory2();
	
};

extern Cat cat;