#include <raylib.h>

int main()
{
    Color c_red = {255,0,0,255}; //se crean a partir de un Struct
    Color c_white = {255,255,255,255};
    InitWindow(800,600,"Titulo");
    SetTargetFPS(60);
    //SetExitKey(32);

    int x = 64;
    int y = 64;

    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_W)){y-=5;}
        else if (IsKeyDown(KEY_S)){y+=5;}

        if (IsKeyDown(KEY_A)){x-=5;}
        else if (IsKeyDown(KEY_D)){x+=5;}

        BeginDrawing();
        ClearBackground(c_white);
        DrawRectangle(x,y,64,64,c_red);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}