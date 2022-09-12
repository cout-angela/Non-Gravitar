
#include "Entity.h"

///costruttori
Entity::Entity(){}
Entity::Entity(float _x, float _y, float _dir){
    x = _x;
    y = _y;
    dir = _dir;
}
Entity::Entity(float _x, float _y, sf::Texture &txtr, float xOrigin, float yOrigin){
    x = _x;
    y = _y;
    sprt.setTexture(txtr);
    sprt.setOrigin(xOrigin, yOrigin);
}
Entity::Entity(float _x, float _y, float _dir, sf::Texture &txtr, float xOrigin, float yOrigin){
    x = _x;
    y = _y;
    dir = _dir;
    sprt.setTexture(txtr);
    sprt.setOrigin(xOrigin, yOrigin);
}

/// Status Getter
bool Entity::getActive(){
    return active;
}
///Position and Rotation getters
float Entity::getX(){
    return x;
}
float Entity::getY(){
    return y;
}
float Entity::getDir(){
    return dir;
}
/// Sprite getter
sf::Sprite Entity::getSprt(){
    return sprt;
}
sf::Sprite Entity::getSprt2(){
    return sprt2;
}

/// Mask getters
float Entity::getLMask(){
    return (x - lMask);
}
float Entity::getRMask(){
    return (x + rMask);
}
float Entity::getUMask(){
    return (y - uMask);
}
float Entity::getDMask(){
    return (y + dMask);
}


///Status setter
void Entity::setActive(bool _active){
    active = _active;
}
///Position and Rotation setters
void Entity::setX(float _x){
    x = _x;
}
void Entity::setY(float _y){
    y = _y;
}
void Entity::setDir(float _dir){
    dir = _dir;
}
/// Sprite setters
void Entity::setSprite(sf::Texture &txtr, float xOrigin, float yOrigin){
    sprt.setTexture(txtr);
    sprt.setOrigin(xOrigin, yOrigin);
}
void Entity::setSpriteScale(float xS, float yS){
    sprt.setScale(xS, yS);
}
void Entity::setSpriteOrigins(float xO, float yO){
    sprt.setOrigin(xO, yO);
}
void Entity::setSpriteColour(sf::Color &colour){
    sprt.setColor(colour);
}
/// Sprite2 setters
void Entity::setSprite2(sf::Texture &txtr, float xOrigin, float yOrigin){
    sprt2.setTexture(txtr);
    sprt2.setOrigin(xOrigin, yOrigin);
}
void Entity::setSprite2Scale(float xS, float yS){
    sprt2.setScale(xS, yS);
}

/// Mask setters
void Entity::setLMask(float _lMask){
    lMask = _lMask;
}
void Entity::setRMask(float _rMask){
    rMask = _rMask;
}
void Entity::setUMask(float _uMask){
    uMask = _uMask;
}
void Entity::setDMask(float _dMask){
    dMask = _dMask;
}
void Entity::setAllMasks(float _lMask, float _rMask, float _uMask, float _dMask){
    lMask = _lMask;
    rMask = _rMask;
    uMask = _uMask;
    dMask = _dMask;
}


///Sprite update
void Entity::updateSprtpos(){
    sprt.setPosition(x, y);
}
void Entity::updateSprtrot(){
    sprt.setRotation(dir);
}
void Entity::updateSprt(){
    sprt.setPosition(x, y);
    sprt.setRotation(dir);
}
void Entity::updateSprt2pos(){
    sprt2.setPosition(x, y);
}
void Entity::updateSprt2rot(){
    sprt2.setRotation(dir);
}
void Entity::updateSprt2(){
    sprt2.setPosition(x, y);
    sprt2.setRotation(dir);
}
void Entity::updateAllSprt(){
    sprt.setPosition(x, y);
    sprt.setRotation(dir);
    sprt2.setPosition(x, y);
    sprt2.setRotation(dir);
}


/// Draw
void Entity::draw(sf::RenderWindow &window){
    window.draw(sprt);
}
void Entity::updateDraw(sf::RenderWindow &window){
    sprt.setPosition(x, y);
    sprt.setRotation(dir);
    window.draw(sprt);
}
void Entity::draw2(sf::RenderWindow &window){
    window.draw(sprt2);
}
void Entity::updateDraw2(sf::RenderWindow &window){
    sprt2.setPosition(x, y);
    sprt2.setRotation(dir);
    window.draw(sprt2);
}



/// respawn

void Entity::respawnEntity(float _x, float _y, float _dir){
    x = _x;
    y = _y;
    dir = _dir;
}
