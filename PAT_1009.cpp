#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
//����Ƕ�׷���
void reverse(string str)
{
	if (str.find_last_of(' ')==-1) //�޷��ҵ��������ַ�ʱ�÷�������-1
	{
		cout << str;
		return;
	}
	else
	{
		int length = str.length();
		int pos = str.find_last_of(' ');
		string temp = str.substr(pos + 1, length - 1 - pos);
		cout << temp << ' ';
		str.erase(pos, length - 1);
		reverse(str);
	}
}


int main()
{
	string str1;
	getline(cin, str1);
	reverse(str1);
	return 0;
}
