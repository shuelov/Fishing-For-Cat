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
	Sprite textbox[8];	 // ����

	Sprite fan;
	Sprite cat_story3[3];
	Sprite fan_effect; // ����

	int story3_aniCount;
	bool direction;

	// ����� ��ġ,����,ũ��
	float x1, y1;
	float radion1;
	float sx1, sy1;

	// �Ķ����� ��ġ,����,ũ��
	float x2, y2;
	float radion2;
	float sx2, sy2;

	// �Ķ����� ��� ȿ�� ���� ����	 // ����
	float sx3;

	bool soundcount;	// ����

public:
	Story();
	~Story();

	virtual void Init();
	virtual void Update(double frame);
	virtual void Draw();
	virtual void OnMessage(MSG* msg);
};

#endif