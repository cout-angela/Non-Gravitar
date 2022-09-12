
#include "Lives.h"

/// Constructors
Lives::Lives(){}

Lives::Lives(float _x, float _y, float _dir, sf::Texture &txtr, float xOrigin, float yOrigin) : Entity(_x, _y, _dir, txtr, xOrigin, yOrigin){}



/// Draw
void Lives::drawLife(sf::RenderWindow &window){
    if(active){
        window.draw(sprt);
    }
}
