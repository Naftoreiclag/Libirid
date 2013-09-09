#ifndef SOCKS_H
#define SOCKS_H

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
