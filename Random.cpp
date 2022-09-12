#include "Random.h"
#include <iostream>
Random::Random (){
        srand(time(NULL));
}

int Random::gen(int a, int b){

    if (a > b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    return (rand() % (b - a + 1) + a);
}


float Random::genFloat(int a){ // a must be between zero and 100, returns a number between a and 1
    return (((rand()%(101 - a))+a)/100.0);
}

int Random::neg(int a){
    if(a < 0)
        a = -a;
    return (rand()% (2*a + 1) - a);
}

void Random::genPlanetColour (sf::Color &colour){

    int choose = rand()%6;

    if(choose == 0){
        colour = sf::Color(0, 255, 0, 255);

    }else if(choose == 1){
        colour = sf::Color(0, 0, 255, 255);

    }else if(choose == 2){
        colour = sf::Color(0, 255, 255, 255);

    }else if(choose == 3){
        colour = sf::Color(255, 0, 255, 255);

    }else if(choose == 4){
        colour = sf::Color(255, 0, 0, 255);

    }else{
        colour = sf::Color(255, 255, 0, 255);

    }
}

void Random::genStarColour (sf::Color &colour){

    int choose = rand()%3;

    if(choose == 0){
        colour = sf::Color(255, 255, 255, 255);

    }else if(choose == 1){
        colour = sf::Color(255, 165, 0, 255);

    }else{
        colour = sf::Color(0, 146, 250, 255);

    }

}

















