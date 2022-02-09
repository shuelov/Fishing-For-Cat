#pragma once


class Sound
{

public:
	Sound(void);
	~Sound(void);

	CSoundManager* g_pSoundManager;

	// ����
	CSound*		m_town;										// ����
															//--------------------------------------logo
	CSound*		m_logo;										// �ΰ� �Ҹ�?
															//-------------------------------------story	
	CSound*		m_menu;										// �޴� �Ҹ�
															//--------------------------------------story	
	CSound*		m_wind;										// �ٶ� �Ҹ�
	CSound*		m_fishshop;									// ���� ���� �Ҹ�
	CSound*		m_hungry;									// ������ �Ҹ�
	CSound*		m_fan;										// �Ķ����� �Ҹ�

															//--------------------------------------game
	CSound*		m_Game;										//���ӻ���
	CSound*		m_fishing;									//����� ��� ���� ���� ��
	CSound*		m_splash;									//����� ÷�� �Ҹ�
	CSound*		m_success;									//���� ���� ����
	CSound*		m_fail;										//���� ���� ����

	CSound*		m_throw;									//������ ������ ����
	CSound*		m_spin;										//������ ������ ����

															//--------------------------------------map
	CSound*		m_valley;									//���

	CSound*		m_birdlake;									//ȣ��

	CSound*		m_ocean;									//�ٴ�
	CSound*		m_boat;										//��Ʈ�����Ҹ�

															//--------------------------------------shop
	CSound*		m_money;									// �ŷ� �� ���� ����

															//--------------------------------------etc
	CSound* 	m_but;										// ��ư �̵� ����
	CSound* 	m_confirm;									// ��ư ���� ����

															/////////////////////����- ����������Ѱ�
															////DirectSound �Ŵ��� ����
															//CSoundManager* g_pSoundManager = NULL;
															////���� ���� (���庰�� �ϳ��� ���� ���� �ʿ�)
															//CSound* g_pSound = NULL;

	int m_Select;

	int num = 0;  //������ ��ư�� Ȯ���ϴ� ����

	bool checks = true;			//�����˾���
	bool confirm = true;			//�������ÿ�

	DWORD KeyTime; // �ð�������

	RECT q_rc;

	char str[100]; //���ڿ�



	void Init();
	void InitEtc();
	void PlayEtc();
	void StopEtc();	// �߰�
	virtual void Update(double frame);
	virtual void Draw();
	virtual void OnMessage(MSG* msg);

};

extern Sound sound;