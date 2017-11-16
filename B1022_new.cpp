#pragma warning (disable:4996)
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

int main()
{
	int A, B, C, n;
	scanf("%d %d %d", &A, &B, &n);
	C = A + B;
	int num[30];
	int i = 0;
	while (C >= n)
	{
		num[i++] = C%n;
		C = C / n;
	}
	num[i] = C;
	for (int j = i; j >= 0; j--)
	{
		printf("%d", num[j]);
	}
	return 0;
}