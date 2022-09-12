
#include "Input.h"
#include "Player.h"
#include "Ground.h"
#include "CollisionHandler.h"
#include "Planets.h"
#include "SolarSystem.h"
#include "GUI.h"
#include "BunkerArray.h"
#include "FuelArray.h"
#include "TextHandler.h"

class Logic {
protected:
    /// Movement related variables
    double xLimiter = 0.0;
    double yLimiter = 0.0;
    double cosMove;
    double sinMove;

    CollisionHandler handler;
    int pos = 0;
    int bulletIndex = 0;
    int hearts = 3;
    float fuelPercentage = 1.0;
    int planetPos = 0;
    sf::Clock clock;
    sf::Time time0 = clock.getElapsedTime(), time1;
    int shootAngle = 0;
    int counterTime = 0;
    int counterReturn = 0;
    bool cutScene = true; // determines when re-spawn should move the player and when it should call all the constructors
    int value = 0; //value of used for storing the score

public:
    /// Player logic
    void setAllMovement(int &scene, Input &input, Player &playerObj, GUI &gui, TextHandler &textHandlerObj);
    void setPlayerFireLogic(Input &input, Player &playerObj);
    void setBeamLogic(Input &input, Player &playerObj, FuelArray &fuelArrayObj, int &planetIndex, GUI &gui);

    void setBunkerFireLogic(BunkerArray &bunkerArrayObj, int &planetIndex, Random &random);

    /// Collisions
    void collisionPlayerScreen(Player &playerObj, Planets &planetObj, BunkerArray &bunkerArrayObj, Ground groundObj, TextHandler &textHandlerObj, GUI &gui, int &scene, int &planetIndex);
    void collisionPlayerGround(int &scene, Player &playerObj, Ground groundObj, GUI &gui, TextHandler &textHandlerObj);
    void collisionPlayerPlanet(Player &playerObj, Planets &planetsObj, int &scene, int &planetIndex);
    void collisionPlayerSystemScreen(int &scene, Player &playerObj, GUI &gui, TextHandler &textHandlerObj);
    void collisionBulletScreen(Player &playerObj, BunkerArray &bunkerArrayObj, Ground groundObj, int &planetIndex);
    void collisionBulletBunker(Player &playerObj, BunkerArray &bunkerArrayObj, int &planetIndex, GUI &gui, TextHandler &textHandlerObj);
    void collisionBulletPlayer(int &scene, Player &playerObj, BunkerArray &bunkerArrayObj, GUI &gui, TextHandler &textHandlerObj, int &planetIndex);

    /// Changing Scene
    void respawn(Player &playerObj, GroundArray &groundArrayObj, BunkerArray &bunkerArrayObj, Entity &starObj, Planets &planetsObj, sf::Texture &planetTxtr0, sf::Texture &planetTxtr1, sf::Texture &planetTxtr2, FuelArray &fuelArrayObj, sf::Sprite fuelSprt0, sf::Sprite fuelSprt1, Random &random, sf::Color &colour, int &scene);

    /// Splash Screen Logic
    void splashScreen(Input &input, bool &showTutorial, int &scene);

    ///Updating score
    void addToScore();
};
