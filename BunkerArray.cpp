
#include "BunkerArray.h"


///Constructors

BunkerArray::BunkerArray(){}

BunkerArray::BunkerArray(GroundArray &groundArrayObj, sf::Texture &bunkerTxtr, sf::Texture &bulletTxtr, Random &random){

    for(int i = 0; i < 5; i++){
        int positions = groundArrayObj.getGround(i).getLength() - 1; //possible positions in which to set the bunkers

        int bunkerQuantity = random.gen(2, 3);
        int spaceLeft = positions%bunkerQuantity; //exceeding positions to be distributed
        int range = positions/bunkerQuantity; // possible positions per bunker
        int bottomLimit = 0; //bottom position per range

        for(int j = 0; j < 3; j++){

            if(spaceLeft > 0){
                unit[i][j] = Bunker(groundArrayObj.getGround(i), random.gen(bottomLimit, bottomLimit+range), bunkerTxtr, bulletTxtr, random);
                spaceLeft = spaceLeft - 1;
                bottomLimit = bottomLimit + range+1;
            } else {
                unit[i][j] = Bunker(groundArrayObj.getGround(i), random.gen(bottomLimit, bottomLimit+range-1), bunkerTxtr, bulletTxtr, random);
                bottomLimit = bottomLimit + range;
            }
            unit[i][j].setAllMasks(30.0, 30.0, 21.0, 21.0);
            unit[i][j].updateSprt();
        }
        if(bunkerQuantity == 2){
            unit[i][2].setActive(false);
        }

    }

}


/// Bullets' Fire and Hit methods
void BunkerArray::fireBullet(int i, int j, float _x, float _y, float _dir, double sinSpeed, double cosSpeed){
        unit[i][j].fire(_x, _y, _dir, sinSpeed, cosSpeed);

}
void BunkerArray::isHit(int i, int j, int bIndex){
        unit[i][j].hit(bIndex);

}

/// Getter
Bunker BunkerArray::getBunker(int i, int j){
    return unit[i][j];
}

///Setter
void BunkerArray::setBunkerActive(int i, int j, bool _active){
    unit[i][j].setActive(_active);
}

/// Bullet setters
void BunkerArray::setBulletX(int i, int j, int bIndex, float _x){
    unit[i][j].setBX(bIndex, _x);
}
void BunkerArray::setBulletY(int i, int j, int bIndex, float _y){
    unit[i][j].setBY(bIndex, _y);
}
void BunkerArray::setBulletXSpeed(int i, int j, int bIndex, double _xSpeed){
    unit[i][j].setBXSpeed(bIndex, _xSpeed);
}
void BunkerArray::setBulletYSpeed(int i, int j, int bIndex, double _ySpeed){
    unit[i][j].setBYSpeed(bIndex, _ySpeed);
}

/// Draw
void BunkerArray::drawBunkerArray(sf::RenderWindow &window, int &planetIndex){
    for(int i = 0; i < 3; i++){
        if(unit[planetIndex][i].getActive()){
            window.draw(unit[planetIndex][i].getSprt());
            for(int j = 0; j < 10; j++){
                if(unit[planetIndex][i].getAmmo().getBulletUnit(j).getFired()){
                    window.draw(unit[planetIndex][i].getAmmo().getBulletUnit(j).getSprt());
                }
            }
        }
    }
}


/// Re-spawn
void BunkerArray::respawnBunkerArray(GroundArray &groundArrayObj, Random &random){

    for(int i = 0; i < 5; i++){
        int positions = groundArrayObj.getGround(i).getLength() - 1; //possible positions in which to set the bunkers

        int bunkerQuantity = random.gen(2, 3);
        int spaceLeft = positions%bunkerQuantity; //exceeding positions to be distributed
        int range = positions/bunkerQuantity; // possible positions per bunker
        int bottomLimit = 0; //bottom position per range

        for(int j = 0; j < 3; j++){
            unit[i][j].setActive(true); // re-activates all the destroyed bunkers of the previous system
            if(spaceLeft > 0){
                unit[i][j].respawnBunker(groundArrayObj.getGround(i), random.gen(bottomLimit, bottomLimit+range), random);
                spaceLeft = spaceLeft - 1;
                bottomLimit = bottomLimit + range+1;
            } else {
                unit[i][j].respawnBunker(groundArrayObj.getGround(i), random.gen(bottomLimit, bottomLimit+range-1), random);
                bottomLimit = bottomLimit + range;
            }
            unit[i][j].updateSprt();
        }
        if(bunkerQuantity == 2){
            unit[i][2].setActive(false);
        }

    }
}

