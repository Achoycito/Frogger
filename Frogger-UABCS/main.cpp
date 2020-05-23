#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <mmsystem.h>
#include <sstream>

#include "Auto.h"
#include "Rana.h"

#define tecla_Arriba 72
#define tecla_Abajo 80
#define tecla_Izq 75
#define tecla_Der 77
#define tecla_Enter 13

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
int opcionSelect = 1;

void ocultarCursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void letras();
int menu (const char *titulo, const char *opciones[], int n);
void primeraLinea(int x, int y);
void imprimirMapa();
void imprimirMapa2();
void imprimirMapa3();
void imprimirMapa4();
void jugar();
void instrucciones();
void creditos();
void salir();
void menu_principal();
bool AjustarVentana(int Ancho, int Alto);
void printAuto(int xT, int yT);

            int main (){
    AjustarVentana(120,30);
	ocultarCursor();
    menu_principal();
    return 0;
}

void letras(){
    SetConsoleTextAttribute(h, 2);
    int xTitu=10;
    int yTitu=5;
    gotoxy(xTitu, yTitu);   cout<<"##########    ###########     ########      ########      ########      ########    ###########   "<<endl;
    gotoxy(xTitu, yTitu+1); cout<<"############  ############  ############  ############  ############  ############  ############  "<<endl;
    gotoxy(xTitu, yTitu+2); cout<<"####          ####     ###  ####    ####  ####          ####          ####          ####     ###  "<<endl;
    gotoxy(xTitu, yTitu+3); cout<<"####          ####     ###  ####    ####  ####          ####          ####          ####     ###  "<<endl;
    gotoxy(xTitu, yTitu+4); cout<<"####          ####    ####  ####    ####  ####          ####          ####          ####    ####  "<<endl;
    gotoxy(xTitu, yTitu+5); cout<<"##########    ###########   ####    ####  ####          ####          ############  ###########   "<<endl;
    gotoxy(xTitu, yTitu+6); cout<<"########      ######        ####    ####  ####  #####   ####  #####   ############  ######        "<<endl;
    gotoxy(xTitu, yTitu+7); cout<<"####          ########      ####    ####  ####  ######  ####  ######  ####          ########      "<<endl;
    gotoxy(xTitu, yTitu+8); cout<<"####          #### ####     ####    ####  ####    ####  ####    ####  ####          #### ####     "<<endl;
    gotoxy(xTitu, yTitu+9); cout<<"####          ####  ####    ####    ####  ####    ####  ####    ####  ####          ####  ####    "<<endl;
    gotoxy(xTitu, yTitu+10);cout<<"####          ####    ###   ############  ############  ############  ############  ####    ###   "<<endl;
    gotoxy(xTitu, yTitu+11);cout<<"##            ####     ####   ########      ########      ########      ########    ####     ####  "<<endl;
    cout<<endl;
    SetConsoleTextAttribute(h, 15);
}

int menu(const char *titulo, const char *opciones[], int n){

    int tecla;
    bool repeticion = true;

    do{
        system("cls");

        gotoxy(44, 19 + opcionSelect);
        SetConsoleTextAttribute(h, 3);
        cout<<"-->";
        SetConsoleTextAttribute(h, 15);
        gotoxy(15, 2);
        letras();

        for(int i = 0; i < 4; i++){
            gotoxy(48, 20 + i ); cout<<i + 1<< ") "<<opciones[i];
    	}
        do{
            tecla = getch();
        }while(tecla != tecla_Arriba && tecla != tecla_Abajo && tecla != tecla_Enter);

    switch (tecla){
        case tecla_Arriba:
            PlaySound(TEXT("sfx/Change.wav"), NULL, SND_ASYNC);
            opcionSelect--;
            if (opcionSelect < 1){
                opcionSelect = n;
            }
            break;
        case tecla_Abajo:
            PlaySound(TEXT("sfx/Change.wav"), NULL, SND_ASYNC);
            opcionSelect++;
            if (opcionSelect > n){
                opcionSelect = 1;
            }
            break;
        case tecla_Enter:
            PlaySound(TEXT("sfx/Select.wav"), NULL, SND_ASYNC);
            repeticion = false;
            break;
    }

    }while(repeticion);


    return opcionSelect;
}

