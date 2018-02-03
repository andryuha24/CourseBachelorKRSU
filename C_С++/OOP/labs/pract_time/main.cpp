#include <iostream>
#include <time.h>

using namespace std;

int main()
{
     time_t t;
    tm *t_m;
    time(&t);
    t_m=localtime(&t);
    cout<<"Local time is: "<<t_m->tm_hour<<":"<<t_m->tm_min<<":"<<t_m->tm_sec<<endl;
    cout<<"Local date is: "<<t_m->tm_mday<<"."<<t_m->tm_mon+1<<"."<<t_m->tm_year+1900<<endl;


    return 0;
}
