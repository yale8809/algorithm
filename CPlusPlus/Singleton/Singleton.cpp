// Singleton.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "Singleton.h"


int _tmain(int argc, _TCHAR* argv[])
{
    Singleton * inst = Singleton::Instance();
	return 0;
}


auto_ptr<Singleton> Singleton::instance;

Singleton* Singleton::Instance()
{
    if(instance.get() == NULL)
    {
        instance.reset( new Singleton);
    }
    return instance.get();
}

Singleton::Singleton(void)
{
    cout<<"Create Singleton"<<endl;
}


Singleton::~Singleton(void)
{
    cout<<"Destroy Singleton"<<endl;
}
