#ifndef INARRAY_H_INCLUDED
#define INARRAY_H_INCLUDED
class intArray
{
    int * p;
    int n;
    int error;
    static int count;

public:
    intArray();
    intArray(int);
    intArray(const intArray &);
    ~intArray();

  int &getElem(int i);
    int  getN(){return n;}
    int  getMin();
    int  getMax();
    float getAverage();
    int   getMediana();
    int   getEror();
     double getDis();//дисперсия
     double getRMS();//отклонение
     static int getCount(){return count;}
     void fill();
     void sort();

    intArray & operator -();

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

    int &operator [](int a);
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

     friend istream& operator>>(std::istream&, intArray &);
    friend ostream& operator << (ostream&, const intArray &);
};




#endif // INARRAY_H_INCLUDED
