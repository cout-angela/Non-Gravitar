#pragma once
#include <SFML/Graphics.hpp>
class Entity{
protected:
    ///stato
    bool active = true;
    /// posizione
    float x = 0.0, y = 0.0;
    /// rotazione
    float dir = 0.0;
    /// Sprite
    sf::Sprite sprt;
    sf::Sprite sprt2;
    /// Collision masks
    float lMask = 0.0;
    float rMask = 0.0;
    float uMask = 0.0;
    float dMask = 0.0;


public:

    /// costruttori
    Entity();
    Entity(float _x, float _y, float _dir);
    Entity(float _x, float _y, sf::Texture &txtr, float xOrigin, float yOrigin);
    Entity(float _x, float _y, float _dir, sf::Texture &txtr, float xOrigin, float yOrigin);
    /// getters
    bool getActive();
    float getX();
    float getY();
    float getDir();
    sf::Sprite getSprt();
    sf::Sprite getSprt2();
    float getLMask();
    float getRMask();
    float getUMask();
    float getDMask();
    /// setters
    void setActive(bool _active);
    void setX(float _x);
    void setY(float _y);
    void setDir(float _dir);
    void setSprite(sf::Texture &txtr, float xOrigin, float yOrigin);
    void setSpriteScale(float xS, float yS);
    void setSpriteOrigins(float xO, float yO);
    void setSpriteColour(sf::Color &colour);
    void setSprite2(sf::Texture &txtr, float xOrigin, float yOrigin);
    void setSprite2Scale(float xS, float yS);
    void setLMask(float _lMask);
    void setRMask(float _rMask);
    void setUMask(float _uMask);
    void setDMask(float _dMask);
    void setAllMasks(float _lMask, float _rMask, float _uMask, float _dMask);
    /// Sprite update
    void updateSprtpos();
    void updateSprtrot();
    void updateSprt();
    void updateSprt2pos();
    void updateSprt2rot();
    void updateSprt2();
    void updateAllSprt();
    /// Draw
    void draw(sf::RenderWindow &window);
    void updateDraw(sf::RenderWindow &window);
    void draw2(sf::RenderWindow &window);
    void updateDraw2(sf::RenderWindow &window);

    /// respawn
    void respawnEntity(float _x, float _y, float _dir);
};
