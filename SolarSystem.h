#pragma once

#include <iostream>

#include "Planets.h"

class SolarSystem{
protected:

    Planets systemPlanets;

public:

    SolarSystem();
    SolarSystem(int ScreenWidth, int ScreenHeight, sf::Texture &planetTxtr, float XO, float YO);


};
