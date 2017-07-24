#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct mooncake
{
	double price;//总售价
	double number;//总销量
	double unitPrice;//单价
};

bool cmp(mooncake a, mooncake b)
{
	return a.unitPrice > b.unitPrice;
}

int main()
{
	int N;//月饼的种类数(正整数)
	double D;//市场需求量(单位为万吨,所以可以取浮点数)
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
			ans = ans + s[i].price;//千里之堤,溃于蚁穴啊
			D = D - s[i].number;
		}
	}

	printf("%.2f\n", ans);
	return 0;
}