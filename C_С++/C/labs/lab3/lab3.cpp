#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL,"Rus");
 char c; /* ��� ��������� */
 char f; /* ������� ������ */
 char b; /* ������� ��������� */
 unsigned char n; /* ���������� ���� */
 unsigned int UnitStateWord; /* ����� ��������� */
  /* ���� ��������� ������ */
  printf("������� ��� ��������� (0 - 31) >");
  scanf("%d",&c);
  printf("������� ������� ������ (0 / 1) >");
  scanf("%d",&f);
  printf("������� ������� ��������� (0 / 1) >");
  scanf("%d",&b);
  printf("������� ���������� ���������� ���� (0 - 255) >");
  scanf("%d",&n);
  /* ������������ ������������ ���� */
  UnitStateWord=((unsigned int)c&0x1F)<<11;
  UnitStateWord|=((unsigned int)f&1)<<9;
  UnitStateWord|=((unsigned int)b&1)<<8;
  UnitStateWord|=n&0xFF;
  /* ����� ���������� */
  printf("\n����� ��������� ���������� = %04x\n",
     UnitStateWord);
  return 0;
}
