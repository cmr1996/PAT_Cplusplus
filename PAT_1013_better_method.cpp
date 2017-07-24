#include<stdio.h>

int main()
{
	int M, N;//输入的M,N
	scanf_s("%d%d", &M, &N);
	int count = 0;//计数器
	int flag_NotPrime = 0;
	for (int i = 2; count <= N; i++)
	{
		flag_NotPrime = 0;
		for (int j = 2; j*j <= i ; j++)
		{
			if (i%j==0)
			{
				flag_NotPrime++;
			}
		}
		if (flag_NotPrime==0)
		{
			count++;
		}
		if (count>=M&&count<=N&&flag_NotPrime==0)
		{
			printf("%d", i);
			if ((count-M)%10==9)
			{
				printf("\n");
			}
			else if(count!=N)
			{
				printf(" ");
			}
		}
	}

	return 0;
}