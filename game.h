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
	void drawCrosshair();

public:
	void getInput();
	void update();

private:
	std::vector<entity> enemyEntity; // enemy entity class
	player player; // enemy entity

private:
float SWR = ScreenWidth() / 256.0f; // Screen Width Ratio
private:
    bool bplayApp;
	float prevframetime;
	float currframetime;

};