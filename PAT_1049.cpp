#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

int main()
{
	vector<double> tmp;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		double l;
		cin >> l;
		tmp.push_back(l);
	}

	double sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += tmp[i] * (N - i)*(i + 1);
	}

	printf("%.2f\n", sum);
	return 0;
}