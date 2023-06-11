#pragma once

class entity
{
public:

    entity(
    float fposxInp = 0,
    float fposyInp = 0,
    float fvxInp = 0,
    float fvyInp = 0,
    float axInp = 0,
    float ayInp = 0,
    float normVel = 0);
    // basic setters
    void set_posX(float inp);
    void set_posY(float inp);
    void set_velX(float inp);
    void set_velY(float inp);
    void set_accelX(float inp);
    void set_accelY(float inp);
    // basic getters
    float get_posX();
    float get_posY();
    float get_velX();
    float get_velY();
    float get_accelX();
    float get_accelY();
    float get_normVel();


public:
    virtual void update();
    void normalize_Vel();

private:
    float fposx;
    float fposy;

    float fvx;
    float fvy;
    float normVel; // this should be set by the derived classes.

    float ax;
    float ay;    
};