#include "game.h"
#include "player.h"


bool game::OnUserCreate()
{
    player.set_posY(5.2f);
    player.set_posX(10.0f);
    prevframetime = 1.0f;
    bplayApp = true;
    return true;
}


bool game::OnUserUpdate(float fElapsedTime)
{
    currframetime = fElapsedTime;
    getInput();
    update();
    Draw();
    DrawPlayer();
    drawCrosshair();

    prevframetime = fElapsedTime;
    return bplayApp;
}

void game::getInput()
{
    float gain = currframetime / prevframetime;
    #include <iostream>
    if(GetKey(olc::W).bHeld){
        player.updateYAccel(-1*gain);
        // std::cout << gain << std::endl;
    }

    else if(GetKey(olc::S).bHeld){
        player.updateYAccel(+1*gain);
        // std::cout << gain << std::endl;
    }
    else{
        player.set_velY(0);
        player.set_accelY(0);
    }
    if(GetKey(olc::A).bHeld){
        player.updateXAccel(-1*gain);
        // std::cout << gain << std::endl;
    }
    else if(GetKey(olc::D).bHeld){
        player.updateXAccel(1*gain);
        // std::cout << gain << std::endl;
    }
    else{
        player.set_velY(0);
        player.set_accelX(0);
    }
}
	
void game::update()
{
    player.update();
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

void game::DrawPlayer()
{
        // loop over the x and y coordinate of the screen
    for(int ix = 0; ix < ScreenWidth(); ix++ ){ // loop over x coordinate
        for(int iy = 0; iy < ScreenHeight(); iy++){
            if( (ix < int(player.get_posX() + player.get_sizeX()/2) ) && 
                (ix > int(player.get_posX() - player.get_sizeX()/2) ) && 
                (iy < int(player.get_posY() + player.get_sizeY()/2) ) &&
                (iy > int(player.get_posY() - player.get_sizeY()/2) ) 
             )
                PixelGameEngine::Draw(ix, iy, olc::Pixel(0,  0,  255)); 
            if( ix == int(player.get_posX()) && iy == int(player.get_posY()) )
                PixelGameEngine::Draw(ix, iy, olc::Pixel(255,  0,  255)); 

        } // for loop over iy
    } // for loop over ix
}

void game::drawCrosshair()
{
	DrawCircle(GetMouseX(), GetMouseY(), 3 * SWR, olc::Pixel(0,0,0));
}