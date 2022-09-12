
#include "Input.h"


/// Getters
bool Input::getRight(){
    return rightIn;
}
bool Input::getLeft(){
    return leftIn;
}
bool Input::getUp(){
    return upIn;
}
bool Input::getDown(){
    return downIn;
}
bool Input::getFire(){
    return fireInPressed;
}
bool Input::getBeam(){
    return beamIn;
}
bool Input::getReturn(){
    return returnIn;
}


/// Check for Return
void Input::checkReturn(sf::Event &event){
    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return){
        returnIn = false;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
        returnIn = true;
    }
}


/// Check all the player's inputs
void Input::checkAll(sf::Event &event){
    /// Movement
    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Right){
        rightIn = false;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        rightIn = true;
    }
    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Left){
        leftIn = false;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        leftIn = true;
    }
    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up){
        upIn = false;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        upIn = true;
    }
    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down){
        downIn = false;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        downIn = true;
    }
    /// Fire
    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Z){
        fireInPressed = false;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
        fireInPressed = true;
    }
    /// Beam
    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::C){
        beamIn = false;

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
        beamIn = true;
    }
}

