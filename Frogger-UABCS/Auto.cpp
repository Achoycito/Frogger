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

Auto::Auto(int x, int y, int direccion){
    this->xAuto = x;
    this->yAuto = y;
    this->direccion = direccion;
}

Auto::Auto(){}



void Auto::mover(){
    if(this->direccion==0){
        this->xAuto--;
    }
    else{
        this->yAuto++;
    }
}

int Auto::getxAuto(){
    return this->xAuto;
}
int Auto::getyAuto(){
    return this->yAuto;
}