void menu_principal(){
    bool repetir = true;
    int opcion;
    const char *titulo = "FROGGER";
    const char *opciones[] = {"Iniciar juego", "Instrucciones", "Creditos", "Salir"};
    int n = 4;

    opcion = menu(titulo, opciones, n);

    do {
        switch (opcion){
            case 1:
                repetir = false;
                jugar();
                break;
            case 2:
                repetir = false;
                instrucciones();
                break;
            case 3:
                repetir = false;
                creditos();
                break;
            case 4:
                salir();
                repetir = false;
                break;
        }
    }while (repetir);

}

void primeraLinea(int x, int y){
    SetConsoleTextAttribute(h, 2);
    gotoxy(x,y-1);
    for(int i=0; i<66; i++){
        printf("%c", 219);
    }
    for(int i=0; i<2; i++){
        gotoxy(x,y);
        for(int j=0; j<66; j++){
            if((j>=6 && j<12) || (j>=18 && j<24) || (j>=30 && j<36) || (j>=42 && j<48) || (j>=54 && j<60)){
                SetConsoleTextAttribute(h, 3);
            }
            else{
                SetConsoleTextAttribute(h, 2);
            }
            printf("%c", 219);
        }
        y++;
    }
}

void imprimirMapa(){
    int xMap=10, yMap=2;
    primeraLinea(xMap, yMap);
    yMap+=2;
    SetConsoleTextAttribute(h, 8);
    for(int i=0; i<2; i++){
        gotoxy(xMap, yMap);
        for(int j=0; j<66; j++){
            printf("%c", 219);
        }
        yMap++;
    }
    yMap+=8;
    for(int i=0; i<2; i++){
        gotoxy(xMap, yMap);
        for(int j=0; j<66; j++){
            printf("%c", 219);
        }
        yMap++;
    }
    yMap+=10;
    for(int i=0; i<2; i++){
        gotoxy(xMap, yMap);
        for(int j=0; j<66; j++){
            printf("%c", 219);
        }
        yMap++;
    }



    SetConsoleTextAttribute(h, 15);
}

void imprimirMapa2(){
    int xMap=10, yMap=2;
    primeraLinea(xMap, yMap);
    yMap+=6;
    SetConsoleTextAttribute(h, 8);
    for(int i=0; i<2; i++){
        gotoxy(xMap, yMap);
        for(int j=0; j<66; j++){
            printf("%c", 219);
        }
        yMap++;
    }
    yMap+=4;
    for(int i=0; i<2; i++){
        gotoxy(xMap, yMap);
        for(int j=0; j<66; j++){
            printf("%c", 219);
        }
        yMap++;
    }
    yMap+=10;
    for(int i=0; i<2; i++){
        gotoxy(xMap, yMap);
        for(int j=0; j<66; j++){
            printf("%c", 219);
        }
        yMap++;
    }



    SetConsoleTextAttribute(h, 15);
}

void imprimirMapa3(){
    int xMap=10, yMap=2;
    primeraLinea(xMap, yMap);
    yMap+=2;
    SetConsoleTextAttribute(h, 3);
    for(int i=0; i<10; i++){
        gotoxy(xMap, yMap);
        for(int j=0; j<66; j++){
            SetConsoleTextAttribute(h, 2);
           if(i <= 5 and i>=4  and j > 6 and j <60 ){
            printf("%c", 219);
           }
           else{
            SetConsoleTextAttribute(h, 3);
            printf("%c", 219);
           }


        }
        yMap++;
    }

    SetConsoleTextAttribute(h, 8);
    for(int i=0; i<2; i++){
        gotoxy(xMap, yMap);
        for(int j=0; j<66; j++){
            printf("%c", 219);
        }
        yMap++;
    }
    yMap+=10;
    for(int i=0; i<2; i++){
        gotoxy(xMap, yMap);
        for(int j=0; j<66; j++){
            printf("%c", 219);
        }
        yMap++;
    }
    SetConsoleTextAttribute(h, 15);
}

