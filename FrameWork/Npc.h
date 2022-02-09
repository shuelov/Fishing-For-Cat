#pragma once
#include "Include.h"

class Npc
{
public:
	Npc();
	~Npc();

	Sprite dealer;
	Sprite owner;

	RECT m_rc;
	double m_Left;
	double m_High;
	char str[100]; //¹®ÀÚ¿­
				   /*Seller npc;*/
	bool selling;

	void Init();
	void Update();
	void Draw();
};

extern Npc npc;