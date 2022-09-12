#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include "Lives.h"
#include "FuelBar.h"
#include "Score.h"

class GUI : public Entity{

protected:
    sf::Sprite background;
    Lives life[3];
    FuelBar bar;

public:

    /// Constructor
    GUI(float _x, float _y, float _dir, sf::Texture &txtr, float xOrigin, float yOrigin, sf::Texture &heartTxtr, sf::Texture &fuelBarTxtr);

    /// Getter
    float getFuelTank();

    /// Setters
    void setLivesActive(int hearts);
    void setFuelTank(float _tank);

    /// Draw
    void updateLives();
    void drawAll(sf::RenderWindow &window);
};
