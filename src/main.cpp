#include "info.h"
#include "Game.h"
using namespace std;

double lastUpdateTime = 0;

bool EventTrigger(double interval)
{
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}


int main()
{
    InitWindow(2*offset + cellsize * cellNumber, 2*offset + cellsize * cellNumber, "snake game");

    Game game = Game();


    while(WindowShouldClose() == false)
    {

        BeginDrawing();

        
        ClearBackground(BG);
        
        if(EventTrigger(0.1))
        {
            game.Update();
        }

        game.Input();
        
        game.Draw();
        DrawRectangleLinesEx(Rectangle{(float)offset-5, (float)offset-5, (float)cellsize*cellNumber + 10, (float)cellsize*cellNumber + 10}, 5, objects);
        DrawText("Snake Game", offset-5, offset-40, 40, objects);
        DrawText(TextFormat("%i", game.score), offset+cellNumber*cellsize-20, offset-40, 40, objects);
        
        EndDrawing();
    }
}