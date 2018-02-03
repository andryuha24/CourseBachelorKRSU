#include <stdio.h>

int main()
{

  int months[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30,31};
  char week[7][10]{"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
  int year, day, month;
  long sumDays = 0;

  printf("Input date: dd mm yyyy:");
  scanf("%d %d %d", &day, &month, &year);

  for(int i = 1800; i<year; i++)
  {
    if(i%4==0 && (i%100!=0 || i%400==0)) sumDays+=366;
      else sumDays+=365;
  }

  for(int i=0;i<month-1;i++) sumDays+=months[i];

  if(year%4 ==0  && (year%100!=0 || year%400==0) && month >2) sumDays++;
  sumDays+=day;
  int numDays=sumDays%7;

  printf("Today is %s ", week[numDays+1]);

  return 0;
}
