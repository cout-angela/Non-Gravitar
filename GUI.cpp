
#include "GUI.h"

/// Constructor
GUI::GUI(float _x, float _y, float _dir, sf::Texture &txtr, float xOrigin, float yOrigin, sf::Texture &heartTxtr, sf::Texture &fuelBarTxtr) : Entity(_x, _y, _dir, txtr, xOrigin, yOrigin){
    ///lives setup
    for (int i = 0; i < 3; i++){
        life[i] = Lives(1300.0 + (((float)i)+1.0)*35.0, 15.0, 0.0, heartTxtr, 9.0, 8.0);
        life[i].setSpriteScale(1.7, 1.7);
    }
    ///fuelbar setup
    bar = FuelBar(1500.0, 17.0, 0.0, fuelBarTxtr, 0.0, 13.0);
    bar.updateSprt();

}


/// Getter
float GUI::getFuelTank(){
    return bar.getTank();
}


/// Setters
void GUI::setLivesActive(int hearts){
    for(int i = 0; i < 3; i++){
        if(hearts <= i){
            life[i].setActive(false);
        } else {
            life[i].setActive(true);
        }
    }
}
void GUI::setFuelTank(float _tank){
    bar.setTank(_tank);
}


/// Draw
void GUI::updateLives(){
    for (int i = 0; i < 3; i++){
        life[i].updateSprt();
    }
}
void GUI::drawAll(sf::RenderWindow &window){
    window.draw(sprt);
    for (int i = 0; i < 3; i++){
        life[i].drawLife(window);
    }
    window.draw(bar.getSprt());
}
