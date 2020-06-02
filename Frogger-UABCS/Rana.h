#ifndef RANA_H
#define RANA_H

class Rana
{
    public:
        Rana();
        Rana(int,int);

        void gotoxy2(int, int);
        void printRana();
        void printRanaJR(int,int);
        void mover(int,bool,bool,bool,bool,bool);
        void borrarRana();
        void respawnRana();
        void recorrer(int,int);

        int getXRana();
        int getYRana();

    protected:

    private:
        int x;
        int y;
};

#endif // RANA_H
