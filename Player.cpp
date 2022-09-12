
#include "Player.h"

Player::Player(float _x, float _y, float _dir, sf::Texture &txtr, sf::Texture &txtr2, sf::Texture &bulletTxtr, float xOrigin, float yOrigin) : Entity(_x, _y, _dir, txtr, xOrigin, yOrigin){
    ammo.genBulletArray(1000.0, 0.0, 0.0, bulletTxtr, 4, 4);
    sprt2.setTexture(txtr2);
    sprt2.setOrigin(150.0, 150.0);
}



///Player bullet logic

void Player::fire(float _x, float _y, float _dir, double sinSpeed, double cosSpeed){
    ammo.fireBullet(_x, _y, _dir, sinSpeed, cosSpeed);

}

void Player::hit(int i){
    ammo.isHit(i);

}






double Player::getXSpeed(){
    return xSpeed;
}
double Player::getYSpeed(){
    return ySpeed;
}
void Player::setXSpeed(float _xSpeed){
    xSpeed = _xSpeed;
}
void Player::setYSpeed(float _ySpeed){
    ySpeed = _ySpeed;
}

/// bullet getters
BulletEntity Player::getBullet(int i){
    return (ammo.getBulletUnit(i));
}



///Bullet setters

void Player::setBX(int i, float _x){
    ammo.setBulletX(i, _x);
}
void Player::setBY(int i, float _y){
    ammo.setBulletY(i, _y);
}
void Player::setBXSpeed(int i, double _xSpeed){
    ammo.setBulletXSpeed(i, _xSpeed);
}
void Player::setBYSpeed(int i, double _ySpeed){
    ammo.setBulletYSpeed(i, _ySpeed);
}

void Player::drawPlayerBullet(sf::RenderWindow &window){
    for(int i = 0; i < 10; i++){
        if(ammo.getBulletUnit(i).getFired()){
            ammo.getBulletUnit(i).draw(window);
        }
    }
}
///Tractor Beam
void Player::setBeam(bool _beamOn){
    beamOn = _beamOn;
}
bool Player::getBeam(){
    sprt2.setPosition(x, y);
    return beamOn;
}
float Player::getRadius(){
    return beamRadius;
}
