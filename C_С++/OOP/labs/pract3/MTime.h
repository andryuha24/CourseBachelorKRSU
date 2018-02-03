#ifndef MTIME_H_INCLUDED
#define MTIME_H_INCLUDED
class MTime
{
private:
    long  fullTime;//элементы-данные
    void fromLong(int &h, int &m, int &s);
    long toLong(int h, int m,int s);

public:
    MTime();                                     //Конструктор без парметров
    MTime(int h, int m, int s);            //Конструктор с парметрами
    ~MTime(){};                                  //Деструктор

    int getSec();                             //Функции доступа
    int getMin();
    int getHour();
    void setSec(int);
    void setMin(int);
    void setHour(int);

    MTime diffTime(const MTime&);

    int    equals(const MTime&);                   //сравнить объекты на равенство
    int    more(const MTime&);                     //сравнить объекты на «больше»
    int    less(const MTime&);                       //сравнить объекты на «меньше»

    void showTime();//int x, int y, int color);   //пример: 09:15:45
    MTime& inkr(); //++
};

#endif // MTIME_H_INCLUDED
