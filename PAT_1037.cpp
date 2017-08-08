#include<iostream>
#include<stdio.h>
#include<cmath>
#pragma warning(disable:4996);
using namespace std;

typedef struct
{
	long int Galleon;
	long int Sickle;
	long int Knut;
	long int ALL;//= Galleon * 17 * 29 + Sickle * 29 + Knut;
}money;

money cnt(money a)
{
	a.ALL = a.Galleon * 17 * 29 + a.Sickle * 29 + a.Knut;
	return a;
}

money money_minus(money a, money b)//b-a,a是应付的钱数,b是实付的钱数
{
	money c;
	c.ALL = b.ALL - a.ALL;
	long int tmp = abs(c.ALL);
	c.Galleon = tmp / (17 * 29);
	c.Sickle = tmp / 29 - c.Galleon * 17;
	c.Knut = tmp - 17 * 29 * c.Galleon - 29 * c.Sickle;
	return c;
}

void prt_mon(money a)
{
	if (a.ALL >= 0) { printf("%ld.%ld.%ld", a.Galleon, a.Sickle, a.Knut); }
	else { printf("-%ld.%ld.%ld", a.Galleon, a.Sickle, a.Knut); }
}

int main()
{
	money pay;
	money back;
	money rst;
	scanf("%ld.%ld.%ld %ld.%ld.%ld", &pay.Galleon, &pay.Sickle, &pay.Knut, &back.Galleon, &back.Sickle, &back.Knut);
	pay = cnt(pay); back = cnt(back);
	rst = money_minus(pay, back);
	prt_mon(rst);
	return 0;
}