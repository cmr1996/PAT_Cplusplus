#include <stdio.h>

void print(int n);             //����������� 

int main()
{
	int n;
	scanf("%d", &n);           //��������n 
	print(n);

	return 0;
}

void print(int n)              //������� 
{
	int a, b, c;               //aΪ��λ���֣�bΪʮλ���֣�cΪ��λ���� 
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