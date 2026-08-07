#include "playerVariables.h"
#include <array>
#pragma once


class Player
{
    public:
        float x;
        float y;
        float width;
        float height;

        Player(float get_x,float get_y,float get_w,float get_h);
        void UpdateControl(playerVariables& playerVars);
        void UpdateMovement(playerVariables& playerVars);
        void SetX(float get_x);
        void SetY(float get_y);
        void Draw();
        std::array<float,4> Get_XYWH();
};