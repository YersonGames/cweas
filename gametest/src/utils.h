#pragma once

#include <vector>
#include <array>

class Enemy;
class Player;
class Block;

//Detect collision
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

void EnemyUpdate(std::vector<Enemy>& enemies, Player& player, std::vector<Block>& blocks);
void EnemyDraw(std::vector<Enemy>& enemies);
void BlockDraw(std::vector<Block>& blocks);

auto sgn(auto value)
{
    return (auto(0) < value) - (value < auto(0));
}