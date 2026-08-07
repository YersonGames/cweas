#include "utils.h"
#include <vector>
#include <array>
#include "Enemy.h"
#include "Player.h"

void EnemyUpdate(std::vector<Enemy>& enemies, Player& player)
{
for (auto enemy = enemies.begin(); enemy != enemies.end();enemy++)
        {
            enemy->Update(player);
        }
}