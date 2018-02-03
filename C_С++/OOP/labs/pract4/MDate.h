#ifndef MDATE_H_INCLUDED
#define MDATE_H_INCLUDED
class MDate
{
private:
    long fullDate;
    long to_LongDate(int y, int m, int d);
    void from_LongDate(int &y,int &m,int &d);
public:
    MDate();                            // онструктор без парметров
    MDate(int y, int m, int d);  // онструктор с параметрами
    ~MDate(){};                           //ƒеструктор

    int getYear();
    int getMonth();
    int getDay();
    void setYear(int);
    void setMonth(int);
    void setDay(int);

    long diffDate( const MDate &, int num);   //получить разницу: 1-в дн€х, 2-в мес€цах, 3-в годах

    int equals(const MDate &);
    int more(const MDate &);
    int less(const MDate &);

    void showDate(int type);                          //type: 1-У15.12.2006Ф, 2- У15 December 2006Ф


};


#endif // MDATE_H_INCLUDED
