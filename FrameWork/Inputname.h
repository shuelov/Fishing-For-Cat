#pragma once

#ifndef __Inputname_H__
#define __Inputname_H__

class Inputname : public Chap
{
	Sprite menuimg;
	Sprite Input;
	Sprite Ok;
	Sprite Back;
	Sprite pointer;

	int select = 0; //선택한 버튼을 확인하는 변수

public:
	Inputname();
	~Inputname();

	int count, alpha;


	virtual void Init();
	virtual void Update(double frame);
	virtual void Draw();

	virtual void OnMessage(MSG* msg);

};

#endif