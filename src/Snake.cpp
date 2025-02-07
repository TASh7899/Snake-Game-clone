#include "Snake.h"
#include "info.h"
#include <raymath.h>

void Snake::Draw()
{
    for(unsigned int i = 0; i < body.size(); i++)
    {
        float x = body[i].x;
        float y = body[i].y;
        Rectangle rec = Rectangle{offset+x*cellsize, offset+y*cellsize, (float)cellsize, (float)cellsize};
        DrawRectangleRounded(rec, 0.5, 6, objects);
    }
}

void Snake::update()
{
    body.push_front(Vector2Add(body[0], direction));
    if(AddSegment == true)
    {
       AddSegment = false;
    }

    else
    {
        body.pop_back();
    }
}

void Snake::HandleInput()
{
    int key = GetKeyPressed();

    switch (key)
    {
    case KEY_UP:
        if(direction.y != 1) 
        {
            direction = {0, -1};
            running = true;
        }
        break;
    
    case KEY_DOWN:
        if(direction.y != -1) 
        {
            direction = {0, 1};
            running = true;
        }
        break;
    
    case KEY_RIGHT:
        if(direction.x != -1)
        {
            direction = {1, 0};
            running = true;
        }
        break;

    case KEY_LEFT:
        if(direction.x != 1) 
        {
            direction = {-1, 0};
            running = true;
        }
        break;

    default:
        break;
    }
}

void Snake::Reset()
{
    body = {Vector2{4, 5}, Vector2{3, 5}, Vector2{2, 5}};
    direction = {1, 0}; 
    running = false;
}