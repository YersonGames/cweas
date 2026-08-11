#pragma once

#include "PlayerVariables.h"
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
        float dmgTimer;

        Player(float get_x,float get_y,float get_w,float get_h);
        void UpdateControl(PlayerVariables& playerVars);
        void UpdateCollisionBlock(std::vector<Block>& blocks, PlayerVariables& playerVars);
        void UpdateCollisionEnemy(std::vector<Enemy>& enemies, PlayerVariables& playerVars);
        void UpdateMovement(PlayerVariables& playerVars);
        void UpdateShoot(std::vector<Bullet>& bullets);
        void UpdateTimer();
        void SetX(float get_x);
        void SetY(float get_y);
        void Draw(PlayerVariables& playerVars);
        std::array<float,4> Get_XYWH();
};
