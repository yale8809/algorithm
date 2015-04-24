// Polymorphism.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void bit_operation()
{
    int a  = 0x32;
    int b = 0x20;
    int c = a&b;
    cout<<c<<endl;
    printf("%x", c);
}               

struct Base
{
    virtual ~ Base(){};
    virtual void f(){ cout<<"Base"<<endl;};
};

struct Derived: public Base
{
    virtual void f(){cout<<"Derived"<<endl;}
};

void fun1()
{
    Derived derived;
    Base & base = derived;
    try
    {
        throw base;
    }
    catch(Base& e)
    {
        e.f();
    }
    catch(Derived& e)
    {
        e.f();
    }
}

void fun2()
{
    Derived derived;
    Base * base = &derived;
    try
    {
        throw base;
    }
    catch(Base* e)
    {
        e->f();
    }
    catch(Derived* e)
    {
        e->f();
    }
}

void fun3()
{
    Derived derived;
    Base & base = derived;
    base.f();
}

class A
{
public:
    virtual double Avalue(double x){return x*x;};
    double Bvalue(double x){return Avalue(x)/2;};
    double Cvalue(double x){return x*x;};
    double Dvaule(double x){return Cvalue(x)/2;};
};

class B: public A
{
public:
    virtual double Avalue(double x){return x*x*x;};
    double Cvalue(double x){return x*x*x;};
};

struct E{virtual ~E(){};};
struct D{virtual ~D(){};};
struct C:public D,public E{virtual ~C(){};};

int _tmain(int argc, _TCHAR* argv[])
{
    fun1();
    fun2();
    fun3();
    B b;
    cout<<b.Bvalue(3)<<" "<<b.Dvaule(3)<<endl;

    C *c = new C();
    E *e = (E*)c;
    D *d = (D*)c;
	return 0;
}

