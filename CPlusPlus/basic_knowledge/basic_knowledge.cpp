// basic_knowledge.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <string.h>
#include <stdint.h>

void f1()
{
    char *s1 = "abc";
    const char * s2 = "def";
    char * const s3 = "xyz";
    char s4[] = "abcdef";
    //s1 = s4; // point can modified;
    s2 = s4;
    //s3 = s4; // point can't modified;
    //s4 = s1;

    //*s1 = 'b'; // run error
    //*s2 = 'b'; // build error
    //*s3 = 'b'; // run error
    *s4 = 'b';

}

void f2()
{
    char * s1 = "abcde";
    char s2[] = "abcde";
    char s3[] = { 'a', 'b', 'c', 'd', 'e'};
    int i = 0;
    int j = strlen(s1);

    int size1 = sizeof(s1);
    int size2 = sizeof(s2);
    int size3 = sizeof(s3);
    int len2 = strlen(s2);
    int len3 = strlen(s3);
    int k = sizeof(j/i);
}

void structsize()
{
    struct foo
    {
        int i1;
        char bar;
        int i2;
        char c2;
        int i3;
        short s1;
        long *l1;
    };
    
    struct foo1
    { 
        char bar;
        char c2;
        short s1;
        int i1;
        int i2;
        int i3;
        long *l1;
    };

    struct foo2
    {
        int i1;
        bool b1;
        char ch[8];
        short d;
        bool b2;
        char *cp;
    };

    struct foo3
    {
        char ch[8];
        int i1;
        char *cp;
        short d;
        bool b1;
        bool b2;
    };

    int size = sizeof(foo);
    int size1 = sizeof(foo1);
    int size2 = sizeof(foo2);
    int size21 = sizeof(foo2*);
    int size3 = sizeof(foo3);
}

void f3()
{
    uint64_t *p = (uint64_t*)0;
    printf("%d",(uint64_t)(p+100));
}

void f4()
{
    class A
    {
        int a;
        virtual void foo(){};
    };
    int size = sizeof(A);
}

int _tmain(int argc, _TCHAR* argv[])
{
    f1();
    f2();
    structsize();
    f3();
    f4();
	return 0;
}

