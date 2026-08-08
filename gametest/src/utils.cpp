#include "utils.h"
#include <vector>
#include <array>
#include "Enemy.h"
#include "Player.h"
#include "Block.h"

//Enemies Update
void EnemyUpdate(std::vector<Enemy>& enemies, Player& player, std::vector<Block>& blocks)
{
for (auto enemy = enemies.begin(); enemy != enemies.end();enemy++)
        {
            enemy->Update(player,blocks);
        }
}

//Enemies Draw
void EnemyDraw(std::vector<Enemy>& enemies)
{
    for (auto enemy = enemies.begin(); enemy != enemies.end();enemy++)
        {
            enemy->Draw();
        }
}

//Blocks Draw
void BlockDraw(std::vector<Block>& blocks)
{
    for (auto block = blocks.begin(); block != blocks.end();block++)
        {
            block->Draw();
        }
}