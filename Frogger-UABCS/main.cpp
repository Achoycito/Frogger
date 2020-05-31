#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <mmsystem.h>
#include <sstream>
#include <ctime>

#include "Auto.h"
#include "Rana.h"
#include "Tronco.h"

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
void contornoMapa();
void jugar();
void instrucciones();
void creditos();
void gameOver();
void ganar();
void salir();
void menu_principal();
bool AjustarVentana(int Ancho, int Alto);
void printAuto(int xT, int yT);

            int main (){
    AjustarVentana(120,29);
	ocultarCursor();
    menu_principal();
    return 0;
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
            SetConsoleTextAttribute(h, 'J');
            if(i <= 5 and i>=4  and j >= 6 and j <60 ){
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
            //42, 26
    Auto autosN1[4];
        autosN1[0]= Auto(0, 6, 0, 3);
        autosN1[1]= Auto(0, 12, 1, 1);
        autosN1[2]= Auto(0, 18, 1, 2);
        autosN1[3]= Auto(0, 22, 0, 1);

        srand(time(NULL));
        for(int i=0; i<4; i++){
            autosN1[i].setColor(rand() % 7+2);
            autosN1[i].setX(rand() % 60+11);
        }

    Auto autosN2[17];
        autosN2[0]= Auto(10, 4, 0, 2);
        autosN2[1]= Auto(39, 4, 0, 2);
        autosN2[2]= Auto(40, 6, 1, 3);
        autosN2[3]= Auto(50, 10, 1, 1);
        autosN2[4]= Auto(10, 12, 0, 3);
        autosN2[5]= Auto(30, 12, 0, 3);
        autosN2[6]= Auto(50, 12, 0, 3);
        autosN2[7]= Auto(10, 16, 1, 1);
        autosN2[8]= Auto(39, 16, 1, 1);
        autosN2[9]= Auto(10, 18, 0, 2);
        autosN2[10]= Auto(39, 18, 0, 2);
        autosN2[11]= Auto(10, 20, 1, 1);
        autosN2[12]= Auto(39, 20, 1, 1);
        autosN2[13]= Auto(10, 22, 0, 2);
        autosN2[14]= Auto(39, 22, 0, 2);
        autosN2[15]= Auto(10, 24, 1, 1);
        autosN2[16]= Auto(39, 24, 1, 1);

        srand(time(NULL));
        for(int i=0; i<17; i++){
            autosN2[i].setColor(rand() % 7+2);
        }

    Auto autosN3[12];
        autosN3[0]= Auto(20, 16, 1, 2);
        autosN3[1]= Auto(50, 16, 1, 2);

        autosN3[2]= Auto(40, 18, 0, 1);
        autosN3[3]= Auto(64, 18, 0, 1);
        autosN3[4]= Auto(17, 18, 0, 1);

        autosN3[5]= Auto(18, 20, 1, 3);
        autosN3[6]= Auto(50, 20, 1, 3);

        autosN3[7]= Auto(12, 22, 0, 1);
        autosN3[8]= Auto(54, 22, 0, 1);
        autosN3[9]= Auto(30, 22, 0, 1);

        autosN3[10]= Auto(58, 24, 1, 2);
        autosN3[11]= Auto(27, 24, 1, 2);

        srand(time(NULL));
        for(int i=0; i<12; i++){
            autosN3[i].setColor(rand() % 7+2);
        }

     Auto autosN4[13];
        autosN4[0]= Auto(17, 16, 0, 2);
        autosN4[1]= Auto(60, 16, 0, 2);
        autosN4[2]= Auto(38, 16, 0, 2);

        autosN4[3]= Auto(65, 18, 1, 1);
        autosN4[4]= Auto(35, 18, 1, 1);

        autosN4[5]= Auto(38, 20, 0, 3);
        autosN4[6]= Auto(63, 20, 0, 3);
        autosN4[7]= Auto(13, 20, 0, 3);

        autosN4[8]= Auto(46, 22, 1, 1);
        autosN4[9]= Auto(17, 22, 1, 1);

        autosN4[10]= Auto(59, 24, 0, 2);
        autosN4[11]= Auto(14, 24, 0, 2);
        autosN4[12]= Auto(35, 24, 0, 2);

        srand(time(NULL));
        for(int i=0; i<13; i++){
            autosN4[i].setColor(rand() % 7+2);
        }

    Tronco tronquito = Tronco(58, 4, 0, 3);

    Tronco troncosN3[8];
        troncosN3[0] = Tronco(56,4,1,3);
        troncosN3[1] = Tronco(20,4,1,3);

        troncosN3[2] = Tronco(56,6,0,3);
        troncosN3[3] = Tronco(20,6,0,3);

        troncosN3[4] = Tronco(56,10,1,3);
        troncosN3[5] = Tronco(20,10,1,3);

        troncosN3[6] = Tronco(56,12,0,3);
        troncosN3[7] = Tronco(20,12,0,3);

    Rana ranita = Rana(42, 26);
    int tecla;
    int tiempoNivel=150;
    int extensionTiempo=30;
    int tiempoInic = time(NULL)+tiempoNivel;
    int tiempoActual;
    int tiempoRest;
    int vidas=5;
    bool tocandoTronco=false;
    int velTronco, direcTronco;
    int puntuacion=0;
    int xRanita=91;
    int nivel = 3;
    int contador = 0;
    bool estanque1 = true;
    bool estanque2 = true;
    bool estanque3 = true;
    bool estanque4 = true;
    bool estanque5 = true;



    bool repeticion=true;
    system("cls");
    do{
        if (nivel == 1){
            imprimirMapa();
            for(int x=0; x<4; x++){
                autosN1[x].borrarAuto();
                if(autosN1[x].checkColision(ranita.getXRana(), ranita.getYRana())){
                    ranita.borrarRana();
                    SetConsoleTextAttribute(h, 2);
                    for(int i=0; i<vidas; i++){
                        if(i==vidas-1){
                            SetConsoleTextAttribute(h, 4);
                        }
                        ranita.printRanaJR(xRanita,20);
                        xRanita+=3;
                    }
                    xRanita=91;
                    vidas--;
                    PlaySound(TEXT("sfx/Vida menos.wav"), NULL, SND_ASYNC);
                    Sleep(1500);
                    if(vidas>=0){
                        ranita.respawnRana();
                    }
                }
                autosN1[x].mover();
                if(autosN1[x].getxAuto()>=10 && autosN1[x].getxAuto()<=70){
                    SetConsoleTextAttribute(h, autosN1[x].getcolor());
                    autosN1[x].printAuto();
                }
            }
        }
        if (nivel == 2){
            imprimirMapa2();
            for(int x=0; x<17; x++){
                autosN2[x].borrarAuto();
                if(autosN2[x].checkColision(ranita.getXRana(), ranita.getYRana())){
                    ranita.borrarRana();
                    SetConsoleTextAttribute(h, 2);
                    for(int i=0; i<vidas; i++){
                        if(i==vidas-1){
                            SetConsoleTextAttribute(h, 4);
                        }
                        ranita.printRanaJR(xRanita,20);
                        xRanita+=3;
                    }
                    xRanita=91;
                    vidas--;
                    PlaySound(TEXT("sfx/Vida menos.wav"), NULL, SND_ASYNC);
                    Sleep(1500);
                    if(vidas>=0){
                        ranita.respawnRana();
                    }
                }
                autosN2[x].mover();
                if(autosN2[x].getxAuto()>=10 && autosN2[x].getxAuto()<=70){
                    SetConsoleTextAttribute(h, autosN2[x].getcolor());
                    autosN2[x].printAuto();
                }
            }

        }
        if (nivel == 3){
            imprimirMapa3();
            for (int i = 0; i < 8; i++){
                troncosN3[i].mover();
                if(troncosN3[i].getxTronco()>=10 && troncosN3[i].getxTronco()<=58){
                    SetConsoleTextAttribute(h, 3);
                    troncosN3[i].borrarTronco();
                    SetConsoleTextAttribute(h, 6);
                    troncosN3[i].printTronco();
                }
                if(troncosN3[i].checkColision(ranita.getXRana(), ranita.getYRana())){
                    tocandoTronco=true;
                    velTronco=troncosN3[i].getVelocidad();
                    direcTronco=troncosN3[i].getDireccion();
                }
            }

            if(tocandoTronco==true){
                ranita.recorrer(velTronco, direcTronco);
            }
            else{
                if(ranita.getYRana()<=12 && ranita.getYRana()>=4){
                    if(ranita.getYRana()!=8){
                        ranita.borrarRana();
                        SetConsoleTextAttribute(h, 2);
                        for(int i=0; i<vidas; i++){
                            if(i==vidas-1){
                                SetConsoleTextAttribute(h, 4);
                            }
                            ranita.printRanaJR(xRanita,20);
                            xRanita+=3;
                        }
                        xRanita=91;
                        vidas--;
                        PlaySound(TEXT("sfx/Vida menos.wav"), NULL, SND_ASYNC);
                        Sleep(1500);
                        if(vidas>=0){
                            ranita.respawnRana();
                        }
                    }
                    else{
                        if(ranita.getXRana()==12 || ranita.getXRana()==72){
                            ranita.borrarRana();
                            SetConsoleTextAttribute(h, 2);
                            for(int i=0; i<vidas; i++){
                                if(i==vidas-1){
                                    SetConsoleTextAttribute(h, 4);
                                }
                                ranita.printRanaJR(xRanita,20);
                                xRanita+=3;
                            }
                            xRanita=91;
                            vidas--;
                            PlaySound(TEXT("sfx/Vida menos.wav"), NULL, SND_ASYNC);
                            Sleep(1500);
                            if(vidas>=0){
                                ranita.respawnRana();
                            }
                        }
                    }
                }
            }
            tocandoTronco=false;

/*
                for(int x=0; x<12; x++){
                autosN3[x].borrarAuto();
                if(autosN3[x].checkColision(ranita.getXRana(), ranita.getYRana())){
                    ranita.borrarRana();
                    SetConsoleTextAttribute(h, 2);
                    for(int i=0; i<vidas; i++){
                        if(i==vidas-1){
                            SetConsoleTextAttribute(h, 4);
                        }
                        ranita.printRanaJR(xRanita,20);
                        xRanita+=3;
                    }
                    xRanita=91;
                    vidas--;
                    PlaySound(TEXT("sfx/Vida menos.wav"), NULL, SND_ASYNC);
                    Sleep(1500);
                    if(vidas>=0){
                        ranita.respawnRana();
                    }
                }
                autosN3[x].mover();
                if(autosN3[x].getxAuto()>=10 && autosN3[x].getxAuto()<=70){
                    SetConsoleTextAttribute(h, autosN3[x].getcolor());
                    autosN3[x].printAuto();
                }
            }*/
        }
        if (nivel == 4){
            imprimirMapa4();
            for(int x=0; x<13; x++){
                autosN4[x].borrarAuto();
                if(autosN4[x].checkColision(ranita.getXRana(), ranita.getYRana())){
                    ranita.borrarRana();
                    SetConsoleTextAttribute(h, 2);
                    for(int i=0; i<vidas; i++){
                        if(i==vidas-1){
                            SetConsoleTextAttribute(h, 4);
                        }
                        ranita.printRanaJR(xRanita,20);
                        xRanita+=3;
                    }
                    xRanita=91;
                    vidas--;
                    PlaySound(TEXT("sfx/Vida menos.wav"), NULL, SND_ASYNC);
                    Sleep(1500);
                    if(vidas>=0){
                        ranita.respawnRana();
                    }
                }
                autosN4[x].mover();
                if(autosN4[x].getxAuto()>=10 && autosN4[x].getxAuto()<=70){
                    SetConsoleTextAttribute(h, autosN4[x].getcolor());
                    autosN4[x].printAuto();
                }
            }
        }

        if (nivel == 5){
            if(vidas != 0 ){
             puntuacion= puntuacion+(vidas*200) ;
             vidas = 0;
            }
            system("cls");
            gotoxy(50,10);cout<<"SCORE: "<<puntuacion<<endl;

             gotoxy(46,24);
            SetConsoleTextAttribute(h, 3);
            cout<<"-->";
            SetConsoleTextAttribute(h, 15);
            gotoxy(50, 24);
            printf("Presione Enter para continuar ", 163);

            do{
                tecla = getch();
            }while(tecla != tecla_Enter);

            if(tecla == tecla_Enter){
                PlaySound(TEXT("sfx/Select.wav"), NULL, SND_ASYNC);
                ganar();
            }
        }
        if(ranita.getXRana() >= 16 && ranita.getXRana() <22 && ranita.getYRana() == 2){
            if(estanque1 == true){
                PlaySound(TEXT("sfx/Meta.wav"), NULL, SND_ASYNC);
                if(contador < 4){

                    tiempoInic+=extensionTiempo;
                    gotoxy(109, 13);
                    SetConsoleTextAttribute(h, 2);
                    cout<<"+"<<extensionTiempo;
                }

                Sleep(2000);
                estanque1 = false;
                contador += 1;
                ranita.respawnRana();
                puntuacion = puntuacion + 50;
            }
        }
        if(estanque1 == false){
            SetConsoleTextAttribute(h, 2);
            ranita.printRanaJR(18,2);
        }

        if(ranita.getXRana() >= 28 && ranita.getXRana() <34 && ranita.getYRana() == 2){
            if(estanque2 == true){
                PlaySound(TEXT("sfx/Meta.wav"), NULL, SND_ASYNC);
                if(contador < 4){

                    tiempoInic+=extensionTiempo;
                    gotoxy(109, 13);
                    SetConsoleTextAttribute(h, 2);
                    cout<<"+"<<extensionTiempo;

                }
                Sleep(2000);
                estanque2 = false;
                contador += 1;
                ranita.respawnRana();
                puntuacion = puntuacion + 50;
            }
        }
        if(estanque2 == false){
            SetConsoleTextAttribute(h, 2);
            ranita.printRanaJR(30,2);
        }

        if(ranita.getXRana() >= 40 && ranita.getXRana() <46 && ranita.getYRana() == 2){
            if(estanque3 == true){
                PlaySound(TEXT("sfx/Meta.wav"), NULL, SND_ASYNC);
                if(contador < 4){

                    tiempoInic+=extensionTiempo;
                    gotoxy(109, 13);
                    SetConsoleTextAttribute(h, 2);
                    cout<<"+"<<extensionTiempo;

                }
                Sleep(2000);
                estanque3 = false;
                contador += 1;
                ranita.respawnRana();
                puntuacion = puntuacion + 50;
            }
        }
        if(estanque3 == false){
            SetConsoleTextAttribute(h, 2);
            ranita.printRanaJR(42,2);
        }

        if(ranita.getXRana() >= 52 && ranita.getXRana() <58 && ranita.getYRana() == 2){
            if(estanque4 == true){
                PlaySound(TEXT("sfx/Meta.wav"), NULL, SND_ASYNC);
                if(contador < 4){

                    tiempoInic+=extensionTiempo;
                    gotoxy(109, 13);
                    SetConsoleTextAttribute(h, 2);
                    cout<<"+"<<extensionTiempo;

                }
                Sleep(2000);
                estanque4 = false;
                contador += 1;
                ranita.respawnRana();
                puntuacion = puntuacion + 50;
            }
        }
        if(estanque4 == false){
            SetConsoleTextAttribute(h, 2);
            ranita.printRanaJR(54,2);
        }
        if(ranita.getXRana() >= 64 && ranita.getXRana() <70 && ranita.getYRana() == 2){
            if(estanque5 == true){
                PlaySound(TEXT("sfx/Meta.wav"), NULL, SND_ASYNC);
                if(contador < 4){

                    tiempoInic+=extensionTiempo;
                    gotoxy(109, 13);
                    SetConsoleTextAttribute(h, 2);
                    cout<<"+"<<extensionTiempo;

                }
                Sleep(2000);
                estanque5 = false;
                contador += 1;
                ranita.respawnRana();
                puntuacion = puntuacion + 50;
            }
        }
        if(estanque5 == false){
            SetConsoleTextAttribute(h, 2);
            ranita.printRanaJR(66,2);
        }

        if (contador == 5){
            PlaySound(TEXT("sfx/Nivel completo.wav"), NULL, SND_ASYNC);
            Sleep(3000);
            tiempoInic = time(NULL)+tiempoNivel;
            ranita.respawnRana();
            nivel+=1;
            system("cls");
            estanque1 = true;
            estanque2 = true;
            estanque3 = true;
            estanque4 = true;
            estanque5 = true;
            contador = 0;
            puntuacion += (tiempoRest*3);
        }
        if(tiempoActual==tiempoInic || vidas<0){
            PlaySound(TEXT("sfx/Game Over.wav"), NULL, SND_ASYNC);
            Sleep(2000);
            gameOver();
        }

        SetConsoleTextAttribute(h, 2);
        ranita.printRana();
        if(kbhit()){
            tecla = getch();
            ranita.mover(tecla);
            if(tecla==32){
                PlaySound(TEXT("sfx/Nivel completo.wav"), NULL, SND_ASYNC);
                Sleep(3000);
                tiempoInic = time(NULL)+tiempoNivel;
                ranita.respawnRana();
                nivel+=1;
                system("cls");
                estanque1 = true;
                estanque2 = true;
                estanque3 = true;
                estanque4 = true;
                estanque5 = true;
                contador = 0;
            }
            if(tecla== 105){
                if(vidas != 0 ){
                 puntuacion= puntuacion+(vidas*200) ;
                 vidas = 0;
                }
                system("cls");
                gotoxy(50,10);cout<<"SCORE: "<<puntuacion<<endl;

                 gotoxy(46,24);
                SetConsoleTextAttribute(h, 3);
                cout<<"-->";
                SetConsoleTextAttribute(h, 15);
                gotoxy(50, 24);
                printf("Presione Enter para continuar ", 163);

                do{
                    tecla = getch();
                }while(tecla != tecla_Enter);

                if(tecla == tecla_Enter){
                    PlaySound(TEXT("sfx/Select.wav"), NULL, SND_ASYNC);
                    ganar();
                }
            }
        }

        SetConsoleTextAttribute(h, 15);
        tiempoActual = time(NULL);
        gotoxy(88, 13);
        tiempoRest = tiempoInic-tiempoActual;
        cout<<"Tiempo restante: "<<tiempoInic-tiempoActual<<"     ";
        gotoxy(88,10);cout<<"Puntuacion: "<<puntuacion<<endl;

        SetConsoleTextAttribute(h, 2);
        for(int i=0; i<vidas; i++){
            ranita.printRanaJR(xRanita,20);
            xRanita+=3;
        }
        gotoxy(xRanita,20);
        cout<<"  ";
        gotoxy(xRanita,21);
        cout<<"  ";
        xRanita=91;


        Sleep(1);

    }while(repeticion);

}

void instrucciones(){
    int tecla;
    system("cls");
    int xgoto = 8;
    int ygoto = 4;

    SetConsoleTextAttribute(h, 3);
    gotoxy(xgoto, ygoto);  cout<<"######  ##  ##   #####  ######  #####   ##  ##   #####   #####  ######   ####   ##  ##    #####   #####"<<endl;
    gotoxy(xgoto, ygoto+1);cout<<"  ##    ### ##  ##        ##    ##  ##  ##  ##  ##      ##        ##    ##  ##  ### ##  ##      ##    "<<endl;
    gotoxy(xgoto, ygoto+2);cout<<"  ##    ######   ####     ##    #####   ##  ##  ##      ##        ##    ##  ##  ######  ####     #### "<<endl;
    gotoxy(xgoto, ygoto+3);cout<<"  ##    ## ###      ##    ##    ##  ##  ##  ##  ##      ##        ##    ##  ##  ## ###  ##          ##"<<endl;
    gotoxy(xgoto, ygoto+4);cout<<"######  ##  ##  #####     ##    ##  ##   ####    #####   #####  ######   ####   ##  ##   #####  ##### "<<endl;
    SetConsoleTextAttribute(h, 15);
    gotoxy(xgoto+28, ygoto+7);
    cout<<"Controles:";
    gotoxy(xgoto+30, ygoto+8);
    cout<<"-Flecha arriba: moverse hacia adelante";
    gotoxy(xgoto+30, ygoto+9);
    printf("-Flecha abajo: moverse hacia atr%cs", 160);
    gotoxy(xgoto+30, ygoto+10);
    cout<<"-Flecha izquierda: salto a la izquierda (6 espacios)";
    gotoxy(xgoto+30, ygoto+11);
    cout<<"-Flecha derecha: salto a la derecha (6 espacios)";
    gotoxy(xgoto+30, ygoto+12);
    cout<<"-A: moverse a la izquierda (un espacio)";
    gotoxy(xgoto+30, ygoto+13);
    cout<<"-D: moverse a la derecha (un espacio)";

    gotoxy(xgoto+28, ygoto+15);
    cout<<"Consigue puntos:";
    gotoxy(xgoto+30, ygoto+16);
    cout<<"-Completando el nivel en poco tiempo";
    gotoxy(xgoto+30, ygoto+17);
    cout<<"-Recogiendo objetos especiales";
    gotoxy(xgoto+30, ygoto+18);
    cout<<"-Ganando con varias vidas restantes";

    gotoxy(25,25);
    SetConsoleTextAttribute(h, 3);
    cout<<"-->";
    SetConsoleTextAttribute(h, 15);
    gotoxy(29, 25);
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
    gotoxy(xGoto-10, yGoto);  cout<<" #####  #####    #####  #####   ######  ######   ####    #####"<<endl;
    gotoxy(xGoto-10, yGoto+1);cout<<"##      ##  ##  ##      ##  ##    ##      ##    ##  ##  ##    "<<endl;
    gotoxy(xGoto-10, yGoto+2);cout<<"##      #####   ####    ##  ##    ##      ##    ##  ##   #### "<<endl;
    gotoxy(xGoto-10, yGoto+3);cout<<"##      ##  ##  ##      ##  ##    ##      ##    ##  ##      ##"<<endl;
    gotoxy(xGoto-10, yGoto+4);cout<<" #####  ##  ##   #####  #####   ######    ##     ####   ##### "<<endl;
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

void gameOver(){
    int tecla;
    system("cls");
    int x=41, y=3;
    SetConsoleTextAttribute(h, 4);
    gotoxy(x+8,y);  cout<<"######  ######  ##  ##";Sleep(150);
    gotoxy(x+8,y+1);cout<<"##        ##    ### ##";Sleep(150);
    gotoxy(x+8,y+2);cout<<"#####     ##    ######";Sleep(150);
    gotoxy(x+8,y+3);cout<<"##        ##    ## ###";Sleep(150);
    gotoxy(x+8,y+4);cout<<"##      ######  ##  ##";Sleep(150);

    gotoxy(x+8,y+6);   cout<<"#####    #####  ##";Sleep(150);
    gotoxy(x+8,y+7);   cout<<"##  ##  ##      ##";Sleep(150);
    gotoxy(x+8,y+8);   cout<<"##  ##  ######  ##";Sleep(150);
    gotoxy(x+8,y+9);   cout<<"##  ##  ##      ##";Sleep(150);
    gotoxy(x+8,y+10);  cout<<"#####    #####  ######";Sleep(150);

    gotoxy(x,y+12);cout<<"  ####  ##  ##   #####   #####   ####";Sleep(150);
    gotoxy(x,y+13);cout<<"    ##  ##  ##  ##      ##      ##  ##";Sleep(150);
    gotoxy(x,y+14);cout<<"    ##  ##  ##  ######  ##  ##  ##  ##";Sleep(150);
    gotoxy(x,y+15);cout<<"##  ##  ##  ##  ##      ##  ##  ##  ##";Sleep(150);
    gotoxy(x,y+16);cout<<" ####    ####    #####   ####    ####";Sleep(400);

    gotoxy(32,24);
    SetConsoleTextAttribute(h, 3);
    cout<<"-->";
    SetConsoleTextAttribute(h, 15);
    gotoxy(36, 24);
    printf("Presione Enter para volver al men%c principal", 163);

    do{
        tecla = getch();
    }while(tecla != tecla_Enter);

    if(tecla == tecla_Enter){
        PlaySound(TEXT("sfx/Select.wav"), NULL, SND_ASYNC);
        menu_principal();
    }
}

void ganar(){
    int tecla;
    system("cls");
    SetConsoleTextAttribute(h, 9);
    int x=12, y=2;
    //PlaySound(TEXT("sfx/Ganar.wav"), NULL, SND_ASYNC);
    gotoxy(x+5, y);  cout<<"######   #####  ##      ######   #####  ######  #####    ####   #####    #####   #####"<<endl;Sleep(150);
    gotoxy(x+5, y+1);cout<<"##      ##      ##        ##    ##        ##    ##  ##  ##  ##  ##  ##  ##      ##    "<<endl;Sleep(150);
    gotoxy(x+5, y+2);cout<<"######  ######  ##        ##    ##        ##    ##  ##  ######  ##  ##  ######   #### "<<endl;Sleep(150);
    gotoxy(x+5, y+3);cout<<"##      ##      ##        ##    ##        ##    ##  ##  ##  ##  ##  ##  ##          ##"<<endl;Sleep(150);
    gotoxy(x+5, y+4);cout<<"##       #####  ######  ######   #####  ######  #####   ##  ##  #####    #####  ##### "<<endl;Sleep(150);

    gotoxy(x, y+7);     cout<<" ##########    ##########   ####    ####   ##########    ##########   ############   ########## "<<endl;Sleep(150);
    gotoxy(x, y+8);     cout<<"############  ############  #####   ####  ############  ############  ############  ############"<<endl;Sleep(150);
    gotoxy(x, y+9);     cout<<"####          ####    ####  ######  ####  ####    ####  ####              ####      ####        "<<endl;Sleep(150);
    gotoxy(x, y+10);    cout<<"####          ####    ####  ####### ####  ####    ####  ####              ####      ####        "<<endl;Sleep(150);
    gotoxy(x, y+11);    cout<<"####  ####    ############  ############  ############  ###########       ####      ########### "<<endl;Sleep(150);
    gotoxy(x, y+12);    cout<<"####  ######  ############  ############  ############   ###########      ####      ########### "<<endl;Sleep(150);
    gotoxy(x, y+13);    cout<<"####    ####  ####    ####  #### #######  ####    ####          ####      ####      ####        "<<endl;Sleep(150);
    gotoxy(x, y+14);    cout<<"####    ####  ####    ####  ####  ######  ####    ####          ####      ####      ####        "<<endl;Sleep(150);
    gotoxy(x, y+15);    cout<<"############  ####    ####  ####   #####  ####    ####  ############      ####      ############"<<endl;Sleep(150);
    gotoxy(x, y+16);    cout<<" ##########   ####    ####  ####    ####  ####    ####   ##########       ####       ########## "<<endl;Sleep(150);

    gotoxy(32,24);
    SetConsoleTextAttribute(h, 3);
    cout<<"-->";
    SetConsoleTextAttribute(h, 15);
    gotoxy(36, 24);
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

void contornoMapa(){
    for(int i=9; i<77;i++){
        gotoxy(i,0);
        printf("%c\n",205);//205 para normal, 203 para cuadro
    }
    for(int i=1; i<28;i++){
        gotoxy(8,i);
        printf("%c\n",186); //186 para normal, 204 para cuadro
        gotoxy(77,i);
        printf("%c\n",186); //186 para normal, 185 para cuadro
    }
    for(int i=9; i<77;i++){
        gotoxy(i,28);
        printf("%c\n",205);//205 para normal, 202 para cuadro
    }

    gotoxy(8,28); printf("%c\n",200); //Esquina inf. izq.
    gotoxy(77,28); printf("%c\n",188); //Esquina inf. izq.
    gotoxy(8,0); printf("%c\n",201); //Esquina sup. izq.
    gotoxy(77,0); printf("%c\n",187); //Esquina sup. der.
}
