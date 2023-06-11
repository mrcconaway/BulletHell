#pragma once

class entity
{
public:

    entity(
    int sizeXInp = 6,
    int sizeYInp = 10,
    float faccelXInp = .25f,
    float faccelYInp = .50f,
    float fvelMaxInp = 2.00f,
    float fposxInp = 0,
    float fposyInp = 0,
    float fvxInp = 0,
    float fvyInp = 0,
    float axInp = 0,
    float ayInp = 0);
    // basic setters
    virtual void set_sizeX(int inp);
    virtual void set_sizeY(int inp);
    virtual void set_posX(float inp);
    virtual void set_posY(float inp);
    virtual void set_velX(float inp);
    virtual void set_velY(float inp);
    virtual void set_accelX(float inp);
    virtual void set_accelY(float inp);
    // basic getters
    virtual int get_sizeX();
    virtual int get_sizeY();
    virtual float get_posX();
    virtual float get_posY();
    virtual float get_velX();
    virtual float get_velY();
    virtual float get_accelX();
    virtual float get_accelY();
    virtual float get_normVel();


public:
    virtual void update();
    void normalize_Vel();
    // this should be +1 or -1 only
    virtual void updateXAccel(float i = 1); 
    virtual void updateYAccel(float i = 1); 

private:
    float fposx;
    float fposy;

    float fvx;
    float fvy;
    float normVel; 

    float ax;
    float ay;

    int sizeX;
    int sizeY;

private:
// this are the preset acceleration values. When a movement key is pressed, 
// player accelerates with the below values till a vel max is reached
    float faccelX = .25f;  
    float faccelY = .50f;
    float fvelMax = 2.00f; 
};