#ifndef INTARRAY_H_INCLUDED
#define INTARRAY_H_INCLUDED
class intArray
{
private:
    int * p;
    int n;
    int error;//error=0 ���� ������ ���
    //error=1 ���� p=NULL
    //error=2 ���� ������ ������� �� �������
    static int count;//���������� ��������� ��������
    //� ������������ ����������, � ����������� ���������

public:
    class Size{};
    intArray();
    intArray(int n);
    intArray(const intArray &);
    ~intArray();

    int   getElem(int i);
    int    getN();
    int    getMin();
    int    getMax();
    float getAverage();
    int    getMediana();
    int    getError();
    double getDis();
    double getRMS();
    static int getCount();
    void fill();
    void sort();

    intArray operator +(const intArray &);
    intArray operator -(const intArray &);
    intArray operator *(const intArray &);
    intArray operator /(const intArray &);

    intArray operator +(int a);
    intArray operator -(int a);
    intArray operator *(int a);
    intArray operator /(int a);

    intArray &operator ++();
    intArray operator ++(int);

    intArray &operator --();
    intArray operator --(int);

    int& operator [](int a);
    void operator ()();

    void *operator new(size_t size);
    void operator delete (void* addr);

    intArray &operator =(const intArray &);
    int operator ==(const intArray &);
    int operator !=(const intArray &);
    int operator >(const intArray &);
    int operator >=(const intArray &);
    int operator <(const intArray &);
    int operator <=(const intArray &);

    friend intArray operator +(int a, const intArray &);
    friend intArray operator -(int a, const intArray &);
    friend intArray operator *(int a, const intArray &);
    friend intArray operator /(int a, const intArray &);
};



#endif // INTARRAY_H_INCLUDED
