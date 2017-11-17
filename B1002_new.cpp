#pragma warning(disable:4996)
#include<cstdio>

int main()
{
	char num[101];
	scanf("%s", num);

	int i = 0, sum = 0;
	while (num[i] != '\0')
	{
		sum += (num[i] - '0');
		i++;
	}

	int ans[4], j = 0;
	do
	{
		ans[j] = sum % 10;
		sum /= 10;
		j++;
	} while (sum != 0);

	char alph[10][5] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
	for (int i = j-1; i >= 0; i--)
	{
		if (i == 0) { 
			printf("%s", alph[ans[i]]); }
		else { printf("%s ", alph[ans[i]]); }
	}

	return 0;
}