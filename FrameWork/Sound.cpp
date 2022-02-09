#include "Include.h"

Sound sound;



Sound::Sound(void)
{
	//g_pSoundManager = NULL; 사용 안했다
}

Sound::~Sound(void)
{
}

void Sound::Init() // 수정
{
	////////// 스토리
	g_pSoundManager->Create(&m_wind, (LPWSTR)L"./resource/Sound/wind-story.wav", 0, GUID_NULL);											//바람 소리
	g_pSoundManager->Create(&m_fishshop, (LPWSTR)L"./resource/Sound/Ship-Docking-Bay-Ambience__360p_-storyfishshop.wav", 0, GUID_NULL);	//생선가게 소리

	g_pSoundManager->Create(&m_hungry, (LPWSTR)L"./resource/Sound/hungry effect(story).wav", 0, GUID_NULL);								//꼬르륵 소리
	g_pSoundManager->Create(&m_fan, (LPWSTR)L"./resource/Sound/fryingpan_story_.wav", 0, GUID_NULL); 									//후라이팬 소리

																																		////////// 맵 사운드
	g_pSoundManager->Create(&m_valley, (LPWSTR)L"./resource/Sound/music-valley.wav", 0, GUID_NULL);										//계곡 사운드

	g_pSoundManager->Create(&m_birdlake, (LPWSTR)L"./resource/Sound/bird-lake.wav", 0, GUID_NULL);										//호수 사운드

	g_pSoundManager->Create(&m_ocean, (LPWSTR)L"./resource/Sound/sea-wave-ocean.wav", 0, GUID_NULL);									//바다 사운드
	g_pSoundManager->Create(&m_boat, (LPWSTR)L"./resource/Sound/Fishing Boat-ocean.wav", 0, GUID_NULL);									//보트 엔진소리

																																		////////// 낚시 게임
	g_pSoundManager->Create(&m_Game, (LPWSTR)L"./resource/Sound/Mr_Turtle-gamemusic.wav", 0, GUID_NULL); 								//게임 사운드(낚시줄 이후)
	g_pSoundManager->Create(&m_splash, (LPWSTR)L"./resource/Sound/Jump_In_Shallow_Water_fish_game.wav", 0, GUID_NULL);					//물고기 첨벙 소리(느낌표)
	g_pSoundManager->Create(&m_fishing, (LPWSTR)L"./resource/Sound/Baltic_Levity_Thatched_Villagers(fishing).wav", 0, GUID_NULL);		//물고기 잡는 게임 진행 시(게임 화면에서)

	g_pSoundManager->Create(&m_throw, (LPWSTR)L"./resource/Sound/fishing_gut_throw.wav", 0, GUID_NULL);									//낚시줄 던지는 소리
	g_pSoundManager->Create(&m_spin, (LPWSTR)L"./resource/Sound/fishing_gut_spin.wav", 0, GUID_NULL);									//낚시줄 돌리는 소리(게임 화면)

	g_pSoundManager->Create(&m_success, (LPWSTR)L"./resource/Sound/success_newgame_.wav", 0, GUID_NULL);								//낚시 성공시 사운드
	g_pSoundManager->Create(&m_fail, (LPWSTR)L"./resource/Sound/The_Story_Unfolds_Sting_fail_newgame.wav", 0, GUID_NULL);				//낚시 실패시 사운드

																																		////////// 상점
	g_pSoundManager->Create(&m_money, (LPWSTR)L"./resource/Sound/money-deal.wav", 0, GUID_NULL);										//거래 시 동전 사운드

																																		////////// 기타
	g_pSoundManager->Create(&m_but, (LPWSTR)L"./resource/Sound/Woodblock_Hit_button_menu.wav", 0, GUID_NULL);										// 버튼 움직이는 사운드
	g_pSoundManager->Create(&m_confirm, (LPWSTR)L"./resource/Sound/Wood_Plank_Flicks_confirm_menu.wav", 0, GUID_NULL);									// 버튼 선택 시 사운드

}

void Sound::Update(double frame)
{


}

void Sound::Draw()
{




}

void Sound::InitEtc()
{
	sound.g_pSoundManager->Create(&m_logo, (LPWSTR)L"./resource/Sound/Fishtank_Bubbles(logo).wav", 0, GUID_NULL);			//로고음악?
	sound.g_pSoundManager->Create(&m_menu, (LPWSTR)L"./resource/Sound/Brittle_Rille_Reunited(logo).wav", 0, GUID_NULL);			//로비음악
	sound.g_pSoundManager->Create(&m_town, (LPWSTR)L"./resource/Sound/music-town.wav", 0, GUID_NULL);							//마을음악

}

void Sound::PlayEtc() // 수정
{
	if (g_Mng.n_Chap == LOGO)
	{
		m_logo->Play(0, DSBPLAY_LOOPING);
	}

	if (g_Mng.n_Chap == MENU)
	{
		m_menu->Play(0, DSBPLAY_LOOPING);
	}

	//if (g_Mng.n_Chap == STORY)	
	//{
	//	m_story->Play(0, DSBPLAY_LOOPING);
	//}

	if (g_Mng.n_Chap == TOWN)
	{
		m_town->Play(0, DSBPLAY_LOOPING);
	}
}

void Sound::StopEtc() // 수정
{
	if (g_Mng.n_Chap != LOGO)
	{
		m_logo->Stop();
	}

	if (g_Mng.n_Chap != MENU)
	{
		m_menu->Stop();
	}

	if (g_Mng.n_Chap != TOWN)
	{
		m_town->Stop();
	}

	sound.m_valley->Stop();
	sound.m_birdlake->Stop();
	sound.m_ocean->Stop();
	sound.m_boat->Stop();

}

void Sound::OnMessage(MSG* msg)
{
}