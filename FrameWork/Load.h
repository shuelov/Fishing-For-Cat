#pragma once

class Load
{
	Sprite Menuimg[2];
public:
	Load(void);
	~Load(void);

	// ������ ���̽� �׽�Ʈ
	int count = 0;
	char cnt[256];
	char pw[256];


	void Init();
	void Update();
	void Draw();


	/////////////////////////db test
	void load();
	void load1();
	void load2();
	void load3();


};

extern Load load;