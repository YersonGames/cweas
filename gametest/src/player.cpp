#include "Player.h"
#include "playerVariables.h"
#include "raylib.h"
#include <vector>

Color c_red = {255,0,0,255};

Player::Player(int get_x,int get_y,int get_w,int get_h)
{
    x = get_x;
    y = get_y;
    width = get_w;
    height = get_h;
}
void Player::UpdateControl(playerVariables& playerVars)
{
    if (IsKeyDown(KEY_W)){playerVars.vspd = -1;}
    else if (IsKeyDown(KEY_S)){playerVars.vspd = 1;}
    else {playerVars.vspd = 0;}

    if (IsKeyDown(KEY_A)){playerVars.hspd = -1;}
    else if (IsKeyDown(KEY_D)){playerVars.hspd = 1;}
    else {playerVars.hspd = 0;}
}

void Player::UpdateMovement(playerVariables& playerVars)
{
    y += playerVars.vspd * playerVars.spd;
    x += playerVars.hspd * playerVars.spd;
}

void Player::Draw()
{
    DrawRectangle(x,y,width,height,c_red);
}

std::vector<int> Player::Get_XYWH()
{
    return {x,y,width,height};
}

void Player::SetX(int get_x)
{
    x = get_x;
}

void Player::SetY(int get_y)
{
    y = get_y;
}