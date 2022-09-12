#include "GroundArray.h"


/// Constructor
GroundArray::GroundArray(sf::Texture &txtr, float xO, float yO, sf::Texture &dotTxtr, Random &random){

    for(int i = 0; i < 5; i++){
        groundUnit[i].genPoints(random);
        groundUnit[i].addSprt(txtr, xO, yO, dotTxtr);
        groundUnit[i].updateGround();
    }
}


/// Getter
Ground GroundArray::getGround(int &planetIndex){

    return groundUnit[planetIndex];
}


/// Draw
void GroundArray::drawCurrentGround(sf::RenderWindow &window, int &planetIndex){

    groundUnit[planetIndex].drawGround(window);
}


/// Re-spawn
void GroundArray::respawnGroundArray(Random &random){

    for(int i = 0; i < 5; i++){
        groundUnit[i].respawnGround(random);
    }
}

