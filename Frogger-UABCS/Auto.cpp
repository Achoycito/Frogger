#include "Auto.h"
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <mmsystem.h>
#include <sstream>

using namespace std;

Auto::Auto(int y, int direccion, int modelo, int color){
    if(direccion == 0){
        this->xAuto = 70;
        this->xInic = 80;
    }
    else{
        this->xAuto = 10;
        this->xInic = 1;
    }
    this->yAuto = y;
    this->direccion = direccion;
    this->modelo = modelo;
    this->color = color;
}

Auto::Auto(){}

void Auto::gotoxy2(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Auto::printAuto(){
    if(this->modelo==1){
        gotoxy2(this->xAuto, this->yAuto+1);printf("%c\n",220);
        gotoxy2(this->xAuto,this->yAuto);printf("%c\n",223);
        gotoxy2(this->xAuto+1, this->yAuto);printf("%c\n",220);
        gotoxy2(this->xAuto+1,this->yAuto+1);printf("%c\n",223);
        gotoxy2(this->xAuto+2, this->yAuto);printf("%c\n",220);
        gotoxy2(this->xAuto+2,this->yAuto+1);printf("%c\n",223);
        gotoxy2(this->xAuto+3,this->yAuto);printf("%c\n",220);
        gotoxy2(this->xAuto+3,this->yAuto+1);printf("%c\n",223);
        gotoxy2(this->xAuto+4,this->yAuto);printf("%c\n",220);
        gotoxy2(this->xAuto+4,this->yAuto+1);printf("%c\n",223);
        gotoxy2(this->xAuto+5,this->yAuto+1);printf("%c\n",220);
        gotoxy2(this->xAuto+5,this->yAuto);printf("%c\n",223);
    }
    if(this->modelo==2 && direccion==0){
        gotoxy2(this->xAuto+5, yAuto);printf("%c\n",223);
        gotoxy2(this->xAuto+4, yAuto);printf("%c\n",220);
        gotoxy2(this->xAuto+3, yAuto);printf("%c\n",220);
        gotoxy2(this->xAuto+2, yAuto);printf("%c\n",219);
        gotoxy2(this->xAuto+1, yAuto);printf("%c\n",219);
        gotoxy2(this->xAuto, yAuto);printf("%c\n",220);
        gotoxy2(this->xAuto+4, yAuto+1);printf("%c\n",184);
        gotoxy2(this->xAuto+1, yAuto+1);printf("%c\n",184);
    }
    if(this->modelo==2 && direccion==1){
        gotoxy2(this->xAuto, yAuto);printf("%c\n",223);
        gotoxy2(this->xAuto+1, yAuto);printf("%c\n",220);
        gotoxy2(this->xAuto+2, yAuto);printf("%c\n",220);
        gotoxy2(this->xAuto+3, yAuto);printf("%c\n",219);
        gotoxy2(this->xAuto+4, yAuto);printf("%c\n",219);
        gotoxy2(this->xAuto+5, yAuto);printf("%c\n",220);
        gotoxy2(this->xAuto+5, yAuto+1);printf("%c\n",184);
        gotoxy2(this->xAuto+2, yAuto+1);printf("%c\n",184);
    }

}

void Auto::borrarAuto(){
    gotoxy2(this->xAuto, this->yAuto+1);printf(" ");
	gotoxy2(this->xAuto,this->yAuto);printf(" ");
	gotoxy2(this->xAuto+1, this->yAuto);printf(" ");
	gotoxy2(this->xAuto+1,this->yAuto+1);printf(" ");
	gotoxy2(this->xAuto+2, this->yAuto);printf(" ");
	gotoxy2(this->xAuto+2,this->yAuto+1);printf(" ");
    gotoxy2(this->xAuto+3,this->yAuto);printf(" ");
    gotoxy2(this->xAuto+3,this->yAuto+1);printf(" ");
    gotoxy2(this->xAuto+4,this->yAuto);printf(" ");
    gotoxy2(this->xAuto+4,this->yAuto+1);printf(" ");
    gotoxy2(this->xAuto+5,this->yAuto+1);printf(" ");
    gotoxy2(this->xAuto+5,this->yAuto);printf(" ");
}

void Auto::mover(){
    if(this->direccion==0){
        this->xAuto--;
    }
    else{
        this->xAuto++;
    }

    if((this->direccion==1) && (this->xAuto>70)){
        this->xAuto = this->xInic;
    }
    if((this->direccion==0) && (this->xAuto<10)){
        this->xAuto = this->xInic;
    }
}

int Auto::getxAuto(){
    return this->xAuto;
}
int Auto::getyAuto(){
    return this->yAuto;
}

void Auto::regresar(){
    if(this->direccion==0){
        this->xAuto=70;
    }
    else{
        this->yAuto=10;
    }
}









