#include <SFML/Graphics.hpp>
class Score {

protected:
    float x, y;
    sf::Text text;
    int value = 0;

public:
    Score();
    Score(float _x, float _y, sf::Font &font, int _size);

    void addToScore(int reward);

    ///Getters
    sf::Text getText();
    float getX();
    float getY();

    ///Setters
    void setX(float _x);
    void setY(float _y);

};
