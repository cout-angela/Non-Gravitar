
#include "Logic.h"


void Logic::setAllMovement(int &scene, Input &input, Player &playerObj, GUI &gui, TextHandler &textHandlerObj){

    ///ROTATION

    if(input.getRight()){
        playerObj.setDir(playerObj.getDir() + 3.0);
        if (playerObj.getDir() >= 360.0){
            playerObj.setDir(0.0);
        }
    }
    if (input.getLeft()){
        playerObj.setDir(playerObj.getDir() - 3.0);
        if (playerObj.getDir() <= 0.0){
            playerObj.setDir(360.0);
        }
    }

    ///THROTTLE

    cosMove = cos(playerObj.getDir()*(3.14/180.0));
    sinMove = sin(playerObj.getDir()*(3.14/180.0));

    if(input.getUp()){



        playerObj.setXSpeed(playerObj.getXSpeed() + xLimiter*cosMove/6);
        playerObj.setYSpeed(playerObj.getYSpeed() + yLimiter*sinMove/6);


        if (cosMove > 0.0 && playerObj.getXSpeed() > cosMove*5.0){
            xLimiter = 0.0;

        } else if (cosMove < 0 && playerObj.getXSpeed() < cosMove*5.0){
            xLimiter = 0.0;
        } else {
            xLimiter = 1.0;
        }
        if (sinMove < 0.0 && playerObj.getYSpeed() < sinMove*5.0){
            yLimiter = 0.0;
        } else if (sinMove > 0.0 && playerObj.getYSpeed() > sinMove*5.0){
            yLimiter = 0.0;
        } else {
            yLimiter = 1.0;
        }
        fuelPercentage = fuelPercentage - 0.05/60.0;


    } else if (input.getDown()){

        if (playerObj.getXSpeed() >= 0.5){
            playerObj.setXSpeed(playerObj.getXSpeed() - 0.05);
            fuelPercentage = fuelPercentage - 0.05/60.0;
        } else if (playerObj.getXSpeed() <= -0.5){
            playerObj.setXSpeed(playerObj.getXSpeed() + 0.05);
            fuelPercentage = fuelPercentage - 0.05/60.0;
        } else {
            playerObj.setXSpeed(0.0);
        }
        if (playerObj.getYSpeed() >= 0.05){
            playerObj.setYSpeed(playerObj.getYSpeed() - 0.05);
            fuelPercentage = fuelPercentage - 0.05/60.0;
        } else if (playerObj.getYSpeed() <= -0.5){
            playerObj.setYSpeed(playerObj.getYSpeed() + 0.05);
            fuelPercentage = fuelPercentage - 0.05/60.0;
        } else {
            playerObj.setYSpeed(0.0);
        }

    }
    /// Updating the fuel
    gui.setFuelTank(fuelPercentage);
        if(fuelPercentage < 0.0){
            scene = 3;
            textHandlerObj.setDeathType(3);
    }

    playerObj.setX(playerObj.getX() + playerObj.getXSpeed());
    playerObj.setY(playerObj.getY() + playerObj.getYSpeed());

        ///Dynamic mask (changes based on the player direction)
    if (cosMove > 0.0){
        playerObj.setRMask(13.0);
        playerObj.setLMask(8.0);
    } else {
        playerObj.setRMask(8.0);
        playerObj.setLMask(13.0);
    }
    if (sinMove > 0.0){
        playerObj.setUMask(8.0);
        playerObj.setDMask(13.0);
    } else {
        playerObj.setUMask(13.0);
        playerObj.setDMask(8.0);
    }
}

/// Bunker Fire Logic

