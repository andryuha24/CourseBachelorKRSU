#ifndef MSTRING_H_INCLUDED
#define MSTRING_H_INCLUDED
#include <iostream>
using namespace std;

class String
{
private:
    int len;
    char *p;   //pointer to char
public:
    String();                 //����������� �� ���������
    String(const char *str);   //����������� � �����������,  str - ������
    String(int n);          //����������� � �����������, n-����� ������
    String(const String &str); //����������� �����������
    ~String();                //����������

//������ �������
    const char * getStr() const;
    int getLength() const;
//���������
    String operator+(const String &) const;
    String & operator=(const String &);
    String & operator+=(const String &);
    char& operator[](int);//�������� ����������
    int operator==(const String &) const;
    int operator!=(const String &) const;
    int operator>(const String &) const;
    int operator>=(const String &) const;
    int operator<=(const String &) const;
    friend istream& operator>>(istream&, String &);
    friend ostream& operator << (ostream&, const String &);
};



#endif // MSTRING_H_INCLUDED
