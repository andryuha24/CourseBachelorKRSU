#include <iostream>
#include <stdio.h>
#include <math.h>
#include "student.h"
using namespace std;



int main()
{

  Student mas[10];
  FILE *in;
  int i=0, k =0 ;

  double sred[10], best=0;
  char str[80];
  if((in=fopen("stud.txt","rt"))==NULL)
  {
    printf("can't open file");
    return 0;
  }
  while(!feof(in))
  {
    fgets(str,80,in);
    sscanf(str,"%s %s %d %d %d %d %d %d",mas[i].name, mas[i].group, &mas[i].year, &mas[i].marks[0], &mas[i].marks[1], &mas[i].marks[2], &mas[i].marks[3], &mas[i].marks[4]);
    i++;
  }
  fclose(in);

  for(int j=0; j<10; j++)
  {
    cout << mas[j].name <<"\t"<< mas[j].group<<"  "<< mas[j].year<<" " << mas[j].marks[0]<<" "<<mas[j].marks[1]<<" " <<mas[j].marks[2]<<" " <<mas[j].marks[3]<<" " <<mas[j].marks[4]<<endl;
  }


  for(int j=0; j<10; j++)
  {
    sred[j] = (mas[j].marks[0]+ mas[j].marks[1]+mas[j].marks[2]+mas[j].marks[3]+mas[j].marks[4])/5.0;
    best = sred[0];
    for(i=0; i < 10; i++)
    {
        if(sred[i] > best)
        {
             best = sred[i];
             k = i;
        }
    }
  }
    cout <<endl<< "Luchshii student po uspevaemosti: "<< mas[k].name <<"\t"<< mas[k].group<<"  "<< mas[k].year<<" srednii bal: "<< best<< endl;


  return 0;
}
