#include "Socks.h"

// Look at all that!

template <class A, class B>
A Socks<A, B>::getA()
{
    return myA;
}
template <class A, class B>
B Socks<A, B>::getB()
{
    return myB;
}
template <class A, class B>
void Socks<A, B>::setA(A a)
{
    myA = a;
}
template <class A, class B>
void Socks<A, B>::setB(B b)
{
    myB = b;
}

template <class A, class B>
Socks<A, B>::Socks()
{
    //ctor
}

// Put every needed type here...
