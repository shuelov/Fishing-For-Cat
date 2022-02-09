#pragma once

#ifndef __Option_H__
#define __Option_H__

class Option : public Chap
{

	/////////////////
	Sprite mission;					//����Ʈ��޴�
	Sprite menuimg;				//�ɼǸ޴�
	Sprite invenimg;				//����޴�

	Sprite pointer;					//������

	Sprite menupopupimg;		//�޴��˾�
	Sprite saveimg;					//�����ϱ��ư
	Sprite optionimg;				//������ư
	Sprite exitimg;					//�����ư
	Sprite gobackimg;				//�ڷΰ����ư
	

	Sprite saving;					//���彽��

	Sprite okimg;					//Ȯ�ι�ư
	Sprite cancelimg;				//��ҹ�ư


	Sprite valleybutton;
	Sprite lakebutton;
	Sprite seabutton;

	Sprite unable_lake;			//ȣ�����
	Sprite unable_sea;				//�ٴ����

	Sprite cannotgo;				//"���� �� �� ����"
	Sprite opennewplace;			//"���ο� ��� ����"



	Sprite beach_goback;

	Sprite sound0p;				//�������� 0%
	Sprite sound50p;				//�������� 50%
	Sprite sound100p;				//�������� 100%

	Sprite save1_text;
	Sprite save2_text;
	Sprite save3_text;

	Sprite savedimg;
	Sprite saveselected;

public:
	
	int pointer_pos;
	int pointer_x;
	int pointer_y;

	bool checkinventory;

	bool temp;

	bool pause; // ���� �������� ����� ����, �������� ������ ���̱�
	bool turnonmenu;// �޴� on / off
	bool stopthecat;  // ����̸� ���߰��� ����ġ
	bool tabhold;
	bool saveframeon;
	bool dealon;

	bool soundon;  //�ɼ�- ���弳��
	bool placeon; // m �������� ������ ����̵�
	bool queston; // ����Ʈ��
	bool mute;
	bool halfsound;
	bool fullsound;
	bool place1;
	bool place2;
	bool place3;

	bool unlocklake;	//�⺻�� false�� �� �� �����ִ� ����, ȣ���� �ٴٴ� ���. true�Ͻ� ȣ���� �� �� ����
	bool unlocksea;	//�⺻�� false�� �� ���� ȣ���� �� �� ����, �ٴٴ� ���. true�� �� �� �� �� ����

	bool showerrormsg;//"���� �� �� ����"
	bool shownewmsg;//"���ο� ��� ����"
	bool msgonoff;


	float timeflow = 0;
	float speed = 3000;


	int nottwotime;

	bool aaa;
	bool save_ok;
	bool save1;
	bool save2;
	bool save3;


	DWORD KeyTime;

	Option();
	~Option();

	virtual void Init();
	virtual void Update(double frame);
	virtual void Draw();

	virtual void OnMessage(MSG* msg);

	void PosSetting(int _pos, int _x, int _y);
};

extern Option option;
#endif