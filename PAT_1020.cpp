#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct mooncake
{
	double price;//���ۼ�
	double number;//������
	double unitPrice;//����
};

bool cmp(mooncake a, mooncake b)
{
	return a.unitPrice > b.unitPrice;
}

int main()
{
	int N;//�±���������(������)
	double D;//�г�������(��λΪ���,���Կ���ȡ������)
	cin >> N >> D;
	mooncake* s = new mooncake[N];

	for (int i = 0; i < N; i++)
	{
		cin >> s[i].number;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> s[i].price;
		s[i].unitPrice = s[i].price / s[i].number;
	}

	sort(s, s + N, cmp);

	double ans = 0;
	for (int i = 0; i < N; i++)
	{
		if (s[i].number >= D)
		{
			ans = ans + D*s[i].unitPrice;
			break;
		}
		else
		{
			ans = ans + s[i].price;//ǧ��֮��,������Ѩ��
			D = D - s[i].number;
		}
	}

	printf("%.2f\n", ans);
	return 0;
}