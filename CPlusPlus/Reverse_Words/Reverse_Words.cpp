// Reverse_Words.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
		if(s.empty()) return;
        while(s[0] == ' ') 
		{
			s.erase(0,1);
			if(s.empty()) return;
		}
        reverseWord( s, 0, s.length()-1);
        while(s[0] == ' ') s.erase(0,1);
        s+=' ';
        for(int i=0,j=0; j<s.length(); j++){
            while(j+1<s.length() && s[j]==' ' && s[j+1]==' '){
                s.erase(j,1);
            }
            if(s[j]==' '){
                reverseWord(s, i, j-1);
                i=j+1;
            }
        }
        s.erase(s.length()-1,1);
    }
    void reverseWord( string &s, int start, int end ){
        char letter;
        while(start<end){
            letter = s[start];
            s[start++] = s[end];
            s[end--] = letter;
        }
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution rev;
	string s1 = "hello, kitty! ";
	string s2 = "    ";
	string s3 = "   good   bye!    ";
	string s4 = "";
	rev.reverseWords(s1);
	rev.reverseWords(s2);
	rev.reverseWords(s3);
	rev.reverseWords(s4);
	cout<<s1<<endl;
	cout<<s2<<endl;
	cout<<s3<<endl;
	cout<<s4<<endl;
	return 0;
}

