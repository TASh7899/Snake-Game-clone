#pragma once
#include<raylib.h>
#include <raymath.h>
#include <deque>

extern int cellsize;
extern int cellNumber;
extern int offset;

extern Color BG;
extern Color objects;

bool CheckCollision(std::deque<Vector2> body, Vector2 element);
