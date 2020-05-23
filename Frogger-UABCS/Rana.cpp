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

void Rana::borrarRana(){
    gotoxy2(this->x, this->y);cout<<" ";
    gotoxy2(this->x+1, this->y);cout<<" ";
    gotoxy2(this->x, this->y+1);cout<<" ";
    gotoxy2(this->x+1, this->y+1);cout<<" ";
}

void Rana::mover(int tecla){
    if(tecla==tecla_Arriba){
        borrarRana();
        this->y-=2;
        PlaySound(TEXT("sfx/Salto.wav"), NULL, SND_ASYNC);
    }
    else if(tecla==tecla_Abajo){
        borrarRana();
        this->y+=2;
        PlaySound(TEXT("sfx/Salto.wav"), NULL, SND_ASYNC);
    }
    else if(tecla==tecla_Der){
        borrarRana();
        this->x+=6;
        PlaySound(TEXT("sfx/Salto.wav"), NULL, SND_ASYNC);
    }
    else if(tecla==tecla_Izq){
        borrarRana();
        this->x-=6;
        PlaySound(TEXT("sfx/Salto.wav"), NULL, SND_ASYNC);
    }
}

void Rana::respawnRana(){
    this->x = 42;
    this->y = 26;
}
