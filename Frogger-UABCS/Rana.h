#ifndef RANA_H
#define RANA_H


class Rana
{
    public:
        Rana();
        Rana(int,int);

        void gotoxy2(int, int);
        void printRana();
        void mover(int);
        void borrarRana();

    protected:

    private:
        int x;
        int y;
};

#endif // RANA_H
