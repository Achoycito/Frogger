#include "Rana.h"
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <mmsystem.h>
#include <sstream>

#define tecla_Arriba 72
#define tecla_Abajo 80
#define tecla_Izq 75
#define tecla_Der 77
#define tecla_A 97
#define tecla_D 100

using namespace std;

void Rana::gotoxy2(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

Rana::Rana(){}

Rana::Rana(int x, int y){
    this->x = x;
    this->y = y;
}

int Rana::getXRana(){
    return this->x;
}
int Rana::getYRana(){
    return this->y;
}

void Rana::printRana(){
    gotoxy2(this->x, this->y);printf("%c\n",219);
    gotoxy2(this->x+1, this->y);printf("%c\n",219);
    gotoxy2(this->x, this->y+1);printf("%c\n",93);
    gotoxy2(this->x+1, this->y+1);printf("%c\n",91);
}
void Rana::printRanaJR(int x, int y){
    gotoxy2(x, y);printf("%c\n",220);
    gotoxy2(x+1, y);printf("%c\n",220);
    gotoxy2(x, y+1);printf("%c\n",217);
    gotoxy2(x+1, y+1);printf("%c\n",192);
}

void Rana::borrarRana(){
    gotoxy2(this->x, this->y);cout<<" ";
    gotoxy2(this->x+1, this->y);cout<<" ";
    gotoxy2(this->x, this->y+1);cout<<" ";
    gotoxy2(this->x+1, this->y+1);cout<<" ";
}

void Rana::mover(int tecla, bool e1, bool e2, bool e3, bool e4, bool e5){
    if(this->y >= 4){
        if(this->y>4){
            if(tecla==tecla_Arriba){
                PlaySound(TEXT("sfx/Salto.wav"), NULL, SND_ASYNC);
                borrarRana();
                this->y-=2;
            }
        }
        else if(y==4){
            if((this->x>=16 && this->x<22 && e1==true) || (this->x>=28&&this->x<34 && e2==true) || (this->x>=40&&this->x<46 && e3==true) || (this->x>=52&&this->x<58 && e4==true) || (this->x>=64&&this->x<70 && e5==true)){
                if(tecla==tecla_Arriba){
                    PlaySound(TEXT("sfx/Salto.wav"), NULL, SND_ASYNC);
                    borrarRana();
                    this->y-=2;
                }
            }
        }
    }
    if(this->y <26){
        if(tecla==tecla_Abajo){
            PlaySound(TEXT("sfx/Salto.wav"), NULL, SND_ASYNC);
            borrarRana();
            this->y+=2;
        }
    }
    if(this->x <74){
        if(tecla==tecla_Der){
            PlaySound(TEXT("sfx/Salto.wav"), NULL, SND_ASYNC);
            borrarRana();
            this->x+=6;
        }
        if(tecla==tecla_D){
            PlaySound(TEXT("sfx/Salto.wav"), NULL, SND_ASYNC);
            borrarRana();
            this->x++;
        }
    }
    if(this->x > 10){
        if(tecla==tecla_Izq){
            PlaySound(TEXT("sfx/Salto.wav"), NULL, SND_ASYNC);
            borrarRana();
            this->x-=6;
        }
        if(tecla==tecla_A){
            PlaySound(TEXT("sfx/Salto.wav"), NULL, SND_ASYNC);
            borrarRana();
            this->x--;
        }
    }
}

void Rana::respawnRana(){
    this->x = 42;
    this->y = 26;
}

void Rana::recorrer(int vel, int dir){
    if(dir==0){
        this->x -= vel;
    }
    else{
        this->x += vel;
    }
}
