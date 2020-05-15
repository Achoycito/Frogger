#ifndef AUTO_H
#define AUTO_H

class Auto
{
    public:
        Auto();
        Auto(int,int,int);
        void imprimirAuto();
        void mover();

        int getxAuto();
        int getyAuto();

    protected:

    private:
        int xAuto;
        int yAuto;

        int direccion;
};

#endif // AUTO_H
