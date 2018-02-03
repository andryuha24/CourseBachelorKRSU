#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


int main(int  n, char **argv)
{
    FILE *in, *out;
    char mem[256];int num;

    if(n!= 3)
    {
      printf("Use: ./copy filename newfile\n");
      return 0;
    }

     if((in=fopen(argv[1],"rb"))==NULL)
  {
    printf("can't open file");
    return 0;
  }
   if((out=fopen(argv[2],"wb"))==NULL)
  {
    printf("can't open file");
    return 0;
  }
  while(!feof(in))
  {
    num = fread(mem,1,256,in);
    fwrite(mem,1,num,out);
  }
  fclose(in);
  fclose(out);



    return 0;
}
