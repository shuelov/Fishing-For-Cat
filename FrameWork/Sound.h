#pragma once


class Sound
{

public:
	Sound(void);
	~Sound(void);

	CSoundManager* g_pSoundManager;

	// 수정
	CSound*		m_town;										// 마을
															//--------------------------------------logo
	CSound*		m_logo;										// 로고 소리?
															//-------------------------------------story	
	CSound*		m_menu;										// 메뉴 소리
															//--------------------------------------story	
	CSound*		m_wind;										// 바람 소리
	CSound*		m_fishshop;									// 생선 가게 소리
	CSound*		m_hungry;									// 꼬르륵 소리
	CSound*		m_fan;										// 후라이팬 소리

															//--------------------------------------game
	CSound*		m_Game;										//게임사운드
	CSound*		m_fishing;									//물고기 잡는 게임 진행 시
	CSound*		m_splash;									//물고기 첨벙 소리
	CSound*		m_success;									//낚시 성공 사운드
	CSound*		m_fail;										//낚시 실패 사운드

	CSound*		m_throw;									//낚시줄 던지는 사운드
	CSound*		m_spin;										//낚시줄 돌리는 사운드

															//--------------------------------------map
	CSound*		m_valley;									//계곡

	CSound*		m_birdlake;									//호수

	CSound*		m_ocean;									//바다
	CSound*		m_boat;										//보트엔진소리

															//--------------------------------------shop
	CSound*		m_money;									// 거래 시 동전 사운드

															//--------------------------------------etc
	CSound* 	m_but;										// 버튼 이동 사운드
	CSound* 	m_confirm;									// 버튼 선택 사운드

															/////////////////////사운드- 수업때사용한거
															////DirectSound 매니저 변수
															//CSoundManager* g_pSoundManager = NULL;
															////사운드 버퍼 (사운드별로 하나의 사운드 버퍼 필요)
															//CSound* g_pSound = NULL;

	int m_Select;

	int num = 0;  //선택한 버튼을 확인하는 변수

	bool checks = true;			//설정팝업용
	bool confirm = true;			//음량선택용

	DWORD KeyTime; // 시간관리용

	RECT q_rc;

	char str[100]; //문자열



	void Init();
	void InitEtc();
	void PlayEtc();
	void StopEtc();	// 추가
	virtual void Update(double frame);
	virtual void Draw();
	virtual void OnMessage(MSG* msg);

};

extern Sound sound;