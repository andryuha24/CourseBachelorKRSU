//Типы данных.
#include <stdio.h>
#include <cmath>
int main(){
    printf(" --------------------------------------------------------\n");
    printf("|  N  |  Type | Byte | Bit |    Minimum   |    Maximum   |\n");
    printf("|--------------------------------------------------------|\n");
    printf("|  1  |  char |%6d|%5d|      -%G    |     +%G     |\n", sizeof(char), sizeof(char)*8, pow(2, sizeof(char)*8-1), pow(2, sizeof(char)*8-1)-1);
    printf("|-----------------------------------------|--------------|\n");
    printf("|  2  | short |%6d|%5d|     -%G   |   +%G     |\n", sizeof(short), sizeof(short)*8, pow(2, sizeof(short)*8-1), pow(2, sizeof(short)*8-1)-1);
    printf("|-----------------------------------------|--------------|\n");
    printf("|  3  |  int  |%6d|%5d|  -%.10G |  +%.10G |\n", sizeof(int), sizeof(int)*8, pow(2, sizeof(int)*8-1), pow(2, sizeof(int)*8-1)-1);
    printf("|-----------------------------------------|--------------|\n");
    printf("|  4  |  long |%6d|%5d| -%G| +%G|\n", sizeof(long), sizeof(long)*8, pow(2, sizeof(long)*8-1), pow(2, sizeof(long)*8-1)-1);
    printf("|-----------------------------------------|--------------|\n");
    printf("|  5  | float |%6d|%5d|    3.4E-38   |    3.4E+38   |\n", sizeof(float), sizeof(float)*8);
    printf("|-----------------------------------------|--------------|\n");
    printf("|  6  | double|%6d|%5d|    1.7E-308  |    1.7E+308  |\n", sizeof(double), sizeof(double)*8);
    printf("|-----------------------------------------|--------------|\n");
    printf("|  7  |  long |%6d|%5d|    3.4E-492  |    3.4E+492  |\n", sizeof(long double), sizeof(long double)*8);
    printf("|     | double|      |     |              |              |\n");
    printf(" --------------------------------------------------------\n");
    return 0;

}
