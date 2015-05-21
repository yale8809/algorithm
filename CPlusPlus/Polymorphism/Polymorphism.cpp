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
    virtual void f1() const{ cout<<"Base const"<<endl;};
};

struct Derived: public Base
{
    virtual void f(){cout<<"Derived"<<endl;}
    virtual void f1() const{ cout<<"derived const"<<endl;};
};

void fun1()
{
    Derived derived;
    Base & base = derived;
    base.f1();
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

    void print(){cout<<"print"<<endl;};
    void print() const {cout<<"const print"<<endl;};
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

class Father
{
protected:
    int f1;
    int f2;
public:
    Father():f1(0),f2(0){cout<<"Father ctor"<<endl;};
    Father(const Father& f):f1(f.f1), f2(f.f2){cout<<"Father copy ctor"<<endl;};
    virtual ~Father(){cout<<"Father dtor"<<endl;};

};

class Son: public Father
{
protected:
    int s1;
    int s2;
    Father f;
public:
    Son():s1(0),s2(0){cout<<"Son ctor"<<endl;};
    Son(const Son& s):s1(s.s1),s2(s.s2){cout<<"Son copy ctor"<<endl;};
    virtual ~Son(){cout<<"Son dtor"<<endl;};

};

class Father1
{
public:
    Father1(){cout<<"Father1 ctor"<<endl;};
    Father1(Father1& f){cout<<"Father1 copy ctor"<<endl;};
    virtual ~Father1(){cout<<"Father1 dtor"<<endl;};

};

class Son1: public Father1
{
    Father1 f;
public:
    Son1(){cout<<"Son1 ctor"<<endl;};
    Son1(Son1& s){cout<<"Son1 copy ctor"<<endl;};
    virtual ~Son1(){cout<<"Son1 dtor"<<endl;};

};


void foo(Father1 f)
{
    cout<<"foo"<<endl;
}
void bar(Father1& f)
{
    cout<<"bar"<<endl;
}

class Father2
{
    int i;
public:
    Father2(){cout<<"Father2 ctor"<<endl;};
    Father2(int x): i(x){cout<<"Father2 ctor with param"<<endl;};
    Father2(const Father2& f){cout<<"Father2 copy ctor"<<endl;};
    Father2& operator =(const Father2& f){cout<<"Father2 ="<<endl; return *this;};
//private:
    virtual ~Father2(){cout<<"Father2 dtor"<<endl;};

};

void functf2()
{
    int i = 1;
    char c = 10;
    Father2 f1;
    Father2 f2(i);
    Father2 f3(c);
    Father2 f4(f2);
    Father2 f5 = f2;
    f1 = f4;
}

class Con
{
    const int c;
public:
    Con():c(1){};
};

class New
{
    static int x;
    int y;
public:
    static void* operator new(size_t size)
    {
        x = 0;
        //y = 0;
        return malloc(size);
    };
};

int New::x = 0;


class base
{};
class pubson: public base
{};
class proson: protected base
{};
class privson: private base
{};

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
    delete c;

    Father* f = new Son();
    Son s = *(Son *)f;
    delete f;

    Son1 s1;
    //Father1& f2 = s1;
    foo(s1);
    bar(s1);
    //cout<<"-------------"<<endl;
    //Father1* f1 = new Son1();
    //delete f1;
    //cout<<"-------------"<<endl;


    //A a1;
    //const A a2;
    //a1.print();
    //a2.print();

    //New* n = new New();
    //delete n;
    functf2();

    //base *bb = new proson();
    //base *bb = new privson();

 	return 0;


}

