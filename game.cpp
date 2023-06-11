#include "game.h"
#include "player.h"


bool game::OnUserCreate()
{
    player->set_posY(5.2f);
    player->set_posX(10.0f);
    bplayApp = true;
    return true;
}


bool game::OnUserUpdate(float fElapsedTime)
{
    getInput();
    Draw();

    return bplayApp;
}

void game::getInput()
{
    if(GetKey(olc::W).bPressed){

    }
    if(GetKey(olc::S).bPressed){

    }
    if(GetKey(olc::A).bPressed){

    }
    if(GetKey(olc::D).bPressed){
        
    }
}


void game::Draw()
{
    // loop over the x and y coordinate of the screen
    for(int ix = 0; ix < ScreenWidth(); ix++ ){ // loop over x coordinate
        for(int iy = 0; iy < ScreenHeight(); iy++){
           PixelGameEngine::Draw(ix, iy, olc::Pixel(255,  255,  255)); 
           if(int(player->get_posX()) == ix && int(player->get_posY()) == iy ) 
                PixelGameEngine::Draw(ix, iy, olc::Pixel(0,  0,  255));
        } // for loop over iy
    } // for loop over ix

    return;
}
