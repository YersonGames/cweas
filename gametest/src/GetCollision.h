#pragma once

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