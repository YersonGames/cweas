#include "raylib.h"
#include <vector>
#include "src/playerVariables.h"
#include "src/player.h"
#include "src/block.h"

void GetCollision(auto& obj, int objX, int objY, int objW, int objH, auto& obj2);

int main()
{
    Color c_red = {255,0,0,255}; //se crean a partir de un Struct
    Color c_white = {255,255,255,255};
    InitWindow(800,600,"Titulo");
    SetTargetFPS(60);
    //SetExitKey(32);
    playerVariables playerVars = {0,0,5};
    Player player(64,64,64,64);
    std::vector<Block> blocks;

    blocks.push_back(Block(192,192,64,64));
    blocks.push_back(Block(256,256,64,64));

    while (!WindowShouldClose())
    {
        player.Update(playerVars);

        BeginDrawing();
        ClearBackground(c_white);

        for (auto& block : blocks)
        {
            block.Draw();
        }

        player.Draw();
        
        DrawText(TextFormat("PlayerX: %i",player.x),0,0,16,BLACK);
        DrawText(TextFormat("PlayerY: %i",player.y),0,16,16,BLACK);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

void GetCollision(auto& obj, int objX, int objY, int objW, int objH, auto& obj2)
{
    
}