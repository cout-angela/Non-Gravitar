#pragma once
#include "BulletEntity.h"

class BulletArray{

protected:
    BulletEntity bulletUnit[10];
public:

    ///Constructor
    BulletArray();

    void genBulletArray(float _x, float _y, float _dir, sf::Texture &txtr, float xOrigin, float yOrigin);

    /// Fire and Hit methods
    void fireBullet(float _x, float _y, float _dir, double sinSpeed, double cosSpeed);
    void isHit(int i);


    /// Getter
    BulletEntity getBulletUnit(int i);


    /// Setters
    void setBulletX(int i, float _x);
    void setBulletY(int i, float _y);
    void setBulletXSpeed(int i, double _xSpeed);
    void setBulletYSpeed(int i, double _ySpeed);
    void setBulletPos(int i, int _pos);



};
