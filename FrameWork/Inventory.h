#pragma once

class Inventory
{


public:
	Sprite inventory_frame;
	Sprite item_frame;
	Sprite item_frame2;
	Sprite item_frame3;
	Sprite inventory_page_right;
	Sprite inventory_page_left;

	Sprite goback;
	Sprite pointer;
	Sprite coin;



	int money; //소유한 돈
	int i,j;

	int frame;
	int nowpage;
	int totalpage;
	int morethanzero; // 0보다 많이 갖고 있는 아이템의 갯수
	int codeframe[16]; // 0보다 많이 갖고 있는 아이템의 코드를 배열에 저장한다


	int usingbaitcode; //사용하고있는 미끼 코드 
	int usingfishrodcode; // 사용하고있는 낚시대 코드

	bool justonetime[16];
	bool stStop;
	RECT q_rc;
	char str[100];
	
	int pointer_pos;

	int pointer_x;
	int pointer_y;

	bool aaa1;
	bool aaa;

	DWORD KeyTime; 

	Inventory(void);
	~Inventory(void);
	void Init();
	void Update();
	void Draw();
	void Reset(); // 인벤토리의 변경이 있을경우, 리셋하여 인벤토리를 다시그린다.
	void PosSetting(int _pos, int _x, int _y);

};

extern Inventory inventory;