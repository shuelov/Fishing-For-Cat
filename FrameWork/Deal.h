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

	bool reallysell;  // 진짜 팔거냐고 물어볼때 true되는 
	bool reallybuy; // 진짜 살거냐고 물어볼때 true 되는 
	bool changepos; //진짜할거냐고 물어볼때 물어볼
	bool notenoughmoney;
	bool successbuy;
	bool successsell;
	bool aaa1;
	bool aaa2;
	bool savepointer;



	bool bbb1;
	bool bbb2;
	DWORD KeyTime;
	int pointer_x, pointer_y; // 화살표좌표
	int pointer_pos;  // 화살표가 있는 위치번호

	int priceofproduct; // 구매할 아이템의 가격
	int numberofproduct; // 구매할 아이템 번호

	int dealer_page; // 상점 페이지
	int my_page; // 내인벤토리 페이지 

	
	int temp; //아이템 선택전의 포인터위치를 저장


	RECT q_rc;
	char str[100];

	void Init();
	void Update();
	void Draw();

	void PosSetting(int _pos, int _x, int _y);

	void Reset(); //구매가 성립되지않거나 취소될시 초기화시키는 함수
};

extern Deal deal;