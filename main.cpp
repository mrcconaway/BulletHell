#include "olcPixelGameEngine.h"
#include "game.h"

int main()
{

    int32_t screenWidth = 256;
    int32_t screenHeight = 240;


    // make player 
    game App;

    App.Construct(screenWidth, screenHeight, 4, 4, false, true);
    App.Start();

    return 1;
}