
#include "FuelBar.h"

/// Constructor
FuelBar::FuelBar(){}
FuelBar::FuelBar(float _x, float _y, float _dir, sf::Texture &txtr, float xOrigin, float yOrigin) : Entity(_x, _y, _dir, txtr, xOrigin, yOrigin){}


/// Getter
float FuelBar::getTank(){
    return tank;
}


/// Setter
void FuelBar::setTank(float _tank){
    if(_tank < 1.0){
        tank = _tank;
    } else {
        tank = 1.0;
    }
    sprt.setScale(tank, 1.0);
}
