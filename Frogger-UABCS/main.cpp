#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>

#define tecla_Arriba 72
#define tecla_Abajo 80
#define tecla_Enter 13

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

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


int main (){
    menu_principal();
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
    int opcionSelect = 1;
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
            opcionSelect--;
            if (opcionSelect < 1){
                opcionSelect = n;
            }
            break;
        case tecla_Abajo:
            opcionSelect++;
            if (opcionSelect > n){
                opcionSelect = 1;
            }
            break;
        case tecla_Enter:
            repeticion = false;
            break;
    }

    }while(repeticion);


    return opcionSelect;
}

void jugar(){
    int tecla;
    system("cls");

    cout<<"Error 404 - Not Found"<<endl;
    cout<<"Work In Progress"<<endl;

    gotoxy(25,7);
    SetConsoleTextAttribute(h, 3);
    cout<<"-->";
    SetConsoleTextAttribute(h, 15);
    gotoxy(29, 7);
    cout<<"Presione Enter para volver al menu principal";

    do{
        tecla = getch();
    }while(tecla != tecla_Enter);

    if(tecla == tecla_Enter){
        menu_principal();
    }

}

void instrucciones(){
    int tecla;
    system("cls");
    int xgoto = 30;
    int ygoto = 4;

    setlocale(LC_ALL, "spanish");
    gotoxy(45, 4);
    SetConsoleTextAttribute(h, 3);
    cout<<"{------INSTRUCCIONES------}"<<endl;
    SetConsoleTextAttribute(h, 15);
    gotoxy(xgoto, ygoto+2);
    cout<<"Controles:";
    gotoxy(xgoto+2, ygoto+3);
    cout<<"-Flecha arriba: moverse hacia adelante";
    gotoxy(xgoto+2, ygoto+4);
    cout<<"-Flecha abajo: moverse hacia atras";
    gotoxy(xgoto+2, ygoto+5);
    cout<<"-Flecha izquierda: moverse a la izquierda";
    gotoxy(xgoto+2, ygoto+6);
    cout<<"-Flecha derecha: moverse a la derecha";

    gotoxy(xgoto, ygoto+8);
    cout<<"Consigue puntos:";
    gotoxy(xgoto+2, ygoto+9);
    cout<<"-Completando el nivel en poco tiempo";
    gotoxy(xgoto+2, ygoto+10);
    cout<<"-Recogiendo objetos especiales";
    gotoxy(xgoto+2, ygoto+11);
    cout<<"-Ganando con varias vidas restantes";

    gotoxy(25,20);
    SetConsoleTextAttribute(h, 3);
    cout<<"-->";
    SetConsoleTextAttribute(h, 15);
    gotoxy(29, 20);
    cout<<"Presione Enter para volver al menu principal";

    do{
        tecla = getch();
    }while(tecla != tecla_Enter);

    if(tecla == tecla_Enter){
        menu_principal();
    }
}

void creditos(){
    int tecla;
    int xGoto=39;
    int yGoto=4;
    system("cls");
    setlocale(LC_ALL, "spanish");
    gotoxy(xGoto+7, yGoto);
    SetConsoleTextAttribute(h, 3);
    cout<<"{------CRÉDITOS------}"<<endl;
    SetConsoleTextAttribute(h, 15);
    gotoxy(xGoto, yGoto+2);
    cout<<"Desarrollado por:"<<endl;
    gotoxy(xGoto+4, yGoto+3);
    cout<<"*Francisco Díaz de la Peña";
    gotoxy(xGoto+4, yGoto+4);
    cout<<"*Alan González de la Llave Achoy";
    gotoxy(xGoto+4, yGoto+5);
    cout<<"*Moises Moreno Quirarte";

    gotoxy(xGoto, yGoto+7);
    cout<<"Estudiantes de la carrera de";
    gotoxy(xGoto, yGoto+8);
    cout<<"Ingeniería en Desarrollo de Software en la ";
    gotoxy(xGoto, yGoto+9);
    cout<<"Universidad Autonoma de Baja California Sur";


    gotoxy(25,20);
    SetConsoleTextAttribute(h, 3);
    cout<<"-->";
    SetConsoleTextAttribute(h, 15);
    gotoxy(29, 20);
    cout<<"Presione Enter para volver al menu principal";

    do{
        tecla = getch();
    }while(tecla != tecla_Enter);

    if(tecla == tecla_Enter){
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






