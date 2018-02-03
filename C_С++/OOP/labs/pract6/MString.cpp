#include <iostream>
#include <string.h>
#include "MString.h"
using namespace std;

String::String()
{
  p=NULL;//проверяется
  len=0;
}
String::String(int n)
{
  len=n;
  p = new char[len+1];
  p[0]='\0';//чтобы не было дампа памяти при распечатки
}
String::String(const char *s)
{
  len = strlen(s);
  p = new char[len+1];
  strcpy(p,s);
}
String :: String(const String &str)
{
  len=str.len;
  p=new char[len+1];
  strcpy(p,str.p);
}

String::~String()
{
  delete[]p;
}

const char *String::getStr()const
{
  return p;
}

int String:: getLength()const
{
  return len;
}

String String::operator+(const String &V)const
{
  String tmp(len+V.len+1);
  strcpy(tmp.p,p);
  strcat(tmp.p,V.p);
  return tmp;
}

String& String::operator=(const String &V)
{
  if(this!=&V) {
    delete []p;
    len = V.len;
    p=new char[len+1];
    strcpy(p,V.p);
  }
  return *this;
}

String& String::operator+=(const String &V)
{
  len+=V.len;
  char *tmp = new char[len+1];
  strcpy(tmp,p);
  strcat(p,V.p);
  delete []p;
  p=tmp;
  return *this;
}

char& String:: operator[](int num)
{
  return p[num];
}


int String::operator==(const String &v) const
{
  return (strcmp(p,v.p) == 0);
}

int String::operator!=(const String &v) const
{
  return (strcmp(p,v.p) != 0);
}

int String::operator>(const String &v)  const
{
  return (strcmp(p, v.p) > 0);
}

int String::operator>=(const String &v) const
{
  return (strcmp(p, v.p) >= 0);
}

int String::operator<=(const String &v) const
{
  return (strcmp(p, v.p) <= 0);
}

ostream& operator<<(ostream& to, const String &V)//передача по ссылки
{
  to<<V.p;
  return to;
}

istream& operator>>(istream& in,  String &V)//передача по ссылки
{
  char *tmp=new char[1000];
  in >> tmp;
  V.len=strlen(tmp);
  delete []V.p;
  V.p= new char[V.len+1];
  strcpy(V.p,tmp);
  delete []tmp;
  return in;
}

