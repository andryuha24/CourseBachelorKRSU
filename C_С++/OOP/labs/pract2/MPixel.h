#ifndef MPIXEL_H_INCLUDED
#define MPIXEL_H_INCLUDED
class MPixel
{
    private:
        int x,y,c;
    public:
        MPixel();
        MPixel(int x, int y, int c);
        ~MPixel(){};

    int getX(){return x;}
    int getY(){return y;}
    int getC(){return c;}
    void setX(int x){this->x = x;}
    void setY(int y){this->y = y;}
    void setC(int color){c = color;}

    void moveTo(int x, int y);
    void move(int,int);

    int equals(const MPixel&)const;

    void show();
    void hide();
};



#endif // MPIXEL_H_INCLUDED
