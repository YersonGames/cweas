#pragma once

#include <vector>

class Enemy;
class Block;

class Bullet
{
    public:
        float x;
        float y;
        float width;
        float height;
        float angle;
        float spd;
        bool destroy;

        Bullet(float get_x,float get_y, float get_w, float get_h, float get_angle, float get_spd);
        void Update();
        void UpdateCollision(std::vector<Block>& blocks,std::vector<Enemy>& enemies);
        void Draw();
        bool GetDestroy();
};