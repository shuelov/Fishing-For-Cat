#ifndef __Story_H__
#define __Story_H__

class Story : public Chap
{
	float speed;
	float alpha;

	float speed2;
	float alpha2;

	DWORD KeyTime;
	DWORD KeyTime1;
	DWORD KeyTime2;
	int m_Story;
	bool enter;

	int textcount1;
	int textcount2;

	Sprite prologue;
	Sprite loding;
	Sprite town_fishshop;
	Sprite town_night;
	Sprite textbox[8];	 // 수정

	Sprite fan;
	Sprite cat_story3[3];
	Sprite fan_effect; // 수정

	int story3_aniCount;
	bool direction;

	// 고양이 위치,각도,크기
	float x1, y1;
	float radion1;
	float sx1, sy1;

	// 후라이팬 위치,각도,크기
	float x2, y2;
	float radion2;
	float sx2, sy2;

	// 후라이팬 충격 효과 노출 여부	 // 수정
	float sx3;

	bool soundcount;	// 수정

public:
	Story();
	~Story();

	virtual void Init();
	virtual void Update(double frame);
	virtual void Draw();
	virtual void OnMessage(MSG* msg);
};

#endif