#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <mmsystem.h>

#define tecla_Arriba 72
#define tecla_Abajo 80
#define tecla_Izq 75
#define tecla_Der 77
#define tecla_Enter 13

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
int opcionSelect = 1;

void ocultarCursor()
{
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
void jugar();
void instrucciones();
void creditos();
void menu_principal();
bool AjustarVentana(int Ancho, int Alto);


int main (){
	ocultarCursor();
    menu_principal();
    AjustarVentana(120,30);
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

int menu (const char *titulo, const char *opciones[], int n){

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
            PlaySound(TEXT("Change.wav"), NULL, SND_ASYNC);
            opcionSelect--;
            if (opcionSelect < 1){
                opcionSelect = n;
            }
            break;
        case tecla_Abajo:
            PlaySound(TEXT("Change.wav"), NULL, SND_ASYNC);
            opcionSelect++;
            if (opcionSelect > n){
                opcionSelect = 1;
            }
            break;
        case tecla_Enter:
            PlaySound(TEXT("Select.wav"), NULL, SND_ASYNC);
            repeticion = false;
            break;
    }

    }while(repeticion);


    return opcionSelect;
}

void jugar(){
    int tecla;
    int xRana=10, yRana=10;
    bool repeticion=true;
    do{
        system("cls");
        SetConsoleTextAttribute(h, 2);
        gotoxy(xRana, yRana);printf("%c\n",219);
        gotoxy(xRana+1, yRana);printf("%c\n",219);
        gotoxy(xRana, yRana+1);printf("%c\n",93);
        gotoxy(xRana+1, yRana+1);printf("%c\n",91);
        do{
            tecla = getch();
        }while(tecla != tecla_Arriba && tecla != tecla_Abajo && tecla != tecla_Izq && tecla != tecla_Der && tecla != tecla_Enter);

        switch(tecla){
        case tecla_Arriba:
            yRana--;
            PlaySound(TEXT("Salto.wav"), NULL, SND_ASYNC);
            break;
        case tecla_Abajo:
            yRana++;
            PlaySound(TEXT("Salto.wav"), NULL, SND_ASYNC);
            break;
        case tecla_Der:
            xRana+=2;
            PlaySound(TEXT("Salto.wav"), NULL, SND_ASYNC);
            break;
        case tecla_Izq:
            xRana-=2;
            PlaySound(TEXT("Salto.wav"), NULL, SND_ASYNC);
            break;
        case tecla_Enter:
            menu_principal();
            break;
        }
    }while(repeticion);

}

void instrucciones(){
    int tecla;
    system("cls");
    int xgoto = 8;
    int ygoto = 4;

   // setlocale(LC_ALL, "spanish");
    SetConsoleTextAttribute(h, 3);
    gotoxy(xgoto, ygoto);  cout<<"######  ######  ######  ######  ######  ##  ##  ######  ######  ######  ######  ######  ######  ######"<<endl;
    gotoxy(xgoto, ygoto+1);cout<<"  ##    ##  ##  ##        ##    ##  ##  ##  ##  ##      ##        ##    ##  ##  ##  ##  ##      ##    "<<endl;
    gotoxy(xgoto, ygoto+2);cout<<"  ##    ##  ##  ######    ##    ####    ##  ##  ##      ##        ##    ##  ##  ##  ##  ####    ######"<<endl;
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
        PlaySound(TEXT("Select.wav"), NULL, SND_ASYNC);
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
    gotoxy(xGoto-10, yGoto);  cout<<"######  ######  ######  ####    ######  ######  ######  ######"<<endl;
    gotoxy(xGoto-10, yGoto+1);cout<<"##      ##  ##  ##      ##  ##    ##      ##    ##  ##  ##    "<<endl;
    gotoxy(xGoto-10, yGoto+2);cout<<"##      ####    ####    ##  ##    ##      ##    ##  ##  ######"<<endl;
    gotoxy(xGoto-10, yGoto+3);cout<<"##      ##  ##  ##      ##  ##    ##      ##    ##  ##      ##"<<endl;
    gotoxy(xGoto-10, yGoto+4);cout<<"######  ##  ##  ######  ####    ######    ##    ######  ######"<<endl;
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
        PlaySound(TEXT("Select.wav"), NULL, SND_ASYNC);
        menu_principal();
    }
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
                system("cls");
                gotoxy(48, 7);
                cout<<"Gracias por jugar"<<endl<<endl<<endl<<endl<<endl<<endl;
                repetir = false;
                break;
        }
    }while (repetir);
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

    // Obtener el handle de la consola
    HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);

    // Ajustar el buffer al nuevo tamaño
    SetConsoleScreenBufferSize(hConsola, Coordenada);

    // Cambiar tamaño de consola a lo especificado en el buffer
    SetConsoleWindowInfo(hConsola, TRUE, &Rect);
    return TRUE;
}



