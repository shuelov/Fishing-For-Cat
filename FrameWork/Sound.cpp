#include "Include.h"

Sound sound;



Sound::Sound(void)
{
	//g_pSoundManager = NULL; ��� ���ߴ�
}

Sound::~Sound(void)
{
}

void Sound::Init() // ����
{
	////////// ���丮
	g_pSoundManager->Create(&m_wind, (LPWSTR)L"./resource/Sound/wind-story.wav", 0, GUID_NULL);											//�ٶ� �Ҹ�
	g_pSoundManager->Create(&m_fishshop, (LPWSTR)L"./resource/Sound/Ship-Docking-Bay-Ambience__360p_-storyfishshop.wav", 0, GUID_NULL);	//�������� �Ҹ�

	g_pSoundManager->Create(&m_hungry, (LPWSTR)L"./resource/Sound/hungry effect(story).wav", 0, GUID_NULL);								//������ �Ҹ�
	g_pSoundManager->Create(&m_fan, (LPWSTR)L"./resource/Sound/fryingpan_story_.wav", 0, GUID_NULL); 									//�Ķ����� �Ҹ�

																																		////////// �� ����
	g_pSoundManager->Create(&m_valley, (LPWSTR)L"./resource/Sound/music-valley.wav", 0, GUID_NULL);										//��� ����

	g_pSoundManager->Create(&m_birdlake, (LPWSTR)L"./resource/Sound/bird-lake.wav", 0, GUID_NULL);										//ȣ�� ����

	g_pSoundManager->Create(&m_ocean, (LPWSTR)L"./resource/Sound/sea-wave-ocean.wav", 0, GUID_NULL);									//�ٴ� ����
	g_pSoundManager->Create(&m_boat, (LPWSTR)L"./resource/Sound/Fishing Boat-ocean.wav", 0, GUID_NULL);									//��Ʈ �����Ҹ�

																																		////////// ���� ����
	g_pSoundManager->Create(&m_Game, (LPWSTR)L"./resource/Sound/Mr_Turtle-gamemusic.wav", 0, GUID_NULL); 								//���� ����(������ ����)
	g_pSoundManager->Create(&m_splash, (LPWSTR)L"./resource/Sound/Jump_In_Shallow_Water_fish_game.wav", 0, GUID_NULL);					//����� ÷�� �Ҹ�(����ǥ)
	g_pSoundManager->Create(&m_fishing, (LPWSTR)L"./resource/Sound/Baltic_Levity_Thatched_Villagers(fishing).wav", 0, GUID_NULL);		//����� ��� ���� ���� ��(���� ȭ�鿡��)

	g_pSoundManager->Create(&m_throw, (LPWSTR)L"./resource/Sound/fishing_gut_throw.wav", 0, GUID_NULL);									//������ ������ �Ҹ�
	g_pSoundManager->Create(&m_spin, (LPWSTR)L"./resource/Sound/fishing_gut_spin.wav", 0, GUID_NULL);									//������ ������ �Ҹ�(���� ȭ��)

	g_pSoundManager->Create(&m_success, (LPWSTR)L"./resource/Sound/success_newgame_.wav", 0, GUID_NULL);								//���� ������ ����
	g_pSoundManager->Create(&m_fail, (LPWSTR)L"./resource/Sound/The_Story_Unfolds_Sting_fail_newgame.wav", 0, GUID_NULL);				//���� ���н� ����

																																		////////// ����
	g_pSoundManager->Create(&m_money, (LPWSTR)L"./resource/Sound/money-deal.wav", 0, GUID_NULL);										//�ŷ� �� ���� ����

																																		////////// ��Ÿ
	g_pSoundManager->Create(&m_but, (LPWSTR)L"./resource/Sound/Woodblock_Hit_button_menu.wav", 0, GUID_NULL);										// ��ư �����̴� ����
	g_pSoundManager->Create(&m_confirm, (LPWSTR)L"./resource/Sound/Wood_Plank_Flicks_confirm_menu.wav", 0, GUID_NULL);									// ��ư ���� �� ����

}

void Sound::Update(double frame)
{


}

void Sound::Draw()
{




}

void Sound::InitEtc()
{
	sound.g_pSoundManager->Create(&m_logo, (LPWSTR)L"./resource/Sound/Fishtank_Bubbles(logo).wav", 0, GUID_NULL);			//�ΰ�����?
	sound.g_pSoundManager->Create(&m_menu, (LPWSTR)L"./resource/Sound/Brittle_Rille_Reunited(logo).wav", 0, GUID_NULL);			//�κ�����
	sound.g_pSoundManager->Create(&m_town, (LPWSTR)L"./resource/Sound/music-town.wav", 0, GUID_NULL);							//��������

}

void Sound::PlayEtc() // ����
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

void Sound::StopEtc() // ����
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