void Logic::setBunkerFireLogic(BunkerArray &bunkerArrayObj, int &planetIndex, Random &random){
    time1 = clock.getElapsedTime();
    for(int i = 0; i < 3; i++){
        if(bunkerArrayObj.getBunker(planetIndex, i).getActive()){

            if(time1.asSeconds() - time0.asSeconds() >= 1.8){
                clock.restart();
                time0 = clock.getElapsedTime();

                if(bunkerArrayObj.getBunker(planetIndex, i).getType() == 0){
                    /// comportamento zero
                    bunkerArrayObj.fireBullet(planetIndex, i, bunkerArrayObj.getBunker(planetIndex, i).getX() + 11.0*cos((bunkerArrayObj.getBunker(planetIndex, i).getDir()-90.0)*(3.14/180.0)), bunkerArrayObj.getBunker(planetIndex, i).getY() + 11.0*sin((bunkerArrayObj.getBunker(planetIndex, i).getDir()-90.0)*(3.14/180.0)), bunkerArrayObj.getBunker(planetIndex, i).getDir(), 6.1*sin((bunkerArrayObj.getBunker(planetIndex, i).getDir()-90.0)*(3.14/180.0)), 6.1*cos((bunkerArrayObj.getBunker(planetIndex, i).getDir()-90.0)*(3.14/180.0)));

                } else {
                    ///comportamento uno
                    shootAngle = random.neg(50);
                    bunkerArrayObj.fireBullet(planetIndex, i, bunkerArrayObj.getBunker(planetIndex, i).getX() + 11.0*cos((bunkerArrayObj.getBunker(planetIndex, i).getDir()-90.0)*(3.14/180.0)), bunkerArrayObj.getBunker(planetIndex, i).getY() + 11.0*sin((bunkerArrayObj.getBunker(planetIndex, i).getDir()-90.0)*(3.14/180.0)), bunkerArrayObj.getBunker(planetIndex, i).getDir(), 3.7*sin((bunkerArrayObj.getBunker(planetIndex, i).getDir()-90.0 + shootAngle)*(3.14/180.0)), 3.7*cos((bunkerArrayObj.getBunker(planetIndex, i).getDir()-90.0 + shootAngle)*(3.14/180.0)));
                    shootAngle = random.neg(50);
                    bunkerArrayObj.fireBullet(planetIndex, i, bunkerArrayObj.getBunker(planetIndex, i).getX() + 11.0*cos((bunkerArrayObj.getBunker(planetIndex, i).getDir()-90.0)*(3.14/180.0)), bunkerArrayObj.getBunker(planetIndex, i).getY() + 11.0*sin((bunkerArrayObj.getBunker(planetIndex, i).getDir()-90.0)*(3.14/180.0)), bunkerArrayObj.getBunker(planetIndex, i).getDir(), 3.7*sin((bunkerArrayObj.getBunker(planetIndex, i).getDir()-90.0 + shootAngle)*(3.14/180.0)), 3.7*cos((bunkerArrayObj.getBunker(planetIndex, i).getDir()-90.0 + shootAngle)*(3.14/180.0)));

                }
            }
        }
    }





    /// attuazione dello spostamento dei proiettili
    for(int i = 0; i < 3; i++){

            for(int j = 0; j < 10; j++){

                if(bunkerArrayObj.getBunker(planetIndex, i).getAmmo().getBulletUnit(j).getFired()){
                    bunkerArrayObj.setBulletY(planetIndex, i, j, bunkerArrayObj.getBunker(planetIndex, i).getAmmo().getBulletUnit(j).getY() + bunkerArrayObj.getBunker(planetIndex, i).getAmmo().getBulletUnit(j).getYSpeed());
                    bunkerArrayObj.setBulletX(planetIndex, i, j, bunkerArrayObj.getBunker(planetIndex, i).getAmmo().getBulletUnit(j).getX() + bunkerArrayObj.getBunker(planetIndex, i).getAmmo().getBulletUnit(j).getXSpeed());

                }
            }

    }


}
///Player Fire Logic

