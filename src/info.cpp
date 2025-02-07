#include "info.h"

int cellsize = 21;
int cellNumber = 25;
int offset = 75;

Color BG = {171, 204, 96, 255};
Color objects = {22, 31, 0, 255};

bool CheckCollision(std::deque<Vector2> body, Vector2 element)
{
    for(unsigned int i = 0; i < body.size(); i++)
    {
        if(Vector2Equals(body[i], element))
        {
            return true;
        }
    }

    return false;
}
