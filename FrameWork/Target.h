#pragma once
#include "Include.h"

//----------------------------------------------------------
//강사님이 주신 코드이므로 참고만하시고 여기서 코딩하지마세요
//----------------------------------------------------------

typedef struct Tar
{
	double dx, dy, dz, drx, dry, drz;	// 데미지존
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