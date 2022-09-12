#pragma once
#include "Ground.h"

class GroundArray{
protected:
    Ground groundUnit[5];

public:

    /// Constructor
    GroundArray(sf::Texture &txtr, float xO, float yO, sf::Texture &dotTxtr, Random &random);


    /// Getter
    Ground getGround(int &planetIndex);


    ///Draw ground
    void drawCurrentGround(sf::RenderWindow &window, int &planetIndex);


    /// Re-spawn
    void respawnGroundArray(Random &random);
};
