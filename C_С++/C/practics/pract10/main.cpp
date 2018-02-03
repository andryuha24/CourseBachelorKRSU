#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int mystrlen(char *p)
{
    int n=0, i=0;
    while (p[i])
    {
      n++;
      i++;
    }

    return n;
}
int mystrlenp(char *p)
{
    int n=0;
    while (*p++) n++;// *p 0 n++ p++
    return n;
}

void mystrcpy(char *p1, char *p2)
{
  int i=0;
  while(p2[i]!='\0')
  {
    p1[i]=p2[i];
    i++;
  }
  p1[i]='\0';

}

void mystrcpyp(char *p1, char *p2)
{
  while(*p2)
  {
    *p1++=*p2++;
  }
  *p1='\0';
}

void mystrcat(char *p1, char *p2)
{
    int i=0, j=0;

   while(p1[i])
    i++;
    while(p2[j])
  {
   p1[i]=p2[j];
    j++;
    i++;
  }
  p1[i]='\0';

}
void mystrcatp(char *p1, char *p2)
{
  while(*p1)
    *p1++;
  while(*p2)
    *p1++=*p2++;
  *p1='\0';
}

int main()
{
    int n,m,p;
    char str1[100]="Hello";
    char str2[100] = "World";
    /*
    //Распечатка
    n = strlen(str1);
    printf("%d \n", n);
    m = mystrlen(str1);
    printf("%d \n", m);
    p = mystrlenp(str1);
    printf("%d \n", p);

    //Копирование
    cout << strcpy(str2,str1);
    mystrcpy(str2,str1);
    cout <<endl<<str2;
    mystrcpyp(str2,str1);
    cout << endl << str2;*/
    mystrcatp(str1," ");
    mystrcatp(str1,str2);
    mystrcatp(str1, "!");
    cout << str1;
    return 0;
}
