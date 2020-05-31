#include "Tronco.h"
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <mmsystem.h>
#include <sstream>

using namespace std;

Tronco::Tronco(int x,int y, int direccion, int _velocidad){
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

void Tronco::printTronco(){

    /*
    gotoxy2(this->xTronco, this->yTronco);printf("%c\n",219);
    gotoxy2(this->xTronco+1, this->yTronco);printf("%c\n",219);
    gotoxy2(this->xTronco+2, this->yTronco);printf("%c\n",219);
    gotoxy2(this->xTronco+3, this->yTronco);printf("%c\n",219);
    gotoxy2(this->xTronco+4, this->yTronco);printf("%c\n",219);
    gotoxy2(this->xTronco+5, this->yTronco);printf("%c\n",219);
    gotoxy2(this->xTronco, this->yTronco+1);printf("%c\n",219);
    gotoxy2(this->xTronco+1, this->yTronco+1);printf("%c\n",219);
    gotoxy2(this->xTronco+2, this->yTronco+1);printf("%c\n",219);
    gotoxy2(this->xTronco+3, this->yTronco+1);printf("%c\n",219);
    gotoxy2(this->xTronco+4, this->yTronco+1);printf("%c\n",219);
    gotoxy2(this->xTronco+5, this->yTronco+1);printf("%c\n",219);
    */
    for(int i=0; i<18; i++){
        gotoxy2(this->xTronco+i, this->yTronco+1);printf("%c\n",219);
    }

}
void Tronco::borrarTronco(){
    /*
	gotoxy2(this->xTronco,this->yTronco);printf(" ");
	gotoxy2(this->xTronco+1, this->yTronco);printf(" ");
	gotoxy2(this->xTronco+2, this->yTronco);printf(" ");
    gotoxy2(this->xTronco+3,this->yTronco);printf(" ");
    gotoxy2(this->xTronco+4,this->yTronco);printf(" ");
    gotoxy2(this->xTronco+5,this->yTronco);printf(" ");
    */
    for(int i=0; i<18; i++){
        gotoxy2(this->xTronco+i, this->yTronco+1);printf("%c\n",219);
    }/*
    gotoxy2(this->xTronco, this->yTronco+1);printf("%c\n",219);
	gotoxy2(this->xTronco+1,this->yTronco+1);printf("%c\n",219);
	gotoxy2(this->xTronco+2,this->yTronco+1);printf("%c\n",219);
    gotoxy2(this->xTronco+3,this->yTronco+1);printf("%c\n",219);
    gotoxy2(this->xTronco+4,this->yTronco+1);printf("%c\n",219);
    gotoxy2(this->xTronco+5,this->yTronco+1);printf("%c\n",219);*/
}

void Tronco::mover(){
    if(this->direccion==0){
        this->xTronco-=this->velocidad;
    }
    else{
        this->xTronco+=this->velocidad;
    }

    if((this->direccion==1) && (this->xTronco>70)){
        this->xTronco = this->xInic;
    }
    if((this->direccion==0) && (this->xTronco<10)){
        this->xTronco = this->xInic;
    }
}

bool Tronco::checkColision(int xr, int yr){
    int coinc=0;

    for(int i=0; i<2; i++){
        for(int j=0; j<18; j++){
            if((xr+i) == (this->xTronco+j) && yr==this->yTronco){
                coinc++;
            }
        }
    }

    if(coinc>0){
        return true;
    }
    else{
        return false;
    }
}


int Tronco::getxTronco(){
    return this->xTronco;
}
int Tronco::getyTronco(){
    return this->yTronco;
}
int Tronco::getVelocidad(){
    return this->velocidad;
}
int Tronco::getDireccion(){
    return this->direccion;
}


void Tronco::regresar(){
    if(this->direccion==0){
        this->xTronco=70;
    }
    else{
        this->yTronco=10;
    }
}

