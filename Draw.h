
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Ground.h"
#include "Bunker.h"
#include "BunkerArray.h"
#include "Planets.h"
#include "BulletArray.h"
#include "GroundArray.h"
#include "FuelArray.h"
#include "GUI.h"
#include "TextHandler.h"

class Draw{
protected:

public:
    void All(sf::RenderWindow &window, int &scene, int &planetIndex, bool &showTutorial, Entity &starObj, Planets &planetsObj, GroundArray &groundArrayObj, BunkerArray &bunkerArrayObj, FuelArray &fuelArrayObj, Player &playerObj, GUI &gui, TextHandler &textHandlerObj, sf::Sprite &titleSprt, sf::Sprite &tutorialSprt);
};
