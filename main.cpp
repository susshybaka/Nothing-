#include <mod/amlmod.h>
#include <mod/logger.h>
#include <mod/config.h>


MYMODCFG(net.someone.player, name_of_your_mod, 1.0, your_name)

void* hGame;

struct Vec3
{ 
    float x,y,z;
};

void (*GetPlayer_Coor)(Vec3&,int);

Vec3 Coordinates;

extern "C" void OnModLoad() //execution of your code starts from here.
{
    hGame = aml->GetLibHandle("libGTASA.so");
    if(hGame != NULL)  //checking if libGTASA.so is loaded
    {
        SET_TO(GetPlayer_Coor, aml->GetSym(hGame, "_Z15FindPlayerCoorsi"));    
        GetPlayer_Coor(Coordinates,-1);
    }
     else
        {
            logger->Error("The game is not supported!");
            return;
        }
}
    

