#pragma once

#include <vector>
#include <array>

class Enemy;
class Player;
class Block;
class Bullet;

//Detect collision

namespace utils
{
    bool GetCollision(float objX, float objY, float objW, float objH, auto& obj)
    {
        std::array<float,4> data = obj.Get_XYWH();
        if (objX+objW > data[0] && objY+objH > data[1] && objX < data[0]+data[2] && objY < data[1]+data[3])
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }


    //Enemy functions
    void EnemyUpdate(std::vector<Enemy>& enemies, Player& player, std::vector<Block>& blocks);
    void EnemyDraw(std::vector<Enemy>& enemies);
    void EnemyUpdateDestroy(std::vector<Enemy>& enemies);

    //Block Functions
    void BlockDraw(std::vector<Block>& blocks);

    //Bullet functions
    void BulletUpdate(std::vector<Bullet>& bullets);
    void BulletUpdateDestroy(std::vector<Bullet>& bullets);
    void BulletUpdateCollision(std::vector<Bullet>& bullets, std::vector<Block>& blocks, std::vector<Enemy>& enemies);
    void BulletDraw(std::vector<Bullet>& bullets);

    //Math sign
    auto sgn(auto value)
    {
        return (auto(0) < value) - (value < auto(0));
    }
}
