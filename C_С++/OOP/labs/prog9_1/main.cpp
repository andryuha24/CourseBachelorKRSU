#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdexcept>
using namespace std;

double dev(double a,double b)
{
    if (b==0) throw (b);
    else return a/b;
}
int myString(char *a)
{
    int len=strlen(a);
    for (int i=0; i<len; i++) if(a[i]=='S')
        {
            char *g;
            g="S- isn't to be in string";
            throw (g);
        }
    return 1;
}

int main()
{
    try
    {
        dev(2,5);
        dev(2,0);
    }
    catch(double b)
    {
        printf ("devide by %G\n",b);
    }
    try
    {
        char *str;
        str="Hello my friend";
        myString(str);
        str="September is good time";
        myString(str);
    }

    catch(char *g)
    {
        cout<<g<<endl;
        //printf ("%s\n",g);
    }

    return 1;
}

