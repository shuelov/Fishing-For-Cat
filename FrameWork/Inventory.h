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



	int money; //������ ��
	int i,j;

	int frame;
	int nowpage;
	int totalpage;
	int morethanzero; // 0���� ���� ���� �ִ� �������� ����
	int codeframe[16]; // 0���� ���� ���� �ִ� �������� �ڵ带 �迭�� �����Ѵ�


	int usingbaitcode; //����ϰ��ִ� �̳� �ڵ� 
	int usingfishrodcode; // ����ϰ��ִ� ���ô� �ڵ�

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
	void Reset(); // �κ��丮�� ������ �������, �����Ͽ� �κ��丮�� �ٽñ׸���.
	void PosSetting(int _pos, int _x, int _y);

};

extern Inventory inventory;