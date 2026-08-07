#include "raylib.h"
#include <vector>
#include <math.h>
#include "src/playerVariables.h"
#include "src/Player.h"
#include "src/Block.h"
#include "src/Enemy.h"
#include <array>

int main()
{
    InitWindow(800,600,"Titulo");
    SetTargetFPS(60);
    //SetExitKey(32);
    playerVariables playerVars = {0.0f,0.0f,300.0f};
    Player player(64,64,64,64);

    std::vector<Block> blocks;
    std::vector<Enemy> enemies;

    blocks.push_back(Block(192,192,192,64));
    blocks.push_back(Block(320,256,64,256));

    enemies.push_back(Enemy(400,400,64,64));

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        player.UpdateControl(playerVars);
        player.UpdateCollisionBlock(blocks,playerVars);
        player.UpdateCollisionEnemy(enemies,playerVars);
        player.UpdateMovement(playerVars);

        for (auto enemy = enemies.begin(); enemy != enemies.end();enemy++)
        {
            enemy->Update(player);
        }

        BeginDrawing();
        ClearBackground({255,255,255,255});

        player.Draw();
        for (auto block = blocks.begin(); block != blocks.end();block++)
        {
            block->Draw();
        }

        for (auto enemy = enemies.begin(); enemy != enemies.end();enemy++)
        {
            enemy->Draw();
        }
        
        DrawText(TextFormat("PlayerX: %f",player.Get_XYWH()[0]),0,0,16,BLACK);
        DrawText(TextFormat("PlayerY: %f",player.Get_XYWH()[1]),0,16,16,BLACK);
        DrawText(TextFormat("FPS: %i",GetFPS()),0,32,16,BLACK);
        EndDrawing();
    }
    blocks.clear();
    enemies.clear();
    CloseWindow();
    return 0;
}

