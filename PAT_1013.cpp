#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
const int MAX = 200000;

int main()
{
	int prime[MAX+1] = { 0 };//�����ı�־Ϊ0
	prime[0] = 1;

	int temp[10100];

	for (int i = 2; i*i <= MAX; i++)//����ɸѡ��ɸ��ǰ10000λ������
	{
		if (prime[i]==0)//ɸȡ�����ı���,ѡ������
		{
			for (int j = i + i; j <= MAX; j += i)
			{
				prime[j] = 1;//������־Ϊ1
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
	int cnt = 0;//���м�����
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