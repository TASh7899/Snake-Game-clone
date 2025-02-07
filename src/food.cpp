#include "food.h"
#include <random>
#include <raymath.h>

food::food(std::deque<Vector2> body)
{
    Image img = LoadImage("image/star.png");
    Texture = LoadTextureFromImage(img);
    UnloadImage(img);
    Position = RandomPosition(body);

}

food::~food()
{
    UnloadTexture(Texture);
}

void food::Draw()
{
    DrawTexture(Texture, offset+Position.x * cellsize, offset+Position.y * cellsize, WHITE);
}

Vector2 food::RandomCell()
{
    float x = GetRandomValue(0, cellNumber-1);
    float y = GetRandomValue(0, cellNumber-1);

    return Vector2{x, y};
}


Vector2 food::RandomPosition(std::deque<Vector2> body)
{
    Vector2 randomPos = RandomCell();
    while(CheckCollision(body, randomPos))
    {
        randomPos = RandomCell();
    }

    return randomPos;

}
