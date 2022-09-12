#include "TextHandler.h"

TextHandler::TextHandler(sf::Font &font){

    ///Set game over text
    gameOver.setFont(font);
    gameOver.setCharacterSize(200);
    gameOver.setFillColor(sf::Color(255, 0, 0, 255));
    gameOver.setString("Game Over");
    gameOver.setPosition(350.0, 240.0);

    ///Set changing system text
    changingSystemText.setFont(font);
    changingSystemText.setCharacterSize(25);
    changingSystemText.setFillColor(sf::Color(255, 50, 50, 255));
    changingSystemText.setString("Changing Solar System...");
    changingSystemText.setPosition(765.0, 1.0);

    ///Set death text
    deathText.setFont(font);
    deathText.setCharacterSize(50);
    deathText.setFillColor(sf::Color(255, 255, 255, 255));


    ///Set next screen Text
    nextScreen.setFont(font);
    nextScreen.setCharacterSize(30);
    nextScreen.setFillColor(sf::Color(255, 255, 255, 255));
    nextScreen.setString("(PRESS ENTER)");
    nextScreen.setPosition(825.0, 1000.0);

    ///Set tutorial Text
    tutorial.setFont(font);
    tutorial.setCharacterSize(90);
    tutorial.setFillColor(sf::Color(255, 230, 5, 255));
    tutorial.setOutlineThickness(2.0);
    tutorial.setOutlineColor(sf::Color(255, 0, 0, 255));
    tutorial.setString("How To Play:");
    tutorial.setPosition(620.0, 16.0);

    ///Set fire Text
    fireTutorial.setFont(font);
    fireTutorial.setCharacterSize(25);
    fireTutorial.setFillColor(sf::Color(255, 255, 255, 255));
    fireTutorial.setString("Fire at Bunkers");
    fireTutorial.setPosition(154.0, 760.0);

    ///Set extract Text
    extractTutorial.setFont(font);
    extractTutorial.setCharacterSize(25);
    fireTutorial.setFillColor(sf::Color(255, 255, 255, 255));
    extractTutorial.setString("Extract Fuel");
    extractTutorial.setPosition(626.0, 760.0);

    ///Set throttle Text
    throttleTutorial.setFont(font);
    throttleTutorial.setCharacterSize(25);
    fireTutorial.setFillColor(sf::Color(255, 255, 255, 255));
    throttleTutorial.setString("Throttle Away\n\t\t\t   or\n  Stop in Place");
    throttleTutorial.setPosition(1077.0, 760.0);

    ///Set rotate Text
    rotateTutorial.setFont(font);
    rotateTutorial.setCharacterSize(25);
    fireTutorial.setFillColor(sf::Color(255, 255, 255, 255));
    rotateTutorial.setString("Rotate in Place");
    rotateTutorial.setPosition(1516.0, 760.0);

    ///Set ready player one Text
    readyPlayerOne.setFont(font);
    readyPlayerOne.setCharacterSize(50);
    readyPlayerOne.setFillColor(sf::Color(255, 255, 255, 255));
    readyPlayerOne.setString("READY PLAYER ONE");
    readyPlayerOne.setPosition(685.0, 925.0);

    ///Set score
    score.setFont(font);
    score.setCharacterSize(25);
    score.setFillColor(sf::Color(255, 230, 5, 255));
    score.setStyle(sf::Text::Bold);
    score.setString("SCORE:  0");
    score.setPosition(100.0, 1.0);



}

///Display methods
void TextHandler::displayGameOver(sf::RenderWindow &window){
    window.draw(gameOver);
}
void TextHandler::displayChangingSystem(sf::RenderWindow &window){
    time1 = clock.getElapsedTime();
    if(time1.asMilliseconds() - time0.asMilliseconds() >= 600.0){
        window.draw(changingSystemText);

        if(time1.asSeconds() - time0.asSeconds() >= 2.0){
            clock.restart();
            time0 = clock.getElapsedTime();
        }
    }
}
void TextHandler::displayDeath(sf::RenderWindow &window){
    window.draw(deathText);
}
void TextHandler::displayNextScreen(sf::RenderWindow &window){
    window.draw(nextScreen);
}
void TextHandler::displayTutorial(sf::RenderWindow &window){
    window.draw(tutorial);
}
void TextHandler::displayFire(sf::RenderWindow &window){
    window.draw(fireTutorial);
}
void TextHandler::displayExtract(sf::RenderWindow &window){
    window.draw(extractTutorial);
}
void TextHandler::displayThrottle(sf::RenderWindow &window){
    window.draw(throttleTutorial);
}
void TextHandler::displayRotate(sf::RenderWindow &window){
    window.draw(rotateTutorial);
}
void TextHandler::displayReadyPlayerOne(sf::RenderWindow &window){
    window.draw(readyPlayerOne);
}
void TextHandler::displayScore(sf::RenderWindow &window){
    window.draw(score);
}





///Setters
void TextHandler::setDeathType(int deathType){
    /// 0 = crash on ground; 1 = shot; 2 = crash against star; 3 = finished fuel.
    if(deathType == 0){
        deathText.setString("You wanted to study the rocks too eagerly,\n\t\t\t\t\t  be more patient next time");
        deathText.setPosition(265.0, 500.0);
        deathText.setFillColor(sf::Color(0, 255, 0, 255));
    }else if(deathType == 1){
        deathText.setString("Unfortunately a bunker had a bullet with your name on it,\n\t\t\t\t\t\t\t\t you could not escape your fate");
        deathText.setPosition(35.0, 500.0);
        deathText.setOutlineThickness(2.0);
        deathText.setOutlineColor(sf::Color(166, 228, 254, 255));
    }else if(deathType == 2){
        deathText.setString("You went stargazing... a little bit too close");
        deathText.setPosition(255.0, 500.0);
        deathText.setFillColor(sf::Color(255, 0, 0, 255));
    }else{
        deathText.setString("Did you forget to plug in the charger last night?");
        deathText.setPosition(165.0, 500.0);
        deathText.setFillColor(sf::Color(0, 199, 255, 255));
    }
}


///Score
void TextHandler::setScore(int &value){
    score.setString("SCORE:  " + std::to_string(value));

}

