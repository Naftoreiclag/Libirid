#ifndef SOCKS_H
#define SOCKS_H

/* This class demonstrates the complexities needed
 * to have both a .h and .cpp for a template class.
 */

template <class A, class B>
class Socks
{
    public:
        A getA();
        B getB();
        void setA(A a);
        void setB(B b);
        Socks();
    protected:
    private:
        A myA;
        B myB;
};

#endif // SOCKS_H
