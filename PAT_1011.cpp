#include<stdio.h>

int main()
{
	int N;
	long long A, B, C;
	scanf_s("%d", &N);//Ñ­»·´ÎÊý
	for (int i = 0; i < N; i++)
	{
		scanf_s("%lld%lld%lld", &A, &B, &C);
		printf("Case #%d: %s\n", i + 1, A > C - B ? "true" : "false");
	}
	return 0;
}