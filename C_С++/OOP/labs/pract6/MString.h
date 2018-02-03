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
    String();                 // онструктор по умолчанию
    String(const char *str);   // онструктор с параметрами,  str - строка
    String(int n);          // онструктор с параметрами, n-длина строки
    String(const String &str); // онструктор копировани€
    ~String();                //ƒеструктор

//методы доступа
    const char * getStr() const;
    int getLength() const;
//операторы
    String operator+(const String &) const;
    String & operator=(const String &);
    String & operator+=(const String &);
    char& operator[](int);//операци€ индексации
    int operator==(const String &) const;
    int operator!=(const String &) const;
    int operator>(const String &) const;
    int operator>=(const String &) const;
    int operator<=(const String &) const;
    friend istream& operator>>(istream&, String &);
    friend ostream& operator << (ostream&, const String &);
};



#endif // MSTRING_H_INCLUDED
