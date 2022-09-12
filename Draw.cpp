
#include "Draw.h"



void Draw::All(sf::RenderWindow &window, int &scene, int &planetIndex, bool &showTutorial, Entity &starObj, Planets &planetsObj, GroundArray &groundArrayObj, BunkerArray &bunkerArrayObj, FuelArray &fuelArrayObj, Player &playerObj, GUI &gui, TextHandler &textHandlerObj, sf::Sprite &titleSprt, sf::Sprite &tutorialSprt){


    if (scene == 3){
        textHandlerObj.displayGameOver(window);
        textHandlerObj.displayDeath(window);
        textHandlerObj.displayNextScreen(window);

    }else if(scene == 1){
        window.draw(playerObj.getSprt());
        playerObj.drawPlayerBullet(window);
        groundArrayObj.drawCurrentGround(window, planetIndex);
        bunkerArrayObj.drawBunkerArray(window, planetIndex);

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 10; j++){
                if(bunkerArrayObj.getBunker(planetIndex, i).getAmmo().getBulletUnit(j).getFired()){
                    bunkerArrayObj.getBunker(planetIndex, i).getAmmo().getBulletUnit(j).draw(window);
                }
            }
        }
        fuelArrayObj.drawFuelArray(window, planetIndex);
        if(playerObj.getBeam()){
            window.draw(playerObj.getSprt2());
        }
        gui.drawAll(window);
        textHandlerObj.displayScore(window);

    } else if (scene == 2){
        window.draw(playerObj.getSprt());
        window.draw(starObj.getSprt());
        planetsObj.drawPlanets(window);
        gui.drawAll(window);
        textHandlerObj.displayScore(window);
        textHandlerObj.displayChangingSystem(window);
    } else if (scene == 0){
        window.draw(playerObj.getSprt());
        window.draw(starObj.getSprt());
        planetsObj.drawPlanets(window);
        gui.drawAll(window);
        textHandlerObj.displayScore(window);
    } else if (scene == 4){
        if(!showTutorial){
            window.draw(titleSprt);
        }else{
            textHandlerObj.displayTutorial(window);
            window.draw(tutorialSprt);
            textHandlerObj.displayFire(window);
            textHandlerObj.displayExtract(window);
            textHandlerObj.displayThrottle(window);
            textHandlerObj.displayRotate(window);
            textHandlerObj.displayReadyPlayerOne(window);
        }
        textHandlerObj.displayNextScreen(window);

    }


}

