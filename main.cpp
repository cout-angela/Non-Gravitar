#include <SFML/Graphics.hpp>
#include "Input.h"
#include "Logic.h"
#include "Update.h"
#include "Draw.h"

#include "Player.h"
#include "Ground.h"
#include "Bunker.h"
#include "BunkerArray.h"
#include "Planets.h"
#include "BulletArray.h"
#include "BulletEntity.h"
#include "GroundArray.h"
#include "Fuel.h"
#include "FuelArray.h"

#include "SolarSystem.h"
#include "GUI.h"
#include "TextHandler.h"

#include "Random.h"
#include <cmath>



int main()
{


    /// Setup Zone Start


    //Create necessary objects for core functionalities
    Input input;
    Logic logic;
    Update update;
    Draw draw;

    Random random;
    sf::Color colour;


    int scene = 4; /// 0 = system screen; 1 = planet screen; 2 = changing system; 3 = Game Over Screen; 4 = Splash Screen.
    int planetIndex = 0;
    bool showTutorial = false;


    //Set the window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Non-Gravitar", sf::Style::Fullscreen);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(80);


    // splash screen
    sf::Texture titleTxtr;
    sf::Texture tutorialTxtr;
    titleTxtr.loadFromFile("data/title.png");
    tutorialTxtr.loadFromFile("data/tutorial.png");
    titleTxtr.setSmooth(true);
    tutorialTxtr.setSmooth(true);
    sf::Sprite titleSprt;
    sf::Sprite tutorialSprt;
    titleSprt.setTexture(titleTxtr);
    tutorialSprt.setTexture(tutorialTxtr);


    //set the ground
    sf::Texture groundTxtr;
    groundTxtr.loadFromFile("data/ground.png");
    groundTxtr.setSmooth(true);
    sf::Texture groundDotTxtr;
    groundDotTxtr.loadFromFile("data/groundDot.png");
    groundDotTxtr.setSmooth(true);
    GroundArray groundArrayObj(groundTxtr, 0.0, 2.0, groundDotTxtr, random);



    //set the bunkers
    sf::Texture bunkerTxtr;
    bunkerTxtr.loadFromFile("data/bunker.png");
    bunkerTxtr.setSmooth(true);
    sf::Texture bulletTxtr;
    bulletTxtr.loadFromFile("data/bullet.png");
    bulletTxtr.setSmooth(true);
    BunkerArray bunkerArrayObj(groundArrayObj, bunkerTxtr, bulletTxtr, random);

    //set the player
    sf::Texture playerTxtr;
    playerTxtr.loadFromFile("data/player.png");
    playerTxtr.setSmooth(true);
    sf::Texture beamTxtr;
    beamTxtr.loadFromFile("data/beam.png");
    beamTxtr.setSmooth(true);
    Player playerObj = Player(75.0, 540.0, 0.0, playerTxtr, beamTxtr, bulletTxtr, 13.0, 17.0);
    playerObj.setAllMasks(13.0, 13.0, 17.0, 14.0);

    //set the star
    sf::Texture starTxtr;
    starTxtr.loadFromFile("data/star.png");
    starTxtr.setSmooth(true);
    Entity starObj(1920.0, 540.0, starTxtr, 200.0, 540.0);
    random.genStarColour(colour);
    starObj.setSpriteColour(colour);
    starObj.updateSprt();

    //set the planets
    sf::Texture planetTxtr0;
    sf::Texture planetTxtr1;
    sf::Texture planetTxtr2;
    planetTxtr0.loadFromFile("data/planet0.png");
    planetTxtr1.loadFromFile("data/planet1.png");
    planetTxtr2.loadFromFile("data/planet2.png");
    planetTxtr0.setSmooth(true);
    planetTxtr1.setSmooth(true);
    planetTxtr2.setSmooth(true);
    Planets planetsObj (planetTxtr0, planetTxtr1, planetTxtr2, 75.0, 75.0, colour, random);

    //set the font
    sf::Font font;
    font.loadFromFile("data/space_invaders.ttf");

    //set the texts
    TextHandler textHandlerObj(font);

    //set the GUI
    sf::Texture GUITxtr;
    GUITxtr.loadFromFile("data/GUIbackGround.png");
    GUITxtr.setSmooth(true);
    sf::Texture heartTxtr;
    heartTxtr.loadFromFile("data/heart.png");
    heartTxtr.setSmooth(true);
    sf::Texture fuelBarTxtr;
    fuelBarTxtr.loadFromFile("data/fuelBar.png");
    fuelBarTxtr.setSmooth(true);
    GUI gui(0.0, 0.0, 0.0, GUITxtr, 0.0, 0.0, heartTxtr, fuelBarTxtr);
    gui.updateSprt();
    gui.updateLives();



    //set fuel
    sf::Texture fuel0Txtr;
    fuel0Txtr.loadFromFile("data/fuel0.png");
    fuel0Txtr.setSmooth(true);
    sf::Sprite fuelSprt0;
    fuelSprt0.setTexture(fuel0Txtr);
    sf::Texture fuel1Txtr;
    fuel1Txtr.loadFromFile("data/fuel1.png");
    fuel1Txtr.setSmooth(true);
    sf::Sprite fuelSprt1;
    fuelSprt1.setTexture(fuel1Txtr);
    FuelArray fuelArrayObj(groundArrayObj, fuelSprt0, fuelSprt1, random);


    /// Setup Zone End



    while (window.isOpen()){
        sf::Event event;

        while (window.pollEvent(event)){
            if(scene == 3 && sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){ // if the game over screen is on and the user presses Enter, the game shuts down
                window.close();
            } else if(scene == 4){
                input.checkReturn(event);
            } else {
                input.checkAll(event);
            }
        }

        // Objects react to Player input and in-Game mechanics

        ///LOGICA
            if (scene == 0){ //out of planet logic here
                logic.setAllMovement(scene, input, playerObj, gui, textHandlerObj);
                logic.collisionPlayerSystemScreen(scene, playerObj, gui, textHandlerObj);
                logic.collisionPlayerPlanet(playerObj, planetsObj, scene, planetIndex);
            } else if (scene == 1){ //in planet logic here
                logic.setAllMovement(scene, input, playerObj, gui, textHandlerObj);
                logic.collisionPlayerScreen(playerObj, planetsObj, bunkerArrayObj, groundArrayObj.getGround(planetIndex), textHandlerObj, gui, scene, planetIndex);
                logic.collisionPlayerGround(scene, playerObj, groundArrayObj.getGround(planetIndex), gui, textHandlerObj);
                logic.setBunkerFireLogic(bunkerArrayObj, planetIndex, random);
                logic.setPlayerFireLogic(input, playerObj);
                logic.collisionBulletScreen(playerObj, bunkerArrayObj, groundArrayObj.getGround(planetIndex), planetIndex);
                logic.collisionBulletBunker(playerObj, bunkerArrayObj, planetIndex, gui, textHandlerObj);
                logic.collisionBulletPlayer(scene, playerObj, bunkerArrayObj, gui, textHandlerObj, planetIndex);
                logic.setBeamLogic(input, playerObj, fuelArrayObj, planetIndex, gui);
            } else if (scene == 2){ // System change animation here
                logic.respawn(playerObj, groundArrayObj, bunkerArrayObj, starObj, planetsObj, planetTxtr0, planetTxtr1, planetTxtr2, fuelArrayObj, fuelSprt0, fuelSprt1, random, colour, scene);
            } else if (scene == 4){
                logic.splashScreen(input, showTutorial, scene);
            }



        // Sprites get updated
        update.All(playerObj);


        window.clear();


        // Everything is drawn on screen
        draw.All(window, scene, planetIndex, showTutorial, starObj, planetsObj, groundArrayObj, bunkerArrayObj, fuelArrayObj, playerObj, gui, textHandlerObj, titleSprt, tutorialSprt);

        window.display();
    }

    return 0;
}
