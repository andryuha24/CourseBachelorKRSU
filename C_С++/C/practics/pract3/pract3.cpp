//�������� 3
#include <stdio.h>
#include <locale.h>
#include <bitset>


void bin(unsigned int t)
{
    for (int i=sizeof(t)*8/3; i>=0; i--)
        putchar (((t>>i)&1)+'0' );
    putchar('\n');
}
void vosm(unsigned int t)
{
    for (int i=sizeof(t)*8/3; i>=0; i--)
        putchar (((t>>(i*3))&7)+'0' );
    putchar('\n');

}
int print_hex (unsigned int t)
{
	unsigned long int char_counter = 0;
	char *hex_digits = "0123456789abcdef";

	for (int i = sizeof (t) * 8-4; i >= 0; i-=4) {
		char_counter += putchar (*(hex_digits + ((t >> i) & 0xf)));
	}

	return char_counter;
}


int main(){

      setlocale(LC_CTYPE,"Russian");
      int chislo, a, b, c, d, e;
      printf ("������� ����� x: ");
      scanf ("%d",&chislo);
      printf ("\n x = %d\n",chislo);
      //���������
      printf("\n 1.�������� �����.\n");
      a = chislo << 1;
      printf ("   2*x = %d\n", a);
      //����� �����
      printf("\n 2.����� �����.\n");
      b = ~chislo;
      b +=1;
      printf ("   -x = %d\n", b);
      //������������
      printf("\n 3.��������, ������������, ����������������� ������� ���������.\n");
      printf("   3.1 ��������: ");
      bin(chislo);
      printf("   3.2 ������������: ");
      vosm(chislo);
      printf("   3.3 �����������������: ");
      print_hex (chislo);
      return 0;
}

