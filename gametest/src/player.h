#include "playerVariables.h"
#include <vector>
#pragma once


class Player
{
    public:
        int x;
        int y;
        int width;
        int height;

        Player(int get_x,int get_y,int get_w,int get_h);
        void Update(playerVariables& playerVars);
        void Draw();
        std::vector<int> Get_XYWH();
};