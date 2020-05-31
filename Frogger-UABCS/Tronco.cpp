#include "Tronco.h"
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <mmsystem.h>
#include <sstream>

Tronco::Tronco(int x,int y, int direccion, int _velocidad)
{

    this->xTronco = x;
    if(direccion == 0){
        this->xInic = 80;
    }
    else{
        this->xInic = 1;
    }
    this->yTronco = y;
    this->direccion = direccion;
    this->velocidad = _velocidad;
}

Tronco::Tronco(){}

void Tronco::gotoxy2(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Tronco::printTonco(){

    gotoxy2(this->xTronco, this->yTronco);printf("%c\n",219);
    gotoxy2(this->xTronco, this->yTronco+1);printf("%c\n",219);
    gotoxy2(this->xTronco+1, this->yTronco);printf("%c\n",219);
    gotoxy2(this->xTronco+1, this->yTronco+1);printf("%c\n",219);
    gotoxy2(this->xTronco+2, this->yTronco);printf("%c\n",219);
    gotoxy2(this->xTronco+2, this->yTronco+1);printf("%c\n",219);
    gotoxy2(this->xTronco+3, this->yTronco);printf("%c\n",219);
    gotoxy2(this->xTronco+3, this->yTronco+1);printf("%c\n",219);
    gotoxy2(this->xTronco+4, this->yTronco);printf("%c\n",219);
    gotoxy2(this->xTronco+4, this->yTronco+1);printf("%c\n",219);
    gotoxy2(this->xTronco+5, this->yTronco);printf("%c\n",219);
    gotoxy2(this->xTronco+5, this->yTronco+1);printf("%c\n",219);

}
void Tronco::borrarTronco(){
    gotoxy2(this->xTronco, this->yTronco+1);printf(" ");
	gotoxy2(this->xTronco,this->yTronco);printf(" ");
	gotoxy2(this->xTronco+1, this->yTronco);printf(" ");
	gotoxy2(this->xTronco+1,this->yTronco+1);printf(" ");
	gotoxy2(this->xTronco+2, this->yTronco);printf(" ");
	gotoxy2(this->xTronco+2,this->yTronco+1);printf(" ");
    gotoxy2(this->xTronco+3,this->yTronco);printf(" ");
    gotoxy2(this->xTronco+3,this->yTronco+1);printf(" ");
    gotoxy2(this->xTronco+4,this->yTronco);printf(" ");
    gotoxy2(this->xTronco+4,this->yTronco+1);printf(" ");
    gotoxy2(this->xTronco+5,this->yTronco+1);printf(" ");
    gotoxy2(this->xTronco+5,this->yTronco);printf(" ");
}

int Auto::getxTronco(){
    return this->xTronco;
}
int Auto::getyTronco(){
    return this->yTronco;
}


void Tronco::regresar(){
    if(this->direccion==0){
        this->xAuto=70;
    }
    else{
        this->yAuto=10;
    }
}

