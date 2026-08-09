#include "utils.h"
#include <vector>
#include <array>
#include "Enemy.h"
#include "Player.h"
#include "Block.h"
#include "Bullet.h"

//Enemies Update
void EnemyUpdate(std::vector<Enemy>& enemies, Player& player, std::vector<Block>& blocks)
{
    for (auto enemy = enemies.begin(); enemy != enemies.end();enemy++)
        {
            enemy->Update(player,blocks);
        }
}

void BulletUpdate(std::vector<Bullet>& bullets)
{
    for (auto bullet = bullets.begin(); bullet != bullets.end();bullet++)
        {
            bullet->Update();
        }
}

void BulletUpdateDestroy(std::vector<Bullet>& bullets)
{
    for (auto bullet = bullets.begin();bullet != bullets.end();)
    {
        if (bullet->GetDestroy())
        {
            bullets.erase(bullet);
        }
        else
        {
            bullet++;
        }
    }
}

void BulletUpdateCollision(std::vector<Bullet>& bullets, std::vector<Block>& blocks, std::vector<Enemy>& enemies)
{
    for (auto bullet = bullets.begin();bullet != bullets.end();bullet++)
    {
        bullet->UpdateCollision(blocks,enemies);
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

void BulletDraw(std::vector<Bullet>& bullets)
{
    for (auto bullet = bullets.begin(); bullet != bullets.end();bullet++)
        {
            bullet->Draw();
        }
}