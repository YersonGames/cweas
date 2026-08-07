#include "Player.h"
#include "playerVariables.h"
#include "raylib.h"
#include <array>

Player::Player(float get_x,float get_y,float get_w,float get_h)
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
    y += (playerVars.vspd * playerVars.spd)*GetFrameTime();
    x += (playerVars.hspd * playerVars.spd)*GetFrameTime();
}

void Player::Draw()
{
    DrawRectangle(x,y,width,height,LIME);
}

std::array<float,4> Player::Get_XYWH()
{
    return {x,y,width,height};
}

void Player::SetX(float get_x)
{
    x = get_x;
}

void Player::SetY(float get_y)
{
    y = get_y;
}