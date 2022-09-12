#pragma once
#include "Entity.h"
#include "Random.h"

class Planets{
protected:

    Entity planetUnit[5];

public:
    Planets();
    Planets(sf::Texture &txtr0, sf::Texture &txtr1, sf::Texture &txtr2, float XO, float YO, sf::Color &colour, Random &random);

    ///Getters

    float getXP(int i);
    float getYP(int i);
    bool getActive(int i);
    int getAlivePlanets();
    //get Masks
    float getLMask(int i);
    float getRMask(int i);
    float getUMask(int i);
    float getDMask(int i);

    ///Setters
    void setActive(int i, bool _active);


    void drawPlanets(sf::RenderWindow &window);

    /// respawn
    void respawnPlanets(sf::Texture &txtr0, sf::Texture &txtr1, sf::Texture &txtr2, sf::Color &colour, Random &random);
};
