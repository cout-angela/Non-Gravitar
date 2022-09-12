#pragma once
#include <iostream>
#include "Entity.h"
#include "BulletArray.h"
class Player : public Entity{
protected:
    float xSpeed = 0.0;
    float ySpeed = 0.0;
    BulletArray ammo;
    bool beamOn = false;
    float beamRadius = 150.0;
public:
    Player (float _x, float _y, float _dir, sf::Texture &txtr, sf::Texture &txtr2, sf::Texture &bulletTxtr, float xOrigin, float yOrigin);

    ///Player bullet logic
    void fire(float _x, float _y, float _dir, double sinSpeed, double cosSpeed);
    void hit(int i);



    double getXSpeed();
    double getYSpeed();
    void setXSpeed(float _xSpeed);
    void setYSpeed(float _ySpeed);

    BulletEntity getBullet(int i);

    /// Bullet setters
    void setBX(int i, float _x);
    void setBY(int i, float _y);
    void setBXSpeed(int i, double _xSpeed);
    void setBYSpeed(int i, double _ySpeed);
    void setPos(int i, int _pos);
    void drawPlayerBullet(sf::RenderWindow &window);

    /// Tractor BEAM
    void setBeam(bool _beamOn);
    bool getBeam();
    float getRadius();
};
