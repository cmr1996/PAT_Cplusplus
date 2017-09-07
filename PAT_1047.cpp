#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int score[10000];
	for (int i = 0; i < 10000; i++)
	{
		score[i] = 0;
	}
	int maxnum = 0;
	for (int i = 0; i < N; i++)
	{
		string tmp1;
		int grade;
		cin >> tmp1 >> grade;
		int cnt = 0;
		int pos = 0;
		pos = tmp1.find("-");
		string tmp2 = tmp1.substr(0, pos);
		stringstream ss;
		ss << tmp2;
		int num;
		ss >> num;
		if (num > maxnum) { 
			maxnum = num;	
		}
		score[num] += grade;
	}
	int max = 0;
	int maxpos = 0;
	for (int i = 0; i <= maxnum; i++)//这个地方要使用小于等于,不然会出现一个点错误,因为会漏掉一个数
	{
		if (score[i] > max) { 
			max = score[i];
			maxpos = i;
		}
	}
	cout << maxpos << ' ' << max;
	return 0;
}