void imprimirMapa4(){
    int xMap=10, yMap=2;
    primeraLinea(xMap, yMap);
    yMap+=2;
    SetConsoleTextAttribute(h, 3);
    for(int i=0; i<10; i++){
        gotoxy(xMap, yMap);
        for(int j=0; j<66; j++){
            printf("%c", 219);
        }
        yMap++;
    }
    SetConsoleTextAttribute(h, 8);
    for(int i=0; i<2; i++){
        gotoxy(xMap, yMap);
        for(int j=0; j<66; j++){
            printf("%c", 219);
        }
        yMap++;
    }
    yMap+=10;
    for(int i=0; i<2; i++){
        gotoxy(xMap, yMap);
        for(int j=0; j<66; j++){
            printf("%c", 219);
        }
        yMap++;
    }
    SetConsoleTextAttribute(h, 15);
}

            void jugar(){
    Auto auto1 = Auto(6, 0, 2, 0);
    Rana ranita = Rana(42, 26);
    int tecla;
    int i=0;
    bool repeticion=true;
    system("cls");
    do{
        gotoxy(100, 13);
        cout<<i;
        imprimirMapa();

        auto1.borrarAuto();
        if(auto1.checkColision(ranita.getXRana(), ranita.getYRana())){
            ranita.borrarRana();
            PlaySound(TEXT("sfx/Vida menos.wav"), NULL, SND_ASYNC);
            Sleep(1500);
            ranita.respawnRana();
        }
        auto1.mover();
        if(auto1.getxAuto()>=10 && auto1.getxAuto()<=70){
            SetConsoleTextAttribute(h, 4);
            auto1.printAuto();
        }

        SetConsoleTextAttribute(h, 2);
        ranita.printRana();

        if(kbhit()){
            tecla = getch();
            ranita.mover(tecla);
        }

        i++;
        Sleep(1);

    }while(repeticion);

}

void instrucciones(){
    int tecla;
    system("cls");
    int xgoto = 8;
    int ygoto = 4;

    SetConsoleTextAttribute(h, 3);
    gotoxy(xgoto, ygoto);  cout<<"######  ######  ######  ######  ######  ##  ##  ######  ######  ######  ######  ######  ######  ######"<<endl;
    gotoxy(xgoto, ygoto+1);cout<<"  ##    ##  ##  ##        ##    ##  ##  ##  ##  ##      ##        ##    ##  ##  ##  ##  ##      ##    "<<endl;
    gotoxy(xgoto, ygoto+2);cout<<"  ##    ##  ##  ######    ##    #####   ##  ##  ##      ##        ##    ##  ##  ##  ##  ####    ######"<<endl;
    gotoxy(xgoto, ygoto+3);cout<<"  ##    ##  ##      ##    ##    ##  ##  ##  ##  ##      ##        ##    ##  ##  ##  ##  ##          ##"<<endl;
    gotoxy(xgoto, ygoto+4);cout<<"######  ##  ##  ######    ##    ##  ##  ######  ######  ######  ######  ######  ##  ##  ######  ######"<<endl;
    SetConsoleTextAttribute(h, 15);
    gotoxy(xgoto+28, ygoto+8);
    cout<<"Controles:";
    gotoxy(xgoto+30, ygoto+9);
    cout<<"-Flecha arriba: moverse hacia adelante";
    gotoxy(xgoto+30, ygoto+10);
    printf("-Flecha abajo: moverse hacia atr%cs", 160);
    gotoxy(xgoto+30, ygoto+11);
    cout<<"-Flecha izquierda: moverse a la izquierda";
    gotoxy(xgoto+30, ygoto+12);
    cout<<"-Flecha derecha: moverse a la derecha";

    gotoxy(xgoto+28, ygoto+14);
    cout<<"Consigue puntos:";
    gotoxy(xgoto+30, ygoto+15);
    cout<<"-Completando el nivel en poco tiempo";
    gotoxy(xgoto+30, ygoto+16);
    cout<<"-Recogiendo objetos especiales";
    gotoxy(xgoto+30, ygoto+17);
    cout<<"-Ganando con varias vidas restantes";

    gotoxy(25,24);
    SetConsoleTextAttribute(h, 3);
    cout<<"-->";
    SetConsoleTextAttribute(h, 15);
    gotoxy(29, 24);
    printf("Presione Enter para volver al men%c principal", 163);

    do{
        tecla = getch();
    }while(tecla != tecla_Enter);

    if(tecla == tecla_Enter){
        PlaySound(TEXT("sfx/Select.wav"), NULL, SND_ASYNC);
        menu_principal();
    }
}

