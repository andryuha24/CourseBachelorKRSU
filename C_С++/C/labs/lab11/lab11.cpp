#include <iostream>
using namespace std;

void matric(int *, int );


int main()
{
    int n;
    cin >> n;
    int *p = new int *[n];
    matric(p,n);
    delete [][]a;
    return 0;
}

void matric(int **p, int n)
{
    int i, j, r1=1,r2=n-2, dd=1, k=1;

    for (j=0; j<n; j++)
    {
        for (i=0; i<n; i++)
          if ((i<r1)||(i>r2)) p[i][j]=0;
          else p[i][j]=k++;
        r1+=dd; r2-=dd;
        if (r1>r2) dd=-dd;
    }
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
          cout << p[i][j];
        cout << endl;
    }
}
