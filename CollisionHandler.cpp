
#include "CollisionHandler.h"

bool CollisionHandler::collisionObjWallLeft(float left, float wall){
    bool collision = false;
    if (left <= wall){
        collision = true;
    }
    return collision;
}
bool CollisionHandler::collisionObjWallRight(float right, float wall){
    bool collision = false;
    if (right >= wall){
        collision = true;
    }
    return collision;
}
bool CollisionHandler::collisionObjWallUp(float up, float wall){
    bool collision = false;
    if (up <= wall){
        collision = true;
    }
    return collision;
}
bool CollisionHandler::collisionObjWallDown(float down, float wall){
    bool collision = false;
    if (down >= wall){
        collision = true;
    }
    return collision;
}

bool CollisionHandler::collisionObjScreen(float left, float right, float up, float down){
    bool collision = false;
    if (left <= 0.0 || right >= 1920.0 || up <= 40.0 || down >= 1080.0)
        collision = true;
    return collision;
}

bool CollisionHandler::collisionObjObj(float Aleft, float Aright, float Aup, float Adown, float Bleft, float Bright, float Bup, float Bdown){
    bool collision = false;
    if (Aleft <= Bright && Aright >= Bleft){
        if(Aup <= Bdown && Adown >= Bup){
            collision = true;
        }
    }

    return collision;
}

bool CollisionHandler::collisionObjLine(float x, float y, float left, float right, float up, float down, float Ax, float Ay, float Bx, float By){

    ///IMPORTANT: Ax < Bx

    bool collision = false;
    float m, q, ix, iy;

    m = (By - Ay)/(Bx - Ax);
    q = By - (m * Bx);
    iy = (x*m) + q;
    ix = (iy - q)/m;

    if((iy >= up && iy <= down && ix >= left && ix <= right) || (down > iy)){
        collision = true;
    }
    return collision;
}

bool CollisionHandler::collisionPointCircle(float Ax, float Ay, float Bx, float By, float BRadius){
    bool collision = false;
    if(sqrt(((Ax - Bx)*(Ax - Bx) + (Ay - By)*(Ay - By))) <= BRadius) //distanza tra i due punti minore del raggio della circonferenza
        collision = true;

    return collision;
}

