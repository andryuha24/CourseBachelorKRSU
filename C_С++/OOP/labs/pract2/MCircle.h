#ifndef MCIRCLE_H_INCLUDED
#define MCIRCLE_H_INCLUDED
class MCircle
{
    private:
        int x,y,r,c,n;
    public:
        MCircle();
        MCircle(int x, int y, int r, int c);
        ~MCircle(){};

    int getX(){return x;}
    int getY(){return y;}
    int getR(){return r;}
    int getC(){return c;}
    double getSquare();
    double getPer();
    void setX(int x){this->x = x;}
    void setY(int y){this->y = y;}
    void setR(int newR){r = newR;}
    void setC(int color){c = color;}
    void setN(int n){this->n=n;}

    void moveTo(int x, int y, int n);
    void move(int,int,int);

    int equals(const MCircle&)const;

    void show(int n);
    void hide(int n);

};
#endif // MCIRCLE_H_INCLUDED
