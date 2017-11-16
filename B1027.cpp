#pragma warning(disable:4996)
#include<cstdio>
#include<cmath>

int main()
{
	int n;
	char tmp;
	scanf("%d %c", &n, &tmp);
	int bottom = int(sqrt(2.0*(n + 1))) - 1;
	if (bottom % 2 == 0) { bottom-- ; }
	for (int i = bottom; i >= 1; i-=2)
	{
		int j = (bottom - i) / 2;
		for (; j > 0; j--) { printf(" "); }
		for (int k = i; k > 0; k--) { printf("%c", tmp); }
		printf("\n");
	}
	for (int i = 3; i <= bottom; i += 2)
	{
		for (int j = (bottom - i) / 2; j > 0; j--) { printf(" "); }
		for (int k = i; k > 0; k--) { printf("%c",tmp); }
		printf("\n");
	}

	int used = 0.5*(bottom + 1)*(bottom + 1) - 1;
	printf("%d", n-used);
	return 0;
}