#pragma once
#include <SFML/Graphics.hpp>

class TextHandler{
protected:
    sf::Text gameOver;
    sf::Text deathText;
    sf::Text changingSystemText;
    sf::Text nextScreen;
    sf::Text tutorial;
    sf::Text fireTutorial;
    sf::Text extractTutorial;
    sf::Text throttleTutorial;
    sf::Text rotateTutorial;
    sf::Text readyPlayerOne;
    sf::Text score;

    sf::Clock clock;
    sf::Time time0 = clock.getElapsedTime(), time1;


public:

    TextHandler(sf::Font &font);


    ///Display methods
    void displayGameOver(sf::RenderWindow &window);
    void displayChangingSystem(sf::RenderWindow &window);
    void displayDeath(sf::RenderWindow &window);
    void displayNextScreen(sf::RenderWindow &window);
    void displayTutorial(sf::RenderWindow &window);
    void displayFire(sf::RenderWindow &window);
    void displayExtract(sf::RenderWindow &window);
    void displayThrottle(sf::RenderWindow &window);
    void displayRotate(sf::RenderWindow &window);
    void displayReadyPlayerOne(sf::RenderWindow &window);
    void displayScore(sf::RenderWindow &window);

    ///Setters
    void setDeathType(int deathType);

    ///Score
    void setScore(int &value);

};
