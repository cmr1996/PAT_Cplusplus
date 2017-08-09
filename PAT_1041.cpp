#include<iostream>
#include<stdio.h>
#pragma warning(disable:4996);
using namespace std;

typedef struct
{
	long int ID;
	int ksh;//¿¼ÊÔºÅ
} sjhsz;//ÊÔ»úºÅÊý×é

int main()
{
	int n;
	cin >> n;
	sjhsz sjh[1001];
	for (int i = 0; i < n; i++)
	{
		long int m;
		int n, k;
		scanf("%ld %d %d", &m, &n, &k);
		sjh[n].ID = m;
		sjh[n].ksh = k;
	}

	int n1;
	cin >> n1;
	for (int i = 0; i < n1-1; i++)
	{
		int tmp;
		cin >> tmp;
		cout << sjh[tmp].ID << " " << sjh[tmp].ksh << endl;
	}
	int tmp;
	cin >> tmp;
	cout << sjh[tmp].ID << " " << sjh[tmp].ksh;
	return 0;
}