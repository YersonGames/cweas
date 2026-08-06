#include <raylib.h>
#include <vector>

class Block
{
    public:
        int x;
        int y;
        int width;
        int height;

    Block(int get_x,int get_y,int get_w,int get_h)
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

    std::vector<int> Get_XYWH()
    {
        return {x,y,width,height};
    }
};