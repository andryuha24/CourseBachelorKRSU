#ifndef MDATE_H_INCLUDED
#define MDATE_H_INCLUDED
class MDate
{
private:
    long fullDate;
    long to_LongDate(int y, int m, int d);
    void from_LongDate(int &y,int &m,int &d);
public:
    MDate();                            //����������� ��� ���������
    MDate(int y, int m, int d);  //����������� � �����������
    ~MDate(){};                           //����������

    int getYear();
    int getMonth();
    int getDay();
    void setYear(int);
    void setMonth(int);
    void setDay(int);

    long diffDate( const MDate &, int num);   //�������� �������: 1-� ����, 2-� �������, 3-� �����

    int equals(const MDate &);
    int more(const MDate &);
    int less(const MDate &);

    void showDate(int type);                          //type: 1-�15.12.2006�, 2- �15 December 2006�


};


#endif // MDATE_H_INCLUDED
