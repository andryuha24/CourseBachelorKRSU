//Лабораторная №1
#include <stdio.h>

int main(){
    char name1[9], name2[9], name3[8];
    char type1, type2, type3;
    float cost1, cost2, cost3;
    int number1, number2, number3;
    printf("1.Input  Name, Type, Nominal, Amount:  ");
    scanf("%s %c %f %d", name1, &type1, &cost1, &number1);
    printf("2.Input  Name, Type, Nominal, Amount:  ");
    scanf("%s %c %f %d", name2, &type2, &cost2, &number2);
    printf("3.Input  Name, Type, Nominal, Amount:  ");
    scanf("%s %c %f %d", name3, &type3, &cost3, &number3);
    printf(" \n ---------------------------------\n");
    printf("|    Vedomost' komplectuyushih    |\n");
    printf("|---------------------------------|\n");
    printf("|  Name  | Type| Nominal | Amount |\n");
    printf("|---------------------------------|\n");
    printf("|%8s|%5c|%9.1f|%8d|\n", name1, type1, cost1, number1);
    printf("|---------------------------------|\n");
    printf("|%8s|%5c|%9.1f|%8d|\n", name2, type2, cost2, number2);
    printf("|---------------------------------|\n");
    printf("|%8s|%5c|%9.1f|%8d|\n", name3, type3, cost3, number3);
    printf("|---------------------------------|\n");
    printf("| Primechanie: R - resistor;      |\n");
    printf("|              C - capacitor.     |\n");
    printf(" ---------------------------------\n");
    return 0;

}
