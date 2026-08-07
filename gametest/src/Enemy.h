#pragma once

#include "playerVariables.h"
#include "Player.h"
#include <vector>

class Enemy
{
    public:
        float x;
        float y;
        float width;
        float height;

        Enemy(float get_x,float get_y,float get_w,float get_h);
        void Update(Player& player);
        void Draw();
        std::vector<float> Get_XYWH();
};