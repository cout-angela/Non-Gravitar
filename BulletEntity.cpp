
#include "BulletEntity.h"

/// Constructors
BulletEntity::BulletEntity(){}

BulletEntity::BulletEntity(float _x, float _y, float _dir, sf::Texture &txtr, float xOrigin, float yOrigin) : Entity(_x, _y, _dir, txtr, xOrigin, yOrigin){
    active = false;
}



/// Fire and Hit methods

void BulletEntity::fire(float _x, float _y, float _dir, double sinSpeed, double cosSpeed){
    active = true;
    x = _x;
    y = _y;
    sprt.setRotation(_dir);
    xSpeed = cosSpeed;
    ySpeed = sinSpeed;

}

void BulletEntity::hit(){
    active = false;
    xSpeed = 0.0;
    ySpeed = 0.0;
}



/// Getters

bool BulletEntity::getFired(){
    return active;
}
double BulletEntity::getXSpeed(){
    return xSpeed;
}
double BulletEntity::getYSpeed(){
    return ySpeed;
}



/// Setters

void BulletEntity::setXSpeed(double _xSpeed){
    xSpeed = _xSpeed;
}
void BulletEntity::setYSpeed(double _ySpeed){
    ySpeed = _ySpeed;
}




/// Draw

void BulletEntity::draw(sf::RenderWindow &window){
    sprt.setPosition(x, y);
    window.draw(sprt);
}










