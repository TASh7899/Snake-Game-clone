#pragma once
#include"Snake.h"
#include "food.h"

class Game{
    public:
        Game();
        ~Game();
        Snake snake = Snake();
        food myfood = food(snake.body);
        void Draw();
        void Input();
        void CheckFoodCollision();
        void CheckCollisionWithEdges();
        void CheckCollisionWithTail();
        void GameOver();
        void Update();
        int score;

    private:
        Sound wall;
        Sound eat;
};