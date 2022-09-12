#pragma once
#include <stdlib.h>
#include <ctime>
#include <SFML/Graphics.hpp>


class Random {
protected:

public:
    Random();
    int gen (int a, int b);
    float genFloat(int a);
    int neg (int a);
    void genPlanetColour (sf::Color &colour);
    void genStarColour (sf::Color &colour);

};
