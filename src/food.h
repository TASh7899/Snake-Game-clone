#pragma once
#include<raylib.h>
#include<deque>
#include "info.h"


class food{

    public:
        food(std::deque<Vector2> body);
        ~food();
        void Draw();
        Vector2 Position;
        Vector2 RandomCell();
        Vector2 RandomPosition(std::deque<Vector2> body);
    
    private:
        Texture2D Texture;

};
