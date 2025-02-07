#include "Game.h"
#include <raymath.h>

Game::Game()
{
    InitAudioDevice();
    wall = LoadSound("audio/wall.mp3");
    eat = LoadSound("audio/eat.mp3");
}

Game::~Game()
{
    UnloadSound(wall);
    UnloadSound(eat);
}

void Game::Draw()
{
    snake.Draw();
    myfood.Draw();
}


void Game::Input()
{
    snake.HandleInput();
}

void Game::CheckFoodCollision()
{
    if(Vector2Equals(snake.body[0], myfood.Position))
    {
        myfood.Position = myfood.RandomPosition(snake.body);
        snake.AddSegment = true;
        score += 1;
        PlaySound(eat);
       
    }
}

void Game::CheckCollisionWithEdges()
{
    if(snake.body[0].x == cellNumber || snake.body[0].x == -1)
    {
        GameOver();
        PlaySound(wall);
    }

    if(snake.body[0].y == cellNumber || snake.body[0].y == -1)
    {
        GameOver();
        PlaySound(wall);
    }


}

void Game::CheckCollisionWithTail()
{
    std::deque<Vector2> headless = snake.body;
    headless.pop_front();

    if(CheckCollision(headless, snake.body[0]))
    {
        GameOver();
        PlaySound(wall);
    }
    
}

void Game::GameOver()
{
    snake.Reset();
    myfood.Position = myfood.RandomPosition(snake.body);
    snake.running = false;
    score = 0;
}

void Game::Update()
{
    if(snake.running)
    {
        snake.update();
        CheckFoodCollision();
        CheckCollisionWithEdges();
        CheckCollisionWithTail();
    }
}


