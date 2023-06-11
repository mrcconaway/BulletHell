#include "entity.h"
#include <cmath>

// constructor
entity::entity(
    float fposxInp,
    float fposyInp,
    float fvxInp,
    float fvyInp,
    float axInp,
    float ayInp,
    float normVelInp )
{
    fposx = fposxInp;
    fposyInp = fposy;
    fvx = fvxInp;
    fvy = fvyInp;
    ax = axInp;
    ay = ayInp;
    normVel = normVelInp;
}

// basic setters
void entity::set_posX(float inp){ fposx = inp;}
void entity::set_posY(float inp){ fposy = inp;}
void entity::set_velX(float inp){ fvx = inp;}
void entity::set_velY(float inp){ fvy = inp;}
void entity::set_accelX(float inp){ ax = inp;}
void entity::set_accelY(float inp){ ay = inp;}

// basic getters
float entity::get_posX(){ return fposx;}
float entity::get_posY(){ return fposy;}
float entity::get_velX(){ return fvx;}
float entity::get_velY(){ return fvy;}
float entity::get_accelX(){ return ax;}
float entity::get_accelY(){ return ay;}
float entity::get_normVel(){ return normVel;}

// normalize the velocity
void entity::normalize_Vel(){ normVel = std::abs(fvx * fvy);}

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
