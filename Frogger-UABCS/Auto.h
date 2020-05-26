#ifndef AUTO_H
#define AUTO_H

class Auto
{
    public:
        Auto();
        Auto(int,int,int,int);
        void printAuto();
        void borrarAuto();
        int getcolor();
        void setColor(int);
        void setX(int);
        void mover();
        void gotoxy2(int,int);

        int getxAuto();
        int getyAuto();
        void regresar();

        bool checkColision(int, int);

    protected:

    private:
        int xAuto;
        int yAuto;
        int xInic;
        int direccion;
        int modelo;
        int color;
};

#endif // AUTO_H
