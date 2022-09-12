#pragma once
#include "Entity.h"
#include "Random.h"


class Ground{
protected:
    int const length = 11;
    Entity unit[11];
    double distance = 0.0;

public:
    /// Constructor
    Ground();

    /// Set-up Ground
    void genPoints(Random &random);
    void addSprt(sf::Texture &txtr, float xO, float yO, sf::Texture &dotTxtr);

    /// Getters
    float getXU(int i);
    float getYU(int i);
    float getDirU(int i);
    int getLength();

    /// Draw
    void updateGround();
    void drawGround(sf::RenderWindow &window);

    /// Re-spawn
    void respawnGround(Random &random);

};
