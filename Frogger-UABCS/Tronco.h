#ifndef TRONCO_H
#define TRONCO_H


class Tronco
{
    public:
        Tronco();
        Tronco(int, int, int, int);
        void printTonco();
        void borrarTronco();
        int getxTronco();
        int setxTronco();
        int getyTronco();
        int setxTronco();
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
