#pragma once

#include "playerVariables.h"
#include <array>
#include <vector>

class Block;
class Enemy;
class Bullet;


class Player
{
    public:
        float x;
        float y;
        float width;
        float height;

        Player(float get_x,float get_y,float get_w,float get_h);
        void UpdateControl(playerVariables& playerVars);
        void UpdateCollisionBlock(std::vector<Block>& blocks, playerVariables& playerVars);
        void UpdateCollisionEnemy(std::vector<Enemy>& enemies, playerVariables& playerVars);
        void UpdateMovement(playerVariables& playerVars);
        void UpdateShoot(std::vector<Bullet>& bullets);
        void SetX(float get_x);
        void SetY(float get_y);
        void Draw();
        std::array<float,4> Get_XYWH();
};
