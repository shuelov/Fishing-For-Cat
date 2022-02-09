#pragma once

struct SysTem
{
	int m_Save1;
	int m_Save2;

};

class GameManager
{
	Sprite Menuimg[2];
public:
	GameManager(void);
	~GameManager(void);

	FILE *fp;  //파일을 열수있는 포인터 
	SysTem m_SysTem;

	bool m_Pause;
	int m_GameSpeed;
	
	DWORD GameTime;
	bool m_GameStart;

	bool m_Collision;

	// 데이터 베이스 테스트
	int count = 0;
	char cnt[256];
	char pw[256];

	void GameReset(void);
	void Init();
	void Update();
	void Draw();
	void Save();
	void Delete();
	
	
};

extern GameManager Gmanager;