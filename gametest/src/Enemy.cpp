#include "Enemy.h"
#include "Player.h"
#include "Block.h"
#include <raylib.h>
#include <cmath>
#include <array>
#include <vector>
#include "utils.h"

#include <iostream>

Enemy::Enemy(float get_x,float get_y,float get_w,float get_h)
{
    x = get_x;
    y = get_y;
    width = get_w;
    height = get_h;
    spd = 150.0f;;
    hp = 10;
    destroy = false;
}

void Enemy::Update(Player& player, std::vector<Block>& blocks)
{
    //Get difference
    float distX = player.Get_XYWH()[0]-x;
    float distY = player.Get_XYWH()[1]-y;

    //hypotenuse
    float distance = sqrt((distX*distX)+(distY*distY));

    if (distance > 0)
    {
        //direction
        float dirX = distX/distance;
        float dirY = distY/distance;

        //collision block
        for (auto block = blocks.begin(); block != blocks.end(); block++)
        {
            //horizontal
            if ( utils::GetCollision(x+(dirX*spd)*GetFrameTime(),y,width,height,*block) )
            {
                //Left
                if (dirX > 0)
                {
                    x = block->Get_XYWH()[0]-width;
                }
                //Tight
                else if (dirX < 0)
                {
                    x = block->Get_XYWH()[0]+block->Get_XYWH()[2];
                }
                dirX = 0;
            }

            //vertical
            if ( utils::GetCollision(x,y+(dirY*spd)*GetFrameTime(),width,height,*block) )
            {
                //Up
                if (dirY > 0)
                {
                    y = block->Get_XYWH()[1]-height;
                }
                //Down
                else if (dirY < 0)
                {
                    y = block->Get_XYWH()[1]+block->Get_XYWH()[3];
                }
                dirY = 0;
            }
        }

        x += (dirX*spd)*GetFrameTime();
        y += (dirY*spd)*GetFrameTime();
        
        //float angle = (std::atan2(dirY,dirX)*(180.0f/PI));
        //DrawText(TextFormat("Angle: %0.2f",angle),0,48,16,BLACK);
    }
}

void Enemy::Draw()
{
    DrawRectangle(x,y,width,height,RED);
    DrawText(TextFormat("HP: %i",hp),x,y+64,16,BLACK);
}

std::array<float,4> Enemy::Get_XYWH()
{
    return {x,y,width,height};
}

bool Enemy::GetDestroy()
{
    return destroy;
}

void Enemy::Damage(int get_dmg)
{
    hp -= get_dmg;

    if (hp <= 0)
    {
        destroy = true;
    }
}