
#include "Fuel.h"
#include <iostream>


/// Constructors
Fuel::Fuel(){}

Fuel::Fuel(Ground groundObj, int pos, sf::Sprite sprt0, sf::Sprite sprt1, Random &random){
    x = (groundObj.getXU(pos) - groundObj.getXU(pos+1))/2.0 + groundObj.getXU(pos+1);

    if(groundObj.getYU(pos) < groundObj.getYU(pos+1)){
        y = (groundObj.getYU(pos+1) - groundObj.getYU(pos))/2.0 + groundObj.getYU(pos);
    } else {
        y = (groundObj.getYU(pos) - groundObj.getYU(pos+1))/2.0 + groundObj.getYU(pos+1);
    }
    type = random.gen(0, 1);
    if(type == 0){
        sprt = sprt0;
        sprt.setOrigin(12.0, 7.0);
        y = y + 8.0;
    } else {
        sprt = sprt1;
        sprt.setOrigin(17.0, 10.0);
        y = y + 11.0;
    }
    dir = groundObj.getDirU(pos) + 180.0;
}


/// Getter
int Fuel::getType(){
    return type;
}

/// Setter
void Fuel::setType(int _type){
    type = _type;
}



/// Re-spawn
void Fuel::respawnFuel(Ground groundObj, int pos, sf::Sprite sprt0, sf::Sprite sprt1, Random &random){
    x = (groundObj.getXU(pos) - groundObj.getXU(pos+1))/2.0 + groundObj.getXU(pos+1);

    if(groundObj.getYU(pos) < groundObj.getYU(pos+1)){
        y = (groundObj.getYU(pos+1) - groundObj.getYU(pos))/2.0 + groundObj.getYU(pos);
    } else {
        y = (groundObj.getYU(pos) - groundObj.getYU(pos+1))/2.0 + groundObj.getYU(pos+1);
    }
    dir = groundObj.getDirU(pos) + 180.0;

        if(random.gen(0, 1) == 0){
            type = 0;
            sprt = sprt0;

        } else {

            type = 1;
            sprt = sprt1;

        }
}


