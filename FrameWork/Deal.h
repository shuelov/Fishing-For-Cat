#pragma once
#include "Include.h"

class Deal
{
public:
	Deal();
	~Deal();

	Sprite dealer;
	Sprite dealers_bag;
	Sprite dealers_itemframe1;
	Sprite dealers_itemframe2;
	Sprite dealers_itemframe3;
	Sprite dealers_left;
	Sprite dealers_right;

	Sprite bag;
	Sprite mybag;
	Sprite myitemframe1;
	Sprite myitemframe2;
	Sprite myitemframe3;
	Sprite myleft;
	Sprite myright;

	Sprite purchase;
	Sprite sell;
	Sprite cancle;

	Sprite pointer;

	Sprite askrealbuy;
	Sprite askrealsell;
	Sprite okay;

	Sprite money;

	Sprite deal_confirm;
	Sprite deal_cancel;
	Sprite deal_problem;




	bool soundcount;

	bool reallysell;  // ��¥ �Ȱųİ� ����� true�Ǵ� 
	bool reallybuy; // ��¥ ��ųİ� ����� true �Ǵ� 
	bool changepos; //��¥�Ұųİ� ����� ���
	bool notenoughmoney;
	bool successbuy;
	bool successsell;
	bool aaa1;
	bool aaa2;
	bool savepointer;



	bool bbb1;
	bool bbb2;
	DWORD KeyTime;
	int pointer_x, pointer_y; // ȭ��ǥ��ǥ
	int pointer_pos;  // ȭ��ǥ�� �ִ� ��ġ��ȣ

	int priceofproduct; // ������ �������� ����
	int numberofproduct; // ������ ������ ��ȣ

	int dealer_page; // ���� ������
	int my_page; // ���κ��丮 ������ 

	
	int temp; //������ �������� ��������ġ�� ����


	RECT q_rc;
	char str[100];

	void Init();
	void Update();
	void Draw();

	void PosSetting(int _pos, int _x, int _y);

	void Reset(); //���Ű� ���������ʰų� ��ҵɽ� �ʱ�ȭ��Ű�� �Լ�
};

extern Deal deal;