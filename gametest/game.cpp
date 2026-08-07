#include "raylib.h"
#include <vector>
#include <math.h>
#include "src/playerVariables.h"
#include "src/Player.h"
#include "src/Block.h"
#include "src/Enemy.h"

bool GetCollision(float objX, float objY, float objW, float objH, auto& obj);

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


        //colisiones, deberia funcionar como el place_meeting del gamemaker jeje
        for (auto block = blocks.begin(); block != blocks.end();)
        {
            //horizontal
            if ( GetCollision(player.Get_XYWH()[0]+(playerVars.spd*playerVars.hspd)*dt,player.Get_XYWH()[1],player.Get_XYWH()[2],player.Get_XYWH()[3],*block) )
            {
                //blocks.erase(block); //borrar la wea
                if (playerVars.hspd > 0)
                {
                    player.SetX(block->Get_XYWH()[0]-player.Get_XYWH()[2]);
                }
                else if (playerVars.hspd < 0)
                {
                    player.SetX(block->Get_XYWH()[0]+block->Get_XYWH()[2]);
                }
                playerVars.hspd = 0;
            }

            //vertical
            if ( GetCollision(player.Get_XYWH()[0],player.Get_XYWH()[1]+(playerVars.spd*playerVars.vspd)*dt,player.Get_XYWH()[2],player.Get_XYWH()[3],*block) )
            {
                if (playerVars.vspd > 0)
                {
                    player.SetY(block->Get_XYWH()[1]-player.Get_XYWH()[3]);
                }
                else if (playerVars.vspd < 0)
                {
                    player.SetY(block->Get_XYWH()[1]+block->Get_XYWH()[3]);
                }
                playerVars.vspd = 0;
            }

            ++block;
        }
        
        for (auto enemy = enemies.begin(); enemy != enemies.end();enemy++)
        {
            enemy->Update(player);

            if (GetCollision(player.Get_XYWH()[0],player.Get_XYWH()[1],player.Get_XYWH()[2],player.Get_XYWH()[3],*enemy))
            {
                CloseWindow();
            }
        }

        player.UpdateMovement(playerVars);

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
    CloseWindow();
    return 0;
}

bool GetCollision(float objX, float objY, float objW, float objH, auto& obj)
{
    std::vector<float> data = obj.Get_XYWH();
    if (objX+objW > data[0] && objY+objH > data[1] && objX < data[0]+data[2] && objY < data[1]+data[3])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}