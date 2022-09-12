#pragma once
#include <SFML/Graphics.hpp>

class Input {
protected:
    bool rightIn = false;
    bool leftIn = false;
    bool upIn = false;
    bool downIn = false;
    bool fireInPressed = false;
    bool beamIn = false;
    bool returnIn = false;

public:

    ///  Getters
    bool getRight();
    bool getLeft();
    bool getUp();
    bool getDown();
    bool getFire();
    bool getBeam();
    bool getReturn();


    /// Check for Return
    void checkReturn(sf::Event &event);
    /// Check all the player's inputs
    void checkAll(sf::Event &event);


};
