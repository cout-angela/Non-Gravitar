#include "FuelArray.h"

/// Constructor
FuelArray::FuelArray(GroundArray &groundArrayObj, sf::Sprite sprt0, sf::Sprite sprt1, Random &random){

for(int i = 0; i < 5; i++){
        int positions = groundArrayObj.getGround(i).getLength() - 1; //possible positions in which to set the fuel

        int fuelQuantity = random.gen(2, 3);
        int spaceLeft = positions%fuelQuantity; //exceeding positions to be distributed
        int range = positions/fuelQuantity; // possible positions per fuel
        int bottomLimit = 0; //bottom position per range

        for(int j = 0; j < 3; j++){

            if(spaceLeft > 0){
                unit[i][j] = Fuel(groundArrayObj.getGround(i), random.gen(bottomLimit, bottomLimit+range), sprt0, sprt1, random);
                spaceLeft = spaceLeft - 1;
                bottomLimit = bottomLimit + range+1;
            } else {
                unit[i][j] = Fuel(groundArrayObj.getGround(i), random.gen(bottomLimit, bottomLimit+range-1), sprt0, sprt1, random);
                bottomLimit = bottomLimit + range;
            }
            unit[i][j].updateSprt();
        }
        if(fuelQuantity == 2){
            unit[i][2].setActive(false);
        }

    }

}

/// Getters
bool FuelArray::getFActive(int &planetIndex, int j){
    return unit[planetIndex][j].getActive();
}
float FuelArray::getFX(int &planetIndex, int j){
    return unit[planetIndex][j].getX();
}
float FuelArray::getFY(int &planetIndex, int j){
    return unit[planetIndex][j].getY();
}
int FuelArray::getFType(int &planetIndex, int j){
    return unit[planetIndex][j].getType();
}
/// Setters
void FuelArray::setFType(int &planetIndex, int j, int _type){
    unit[planetIndex][j].setType(_type);

}
void FuelArray::setFActive(int &planetIndex, int j, bool _active){
    unit[planetIndex][j].setActive(_active);
}

/// Draw
void FuelArray::drawFuelArray(sf::RenderWindow &window, int &planetIndex){

    for(int i = 0; i < 3; i++){
        if(unit[planetIndex][i].getActive()){
            window.draw(unit[planetIndex][i].getSprt());

        }
    }
}


/// Re-spawn
void FuelArray::respawnFuelArray(GroundArray &groundArrayObj, sf::Sprite sprt0, sf::Sprite sprt1, Random &random){

for(int i = 0; i < 5; i++){
        int positions = groundArrayObj.getGround(i).getLength() - 1; //possible positions in which to set the fuel
        int fuelQuantity = random.gen(2, 3);
        int spaceLeft = positions%fuelQuantity; //exceeding positions to be distributed
        int range = positions/fuelQuantity; // possible positions per fuel
        int bottomLimit = 0; //bottom position per range

        for(int j = 0; j < 3; j++){
            unit[i][j].setActive(true); // re-activates all the harvested fuels of the previous system
            if(spaceLeft > 0){
                unit[i][j].respawnFuel(groundArrayObj.getGround(i), random.gen(bottomLimit, bottomLimit+range), sprt0, sprt1, random);

                spaceLeft = spaceLeft - 1;
                bottomLimit = bottomLimit + range+1;
            } else {
                unit[i][j].respawnFuel(groundArrayObj.getGround(i), random.gen(bottomLimit, bottomLimit+range-1), sprt0, sprt1, random);
                bottomLimit = bottomLimit + range;

            }

            unit[i][j].updateSprt();
        }
        if(fuelQuantity == 2){
            unit[i][2].setActive(false);
        }

    }

}