void creditos(){
    int tecla;
    int xGoto=39;
    int yGoto=4;
    system("cls");
  //  setlocale(LC_ALL, "spanish");
    SetConsoleTextAttribute(h, 3);
    gotoxy(xGoto-10, yGoto);  cout<<"######  ######  ######  #####   ######  ######  ######  ######"<<endl;
    gotoxy(xGoto-10, yGoto+1);cout<<"##      ##  ##  ##      ##  ##    ##      ##    ##  ##  ##    "<<endl;
    gotoxy(xGoto-10, yGoto+2);cout<<"##      #####   ####    ##  ##    ##      ##    ##  ##  ######"<<endl;
    gotoxy(xGoto-10, yGoto+3);cout<<"##      ##  ##  ##      ##  ##    ##      ##    ##  ##      ##"<<endl;
    gotoxy(xGoto-10, yGoto+4);cout<<"######  ##  ##  ######  #####   ######    ##    ######  ######"<<endl;
    SetConsoleTextAttribute(h, 15);
    gotoxy(xGoto+2, yGoto+8);
    cout<<"Desarrollado por:"<<endl;
    gotoxy(xGoto+6, yGoto+9);
    printf("*Francisco Javier D%Caz de la Pe%ca", 161, 164);
    gotoxy(xGoto+6, yGoto+10);
    printf("*Alan Gonz%clez de la Llave Achoy", 160);
    gotoxy(xGoto+6, yGoto+11);
    cout<<"*Moises Moreno Quirarte";

    gotoxy(xGoto+2, yGoto+14);
    cout<<"Estudiantes de la carrera de";
    gotoxy(xGoto+2, yGoto+15);
    printf("Ingenier%ca en Desarrollo de Software en la ", 161);
    gotoxy(xGoto+2, yGoto+16);
    cout<<"Universidad Autonoma de Baja California Sur";


    gotoxy(25,23);
    SetConsoleTextAttribute(h, 3);
    cout<<"-->";
    SetConsoleTextAttribute(h, 15);
    gotoxy(29, 23);
    printf("Presione Enter para volver al men%c principal", 163);

    do{
        tecla = getch();
    }while(tecla != tecla_Enter);

    if(tecla == tecla_Enter){
        PlaySound(TEXT("sfx/Select.wav"), NULL, SND_ASYNC);
        menu_principal();
    }
}

void salir(){
    system("cls");
    SetConsoleTextAttribute(h, 3);
    int x=33, y=6;
    gotoxy(x,y);  cout<<" #####  #####    ####    #####  ######   ####    #####";
    gotoxy(x,y+1);cout<<"##      ##  ##  ##  ##  ##        ##    ##  ##  ##    ";
    gotoxy(x,y+2);cout<<"## ###  #####   ######  ##        ##    ######   #### ";
    gotoxy(x,y+3);cout<<"##  ##  ##  ##  ##  ##  ##        ##    ##  ##      ##";
    gotoxy(x,y+4);cout<<" ####   ##  ##  ##  ##   #####  ######  ##  ##  ##### ";

    gotoxy(x+16,y+6);   cout<<"#####   ####   ##### ";
    gotoxy(x+16,y+7);   cout<<"##  ## ##  ##  ##  ##";
    gotoxy(x+16,y+8);   cout<<"#####  ##  ##  ##### ";
    gotoxy(x+16,y+9);   cout<<"##     ##  ##  ##  ##";
    gotoxy(x+16,y+10);  cout<<"##      ####   ##  ##";

    gotoxy(x+8,y+12);cout<<"  ####  ##  ##   #####   ####   ##### ";
    gotoxy(x+8,y+13);cout<<"    ##  ##  ##  ##      ##  ##  ##  ##";
    gotoxy(x+8,y+14);cout<<"    ##  ##  ##  ##  ##  ######  ##### ";
    gotoxy(x+8,y+15);cout<<"##  ##  ##  ##  ##  ##  ##  ##  ##  ##";
    gotoxy(x+8,y+16);cout<<" ####    ####    ####   ##  ##  ##  ##";
    SetConsoleTextAttribute(h, 0);
    Sleep(1000);
}

bool AjustarVentana(int Ancho, int Alto) {
    _COORD Coordenada;
    Coordenada.X = Ancho;
    Coordenada.Y = Alto;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Right = Ancho - 1;
    Rect.Bottom = Alto - 1;

    HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleScreenBufferSize(hConsola, Coordenada);

    SetConsoleWindowInfo(hConsola, TRUE, &Rect);
    return TRUE;
}


