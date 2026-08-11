#include "raylib.h"
#include <vector>
#include <math.h>
#include <array>

#include "src/PlayerVariables.h"
#include "src/Player.h"
#include "src/Block.h"
#include "src/Enemy.h"
#include "src/Bullet.h"
#include "utils.h"


int main()
{
    InitWindow(800,600,"Titulo");
    SetTargetFPS(60);
    //SetExitKey(32);

    //Create Player and variables
    PlayerVariables playerVars;
    playerVars.hspd = 0.0f;
    playerVars.vspd = 0.0f;
    playerVars.spd = (5.0f*60);
    playerVars.hp = 10;

    Player player(64,64,64,64);

    //Vector list for Objects
    std::vector<Block> blocks;
    std::vector<Enemy> enemies;
    std::vector<Bullet> bullets;

    //Create Blocks
    blocks.push_back(Block(192,192,192,64));
    blocks.push_back(Block(320,256,64,256));

    //Create Enemies
    enemies.push_back(Enemy(400,400,64,64));

    while (!WindowShouldClose())
    {

        //Player Update
        player.UpdateControl(playerVars);
        player.UpdateCollisionBlock(blocks,playerVars);
        player.UpdateCollisionEnemy(enemies,playerVars);
        player.UpdateMovement(playerVars);
        player.UpdateShoot(bullets);
        player.UpdateTimer();

        //Enemy Update
        utils::EnemyUpdate(enemies,player,blocks);
        utils::EnemyUpdateDestroy(enemies);

        //Bullet Update
        utils::BulletUpdate(bullets);
        utils::BulletUpdateCollision(bullets,blocks,enemies);
        utils::BulletUpdateDestroy(bullets);

        BeginDrawing();

            //Draw Background Color
            ClearBackground({255,255,255,255});

            //Draw Objects
            player.Draw(playerVars);
            utils::BlockDraw(blocks);
            utils::EnemyDraw(enemies);
            utils::BulletDraw(bullets);

            //Draw Texts
            DrawText(TextFormat("PlayerX: %f",player.Get_XYWH()[0]),0,0,16,BLACK);
            DrawText(TextFormat("PlayerY: %f",player.Get_XYWH()[1]),0,16,16,BLACK);
            DrawText(TextFormat("FPS: %i",GetFPS()),0,32,16,BLACK);
            //DrawText(TextFormat("COS: %f",cos(0)),0,48,16,BLACK);

        EndDrawing();
    }

    //Clean vectors
    blocks.clear();
    enemies.clear();
    
    CloseWindow();
    return 0;
}

