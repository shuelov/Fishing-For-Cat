#pragma once
#include "Include.h"


class Power

{


public:
	Power(void);
	~Power(void);
	Sprite powerbar; //�Ŀ���
	Sprite pointer; //ȭ��ǥ

	Sprite line_right_178; //������ �̹��� 
	Sprite line_right_356;
	Sprite line_right_600;

	Sprite line_left_178;
	Sprite line_left_356;
	Sprite line_left_600;



	DWORD KeyTime; // �ð������� ����


	float fishingline_x;  // �������̹����� ���۵� x��ǥ
	float fishingline_y;   // ������ �̹����� ���۵� y��ǥ 
	int pointer_y; //����� ȭ���� ����ų y��ǥ

	bool plusorminus; // ȭ��ǥ�� �ö��� �������� ������
	bool startfishing; //�������� �����Ŀ� �������� fishing�� ����
	bool startpowering;  //����⸦ �����Ŀ� false �� �ٲܰ���/ �����̽��� �ٽô����� �Ŀ��ٰ� �ȶ߰� ���ٺ��� 

	int pos;  // ������� ����. 0 �ϰ�� ���� 1�ϰ�� ������

	int howmuchpower;  // ������ ���� �Ŀ� 1.���ϳ���-178 2.�߰�-356 3.����ŭ-600

	int direction; //���ô븦 ������ ���� 1.���� 2. ������

	void Init();
	void Update();
	void Draw();
	void Changecal(); // ���밡 �Ѱ迡 �ٴٸ��� ����� �ٲ����Լ�

};

extern Power power;