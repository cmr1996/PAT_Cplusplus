#pragma warning(disable:4996)
#include<cstdio>
#define Galleon 17*29 //һ��Galleon�һ�17*29��Knut
#define Sickle 29 //һ��Sickle�һ�29��Knut

int main()
{
	int Pg, Ps, Pk, Ag, As, Ak, P, A;
	scanf("%d.%d.%d %d.%d.%d", &Pg, &Ps, &Pk, &Ag, &As, &Ak);
	P = Pg*Galleon + Ps*Sickle + Pk;  //Ӧ��
	A = Ag*Galleon + As*Sickle + Ak;  //ʵ��
	int ans = A - P;
	if (ans < 0)
	{ 
		ans = -ans;
		printf("-");
	}
	printf("%d.%d.%d", ans / (17 * 29), ans % (17 * 29) / 29, ans % 29);  //�ص㣡����
	return 0;
}