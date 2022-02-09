#pragma once

#include "Include.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Init()
{
	//수정
	//sql.Init();
	//load.Init();
	map.m_Stage = 3;
	map.Init();
	sound.Init();
	Gmanager.Init();
	cat.Init();
	power.Init();
	fishing.Init();
	fish.Init();
	boat.Init();
	quest.Init();
	item.Init();
	option.Init();
	comeonfish.Init();
	
}

void Game::Draw()
{
	
	map.Draw();
	fish.Draw();

	Gmanager.Draw();

	if (map.m_Stage == 1)
		cat.Draw();
	if (map.m_Stage == 2) // 보트 타는 모양새때문에 바꿔둔거
	{
		boat.Draw();
		cat.Draw();
	}
	if (map.m_Stage == 3)
	{
		cat.Draw();
		boat.Draw();
	}

	power.Draw();
	fishing.Draw();
	item.Draw();
	option.Draw();
	load.Draw();
	sql.Draw();
	
}

void Game::Update(double frame)
{
	sql.Update();
	map.Update(frame);
	Gmanager.Update();
	boat.Update();
	cat.Update();
	option.Update(200);
	power.Update();
	fishing.Update();
	fish.Update();
	item.Update();
	
	static int a = 0;
	if(a == 0) 
	{
		GameTime = GetTickCount();
		a = 1;

	}
}


void Game::OnMessage( MSG* msg )
{

}