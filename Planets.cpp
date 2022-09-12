#include "Planets.h"

Planets::Planets(){}


Planets::Planets(sf::Texture &txtr0, sf::Texture &txtr1, sf::Texture &txtr2, float XO, float YO, sf::Color &colour, Random &random){
    float planetSize;

    int txtr;

    int activePlanets = random.gen(4, 5);

    float spacesWidth = 1920.0 / (activePlanets + 2.0); //width of the spaces for the planets, sun and player




    for(int i = 0; i < 5; i++ ){

        txtr = random.gen(0,2);
        if(txtr == 0){
            planetUnit[i] = Entity(random.gen(spacesWidth *(i + 1) + 100, spacesWidth * (i + 2) - 100), random.gen(400, 700), txtr0, XO, YO);
        }else if(txtr == 1){
            planetUnit[i] = Entity(random.gen(spacesWidth *(i + 1) + 100, spacesWidth * (i + 2) - 100), random.gen(400, 700), txtr1, XO, YO);
        }else{
            planetUnit[i] = Entity(random.gen(spacesWidth *(i + 1) + 100, spacesWidth * (i + 2) - 100), random.gen(400, 700), txtr2, XO, YO);
            planetUnit[i].setDir(random.gen(0, 359));
        }
        random.genPlanetColour(colour);
        planetUnit[i].setSpriteColour(colour);
        if(random.gen(0, 1) == 0){
            planetSize = random.genFloat(80);
            planetUnit[i].setSpriteScale(planetSize, planetSize);
            planetUnit[i].setAllMasks(65.0*planetSize, 65.0*planetSize, 65.0*planetSize, 65.0*planetSize);
        } else {
            planetUnit[i].setAllMasks(65.0, 65.0, 65.0, 65.0);

        }
        planetUnit[i].updateSprt();

    }
    if(activePlanets == 4){
        planetUnit[4].setActive(false);
    }
}





 /// QUANDO NUOVO SISTEMA CAMBIA LE POSIZIONI E AGGIORNA LE SPRITE






///Getters

float Planets::getXP(int i){
    return (planetUnit[i].getX());
}
float Planets::getYP(int i){

    return (planetUnit[i].getY());
}

bool Planets::getActive(int i){

    return (planetUnit[i].getActive());
}

int Planets::getAlivePlanets(){

    int c = 0;
    for(int i = 0; i < 5; i++){

        if(planetUnit[i].getActive()){
            c = c + 1;
        }

    }

    return c;
}







float Planets::getLMask(int i){

    return (planetUnit[i].getLMask());
}
float Planets::getRMask(int i){

    return (planetUnit[i].getRMask());
}
float Planets::getUMask(int i){

    return (planetUnit[i].getUMask());
}
float Planets::getDMask(int i){

    return (planetUnit[i].getDMask());
}

///Setters

void Planets::setActive(int i, bool _active){

    planetUnit[i].setActive(_active);
}








void Planets::drawPlanets(sf::RenderWindow &window){

    for(int i = 0; i < 5; i++){

         if(planetUnit[i].getActive()){

            window.draw(planetUnit[i].getSprt());

         }
    }
}

/// respawn

void Planets::respawnPlanets(sf::Texture &txtr0, sf::Texture &txtr1, sf::Texture &txtr2, sf::Color &colour, Random &random){
    float planetSize;

    int txtr;

    int activePlanets = random.gen(4, 5);

    float spacesWidth = 1920.0 / (activePlanets + 2.0); //width of the spaces for the planets, sun and player




    for(int i = 0; i < 5; i++ ){
        planetUnit[i].setActive(true); // re-activates all the destroyed planets of the previous system
        txtr = random.gen(0,2);
        if(txtr == 0){
            planetUnit[i].respawnEntity(random.gen(spacesWidth *(i + 1.0) + 100.0, spacesWidth * (i + 2.0) - 100.0), random.gen(400, 700), 0.0);
            planetUnit[i].setSprite(txtr0, 75.0, 75.0);
        }else if(txtr == 1){
            planetUnit[i].respawnEntity(random.gen(spacesWidth *(i + 1.0) + 100.0, spacesWidth * (i + 2.0) - 100.0), random.gen(400, 700), 0.0);
            planetUnit[i].setSprite(txtr1, 75.0, 75.0);
        }else{
            planetUnit[i].respawnEntity(random.gen(spacesWidth *(i + 1.0) + 100.0, spacesWidth * (i + 2.0) - 100.0), random.gen(400, 700), random.gen(0, 359));
            planetUnit[i].setSprite(txtr2, 75.0, 75.0);
        }
        random.genPlanetColour(colour);
        planetUnit[i].setSpriteColour(colour);
        if(random.gen(0, 1) == 0){
            planetSize = random.genFloat(80);
            planetUnit[i].setSpriteScale(planetSize, planetSize);
            planetUnit[i].setAllMasks(65.0*planetSize, 65.0*planetSize, 65.0*planetSize, 65.0*planetSize);
        } else {
            planetUnit[i].setAllMasks(65.0, 65.0, 65.0, 65.0);

        }
        planetUnit[i].updateSprt();

    }
    if(activePlanets == 4){
        planetUnit[4].setActive(false);
    }
}

