#pragma once
#include "Bunker.h"
#include "Random.h"
#include "Ground.h"
#include "GroundArray.h"
#include <SFML/Graphics.hpp>

class BunkerArray {

protected:
    Bunker unit[5][3];

public:

    ///Constructors
    BunkerArray();

    BunkerArray(GroundArray &groundArrayObj, sf::Texture &bunkerTxtr, sf::Texture &bulletTxtr, Random &random);


    /// Bullets' Fire and Hit methods
    void fireBullet(int i, int j, float _x, float _y, float _dir, double sinSpeed, double cosSpeed);
    void isHit(int i, int j, int bIndex);


    ///Getter
    Bunker getBunker(int i, int j);

    ///Setter
    void setBunkerActive(int i, int j, bool _active);

    /// Bullet setters
    void setBulletX(int i, int j, int bIndex, float _x);
    void setBulletY(int i, int j, int bIndex, float _y);
    void setBulletXSpeed(int i, int j, int bIndex, double _xSpeed);
    void setBulletYSpeed(int i, int j, int bIndex, double _ySpeed);

    /// Draw
    void drawBunkerArray(sf::RenderWindow &window, int &planetIndex);

    /// Re-spawn
    void respawnBunkerArray(GroundArray &groundArrayObj, Random &random);
};
