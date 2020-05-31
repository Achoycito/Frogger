#ifndef TRONCO_H
#define TRONCO_H


class Tronco
{
    public:
        Tronco();
        Tronco(int, int, int, int);
        void printTronco();
        void borrarTronco();
        void mover();
        bool checkColision(int,int);

        int getxTronco();
        int getyTronco();
        int getVelocidad();
        int getDireccion();

        int setxTronco();
        int setyTronco();



        void regresar();
        void gotoxy2(int,int);

    protected:

    private:

        int xTronco;
        int yTronco;
        int xInic;
        int direccion;
        int velocidad;


};

#endif // TRONCO_H
