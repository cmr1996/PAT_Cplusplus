#include<stdio.h>
#pragma warning(disable:4996);

typedef struct frac_
{
	long n, d, s;//n是分子,d是分母,s是符号位
} FC;

//求最大公约数
long gcd(long a, long b) 
{
	return b == 0 ? a : gcd(b, a%b);
}

// 分数处理函数(确定符号,约分)
FC hand(FC a)
{
	if (a.n < 0) // 如果分子为负，将符号赋给符号变量，分子取正值
	{
		a.s *= -1;
		a.n *= -1;
	}
	long tmp = gcd(a.n, a.d);
	//约分
	a.n /= tmp;
	a.d /= tmp;
	return a;
}

//单个分数输出函数
void prt_fc(FC a)
{
	if (a.d==0)
	{
		printf("Inf");
	}
	else
	{
		a = hand(a);//约分
		long i = a.n / a.d;//整数部分
		a.n = a.n % a.d;//化简为真分式
		if (i==0&&a.n==0)//如果整数和小数部分均为0,输出'0'
		{
			printf("0");
		}
		else
		{
			if (a.s < 0) { printf("(-"); }
			if (i != 0) { printf("%ld", i); }
			if (i != 0 && a.n != 0) { printf(" "); }
			if (a.n != 0) { printf("%ld/%ld", a.n, a.d); }
			if (a.s < 0) { printf(")"); }
		}
	}
}

// 计算函数，加减乘除
FC plus(FC a, FC b)
{
	FC c;
	c.n = a.s*a.n*b.d + b.s*a.d*b.n;
	c.d = a.d*b.d;
	c.s = 1;
	return(c);
}

FC minus(FC a, FC b)
{
	FC c;
	c.n = a.s*a.n*b.d - b.s*a.d*b.n;
	c.d = a.d*b.d;
	c.s = 1;
	return(c);
}

FC mutil(FC a, FC b)
{
	FC c;
	c.n = a.s*b.s*a.n*b.n;
	c.d = a.d*b.d;
	c.s = 1;//通过这种方式优化计算
	return(c);     //乘和除的符号是可以直接得出的，而加减的依赖于计算结果
}

FC divis(FC a, FC b)
{
	FC c;
	c.n = a.n*b.d;
	c.d = a.d*b.n;
	c.s = a.s*b.s;
	return(c);
}

int main()
{
	FC a = { 0,0,1 }, b = { 0,0,1 }, c = { 0,0,1 };
	scanf("%ld/%ld %ld/%ld", &a.n, &a.d, &b.n, &b.d); // 读取分数a、b
	//hand(a); hand(b); //对a,b
	prt_fc(a); printf(" + "); prt_fc(b); printf(" = "); c = plus(hand(a), hand(b)); prt_fc(c); printf("\n");
	prt_fc(a); printf(" - "); prt_fc(b); printf(" = "); c = minus(hand(a), hand(b)); prt_fc(c); printf("\n");
	prt_fc(a); printf(" * "); prt_fc(b); printf(" = "); c = mutil(hand(a), hand(b)); prt_fc(c); printf("\n");
	prt_fc(a); printf(" / "); prt_fc(b); printf(" = "); c = divis(hand(a), hand(b)); prt_fc(c);
	
	return 0;
}