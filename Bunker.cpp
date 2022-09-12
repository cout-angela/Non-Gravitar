
#include "Bunker.h"

/// Constructors

Bunker::Bunker(){}

Bunker::Bunker(Ground groundObj, int pos, sf::Texture &bunkerTxtr, sf::Texture &bulletTxtr, Random &random){
    x = (groundObj.getXU(pos) - groundObj.getXU(pos+1))/2.0 + groundObj.getXU(pos+1);

    if(groundObj.getYU(pos) < groundObj.getYU(pos+1)){
        y = (groundObj.getYU(pos+1) - groundObj.getYU(pos))/2.0 + groundObj.getYU(pos);
    } else {
        y = (groundObj.getYU(pos) - groundObj.getYU(pos+1))/2.0 + groundObj.getYU(pos+1);
    }

    type = random.gen(0, 1);
    sprt.setTexture(bunkerTxtr);
    sprt.setOrigin(36.0, 27.0);
    dir = groundObj.getDirU(pos) + 180.0;

    ammo.genBulletArray(1000.0, 0.0, 0.0, bulletTxtr, 4.0, 4.0);
}



/// Bullets' Fire and Hit methods

void Bunker::fire(float _x, float _y, float _dir, double sinSpeed, double cosSpeed){
    ammo.fireBullet(_x, _y, _dir, sinSpeed, cosSpeed);

}

void Bunker::hit(int i){
    ammo.isHit(i);

}



/// Getters

BulletArray Bunker::getAmmo(){
    return ammo;
}
int Bunker::getType(){
    return type;
}



/// Setter

void Bunker::genType(Random &random){
    type = random.gen(0, 1);
}



///Bullet setters

void Bunker::setBX(int i, float _x){
    ammo.setBulletX(i, _x);
}
void Bunker::setBY(int i, float _y){
    ammo.setBulletY(i, _y);
}
void Bunker::setBXSpeed(int i, double _xSpeed){
    ammo.setBulletXSpeed(i, _xSpeed);
}
void Bunker::setBYSpeed(int i, double _ySpeed){
    ammo.setBulletYSpeed(i, _ySpeed);
}



/// respawn

void Bunker::respawnBunker(Ground groundObj, int pos, Random &random){
    x = (groundObj.getXU(pos) - groundObj.getXU(pos+1))/2.0 + groundObj.getXU(pos+1);

    if(groundObj.getYU(pos) < groundObj.getYU(pos+1)){
        y = (groundObj.getYU(pos+1) - groundObj.getYU(pos))/2.0 + groundObj.getYU(pos);
    } else {
        y = (groundObj.getYU(pos) - groundObj.getYU(pos+1))/2.0 + groundObj.getYU(pos+1);
    }

    type = random.gen(0, 1);
    dir = groundObj.getDirU(pos) + 180.0;

}
