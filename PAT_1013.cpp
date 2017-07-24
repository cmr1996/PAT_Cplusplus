#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
const int MAX = 200000;

int main()
{
	int prime[MAX+1] = { 0 };//素数的标志为0
	prime[0] = 1;

	int temp[10100];

	for (int i = 2; i*i <= MAX; i++)//素数筛选，筛出前10000位的素数
	{
		if (prime[i]==0)//筛取素数的倍数,选择素数
		{
			for (int j = i + i; j <= MAX; j += i)
			{
				prime[j] = 1;//合数标志为1
			}
		}
	}

	int k = 1;
	for (int i = 2; i <= MAX; i++)
	{
		if (prime[i] == 0)
		{
			temp[k] = i;
			k++;
		}
	}
	temp[k] = -1;

	int M, N;
	int cnt = 0;//换行计数器
	scanf_s("%d%d", &M, &N);
	for (int i = M; i <= N; i++)
	{
		if (i==N)
		{
			cout << temp[i];
		}
		else if (cnt==9)
		{
			cout << temp[i] << endl;
			cnt = 0;
		}
		else
		{
			cout << temp[i] << ' ';
			cnt++;
		}
	}

	return 0;
}