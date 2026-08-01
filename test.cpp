#include <raylib.h>

int main()
{
    Color c_red = {255,0,0,255}; //se crean a partir de un Struct
    InitWindow(800,600,"Titulo");
    SetTargetFPS(60);
    //SetExitKey(32);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        DrawRectangle(64,64,96,96,c_red);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}