#include<stdio.h>
#pragma warning(disable:4996);

typedef struct frac_
{
	long n, d, s;//n�Ƿ���,d�Ƿ�ĸ,s�Ƿ���λ
} FC;

//�����Լ��
long gcd(long a, long b) 
{
	return b == 0 ? a : gcd(b, a%b);
}

// ����������(ȷ������,Լ��)
FC hand(FC a)
{
	if (a.n < 0) // �������Ϊ���������Ÿ������ű���������ȡ��ֵ
	{
		a.s *= -1;
		a.n *= -1;
	}
	long tmp = gcd(a.n, a.d);
	//Լ��
	a.n /= tmp;
	a.d /= tmp;
	return a;
}

//���������������
void prt_fc(FC a)
{
	if (a.d==0)
	{
		printf("Inf");
	}
	else
	{
		a = hand(a);//Լ��
		long i = a.n / a.d;//��������
		a.n = a.n % a.d;//����Ϊ���ʽ
		if (i==0&&a.n==0)//���������С�����־�Ϊ0,���'0'
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

// ���㺯�����Ӽ��˳�
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
	c.s = 1;//ͨ�����ַ�ʽ�Ż�����
	return(c);     //�˺ͳ��ķ����ǿ���ֱ�ӵó��ģ����Ӽ��������ڼ�����
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
	scanf("%ld/%ld %ld/%ld", &a.n, &a.d, &b.n, &b.d); // ��ȡ����a��b
	//hand(a); hand(b); //��a,b
	prt_fc(a); printf(" + "); prt_fc(b); printf(" = "); c = plus(hand(a), hand(b)); prt_fc(c); printf("\n");
	prt_fc(a); printf(" - "); prt_fc(b); printf(" = "); c = minus(hand(a), hand(b)); prt_fc(c); printf("\n");
	prt_fc(a); printf(" * "); prt_fc(b); printf(" = "); c = mutil(hand(a), hand(b)); prt_fc(c); printf("\n");
	prt_fc(a); printf(" / "); prt_fc(b); printf(" = "); c = divis(hand(a), hand(b)); prt_fc(c);
	
	return 0;
}