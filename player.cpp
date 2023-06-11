#include "player.h"
#include "entity.h"

player::player()
{
    entity();
}

void player::update()
{
    if(get_normVel() < fvelMax){
        entity::set_accelX(faccelX);
        entity::set_accelY(faccelY); 
    }
    else{
        entity::set_accelX(0.0f);
        entity::set_accelY(0.0f); 
    }
    entity::update();
}
