#pragma once
#include<raylib.h>
#include <deque>

class Snake{
    public:
        bool AddSegment;
        void Draw();
        void update();
        void HandleInput();
        void Reset();
        std::deque<Vector2> body = {Vector2{4, 5}, Vector2{3, 5}, Vector2{2, 5}};
        Vector2 direction = {1, 0};
        bool running; 

};