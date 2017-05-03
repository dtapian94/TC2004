// Daniel Tapia Nava A01022285
// Analisis y Modelacion de Software

#include <iostream>

using namespace std;

class ReferenceCount
{
public:
  int count;

  ReferenceCount()
  {
    count = 1;
  }

  void increment()
  {
    count++;
  }

  void decrement()
  {
    count--;
    if( count == 0 )
     delete this;
  }
};

class Child
{
public:
  ReferenceCount* reference;
  int* p;

  Child()
  {
    reference = new ReferenceCount;
    p = new int;
  }

  ~Child()
  {
    delete p;
    delete reference;
    p = NULL;
    reference = NULL;
  }

  Child& operator=(const Child& ch)
  {
    reference->decrement();

    p = ch.p;
    reference = ch.reference;
    reference->increment();

    return *this;
  }
};

int main()
{
  Child a;
  Child b;

  b = a;

  *(a.p) = 5;

  cout<<*(b.p)<<endl;
}