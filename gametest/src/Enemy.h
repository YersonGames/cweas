#pragma once

#include "playerVariables.h"
#include <array>
#include <vector>

class Player;
class Block;

class Enemy
{
    public:
        float x;
        float y;
        float width;
        float height;
        float spd;

        Enemy(float get_x,float get_y,float get_w,float get_h);
        void Update(Player& player, std::vector<Block>& blocks);
        void Draw();
        std::array<float,4> Get_XYWH();
};