void Logic::setPlayerFireLogic(Input &input, Player &playerObj){
    if(input.getFire()){
        if(counterTime <= 1)
            counterTime = counterTime + 1; //counterTime prevents the player from shooting while holding z
        if(counterTime == 1){
            playerObj.fire(playerObj.getX(), playerObj.getY(), 0.0, sinMove*10.0, cosMove*10.0);
        }
    }else{
        counterTime = 0;
    }





    /// attuazione dello spostamento dei proiettili

    for(int i = 0; i < 10; i++){
        if(playerObj.getBullet(i).getFired()){
            playerObj.setBY(i, playerObj.getBullet(i).getY() + playerObj.getBullet(i).getYSpeed());
            playerObj.setBX(i, playerObj.getBullet(i).getX() + playerObj.getBullet(i).getXSpeed());
        }
    }
}
void Logic::setBeamLogic(Input &input, Player &playerObj, FuelArray &fuelArrayObj, int &planetIndex, GUI &gui){
    playerObj.setBeam(input.getBeam());
    if (input.getBeam()){
        for(int i = 0; i < 3; i++){
            if(fuelArrayObj.getFActive(planetIndex, i)){
                if(handler.collisionPointCircle(fuelArrayObj.getFX(planetIndex, i), fuelArrayObj.getFY(planetIndex, i), playerObj.getX(), playerObj.getY(), playerObj.getRadius())){
                    fuelArrayObj.setFActive(planetIndex, i, false);
                    if(fuelArrayObj.getFType(planetIndex, i) == 0){
                        fuelPercentage = fuelPercentage + 0.25;
                        gui.setFuelTank(fuelPercentage);
                    }else{
                        fuelPercentage = fuelPercentage + 1.0;
                        gui.setFuelTank(fuelPercentage);
                    }
                    if(fuelPercentage > 1.0){
                        fuelPercentage = 1.0;
                        gui.setFuelTank(fuelPercentage);
                    }
                }
            }
        }
    }
}
///collision player screen


void Logic::collisionPlayerScreen(Player &playerObj, Planets &planetObj, BunkerArray &bunkerArrayObj, Ground groundObj, TextHandler &textHandlerObj, GUI &gui, int &scene, int &planetIndex){
    if(handler.collisionObjWallLeft(playerObj.getLMask(), 0.0)){
        playerObj.setX(1890.0);
        if(groundObj.getYU(0) < playerObj.getY()){
            playerObj.setY(groundObj.getYU(0)-40.0);

        }
    } else if(handler.collisionObjWallRight(playerObj.getRMask(), 1920.0)){
         playerObj.setX(30.0);
        if(groundObj.getYU(10) < playerObj.getY()){
            playerObj.setY(groundObj.getYU(10)-40.0);

        }
    } else if(handler.collisionObjWallUp(playerObj.getUMask(), 0.0)){

        scene = 0;
        playerObj.setXSpeed(0.0);
        playerObj.setYSpeed(0.0);
        playerObj.setY(planetObj.getYP(planetIndex) - 100.0);
        playerObj.setX(planetObj.getXP(planetIndex));
        playerObj.setDir(270.0);

        /// check for planet destruction

        bool killThePlanet = true;
        for(int i = 0; i < 3; i++){
            if(bunkerArrayObj.getBunker(planetIndex, i).getActive()){
                killThePlanet = false;
            }
        }
        if(killThePlanet){
            planetObj.setActive(planetIndex, !killThePlanet);
            value = value + 100;
            textHandlerObj.setScore(value);

        }

        /// check for changing system
        scene = 2;
        for(int i = 0; i < 5; i++){
            if(planetObj.getActive(i)){
                scene = 0;
            }
        }



        /// reset all the bullets
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 10; j++){
                if(bunkerArrayObj.getBunker(planetIndex, i).getAmmo().getBulletUnit(j).getFired()){
                    bunkerArrayObj.isHit(planetIndex, i, j);

                }
            }
        }
        for(int i = 0; i < 10; i++){
                if(playerObj.getBullet(i).getFired()){
                    playerObj.hit(i);

                }
            }
    }
}


///collision player ground

void Logic::collisionPlayerGround(int &scene, Player &playerObj, Ground groundObj, GUI &gui, TextHandler &textHandlerObj){


    while(groundObj.getXU(pos+1) > playerObj.getX())
        pos = pos + 1;
    while(groundObj.getXU(pos) <= playerObj.getX())
        pos = pos - 1;


    if (handler.collisionObjLine(playerObj.getX(), playerObj.getY(), playerObj.getLMask(), playerObj.getRMask(), playerObj.getUMask(), playerObj.getDMask(), groundObj.getXU(pos+1), groundObj.getYU(pos+1), groundObj.getXU(pos), groundObj.getYU(pos))){
        hearts = hearts - 1;
        if(hearts < 1){
            /// INSERT PLAYER DEATH EVENT HERE
            scene = 3;
            textHandlerObj.setDeathType(0);
        }
        gui.setLivesActive(hearts);
        playerObj.setXSpeed(0.0);
        playerObj.setYSpeed(0.0);
        playerObj.setX(960.0);
        playerObj.setY(100.0);
        playerObj.setDir(90.0);
    }

}

