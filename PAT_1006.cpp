#include <stdio.h>

void print(int n);             //输出函数声明 

int main()
{
	int n;
	scanf("%d", &n);           //输入数字n 
	print(n);

	return 0;
}

void print(int n)              //输出函数 
{
	int a, b, c;               //a为百位数字，b为十位数字，c为个位数字 
	a = n / 100;
	b = n % 100 / 10;
	c = n % 10;
	int i;
	for (i = 0; i < a; i++) {
		printf("B");
	}
	for (i = 0; i < b; i++) {
		printf("S");
	}
	for (i = 1; i <= c; i++) {
		printf("%d", i);
	}
}