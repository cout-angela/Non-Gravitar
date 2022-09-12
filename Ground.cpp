
#include "Ground.h"
#include <cmath>

/// Constructor
Ground::Ground(){}


/// Set-up Ground
void Ground::genPoints(Random &random){

    unit[0] = Entity(1920.0, (float)random.gen(750, 1000), 180.0);
    for (int i = 1; i <= 9; i++){
        unit[i] = Entity(unit[i-1].getX() - (float)random.gen(180, 215), (float)random.gen(750, 1000), 180.0);
    }
    unit[10] = Entity(0.0, unit[9].getY() + (float)random.neg(100), 0.0);
}
void Ground::addSprt(sf::Texture &txtr, float xO, float yO, sf::Texture &dotTxtr){

    for(int i = 0; i <= 9; i++){
        distance = sqrt(pow(unit[i].getX() - unit[i+1].getX(), 2) + pow(unit[i].getY() - unit[i+1].getY(), 2));
        unit[i].setDir(unit[i].getDir() + ((asin((unit[i].getY() - unit[i+1].getY())/((float)distance))))*180.0/3.14);
        unit[i].setSprite(txtr, xO, yO);
        unit[i].setSprite2(dotTxtr, 4.0, 4.0);
        unit[i].setSpriteScale(((float)distance)/10.0, 1.0);
    }
    unit[10].setSprite2(dotTxtr, 4.0, 4.0);
}


/// Getters
float Ground::getXU(int i){
    return (unit[i].getX());
}
float Ground::getYU(int i){
    return (unit[i].getY());
}
float Ground::getDirU(int i){
    return (unit[i].getDir());
}
int Ground::getLength(){
    return length;
}


/// Draw
void Ground::updateGround(){
    for(int i = 0; i < 10; i++){
        unit[i].updateSprt();
        unit[i].updateSprt2();
    }
    unit[10].updateSprt2();
}

void Ground::drawGround(sf::RenderWindow &window){
    for(int i = 0; i < 10; i++){
        window.draw(unit[i].getSprt());
        window.draw(unit[i].getSprt2());
    }
    window.draw(unit[10].getSprt2());
}



/// Re-spawn
void Ground::respawnGround(Random &random){
    /// relocate the ground points
    unit[0].respawnEntity(1920.0, (float)random.gen(750, 1000), 180.0);
    for (int i = 1; i <= 9; i++){
        unit[i].respawnEntity(unit[i-1].getX() - (float)random.gen(180, 215), (float)random.gen(750, 1000), 180.0);
    }
    unit[10].respawnEntity(0.0, unit[9].getY() + (float)random.neg(100), 0.0);

    /// reconnect the the points using their textures

    for(int i = 0; i <= 9; i++){
        distance = sqrt(pow(unit[i].getX() - unit[i+1].getX(), 2) + pow(unit[i].getY() - unit[i+1].getY(), 2));
        unit[i].setDir(unit[i].getDir() + ((asin((unit[i].getY() - unit[i+1].getY())/((float)distance))))*180.0/3.14);
        unit[i].setSpriteScale(((float)distance)/10, 1.0);
    }

    /// update the sprites' parameters

    for(int i = 0; i < 10; i++){
        unit[i].updateSprt();
        unit[i].updateSprt2();
    }
    unit[10].updateSprt2();
}
