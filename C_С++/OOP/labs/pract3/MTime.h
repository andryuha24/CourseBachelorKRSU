#ifndef MTIME_H_INCLUDED
#define MTIME_H_INCLUDED
class MTime
{
private:
    long  fullTime;//��������-������
    void fromLong(int &h, int &m, int &s);
    long toLong(int h, int m,int s);

public:
    MTime();                                     //����������� ��� ���������
    MTime(int h, int m, int s);            //����������� � ����������
    ~MTime(){};                                  //����������

    int getSec();                             //������� �������
    int getMin();
    int getHour();
    void setSec(int);
    void setMin(int);
    void setHour(int);

    MTime diffTime(const MTime&);

    int    equals(const MTime&);                   //�������� ������� �� ���������
    int    more(const MTime&);                     //�������� ������� �� �������
    int    less(const MTime&);                       //�������� ������� �� �������

    void showTime();//int x, int y, int color);   //������: 09:15:45
    MTime& inkr(); //++
};

#endif // MTIME_H_INCLUDED
