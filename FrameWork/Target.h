#pragma once
#include "Include.h"

//----------------------------------------------------------
//������� �ֽ� �ڵ��̹Ƿ� �����Ͻð� ���⼭ �ڵ�����������
//----------------------------------------------------------

typedef struct Tar
{
	double dx, dy, dz, drx, dry, drz;	// ��������
};

class Target
{
	Sprite Tgimg[2];
	Sprite Tgimg2[4];

public :
	Target();
	~Target();

	DWORD AniTime1;
	DWORD AniTime2;

	bool m_Life;
	int m_TgCount1;
	int m_TgCount2;
	double m_W;
	double m_H;
	Tar m_Target;

	RECT m_rc;

	void Init();
	void Update();
	void Draw();
	void Reset();
};

extern Target target;