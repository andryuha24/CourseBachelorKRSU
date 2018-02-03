#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

void my_strcpy(char *s1, char *s2, int n)
{
    while (n > 0 && *s2 != '\0') {
        *s1++ = *s2++;
        --n;
    }
    while (n > 0) {
        *s1++ = '\0';
        --n;
    }
}

void mstrcat(char *p1, char *p2)
{
   int len1 = strlen(p1);
   int len2 = strlen(p2);
   char *str3 = new char[len1+len2];

   my_strcpy(str3,p1,len1/2);
   int n = len1/2;
   str3[len1/2] = '\0';

   strcat(str3,p2);
   str3[(len1/2)+len2] = '\0';
   cout << strcat(str3,p1+len1/2);
}

int main()
{
    char str1[80], str2[80];
    cin >> str1;
    cin >> str2;
    mstrcat(str1,str2);

}
