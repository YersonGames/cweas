#include "Player.h"
#include "playerVariables.h"
#include "raylib.h"
#include <array>
#include <vector>
#include "GetCollision.h"
#include "Block.h"
#include "Enemy.h"

Player::Player(float get_x,float get_y,float get_w,float get_h)
{
    x = get_x;
    y = get_y;
    width = get_w;
    height = get_h;
}
void Player::UpdateControl(playerVariables& playerVars)
{
    if (IsKeyDown(KEY_W)){playerVars.vspd = -1;}
    else if (IsKeyDown(KEY_S)){playerVars.vspd = 1;}
    else {playerVars.vspd = 0;}

    if (IsKeyDown(KEY_A)){playerVars.hspd = -1;}
    else if (IsKeyDown(KEY_D)){playerVars.hspd = 1;}
    else {playerVars.hspd = 0;}
}

void Player::UpdateCollisionBlock(std::vector<Block>& blocks, playerVariables& playerVars)
{
    for (auto block = blocks.begin(); block != blocks.end();)
        {
            //horizontal
            if ( GetCollision(x+(playerVars.spd*playerVars.hspd)*GetFrameTime(),y,width,height,*block) )
            {
                //blocks.erase(block); //borrar la wea
                if (playerVars.hspd > 0)
                {
                    x = block->Get_XYWH()[0]-width;
                }
                else if (playerVars.hspd < 0)
                {
                    y = block->Get_XYWH()[0]+block->Get_XYWH()[2];
                }
                playerVars.hspd = 0;
            }

            //vertical
            if ( GetCollision(x,y+(playerVars.spd*playerVars.vspd)*GetFrameTime(),width,height,*block) )
            {
                if (playerVars.vspd > 0)
                {
                    y = block->Get_XYWH()[1]-height;
                }
                else if (playerVars.vspd < 0)
                {
                    y = block->Get_XYWH()[1]+block->Get_XYWH()[3];
                }
                playerVars.vspd = 0;
            }

            ++block;
        }
}

void Player::UpdateCollisionEnemy(std::vector<Enemy>& enemies, playerVariables& playerVars)
{
    for (auto enemy = enemies.begin(); enemy != enemies.end();enemy++)
        {
            if (GetCollision(x,y,width,height,*enemy))
            {
                CloseWindow();
            }
        }
}

void Player::UpdateMovement(playerVariables& playerVars)
{
    y += (playerVars.vspd * playerVars.spd)*GetFrameTime();
    x += (playerVars.hspd * playerVars.spd)*GetFrameTime();
}

void Player::Draw()
{
    DrawRectangle(x,y,width,height,LIME);
}

std::array<float,4> Player::Get_XYWH()
{
    return {x,y,width,height};
}

void Player::SetX(float get_x)
{
    x = get_x;
}

void Player::SetY(float get_y)
{
    y = get_y;
}