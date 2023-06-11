#include "game.h"


bool game::OnUserCreate()
{
    bplayApp = true;
    return true;
}


bool game::OnUserUpdate(float fElapsedTime)
{
    Draw();

    return bplayApp;
}

void game::Draw()
{
    // loop over the x and y coordinate of the screen
    for(int ix = 0; ix < ScreenWidth(); ix++ ){ // loop over x coordinate
        for(int iy = 0; iy < ScreenHeight(); iy++){
           PixelGameEngine::Draw(ix, iy, olc::Pixel(255,  255,  255)); 
        } // for loop over iy
    } // for loop over ix

    return;
}