void Logic::collisionPlayerPlanet(Player &playerObj, Planets &planetsObj, int &scene, int &planetIndex){


    for(int i = 0; i < 5; i++){

        if(planetsObj.getActive(i)){
            if (handler.collisionObjObj(playerObj.getLMask(), playerObj.getRMask(), playerObj.getUMask(), playerObj.getDMask(), planetsObj.getLMask(i), planetsObj.getRMask(i), planetsObj.getUMask(i), planetsObj.getDMask(i))){
                scene = 1;
                planetIndex = i;
                playerObj.setXSpeed(0.0);
                playerObj.setYSpeed(0.0);
                playerObj.setX(960.0);
                playerObj.setY(100.0);
                playerObj.setDir(90.0);
                i = 5;
            }
        }
    }

}


void Logic::collisionPlayerSystemScreen(int &scene, Player &playerObj, GUI &gui, TextHandler &textHandlerObj){

    if(handler.collisionObjWallLeft(playerObj.getLMask(), 0.0)){
        playerObj.setX(playerObj.getX() - playerObj.getXSpeed());
    } else if(handler.collisionObjWallRight(playerObj.getRMask(), 1800.0)){
        hearts = hearts - 1;
        if(hearts < 1){
            /// INSERT PLAYER DEATH EVENT HERE
            scene = 3;
            textHandlerObj.setDeathType(2);
        }
        gui.setLivesActive(hearts);
        playerObj.setXSpeed(0.0);
        playerObj.setYSpeed(0.0);
        playerObj.setX(75.0);
        playerObj.setY(540.0);
        playerObj.setDir(0.0);


    } else if(handler.collisionObjWallUp(playerObj.getUMask(), 0.0)){


        playerObj.setXSpeed(playerObj.getXSpeed()/4.0);
        playerObj.setYSpeed(playerObj.getYSpeed()/4.0);
        playerObj.setY(1070.0);
        playerObj.setDir(270.0);
    } else if(handler.collisionObjWallDown(playerObj.getUMask(), 1100.0)){


        playerObj.setXSpeed(playerObj.getXSpeed()/4.0);
        playerObj.setYSpeed(playerObj.getYSpeed()/4.0);
        playerObj.setY(50.0);
        playerObj.setDir(90.0);
    }

}



void Logic::collisionBulletScreen(Player &playerObj, BunkerArray &bunkerArrayObj, Ground groundObj, int &planetIndex){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 10; j++){
            if(bunkerArrayObj.getBunker(planetIndex, i).getAmmo().getBulletUnit(j).getFired()){
                if(handler.collisionObjWallUp(bunkerArrayObj.getBunker(planetIndex, i).getAmmo().getBulletUnit(j).getUMask(), 0.0)){
                        bunkerArrayObj.isHit(planetIndex, i, j);
                } else if(handler.collisionObjWallRight(bunkerArrayObj.getBunker(planetIndex, i).getAmmo().getBulletUnit(j).getRMask(), 1920.0)){
                        bunkerArrayObj.isHit(planetIndex, i, j);
                } else if(handler.collisionObjWallLeft(bunkerArrayObj.getBunker(planetIndex, i).getAmmo().getBulletUnit(j).getLMask(), 0.0)){
                        bunkerArrayObj.isHit(planetIndex, i, j);
                } else if(handler.collisionObjWallDown(bunkerArrayObj.getBunker(planetIndex, i).getAmmo().getBulletUnit(j).getDMask(), 1080.0)){
                        bunkerArrayObj.isHit(planetIndex, i, j);
                }
            }
        }
    }
    for(int i = 0; i < 10; i++){
            if(playerObj.getBullet(i).getFired()){
                if(handler.collisionObjWallUp(playerObj.getBullet(i).getUMask(), 0.0)){
                        playerObj.hit(i);
                } else if(handler.collisionObjWallRight(playerObj.getBullet(i).getRMask(), 1920.0)){
                        playerObj.hit(i);
                } else if(handler.collisionObjWallLeft(playerObj.getBullet(i).getLMask(), 0.0)){
                        playerObj.hit(i);
                } else if(handler.collisionObjWallDown(playerObj.getBullet(i).getDMask(), 1080.0)){
                        playerObj.hit(i);
                }
            }
        }

}

