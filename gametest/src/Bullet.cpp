#include <iostream>
#include "raylib.h"
#include "cmath"
#include <vector>

#include "Bullet.h"
#include "block.h"
#include "utils.h"
#include "Enemy.h"

Bullet::Bullet(float get_x,float get_y, float get_w, float get_h, float get_angle, float get_spd)
{
    x = get_x;
    y = get_y;
    width = get_w;
    height = get_h;
    angle = get_angle;
    spd = get_spd;
    destroy = false;
}

void Bullet::Update()
{
    float dirX = cos(angle*(PI/180));
    float dirY = sin(angle*(PI/180));

    x += (dirX*spd)*GetFrameTime();
    y += (dirY*spd)*GetFrameTime();
}

void Bullet::UpdateCollision(std::vector<Block>& blocks,std::vector<Enemy>& enemies)
{
    //Block
    if (destroy == false)
    {
        for (auto block = blocks.begin(); block != blocks.end();block++)
        {
            if (GetCollision(x,y,width,height,*block))
            {
                destroy = true;
                break;
            }
        }
    }

    //Enemy
    if (destroy == false)
    {
        for (auto enemy = enemies.begin(); enemy != enemies.end();enemy++)
        {
            if (GetCollision(x,y,width,height,*enemy))
            {
                destroy = true;
                break;
            }
        }
    }

    //Outside screen yiaaaa, afuera e la wea
    if (destroy == false)
    {
        if (x < 0 || x > 800 || y < 0 || y > 600)
        {
            destroy = true;
        }
    }
}

void Bullet::Draw()
{
    DrawRectangle(x,y,width,height,YELLOW);
}

bool Bullet::GetDestroy()
{
    return destroy;
}