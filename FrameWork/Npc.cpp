#pragma once
#include "Include.h"

Npc npc;

Npc::Npc()
{}

Npc::~Npc()
{}

void Npc::Init()
{
	dealer.Create("./resource/Img/Character/dealer.png", false, D3DCOLOR_XRGB(0, 0, 0));	// 상점 NPC
	owner.Create("./resource/Img/Character/owner.png", false, D3DCOLOR_XRGB(0, 0, 0));	// 생선가게 NPC
}

void Npc::Update()
{

}

void Npc::Draw()
{
	dealer.Render(120, 550,0,1,1);
	owner.Render(700, 520, 0, 0.8, 0.8);

	if (120<cat.m_cat.dx<160)
	{
		selling = true;
	}

	if (cat.m_cat.dx >160 || cat.m_cat.dx<120)
		selling = false;


	if (selling == true)
	{

		SetRect(&m_rc, 140, 500, 120 + 200, 550 + 200);
		dv_font.Fonts->DrawTextA(NULL, "PRESS 'Z'", -1, &m_rc, DT_LEFT, D3DCOLOR_ARGB(255, 255, 255, 255));

	}

}