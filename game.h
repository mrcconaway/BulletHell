#pragma once
#include "olcPixelGameEngine.h"
#include "player.h"

#include <vector>


class game : public olc::PixelGameEngine
{
public:
	game()
	{
		sAppName = "Bullet Hell";
	}
	bool OnUserCreate()override;
	bool OnUserUpdate(float fElapsedTime) override;
public:
	void Draw();
	void DrawPlayer();

public:
	void getInput();
	void update();

private:
	std::vector<entity> enemyEntity; // enemy entity class
	player player; // enemy entity

private:
    bool bplayApp;
	float prevframetime;
	float currframetime;
};