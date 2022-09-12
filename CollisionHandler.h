
#include <math.h>

class CollisionHandler{

protected:

public:

    bool collisionObjWallLeft(float left, float wall);
    bool collisionObjWallRight(float right, float wall);
    bool collisionObjWallUp(float up, float wall);
    bool collisionObjWallDown(float down, float wall);
    bool collisionObjScreen(float left, float right, float up, float down);

    bool collisionObjObj(float Aleft, float Aright, float Aup, float Adown, float Bleft, float Bright, float Bup, float Bdown);

    bool collisionObjLine(float x, float y, float left, float right, float up, float down, float Ax, float Ay, float Bx, float By);

    bool collisionPointCircle(float Ax, float Ay, float Bx, float By, float BRadius);

};
