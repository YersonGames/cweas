#include "utils.h"
#include <vector>
#include <array>
#include "Enemy.h"
#include "Player.h"
#include "Block.h"
#include "Bullet.h"

namespace utils
{
    //----------------------Enemies functions----------------------

    //enemy update
    void EnemyUpdate(std::vector<Enemy>& enemies, Player& player, std::vector<Block>& blocks)
    {
        for (auto enemy = enemies.begin(); enemy != enemies.end();enemy++)
            {
                enemy->Update(player,blocks);
            }
    }

    //enemy Draw
    void EnemyDraw(std::vector<Enemy>& enemies)
    {
        for (auto enemy = enemies.begin(); enemy != enemies.end();enemy++)
            {
                enemy->Draw();
            }
    }

    //enemy destroy detect
    void EnemyUpdateDestroy(std::vector<Enemy>& enemies)
    {
        for (auto enemy = enemies.begin();enemy != enemies.end();)
        {
            if (enemy->GetDestroy())
            {
                enemies.erase(enemy);
            }
            else
            {
                enemy++;
            }
        }
    }


    //--------------------Bullets functions--------------------

    //Bullet update
    void BulletUpdate(std::vector<Bullet>& bullets)
    {
        for (auto bullet = bullets.begin(); bullet != bullets.end();bullet++)
            {
                bullet->Update();
            }
    }
    //Bullet destroy detect
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
    //Bullet collision detect
    void BulletUpdateCollision(std::vector<Bullet>& bullets, std::vector<Block>& blocks, std::vector<Enemy>& enemies)
    {
        for (auto bullet = bullets.begin();bullet != bullets.end();bullet++)
        {
            bullet->UpdateCollision(blocks,enemies);
        }
    }
    //Bullet Draw
    void BulletDraw(std::vector<Bullet>& bullets)
    {
        for (auto bullet = bullets.begin(); bullet != bullets.end();bullet++)
            {
                bullet->Draw();
            }
    }


    //------------------Blocks functions---------------------------

    //Block Draw
    void BlockDraw(std::vector<Block>& blocks)
    {
        for (auto block = blocks.begin(); block != blocks.end();block++)
            {
                block->Draw();
            }
    }
}
