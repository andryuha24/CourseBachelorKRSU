//������������ ������ �1. ���
#include <iostream>
#include <ctime>
#include <time.h>
#include <stdlib.h>

using namespace std;

int razmer, b, n;

void bubble(int* a, int razmer)
{
  for (int i=razmer-1; i>=0; i--)
  {
    for (int j=0; j<i; j++)
    {
      if (a[j] > a[j+1])
      {
        int tmp = a[j];
        a[j] = a[j+1];
        a[j+1] = tmp;
      }
    }
  }
}
void lin_search(int* a, int razmer)
{
//�������� �����
   bool k;
   int z, sum = 0, j;
   cout << "������� ���������� �������� ������: ";
   cin >> n;
    j=0;
    while (j < n)
    {
       b = rand()%razmer+1;

       k = 0;
       for(int i=0; i < razmer; i++)
       {
            if(a[i] == b)
            {
               k = 1;
               z = i;
               sum++;
               break;
            }
                sum ++;
       }

    if(n<11)
    {

        cout <<"����� " << b;
        if (k == 1)
            cout << " �������. ��� ������ = " << z+1 << ".���������� ��������� "<<z+1<<endl;
        else
            cout << " �� �������." << " ���������� ��������� "<<razmer<<endl;
    }
        j+=1;
    }
    cout<< endl << "����� ���������� ��������� Sum= "<< sum<<endl;
}

void bin_search(int *a, int razmer)
{
      int j=0, mid, L, R,t, sum1=0, i;
      bool x;
    cout << "������� ���������� �������� ������: ";
    cin >> n;
    //i=-1;
    while(j<n)
    {
      b = rand()%razmer+1;
        L=0;
        R=razmer;
        t=0;
        mid=0;
        x=0;
        while(L<R)
        {
            mid=L+(R-L)/2;
            if (a[mid]==b)
            {
                x=1;
                i=mid;
                t++;
                //  sum1+=t;
                break;
            }

            if (b<a[mid])
                R=mid;
            else
                L=mid+1;
            t++;
        }
          sum1+=t;
          if(n<11)
          {


        if(x==1)cout << "������� " <<b<< " ������. ��� ������ = " << i+1 << " ���������� ��������� " << t << endl;
         else cout << "������� " <<b<< " �� ������. "<< "���������� ��������� " << t <<endl;
          }
        j++;
    }

    cout << endl << "����� ���������� ��������� sum= "<<sum1 << endl;
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL,"Rus");

    int v;
    cout <<"������� ������ �������: ";
    cin>>razmer;
    int *a=new int[razmer];

    for(int i=0; i < razmer; i++)
    {
       a[i] = rand()%razmer+1;
      if(razmer <101)
      {
           if(i%10==0) cout << endl;
       cout << a[i] <<"  ";
      }


    }
    cout << endl;
    cout <<"�������� ��� ������ �������� � ������� �������� - 1, �������� - 2: ";
    cin >> v;
    switch(v)
    {
        case 1:
            {
                lin_search(a,razmer);
                break;
            }
        case 2:
            {
                bubble(a, razmer);
                if(razmer < 15)
                {
                    for(int i=0; i < razmer; i++)
                    {
                         if(i%10==0) cout << endl;
                         cout << a[i] <<"  ";
                    }
                cout << endl;
                }

                bin_search(a,razmer);
                break;
            }
        default:
            {
                cout << "������� �������� ������";
                break;
            }
    }
   delete []a;
    return 0;
}
