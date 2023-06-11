#include "entity.h"
#include <cmath>

// constructor
entity::entity(
    int sizeXInp,
    int sizeYInp,
    float faccelXInp,
    float faccelYInp,
    float fvelMaxInp,
    float fposxInp,
    float fposyInp,
    float fvxInp,
    float fvyInp,
    float axInp,
    float ayInp )
{
    sizeX = sizeXInp;
    sizeY = sizeYInp;
    faccelX = faccelXInp;
    faccelY = faccelYInp;
    fvelMax = fvelMaxInp;
    fposx = fposxInp;
    fposyInp = fposy;
    fvx = fvxInp;
    fvy = fvyInp;
    ax = axInp;
    ay = ayInp;
}

// basic setters
void entity::set_sizeX(int inp){ sizeX = inp;}
void entity::set_sizeY(int inp){ sizeY = inp;}

void entity::set_posX(float inp){ fposx = inp;}
void entity::set_posY(float inp){ fposy = inp;}
void entity::set_velX(float inp){ fvx = inp;}
void entity::set_velY(float inp){ fvy = inp;}
void entity::set_accelX(float inp){ ax = inp;}
void entity::set_accelY(float inp){ ay = inp;}

// basic getters
int entity::get_sizeX(){ return sizeX;}
int entity::get_sizeY(){ return sizeY;}

float entity::get_posX(){ return fposx;}
float entity::get_posY(){ return fposy;}
float entity::get_velX(){ return fvx;}
float entity::get_velY(){ return fvy;}
float entity::get_accelX(){ return ax;}
float entity::get_accelY(){ return ay;}
float entity::get_normVel(){ return normVel;}

// normalize the velocity
void entity::normalize_Vel(){ normVel = std::abs((fvx+1) * (fvy+1));}

// Updated position, velocity, and acceleration
void entity::update()
{
    fvx = ax;
    fvy = ay;
    if((fvx > +0.01f) && (fvx < -0.01f) || 
       (fvy > -0.01f) && (fvy < +0.01f) )
    {
            fvx = ax;
            fvy = ay;
    }
    fposx += fvx;
    fposy += fvy;
}

void entity::updateXAccel(float i)
{    
    if(get_normVel() < fvelMax){
        ax = i * faccelX;
    }
    else{        
        ax = 0;
    }
}

void entity::updateYAccel(float i)
{    
    if(get_normVel() < fvelMax){
        ay = i * faccelX;
    }
    else{        
        ay = 0;
    }
}