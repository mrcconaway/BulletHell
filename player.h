#pragma once
#include "entity.h"

class player : public entity
{
public:
    player();
    void update();

public:



private:
// this are the preset acceleration values. When a movement key is pressed, 
// player accelerates with the below values till a vel max is reached
    float faccelX = .25f;  
    float faccelY = .50f;
    float fvelMax = 2.00f;
};