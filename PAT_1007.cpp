#include<iostream>
using namespace std;
#define MAXN 100000
/*
int IsPrime(int num)
{
	int flag = 1;//���λ
	if (num == 2)
	{
		return flag = 1;
	}
	else
	{
		for (int i = 2; i < num; i++)
		{
			int temp = sqrt(i);
			for (int j = 2; j < temp; j++)
			{

			}
		}
	}
}
*/
int main()
{
	int n;//����һ����
	cin >> n;
	int prime[MAXN];
	prime[0] = 2;//2һ����1~n��������ĵ�һ��
	int prime_pos = 1;//��������λ��ָ��
	for (int i = 3; i <= n; i++)
	{
		int flag = 1;
		int flag_i=sqrt(i);
		for (int j = 2; j <= flag_i; j++)
		{
			if (i%j == 0)
			{
				flag = 0;
			}
		}
		if (flag==1)
		{
			prime[prime_pos] = i;
			prime_pos++;
		}
	}
	prime[prime_pos] = -1;
	int prime_count = 0;//�����Լ�����
	int k = 0;
	while (k+1!=prime_pos)
	{
		int d = prime[k + 1] - prime[k];
		if (d==2)
		{
			prime_count++;
		}
		k++;
	}
	cout << prime_count;
	return 0;
}