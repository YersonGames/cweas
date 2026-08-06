#include <raylib.h>
#include <vector>

class Block
{
    public:
        float x;
        float y;
        float width;
        float height;

    Block(float get_x,float get_y,float get_w,float get_h)
    {
        x = get_x;
        y = get_y;
        width = get_w;
        height = get_h;
    }

    void Update();
    void Draw()
    {
        DrawRectangle(x,y,width,height,BLACK);
    }

    std::vector<float> Get_XYWH()
    {
        return {x,y,width,height};
    }
};