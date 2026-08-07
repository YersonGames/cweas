#include "Enemy.h"
#include "Player.h"
#include <raylib.h>
#include <math.h>
#include <vector>

Enemy::Enemy(float get_x,float get_y,float get_w,float get_h)
{
    x = get_x;
    y = get_y;
    width = get_w;
    height = get_h;
}

void Enemy::Update(Player& player)
{
    float distX = player.Get_XYWH()[0]-x;
    float distY = player.Get_XYWH()[1]-y;

    float distance = std::sqrt((distX*distX)+(distY*distY));

    if (distance > 0)
    {
        float dirX = distX/distance;
        float dirY = distY/distance;

        x += (dirX*150.0f)*GetFrameTime();
        y += (dirY*150.0f)*GetFrameTime();
    }
}

void Enemy::Draw()
{
    DrawRectangle(x,y,width,height,RED);
}

std::vector<float> Enemy::Get_XYWH()
{
    return {x,y,width,height};
}