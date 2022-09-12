#include <SFML/Graphics.hpp>
#include "Entity.h"

class Lives : public Entity{
protected:

public:

    /// Constructors
    Lives();
    Lives (float _x, float _y, float _dir, sf::Texture &txtr, float xOrigin, float yOrigin);

    /// Draw
    void drawLife(sf::RenderWindow &window);

};
