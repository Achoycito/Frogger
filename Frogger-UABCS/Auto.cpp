#include "Auto.h"

Auto::Auto(){

}

void Auto::mover(){
    for(int i=0; i<10; i++){
        if(direccion==0){
            this->xAuto-=2;
        }
        else{
            this->yAuto+=2;
        }
    }
}
