#include <iostream>
#include "Graphics.h"
using namespace std;

struct Graph
{
    int V;
    int E;
};

const int N=100;
int GM[N][N];//матрица смежности
int mas[N],tmp;
bool visited[N];//массив посещенных вершин
int prev[N], prev1[N];
int x[N],y[N];//массивы координат
 char str[20];
Graph G;



struct Queue
{
    int data[N]; //массив данных
    int last; //указатель на начало
};
void Creation(Queue *Q) //создание очереди
{
    Q->last=0;
}
bool Full(Queue *Q) //проверка очереди на пустоту
{
    if (Q->last==0) return true;
    else return false;
}
void Add(Queue *Q,int i) //добавление элемента
{
    if (Q->last==N)return;
    Q->data[Q->last++]=i;
}
int Top(Queue *Q) //вывод начального элемента
{
    return Q->data[0];
}
void Delete(Queue *Q) //удаление элемента
{
    for (int i=0; i<Q->last && i<N; i++) //смещение элементов
        Q->data[i]=Q->data[i+1];
    Q->last--;
}

void outxy(int x, int y, int var)
{
   char buf[10];
   snprintf(buf, sizeof(buf), "%d", var);
   outtextxy(x, y, buf);
}

void showPath(int index1, int index2, int *p)
{
    if (index1==index2) {cout<<endl<<index1<<"  "; return;}
    if(p[index2]==-1) cout<<"Iz "<<index1<<"v "<<index2<<" net puti\n";
    else showPath(index1,prev[index2],p);
    cout<<index2<<" ";
}

void gphDFS(int i)//графика поиск в глубину
{
    Sleep(1000);
    setfillstyle(1,15);
    fillellipse(x[prev1[i]]-30,y[prev1[i]]-30,30,30);
    outxy(x[prev1[i]]-7,y[prev1[i]]-20,mas[prev1[i]]);
    fillellipse(x[i]-30,y[i]-30,30,30);
    outxy(x[i]-7,y[i]-20,mas[i]);
}


void DFS(int vert, int n, int num)
{
    for(int i=0; i<n; i++)
    {
        if(GM[vert][i]==true&&visited[i]==false)
        {
            visited[i]=1;
            prev1[i]=vert;
            showPath(num,i,prev1);
            gphDFS(i);
            DFS(i,n,num);
        }
    }
}

void gphBFS(int j)
{
    Sleep(1000);
    setfillstyle(1,3);
    fillellipse(x[prev[j]]-30,y[prev[j]]-30,30,30);
    outxy(x[prev[j]]-7,y[prev[j]]-20,mas[prev[j]]);
    fillellipse(x[j]-30,y[j]-30,30,30);
    outxy(x[j]-7,y[j]-20,mas[j]);
}

void BFS()
{

}

void graph()
{
  int gdriver = DETECT, gmode;
  initgraph(&gdriver, &gmode);
  setbkcolor(0);
  cleardevice();
  setcolor(3);
}

void matrica(int *ind1,int *ind2,int n)
{
    for (int i=0; i<n; i++)
    {
        GM[ind1[i]][ind2[i]]=true;
        GM[ind2[i]][ind1[i]]=true;
    }
}

int ineterfies(int a, int b, int *m, int *n, int *p, int *p1)
{
   for (int j=0; j<b; j++)
    {
        setcolor(15);
        line(m[p[j]],n[p[j]],m[p1[j]],n[p1[j]]);
    }
    //Шарики
    for (int i=0; i<a; i++)
    {
        setfillstyle(1,10);
        fillellipse(m[i]-30,n[i]-30,30,30);
    }
   //элемент
   for (int i=0; i<a; i++) mas[i]=i;
   setcolor(4);
   settextstyle(1,2,4);
    //вывод чисел
    for (int i=0; i<a; i++) outxy(m[i]-7,n[i]-20,mas[i]);
}



int main()
{
    graph();
    FILE *in,*in1;
    int  n=0,n1=0, num;  //n1 = b, n = a,
    if((in=fopen("graph.txt","r"))==NULL)
    {
        printf("cann't open file");
        return 0;
    }
    fgets(str,20,in);
    sscanf(str,"%d",&n);
    G.E=n;
    for(int j=0; j<n+1; j++)
    {
        fgets(str,20,in);
        sscanf(str,"%d %d",&x[j],&y[j]);
        if (feof(in)) break;
    }
    fclose(in);

    //считывание путей
    if((in1=fopen("graph2.txt","r"))==NULL)
    {
        printf("cann't open file");
        return 0;
    }
    fgets(str,20,in1);
    sscanf(str,"%d",&n1);
    G.V=n1;
    int ind1[n1],ind2[n1];
    for(int j=0; j<n1+1; j++)
    {
        fgets(str,20,in1);
        sscanf(str,"%d %d",&ind1[j],&ind2[j]);
        if(feof(in1)) break;
    }
    fclose(in1);
    ineterfies(n, n1, x, y, ind1, ind2);
    matrica(ind1,ind2,n1); //Матрица смежности
    for (int i=0; i<n; i++)
    {
      for (int j=0; j<n; j++)
         printf("%d",GM[i][j]);
      printf("\n");
    }
    printf("\nVvedite vershinu:\n");
    int v,nomer[n];
    scanf("%d",&v);
    if (v<=n || v>=0)
    {
        for(int i=0; i<n; i++)
            if(v==mas[i])num=i;
        int i=0;
        setlocale(LC_ALL,"Rus");
        Queue Q;
        Creation(&Q);
        for(i=0; i<n; i++) visited[i]=false;
        Add(&Q,num);
        visited[num]=true;
        prev[num]=-1;

      //нашли шарик
        setfillstyle(1,15);
        fillellipse(x[num]-30,y[num]-30,30,30);
        outxy(x[num]-7,y[num]-20,mas[num]);

//в ширину
        cout<<"Poisk v shirinuy"<<endl;
        cout<<"Puti:\n"<<endl;
        cout<<mas[num]<<" "<<endl;
        while(!Full(&Q))
        {
            tmp=Top(&Q);
            Delete(&Q);
            visited[tmp]=true;
            for(int j=0; j<n; j++)
            {
                if (GM[tmp][j]==true && visited[j]==false)
                {
                    visited[j]=true;
                    prev[j]=tmp;
                   //вывод пути
                   showPath(num,j,prev);
                 //   printpath(num,j);
                    gphBFS(j);
                    Add(&Q,j);//добавляем в очередь вершину i
                }
            }
        }
        cout<<endl;
}

    cout << "Hello world!" << endl;
      getch();
    return 0;
}
