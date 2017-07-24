#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

int main()
{
	char A[1001];//除数
	int  B;//被除数
	int Rest = 0;//余数
	char Quotient[1000];//商数

	scanf("%s%d", A, &B);
	int i = 0;
	for (; i < strlen(A); i++)
	{
		Quotient[i] = (Rest * 10 + (A[i] - '0')) / B + '0';
		Rest = (Rest * 10 + (A[i] - '0')) % B;
	}
	Quotient[i] = '\0';

	if (Quotient[0]=='0'&&Quotient[1]!='\0')
	{
		printf("%s", Quotient + 1);
	}
	else
	{
		printf("%s", Quotient);
	}

	printf(" %d", Rest);
	return 0;
}