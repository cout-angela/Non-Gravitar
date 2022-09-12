#pragma once
#include "Entity.h"

class BulletEntity : public Entity{
protected:
    double xSpeed = 0.0;
    double ySpeed = 0.0;

public:

    /// Constructors
    BulletEntity();

    BulletEntity(float _x, float _y, float _dir, sf::Texture &txtr, float xOrigin, float yOrigin);



    /// Fire and hit methods
    void fire(float _x, float _y, float _dir, double sinSpeed, double cosSpeed);
    void hit();

    /// Getters
    bool getFired();
    double getXSpeed();
    double getYSpeed();


    /// Setters
    void setXSpeed(double _xSpeed);
    void setYSpeed(double _ySpeed);


    /// Draw
    void draw(sf::RenderWindow &window);

};
