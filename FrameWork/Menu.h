#ifndef __Menu_H__
#define __Menu_H__

class Menu : public Chap
{
	Sprite menuimg;
	Sprite logo;
	Sprite newgame;
	Sprite loadgame;
	Sprite quit;
	Sprite pointer;

	Sprite light[46];

	Sprite menupopupimg;
	Sprite saving;
	Sprite load1_text;
	Sprite load2_text;
	Sprite load3_text;
	Sprite goback;

	CSoundManager* g_pSoundManager;

	int effect_Count;
	bool turn;

	bool soundcount;

	DWORD KeyTime;

	int select = 0; //������ ��ư�� Ȯ���ϴ� ����
public:
	Menu();
	~Menu();

	int count, alpha;

	bool choose;
	bool loadon;
	int loading = 0;
	//��������

	virtual void Init();
	virtual void Update(double frame);
	virtual void Draw();

	virtual void OnMessage(MSG* msg);

};

#endif
extern Menu menu;