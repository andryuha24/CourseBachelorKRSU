//Классная №4
#include <stdio.h>
int main()
{
    //Перевод в секунды
    /*int hour, minute, sec;
    long d;
    printf("Input hours, minutes, secunds: ");
    scanf("%d %d %d", &hour, &minute, &sec);
    if(hour > 23 || hour <0 || minute > 59 || minute < 0 || sec > 59 || sec < 0)
    {
        printf("Oshibka vvedennih dannih: %02d:%02d:%02d", hour, minute, sec);
        return 0;
    }
    else{
        d = 3600 * hour + 60 * minute + sec;
        printf("%02d:%02d:%02d = %02d", hour, minute, sec, d);
    }*/

    int day;
    printf("Vvedite den' nedeli?\n");
    scanf("%d",&day);

    switch (day){
    case 1:printf("ponedelnik");break;
    case 2: printf("vtornik"); break;
    case 3: printf("sreda"); break;
    case 4: printf("chetverg"); break;
    case 5: printf("pyatnica"); break;
    case 6: printf("subbota"); break;
    case 7: printf("voskresenie"); break;
    default:printf("Oshibka v nedele 7 dnei %d",day);

    }
 return 0;
}
