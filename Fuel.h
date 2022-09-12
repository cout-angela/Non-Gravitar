#pragma once
#include "Entity.h"
#include "Random.h"
#include "Ground.h"

class Fuel : public Entity {
protected:
    int type = 0;
public:
    /// Constructors
    Fuel();
    Fuel(Ground groundObj, int pos, sf::Sprite sprt0, sf::Sprite sprt1, Random &random);

    /// Getter
    int getType();

    /// Setter
    void setType(int _type);

    /// Re-spawn
    void respawnFuel(Ground groundObj, int pos, sf::Sprite sprt0, sf::Sprite sprt1, Random &random);
};
