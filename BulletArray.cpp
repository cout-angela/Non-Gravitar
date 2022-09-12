#include "BulletArray.h"

/// Constructor
BulletArray::BulletArray(){}

void BulletArray::genBulletArray(float _x, float _y, float _dir, sf::Texture &txtr, float xOrigin, float yOrigin){

    for (int i = 0; i < 10; i++){
        bulletUnit[i] = BulletEntity(_x, _y, _dir, txtr, xOrigin, yOrigin);
        bulletUnit[i].setAllMasks(4.0, 4.0, 4.0, 4.0);
    }
}


/// Fire and Hit methods

void BulletArray::fireBullet(float _x, float _y, float _dir, double sinSpeed, double cosSpeed){
    for(int i = 0; i < 10; i++){
        if(!(bulletUnit[i].getFired())){

            bulletUnit[i].fire(_x, _y, _dir, sinSpeed, cosSpeed);
            i = 10;

        }
    }
}

void BulletArray::isHit(int i){
    bulletUnit[i].hit();
}





/// Getter
BulletEntity BulletArray::getBulletUnit(int i){
        return bulletUnit[i];
}

/// Setters

void BulletArray::setBulletX(int i, float _x){
    bulletUnit[i].setX(_x);
}
void BulletArray::setBulletY(int i, float _y){
    bulletUnit[i].setY(_y);
}
void BulletArray::setBulletXSpeed(int i, double _xSpeed){
    bulletUnit[i].setXSpeed(_xSpeed);
}
void BulletArray::setBulletYSpeed(int i, double _ySpeed){
    bulletUnit[i].setYSpeed(_ySpeed);
}




