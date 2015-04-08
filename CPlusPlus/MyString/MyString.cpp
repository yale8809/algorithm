// MyString.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include <string.h>
#include <assert.h>
#include "MyString.h"

char * strcat(char * dest,const char * src){
    assert((dest!=NULL)&&(src!=NULL));
    char *ret=dest;
    while(*dest++);
    dest--;
    while(*dest++=*src++);
    return ret;
}

char * strcpy(char * dest,const char * src){
    assert((dest!=NULL)&&(src!=NULL));
    char *ret=dest;
    while(*dest++=*src++);
    return ret;
}

int strlen(const char * src){
    assert(src!=NULL);
    int len=0;
    while(*src++!='\0')
        len++;
    return len;
}

int strcmp(const char * src,const char * dest){
    assert((dest!=NULL)&&(src!=NULL));
    int ret=0;
    while(!(ret=*(unsigned char *)src-*(unsigned char *)dest)&&*src&&*dest){
        ++src;
        ++dest;
    }
    return ret;
}

const char * strstr(const char * src,const char * sub){
   assert((sub!=NULL)&&(src!=NULL));
   const char * bp;
   const char * sp;
   while(*src){
       bp=src;
       sp=sub;
       while(*bp++==*sp++){
           if(!*sp)
               return src;
       }
       src++;
   }
   return NULL;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}



MyString::MyString(const char *str)
{
	if(str==NULL)
    {
        m_data = new char[1];    // ���ܼ� NULL �ж������
        *m_data = '\0';
    }
    else
    {
        int length = strlen(str);
        m_data = new char[length+1];  // ���ܼ� NULL �ж������
        strcpy(m_data, str);
    }
}

MyString::MyString(const MyString &other)
{
	int length = strlen(other.m_data);   

    m_data = new char[length+1];      // ���ܼ� NULL �ж������   

    strcpy(m_data, other.m_data);   
}


MyString::~MyString(void)
{
	delete [] m_data;     // ����m_data���ڲ��������ͣ�Ҳ����д�� delete m_data;
}

MyString & MyString::operator =(const MyString &other)
{
	// (1) ����Ը�ֵ             

	if(this == &other) return *this;

	// (2) �ͷ�ԭ�е��ڴ���Դ            

    delete [] m_data;

    // ��3�������µ��ڴ���Դ������������ 

    int length = strlen(other.m_data);   

    m_data = new char[length+1];         // ���ܼ� NULL �ж������

    strcpy(m_data, other.m_data);

     // ��4�����ر����������       
	return *this;
}
inline String String::operator+(const String &other)const

{

    String newString;

    if(!other.m_data)

        newString = *this;

    else if(!m_data)

        newString = other;

    else

    {

        newString.m_data = new char[strlen(m_data)+strlen(other.m_data)+1];

        strcpy(newString.m_data,m_data);

        strcat(newString.m_data,other.m_data);

    }

    return newString;

}

bool String::operator==(const String &s)    

{

    if ( strlen(s.m_data) != strlen(m_data) )

        return false;

    return strcmp(m_data,s.m_data)?false:true;

}

char& String::operator[](unsigned int e)

{

    if (e>=0&&e<=strlen(m_data))

        return m_data[e];

}

ostream& operator<<(ostream& os,String& str)

{

    os << str.m_data;

    return os;

}