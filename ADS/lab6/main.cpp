#include <iostream>
#include <stdio.h>
#include <time.h>
#include "Graphics.h"
using namespace std;


const int N=100;
int c=1;
int mas[N];
struct node
{
    int d;//данные узла
    node *l, *r; //левая и правая часть дерева
    int x,y;
};

void outxy(int x, int y, int var)
{
   char buf[10];
   snprintf(buf, sizeof(buf), "%d", var);
   outtextxy(x, y, buf);
}

void menu()
{
  settextstyle(2,2,6);
  setcolor(2);
   outtextxy(20,410,"Choose an action:");
   outtextxy(45,450,"1 - Pre-Order Travers");
   outtextxy(45,490,"2 - In-Order Travers");
   outtextxy(45,530,"3 - Post-Order Travers");
   outtextxy(45,570,"4 - Search with include");
   outtextxy(45,610,"5 - Search with delete");
   outtextxy(45,650,"6 - Delete Tree");
   outtextxy(45,690,"0 - Exit");
  settextstyle(1,2,4);
  setcolor(15);
}


node *Create(int *mas, int n)
{

    if(n==0) return 0;

    int d = n/2;
    node *m = 0;
    m = new node;

    cout<<*(mas+d)<<" ";

    m->d= *(mas+d);
    m->l=Create(mas,d);
    m->r=Create(mas+d+1,n-d-1);
    return m;
}


void graphTravers(node *t)
{
    setfillstyle(1,6);
    setcolor(15);
    fillellipse(t->x,t->y,30,30);
    setbkcolor(0);
    outxy(t->x+15,t->y+10,t->d);
}

void preOrderTravers(node *t)//прямой обход
{
    outtextxy(600,150,"Pre-Order Travers");
    if(t==0) return;
   //cout<<t->d<<" ";
    Sleep(1000);
    graphTravers(t);
    if(t->l)preOrderTravers(t->l);
    if(t->r)preOrderTravers(t->r);

}

void inOrderTravers(node *t)//симметричный
{
    outtextxy(600,150,"In-Order Travers");
    if(t==0)return;
    if(t->l)inOrderTravers(t->l);
    Sleep(1000);
    //cout<<t->d<<endl;
    graphTravers(t);
    if(t->r)inOrderTravers(t->r);
}

void postOrderTravers(node *t)//обратный
{
    outtextxy(600,150,"Post-Order Travers");
    if(t==NULL) return;
    if(t->l) postOrderTravers(t->l);
    if(t->r) postOrderTravers(t->r);
    //cout<<t->d<<endl;
    graphTravers(t);
    Sleep(1000);
}

void graph()
{
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode);
    setbkcolor(0);
    cleardevice();//очистка активной страницы
}
void fillmas(int *mas,int n)
{
    srand(time(0));
    for(int i = 0; i < n; i++) mas[i] = rand()%100;
}
void sort(int *p, long size)
{
    int i;
    for(i=0; i<size; ++i)
        for(int j=i+1; j<size; ++j)
            if(p[j]<p[i])swap(p[i],p[j]);
}
void printTree(node *p, int n,int left, int right )
{
    int sr2;
    if(p)
    {

        setfillstyle(1,1);
        int sr=(left+right)/2;
        int sr1=(left+sr)/2;
        sr2=(right+sr)/2;
        if(p->l) line(sr+25,n*70+20,sr1+25,(n+1)*70+30);
        if(p->r)line(sr+25,n*70+20,sr2+25,(n+1)*70+30);
        fillellipse(sr,n*70,30,30);
        settextstyle(1,2,4);
        outxy(sr+15,n*70+10,p->d);
        printTree(p -> l, n+1,left,sr);

        p->x=sr;
        p->y=n*70;
        printTree(p -> r, n+1,sr,right);

    }
}


node *searchIn(node *&root, int n)
{
    outtextxy(600,150,"Search with include");
    if(root==0)
    {
        root=new node;
        root->d=n;
        root->l=root->r=0;
        setbkcolor(0);
        return root;
    }
    if(root->d==n)return root;
    if(root->d > n)return searchIn(root->l,n);
    else return searchIn(root->r,n);

}


node *& rightmost(node *&root)
{
    node *tmp=root;
    if (root->r==0) return root;
    while (tmp->r ->r!= 0)
        tmp = tmp->r;
    return tmp->r;
}

node* searchDel(node *root, int val)//поиск с удалением
{

    if (!root)
    {
        cout<<"Item not found.\n"<<endl;
        return 0;
    }
    if (root->d == val)
    {
         outtextxy(600,150,"Search with delete");
        if (root->l==0 && root->r==0)
        {
            delete root;
            return 0;
        }
        if (root->r==0 && root->l != 0)
        {
            node *temp = root->l;
            delete root;
            return temp;
        }
        if (root->l==0 && root->r != 0)
        {
            node *temp = root->r;
            delete root;
            return temp;
        }
        node *&tmp=rightmost(root->l);
        root->d = tmp->d;
        tmp = searchDel(tmp, root->d);
        return root;
    }
    if (val < root->d)
    {
       root->l =searchDel(root->l, val);
        return root;
    }
    if (val > root->d)
    {
       root->r = searchDel(root->r, val);
       return root;
    }
}
void deleteTree(node *root)
{
    if (root == NULL) return;
    deleteTree(root->l);
    deleteTree(root->r);
    delete root;
    return;
}
void reDrawTree(node *z, int c)
{
       setbkcolor(0);
    Sleep(1000);
    cleardevice();
    setbkcolor(0);
    setcolor(15);
    printTree(z,c,100,1200);

}

void newElem(node *t, int m)
{
    setbkcolor(0);
   setfillstyle(1,2);

    fillellipse(t->x,t->y,30,30);
    outxy(t->x+15,t->y+10,m);

     menu();
}
int main()
{
    int n;
    graph();
    cout<<"Enter the number of vertices( <31): ";
    cin>>n;
    node *tr;
    if(n>0 && n!=0 && n<32)
    {
        fillmas(mas,n);
        sort(mas,n);
        node* z;
        z=Create(mas,n);
        cout << endl;
        printTree(z,c,100,1200);
        while (1)
        {

          menu();
          int act;
          cin >> act;
          switch(act)
          {
           case 0:
               exit(0);
               deleteTree(z);
               break;
           case 1:

               preOrderTravers(z);
               reDrawTree(z,c);
               break;
           case 2:
               inOrderTravers(z);
               reDrawTree(z,c);
               break;
           case 3:
               postOrderTravers(z);
               reDrawTree(z,c);
               break;
           case 4:
               int elem;
               cout<<"Input element: \n";
               cin>>elem;
               tr =searchIn(z,elem);
               reDrawTree(z,c);
               newElem(tr,elem);
               reDrawTree(z,c);
               break;
           case 5:
               cout<<"Input element: \n";
               cin>>elem;
               z= searchDel(z,elem);
               reDrawTree(z,c);
               break;
           case 6:
               deleteTree(z);
               setbkcolor(0);
               cleardevice();
               setbkcolor(0);
               break;
           default :cout<< "Error selecting actions.\n";
          }
        }
    }
    else cerr<<"Error. The number of vertices <31!\n";
    getch();
    return 0;
}
