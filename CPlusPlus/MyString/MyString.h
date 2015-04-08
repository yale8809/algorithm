#pragma once

class MyString
{
public:
	MyString(const char *str = NULL);    // 普通构造函数

	MyString(const MyString &other);        // 拷贝构造函数

	~MyString(void);                        // 析构函数

	MyString &operator=(const MyString &other);    // 赋值函数

    const char *c_str() const;
    const char &operator[](int n)const;
    char &operator[](int n);
    int length()const;
    bool empty()const;
    bool operator ==(const MyString &other) const;
    MyString substr(int pos = 0,int n = 0) const;
    MyString &insert(int p0, const char *s);
    MyString &erase(int pos = 0, int n = 0);
    MyString &operator+=(const MyString &s);
    MyString &append(const char *s);
private:
	char *m_data;                // 用于保存字符串
};

