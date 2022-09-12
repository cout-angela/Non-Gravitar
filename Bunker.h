#pragma once
#include "Entity.h"
#include "Ground.h"
#include "BulletArray.h"
#include <SFML/Graphics.hpp>


class Bunker : public Entity{
protected:
    float reloadTime = 1.0;
    int type;
    BulletArray ammo;

public:

    /// Constructors
    Bunker();
    Bunker(Ground groundObj, int pos, sf::Texture &bunkerTxtr, sf::Texture &bulletTxtr, Random &random);


    /// Bullets' Fire and Hit methods
    void fire(float _x, float _y, float _dir, double sinSpeed, double cosSpeed);
    void hit(int i);

    /// Getters
    BulletArray getAmmo();
    int getType();

    ///Setter
    void genType(Random &random);

    /// Bullet setters
    void setBX(int i, float _x);
    void setBY(int i, float _y);
    void setBXSpeed(int i, double _xSpeed);
    void setBYSpeed(int i, double _ySpeed);



    /// respawn
    void respawnBunker(Ground groundObj, int pos, Random &random);
};

