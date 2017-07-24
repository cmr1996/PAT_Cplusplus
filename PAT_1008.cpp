#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	
	int NUM[101];//原数组
	int* temp = NUM;
	for (int i = 0; i < N; i++)
	{
		cin >> *temp;
		temp++;
	}
	*temp = -1;//结束标记

	M = M % N;
	int DFT[101];
	int j = 0;
	for (int j = 0; j < N; j++)
	{
		if (j + M < N)
		{
			DFT[j + M] = NUM[j];
		}
		else
		{
			DFT[j + M - N] = NUM[j];
		}
	}

	for (int i = 0; i < N-1; i++)
	{
		cout << DFT[i] << ' ';
	}
	cout << DFT[N - 1];
	return 0;
}