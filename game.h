#pragma once
#include "olcPixelGameEngine.h"


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


private:
    bool bplayApp;
};