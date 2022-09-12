#include "Entity.h"

class FuelBar : public Entity{
protected:
    float tank = 1;

public:

    /// Constructors
    FuelBar();
    FuelBar(float _x, float _y, float _dir, sf::Texture &txtr, float xOrigin, float yOrigin);

    /// Getter
    float getTank();

    /// Setter
    void setTank(float _tank);
};
