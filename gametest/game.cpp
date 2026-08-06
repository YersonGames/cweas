#include "raylib.h"
#include <vector>
#include <math.h>
#include "src/playerVariables.h"
#include "src/Player.h"
#include "src/Block.h"

bool GetCollision(int objX, int objY, int objW, int objH, auto& obj);

int main()
{
    InitWindow(800,600,"Titulo");
    SetTargetFPS(60);
    //SetExitKey(32);
    playerVariables playerVars = {0,0,5};
    Player player(64,64,64,64);
    std::vector<Block> blocks;

    blocks.push_back(Block(192,192,64,64));
    blocks.push_back(Block(256,256,64,64));

    while (!WindowShouldClose())
    {
        

        player.UpdateControl(playerVars);


        //colisiones, deberia funcionar como el place_meeting del gamemaker jeje
        //por alguna razon la colision se queda a 1 pixel de ser perfecta :(
        for (auto block = blocks.begin(); block != blocks.end();)
        {
            //horizontal
            if ( GetCollision(player.Get_XYWH()[0]+(playerVars.spd*playerVars.hspd),player.Get_XYWH()[1],player.Get_XYWH()[2],player.Get_XYWH()[3],*block) )
            {
                //blocks.erase(block); //borrar la wea
                while ( !GetCollision(player.Get_XYWH()[0]+playerVars.hspd,player.Get_XYWH()[1],player.Get_XYWH()[2],player.Get_XYWH()[3],*block) )
                {
                    player.SetX(player.Get_XYWH()[0]+playerVars.hspd);
                }
                playerVars.hspd = 0;
            }

            //vertical
            if ( GetCollision(player.Get_XYWH()[0],player.Get_XYWH()[1]+(playerVars.spd*playerVars.vspd),player.Get_XYWH()[2],player.Get_XYWH()[3],*block) )
            {
                while ( !GetCollision(player.Get_XYWH()[0],player.Get_XYWH()[1]+playerVars.vspd,player.Get_XYWH()[2],player.Get_XYWH()[3],*block) )
                {
                    player.SetY(player.Get_XYWH()[1]+playerVars.vspd);
                }
                playerVars.vspd = 0;
            }

            ++block;
        }

        player.UpdateMovement(playerVars);

        BeginDrawing();
        ClearBackground({255,255,255,255});

        player.Draw();
        for (auto& block : blocks) {block.Draw();}
        
        DrawText(TextFormat("PlayerX: %i",player.Get_XYWH()[0]),0,0,16,BLACK);
        DrawText(TextFormat("PlayerY: %i",player.Get_XYWH()[1]),0,16,16,BLACK);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

bool GetCollision(int objX, int objY, int objW, int objH, auto& obj)
{
    std::vector<int> data = obj.Get_XYWH();
    if (objX+objW >= data[0] && objY+objH >= data[1] && objX <= data[0]+data[2] && objY <= data[1]+data[3])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}