#include "Score.h"

Score::Score(){}

Score::Score(float _x, float _y, sf::Font &font, int _size){
    x = _x;
    y = _y;
    text.setFont(font);
    text.setString("SCORE     " + std::to_string(value));
    text.setCharacterSize(_size);
    text.setFillColor(sf::Color(255, 255, 255, 255));
    text.setStyle(sf::Text::Bold);
    text.setPosition(x, y);

}

void Score::addToScore(int reward){
    value = value + reward;
    text.setString("SCORE " + std::to_string(value));

}


///Getters
sf::Text Score::getText(){
    return text;
}
float Score::getX(){
    return x;
}
float Score::getY(){
    return y;
}

///Setters
void Score::setX(float _x){
    x = _x;
}
void Score::setY(float _y){
    y = _y;
}



















