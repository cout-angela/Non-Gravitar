#pragma once
#include "Fuel.h"
#include "GroundArray.h"

class FuelArray{
protected:
    Fuel unit[5][3];

public:

    /// Constructor
    FuelArray(GroundArray &groundArrayObj, sf::Sprite sprt0, sf::Sprite sprt1, Random &random);


    /// Getters
    bool getFActive(int &planetIndex, int j);
    float getFX(int &planetIndex, int j);
    float getFY(int &planetIndex, int j);
    int getFType(int &planetIndex, int j);

    /// Setters
    void setFType(int &planetIndex, int j, int _type);
    void setFActive(int &planetIndex, int j, bool _active);

    /// Draw
    void drawFuelArray(sf::RenderWindow &window, int &planetIndex);

    /// Re-spawn
    void respawnFuelArray(GroundArray &groundArrayObj, sf::Sprite sprt0, sf::Sprite sprt1, Random &random);
};