void Logic::collisionBulletBunker(Player &playerObj, BunkerArray &bunkerArrayObj, int &planetIndex, GUI &gui, TextHandler &textHandlerObj){
    for(int j = 0; j < 3; j++){
        if(bunkerArrayObj.getBunker(planetIndex, j).getActive()){
            for(int i = 0; i < 10; i++){
                if(playerObj.getBullet(i).getFired()){
                    if(handler.collisionObjObj(bunkerArrayObj.getBunker(planetIndex, j).getLMask(), bunkerArrayObj.getBunker(planetIndex, j).getRMask(), bunkerArrayObj.getBunker(planetIndex, j).getUMask(), bunkerArrayObj.getBunker(planetIndex, j).getDMask(), playerObj.getBullet(i).getLMask(), playerObj.getBullet(i).getRMask(), playerObj.getBullet(i).getUMask(), playerObj.getBullet(i).getDMask())){
                        bunkerArrayObj.setBunkerActive(planetIndex, j, false);
                        playerObj.hit(i);
                        value = value + 25;
                        textHandlerObj.setScore(value);

                    }
                }
            }
        }
    }
}

void Logic::collisionBulletPlayer(int &scene, Player &playerObj, BunkerArray &bunkerArrayObj, GUI &gui, TextHandler &textHandlerObj, int &planetIndex){
    for (int i = 0; i < 3; i++){
        for(int j = 0; j < 10; j++){
            if(bunkerArrayObj.getBunker(planetIndex, i).getAmmo().getBulletUnit(j).getFired()){
                if(handler.collisionObjObj(bunkerArrayObj.getBunker(planetIndex, i).getAmmo().getBulletUnit(j).getLMask(), bunkerArrayObj.getBunker(planetIndex, i).getAmmo().getBulletUnit(j).getRMask(), bunkerArrayObj.getBunker(planetIndex, i).getAmmo().getBulletUnit(j).getUMask(), bunkerArrayObj.getBunker(planetIndex, i).getAmmo().getBulletUnit(j).getDMask(), playerObj.getLMask(), playerObj.getRMask(), playerObj.getUMask(), playerObj.getDMask())){
                    bunkerArrayObj.isHit(planetIndex, i, j);
                    hearts = hearts - 1;
                    if(hearts < 1){
                        /// INSERT PLAYER DEATH EVENT HERE
                        scene = 3;
                        textHandlerObj.setDeathType(1);
                    }
                    gui.setLivesActive(hearts);
                }
            }
        }
    }
}

void Logic::respawn(Player &playerObj, GroundArray &groundArrayObj, BunkerArray &bunkerArrayObj, Entity &starObj, Planets &planetsObj, sf::Texture &planetTxtr0, sf::Texture &planetTxtr1, sf::Texture &planetTxtr2, FuelArray &fuelArrayObj, sf::Sprite fuelSprt0, sf::Sprite fuelSprt1, Random &random, sf::Color &colour, int &scene){
    if(cutScene){
        playerObj.setY(playerObj.getY() - 1.0);

        if(handler.collisionObjWallUp(playerObj.getUMask(), 0.0)){
            playerObj.setY(1050.0);
            cutScene = false; /// ground, fuel e bunker e bullet inizializzali lì
        }
    } else {
        /// respawn ground
        groundArrayObj.respawnGroundArray(random);
        /// respawn bunkers
        bunkerArrayObj.respawnBunkerArray(groundArrayObj, random);
        /// respawn star
        random.genStarColour(colour);
        starObj.setSpriteColour(colour);
        /// respawn planets
        planetsObj.respawnPlanets(planetTxtr0, planetTxtr1, planetTxtr2, colour, random);
        /// respawn fuel
        fuelArrayObj.respawnFuelArray(groundArrayObj, fuelSprt0, fuelSprt1, random);

        /// Give control back to the system screen
        cutScene = true;
        scene = 0;
    }
}


/// Splash Screen Logic
void Logic::splashScreen(Input &input, bool &showTutorial, int &scene){


    if(input.getReturn()){
        if(counterReturn <= 1)
            counterReturn = counterReturn + 1; //counterReturn prevents the user from missing the tutorial screen
        if(counterReturn == 1){
            if(showTutorial){
                scene = 0;
            } else {
                showTutorial = true;
            }
        }
    }else{
        counterReturn = 0;
    }
}
